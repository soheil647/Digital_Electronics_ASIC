#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "ldata.h"
#include "demo.h"

/* Input Default values  */
#define CAPVAL			100		/* in femtofarads */
#define UNIT_CAPVAL	1000		/* in attofarads per square micron */
#define LAYER1			"Poly"
#define LAYER2			"Poly2"
#define OVERLAP		1			/* in microns */
#define LIMIT_LENGTH	0			/* in microns */
#define LIMIT_WIDTH	4			/* in microns */

int get_cap_parameters(float *pdesired_capval, float *plimit_length,
							  float *plimit_width, char *layer1_name,
							  char *layer2_name, float *punit_capval,
							  float *poverlap, float FEMTO, float UNITS,
							  float ATTO)
{
	/*  input box struct  */
	LDialogItem  Menu_Items[7]= {
		{"Desired capacitor value (fF):", ""},
		{"Set capacitor length {0=none} (um):", ""},
		{"Set capacitor width {0=none} (um):", ""},
		{"Name of layer1 {top plate} (um):", ""},
		{"Name of layer2 {bottom plate} (um):", ""},
		{"Inter-layer unit cap (aF/um^2):", ""},
		{"Overlap of layer1 beyond layer2 (um):", ""},
	};

	/*	convert and store input values into menu struct */
	sprintf( Menu_Items[0].value, "%g", (*pdesired_capval) *=FEMTO);
	sprintf( Menu_Items[1].value, "%.2f", (*plimit_length) *=UNITS);
	sprintf( Menu_Items[2].value, "%.2f", (*plimit_width) *=UNITS);
	strcpy( Menu_Items[3].value, layer1_name);
	strcpy( Menu_Items[4].value, layer2_name );
	sprintf( Menu_Items[5].value, "%g", (*punit_capval) *=(ATTO/pow(UNITS,2)) );
	sprintf( Menu_Items[6].value, "%.2f", (*poverlap) *=UNITS);

	if( LDialog_MultiLineInputBox( "Capacitor Parameters", Menu_Items, 7 ) )
	{
		*pdesired_capval = atof( Menu_Items[0].value);
		*plimit_length = atof( Menu_Items[1].value );
		*plimit_width = atof( Menu_Items[2].value );
		strcpy( layer1_name, Menu_Items[3].value );
		strcpy( layer2_name, Menu_Items[4].value );
		*punit_capval = atof( Menu_Items[5].value );
		*poverlap = atof( Menu_Items[6].value );
		return 1;
	}
	else
	{
		return 0;
	}
} /* End of Function:  get_cap_parameters */

void CapacitorMacro( void )
{
	LFile File;
	LCell Cell;
	char STR[PAGESIZE], STR2[PAGESIZE];
	LTechnology InitialTechSettings, tech;
	LGrid GridSettings;
	long InitialGridSize;

	/*  units variables  */
	float ATTO, FEMTO, FEMTO2ATTO, ATTO2FEMTO;
	float UNITS;
	char  units[LINESIZE];

	/*  input and design variables  */
	LLayer  layer1, layer2;
	char  layer1_name[NAMESIZE], layer2_name[NAMESIZE];

	float desired_capval, unit_capval;
	float ideal_area;
	long  real_capval, real_area;
	float limit_length, limit_width;
	float overlap;
	long  width1, width2, length1, length2;
	int   negative, too_small;

	/*  construction variables  */
	LPoint   cursor_location;
	LCoord   x, y;

	/*****************************/
	/*  Display Warning Message  */
	/*****************************/
	LStatusBar_SetMsg("All dimensions must be in Microns.");

	/**************************/
	/*  Form default values  */
	/**************************/
	Cell = LCell_GetVisible();				// the current cell
	File = LCell_GetFile(Cell);			// the current file 

	/*	X and Y location  */
	cursor_location = LCursor_GetPosition();
	x = cursor_location.x;
	y = cursor_location.y;

	/*  conversion values  */
	ATTO =   pow(10,18);
	FEMTO =  pow(10,15);
	FEMTO2ATTO = ATTO/FEMTO;
	ATTO2FEMTO = FEMTO/ATTO;

	/*  Grid size and technology size  */
	/*  this sets the tech vals, but let's have it read them sometime in future  */
	InitialTechSettings = tech = LFile_GetTechnology( File );

	LFile_GetGrid( File, &GridSettings );
	InitialGridSize = GridSettings.mouse_snap_grid_size;

	tech = LFile_GetTechnology( File );
	switch( tech.unit_type )
	{
		case MICRONS: strcpy(units, "MICRONS"); break;
		case OTHER: strcpy(units, "OTHER"); break;
	}
	if( tech.unit_type == LAMBDA )
		UNITS = 1.0 * tech.num * tech.lambda_num / tech.denom / tech.lambda_denom;
	else if(tech.unit_type == MICRONS )
		UNITS = tech.num / tech.denom;
	else
	{
		sprintf (STR,"Warning: Set file technology to Microns!");
		LDialog_AlertBox( STR );
		return;
	}

	/* Don't divide by 0 */
	if(UNITS == 0)
		UNITS = 1;

	/*	assign default input values  */
	desired_capval = CAPVAL /FEMTO;
	unit_capval = UNIT_CAPVAL /(ATTO/pow(UNITS,2));
	strcpy( layer1_name, LAYER1 );
	strcpy( layer2_name, LAYER2 );
	overlap =  OVERLAP / UNITS;
	limit_length = LIMIT_LENGTH / UNITS;
	limit_width = LIMIT_WIDTH /UNITS; 

	/***********/
	/* INPUT:  */
	/***********/
	while(1)
	{
		if( !get_cap_parameters(&desired_capval, &limit_length, &limit_width,
										layer1_name, layer2_name, &unit_capval,
										&overlap, FEMTO, UNITS, ATTO) )
			return;

		/*	convert input values  */
		desired_capval /= FEMTO;
		unit_capval /= (ATTO / pow(UNITS,2) );
		layer1 = LLayer_Find (File, layer1_name);
		layer2 = LLayer_Find (File, layer2_name);
		overlap /= UNITS;
		limit_length /= UNITS;
		limit_width /= UNITS;

		/***********/
		/* CHECK:  */
		/***********/
		if( desired_capval <= 0 || unit_capval <= 0 )
		{
			sprintf (STR,"Error: Given unit capacitor value or desired.\n");
			strcat( STR,   "capacitor value, is zero or negative.\nPlease re-enter these values.");
			LDialog_AlertBox(STR);
			continue;
		}

		if( !layer1 )
		{
			sprintf (STR,"Error: Layer 1 not found in file.\n");
			sprintf( STR2,"\tLayer: %s.\nPlease re-enter layername.", layer1_name);
			strcat( STR, STR2);
			LDialog_AlertBox(STR);
			continue;
		}

		if( !layer2 )
		{
			sprintf (STR,"Error: Layer 2 not found in file.\n");
			sprintf( STR2,"\tLayer: %s.\nPlease re-enter layername.", layer1_name);
			strcat( STR, STR2);
			LDialog_AlertBox(STR);
			continue;
		}

		/***********/
		/* BEGIN:  */
		/***********/
		ideal_area = desired_capval / unit_capval;

		if( !limit_length )
		{
			width2 = limit_width;
			width1 = width2 + 2.0 * overlap;
			length2 = ideal_area / width2;
			length1 = length2 + 2.0 * overlap;
		}
		else if( !limit_width )
		{
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
		real_capval = real_area * unit_capval;

		negative = length1 <= 0 || length2 <= 0 || width1 <= 0 || width2 <= 0;
		too_small = real_area - ideal_area <= -real_area;
		if( negative || too_small  )
		{
			sprintf( STR, "The values given for width constraint and ");
			strcat(STR,"length constraint will not produce the capacitor ");
			strcat(STR, "value you desire (i.e. negative values are resulting or ");
			strcat(STR, "the capacitance is too small).\n\n");
			sprintf(STR2,"(%.2f um  x  %.2f um  x  %.2f Atto/sq.  !=  %.3f Ff )\n\n", length2*UNITS, width2*UNITS, unit_capval/(ATTO/pow(UNITS,2)), real_capval/FEMTO );
			strcat(STR, STR2);
			strcat(STR, "Please re-enter values.");
			LDialog_AlertBox( STR );
			continue;
		}
		break; /* Come out of the loop */
	}/* end of while loop */


	/*  Draw capacitor plates and center them  */
	LSelection_DeselectAll();
	LSelection_AddObject( LBox_New(Cell, layer1, x, y, x+width1, y+length1) );
	x += overlap;  y += overlap;
	LSelection_AddObject( LBox_New(Cell, layer2, x, y, x+width2, y+length2) );
	LSelection_Move( -length1 / 2 , -width1 / 2 );

	/*********/
	/* DONE: */
	/*********/

	/* Inform user of modified values. */
	sprintf( STR, "Input values may have been modified slightly to keep\n");
	strcat(STR, "capacitor dimensions in unit values of the grid spacing.\n\n");
	sprintf( STR2, "Actual capacitor value: %.2f fF\n", real_capval/FEMTO );
	strcat(STR, STR2);
	sprintf( STR2, "Capacitor's dimensions:   %.2f um  x  %.2f um.\n   Area: %.2f sq.um.\n", length2*UNITS, width2*UNITS, real_area * pow(UNITS,2) );
	strcat(STR, STR2);
	sprintf( STR2, "Plate1 dimensions:    %.2f um  x  %.2f um.\n", length2*UNITS, width2*UNITS);
	strcat(STR, STR2);
	sprintf( STR2, "Plate2 dimensions:  %.2f um  x  %.2f um.\n", length1*UNITS, width1*UNITS );
	strcat(STR, STR2);
	LDialog_MsgBox(STR);

}	/* End of function : CapacitorMacro */ 

int UPI_Entry_Point(void)
{
	LMacro_BindToHotKey(KEY_C, "Draw Capacitor Geometry", "CapacitorMacro");

	return 1; 
}
