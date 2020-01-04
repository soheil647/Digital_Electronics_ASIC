module resistor_module {

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "ldata.h"
#include "demo.h"

/*  Input Default values  */
#define RESVAL		100				/* in femtofarads */
#define UNIT_RESVAL	10	/* in attofarads per square micron */
#define LAYER2	"Poly"
#define LAYER1	"Active"
#define OVERLAP		1			/* in microns */
#define LIMIT_LENGTH	0		/* in microns */
#define LIMIT_WIDTH	6		/* in microns */

int get_res_parameters(float *pdesired_resval, float *plimit_length,
							  float *plimit_width, char *layer1_name,
							  char *layer2_name, float *punit_resval,
							  float *poverlap, float UNITS)
{
	/*  input box struct  */
	LDialogItem  Menu_Items[7]= {
		{"Desired resistor value:", ""},
		{"Set resistor length (0=none):", ""},
		{"Set resistor width (0=none):", ""},
		{"Name of resis layer:", ""},
		{"Name of active layer:", ""},
		{"   Sheet res of res layer (Ohms/sq.um):", ""},
		{"   Overlap of active beyond res layer:", ""},
	};
/***********/
   INPUT:
/***********/
/*	convert and store input values into menu struct */
	sprintf( Menu_Items[0].value, "%g", *pdesired_resval );
	sprintf( Menu_Items[1].value, "%.2f", (*plimit_length) *=UNITS );
	sprintf( Menu_Items[2].value, "%.2f", (*plimit_width) *=UNITS );
	strcpy( Menu_Items[3].value, layer2_name );
	strcpy( Menu_Items[4].value, layer1_name);
    sprintf( Menu_Items[5].value, "%g", (*punit_resval) /= pow(UNITS,2) );
	sprintf( Menu_Items[6].value, "%.2f", (*poverlap) *=UNITS );

	if ( LDialog_MultiLineInputBox( "Resistor Parameters", Menu_Items, 7 ) ) {
		*pdesired_resval = atof( Menu_Items[0].value);
		*plimit_length = atof( Menu_Items[1].value );
		*plimit_width = atof( Menu_Items[2].value );
		strcpy( layer2_name, Menu_Items[3].value );
		strcpy( layer1_name, Menu_Items[4].value );
		*punit_resval = atof( Menu_Items[5].value );
		*poverlap = atof( Menu_Items[6].value );
		return 1;
	} 
	else
	    return 0;


}

void ResistorMacro( void )
{
	LFile	File;
	LCell	Cell;
	char	STR[PAGESIZE], STR2[PAGESIZE];
	LTechnology		InitialTechSettings, tech;
	LGrid	GridSettings;
	long	InitialGridSize;

	/*  units variables  */
	float	ATTO, FEMTO, FEMTO2ATTO, ATTO2FEMTO;
	float	UNITS, S_UNITS;
	char	units[LINESIZE];

	/*  input and design variables  */
	LLayer  layer1, layer2;
	char	layer1_name[NAMESIZE], layer2_name[NAMESIZE];

	float	desired_resval, unit_resval;
	float	ideal_area;
	float	real_resval, real_area;
	float	limit_length, limit_width;
	float	overlap;
	long	width1, width2, length1, length2;
	int		too_small, negative;

	/*  construction variables  */
	LPoint	cursor_location;
	LCoord	x, y;

	/*****************************/
	/*  Display Warning Message  */
	/*****************************/
	sprintf (STR,"All dimensions must be in Microns:\n   %s\n");
	LStatusBar_SetMsg(STR);


	/**************************/
	/*  Form default values  */
	/**************************/
	Cell = LCell_GetVisible(); 			// the current cell
	File = LCell_GetFile(Cell);			// the current file 
	//	LFile_GetName(File, Filename, NAMESIZE);

	/*	X and Y location  */
	cursor_location = LCursor_GetPosition();
	x = cursor_location.x;
	y = cursor_location.y;


	/*  Grid size and technology size  */
	/*  this sets the tech vals, but let's have it read them sometime in future  */

	InitialTechSettings = tech = LFile_GetTechnology( File );

	LFile_GetGrid( File, &GridSettings );
	InitialGridSize = GridSettings.mouse_snap_grid_size;

	tech = LFile_GetTechnology( File );
	switch ( tech.unit_type ) 
	{
		case MICRONS: strcpy(units, "MICRONS"); break;
		case MILLIMETERS: strcpy(units, "MILLIMETERS"); break;
		case CENTIMETERS: strcpy(units, "CENTIMETERS"); break;
		case MILS: strcpy(units, "MILS"); break;
		case INCHES: strcpy(units, "INCHES"); break;
		case LAMBDA: strcpy(units, "LAMBDA"); break;
		case OTHER: strcpy(units, "OTHER"); break;
	}
	if( tech.unit_type == LAMBDA ) 
		UNITS = 1.0 * tech.num * tech.lambda_num / tech.denom / tech.lambda_denom;
	else
		UNITS = tech.num / tech.denom;

	/* Don't divide by 0 */
	if(UNITS == 0)  
		UNITS = 1;

	//	GridSettings.mouse_snap_grid_size = 1 / UNITS;
	//	LFile_SetGrid( File, &GridSettings );

	/*	assign default input values  */
	desired_resval = RESVAL;
	unit_resval = UNIT_RESVAL *pow(UNITS,2) ;
	strcpy( layer2_name, LAYER2 );
	strcpy( layer1_name, LAYER1 );
	overlap =  OVERLAP / UNITS;
	limit_length = LIMIT_LENGTH / UNITS;
	limit_width = LIMIT_WIDTH /UNITS; 

	while (1) {
		if ( !get_res_parameters(&desired_resval, &limit_length, &limit_width,
										 layer1_name, layer2_name, &unit_resval,
										 &overlap, UNITS) )
			return;

		/*	convert input values  */
		desired_resval = desired_resval;
		unit_resval *=  pow(UNITS,2);
		layer2 = LLayer_Find (File, layer2_name);
		layer1 = LLayer_Find (File, layer1_name);
		overlap /= UNITS;
		limit_length /= UNITS;
		limit_width /= UNITS;

		/***********/
CHECK: 
	/***********/
	if ( desired_resval <= 0 || unit_resval <= 0 )
	{
		sprintf (STR,"Error: Given unit resistor value or desired.\n");
		strcat( STR, "resistor value, is zero or negative.\nPlease re-enter these values.");
		LDialog_AlertBox(STR);
		continue;
	}

	if ( !layer1 )
	{
		sprintf( STR,"Error: Layer 1 not found in file.\n");
		sprintf( STR2, "\tLayer: %s.\nPlease re-enter layername.", layer1_name);
		strcat(STR, STR2);
		LDialog_AlertBox(STR);
		continue;
	}

	if ( !layer2 )
	{
		sprintf( STR, "Error: Layer 2 not found in file.\n\tLayer: %s.\n",
					layer1_name);
		strcat( STR, "\nPlease re-enter layername.");				
		LDialog_AlertBox(STR);
		continue;
	}


	/***********/
	/* BEGIN: 
	/***********/
		ideal_area = desired_resval / unit_resval;

		if( !limit_length ) {
			width2 = limit_width;
			width1 = width2 + 2.0 * overlap;
			length2 = ideal_area / width2;
			length1 = length2 + 2.0 * overlap;
		}
		else if( !limit_width ) {
			length2 = limit_length;
			length1 = length2 + 2.0 * overlap;
			width2 = ideal_area / length2;
			width1 = width2 + 2.0 * overlap;
		}
		else 
		{
			length2 = limit_length;
			width2 = limit_width;
			length1 = length2 + 2 * overlap;
			width1 = width2 + 2 * overlap;
			ideal_area = length2 * width2;
		}
		if( !limit_width && !limit_length ) 
		{
			length2 = width2 = sqrt( ideal_area );
			length1 = length2 + 2 * overlap;
			width1 = width2 + 2 * overlap;
		}


		real_area = length2 * width2;
		real_resval = real_area * unit_resval;

		negative = length1 <= 0 || length2 <= 0 || width1 <= 0 || width2 <= 0;
		too_small = real_area - ideal_area <= -real_area;
		if( negative || too_small  ) {
			sprintf( STR, "The values given for width constraint and ");
			strcat(STR,"length constraint will not produce the resistor ");
			strcat(STR,	"value you desire (i.e.negative values are resulting or");
			strcat(STR,	"the resistance is too small).\n\n");
			sprintf(STR2,"(%.2f um x  %.2f um  x  %.2f Ohm/sq.um != %.3fOhms)\n\n"
					  , length2*UNITS, width2*UNITS, unit_resval/pow(UNITS,2),
					  real_resval );
			strcat(STR, STR2);
			strcat(STR,	"Please re-enter values.");
			LDialog_AlertBox( STR );
			continue;
		}
		break; /* Come out of the loop */		
	}/*end of while loop */

	/*  Draw resistor plates and center them  */
	LSelection_DeselectAll();
	LSelection_AddObject( LBox_New(Cell, layer2, x, y, x+width2, y+length2) );
	x -= overlap;  y -= overlap;
	LSelection_AddObject( LBox_New(Cell, layer1, x, y, x+width1, y+length1) );
	LSelection_Move( -width2 / 2, -length2 / 2  );

	/*  Inform user of modified values  */
	sprintf( STR, "Input values may have been modified slightly to keep\n");
	strcat(STR,	"resistor dimensions in unit values of the grid spacing.\n\n");
	sprintf( STR2, "Actual resistor value: %.2f Ohms\n", real_resval );
	strcat(STR, STR2);
	sprintf( STR2, "Resistor dimensions:   %.2f um  x  %.2f um.\n   Area: %.2f sq.um.\n", length2*UNITS, width2*UNITS, real_area * pow(UNITS,2) );
	strcat(STR, STR2);
	sprintf( STR2, "Poly dimensions:    %.2f um  x  %.2f um.\n", length2*UNITS, width2*UNITS);
	strcat(STR, STR2);
	sprintf( STR2, "Active dimensions:  %.2f um  x  %.2f um.\n", length1*UNITS, width1*UNITS );
	strcat(STR, STR2);
	LDialog_MsgBox( STR );

	LDisplay_Refresh();


}	/* End of function : Res_Macro_main */ 


void  res_macro_register( void ) 
{
	LMacro_BindToHotKey ( KEY_R, "Draw Resistor Geometry",
								 "ResistorMacro" );
}


}  /* End of Module hierarchy */

res_macro_register ( );

