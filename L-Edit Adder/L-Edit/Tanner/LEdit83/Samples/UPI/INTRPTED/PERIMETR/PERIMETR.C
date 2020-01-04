module perimeter_module {

#include <math.h>
#include <string.h>
#include <stdio.h>
#include "ldata.h"
#include "demo.h"

LPoint pm_LPoint_Subtract(LPoint Point1, LPoint Point2) {

	LPoint Temp;

	Temp.x = Point1.x - Point2.x;
	Temp.y = Point1.y - Point2.y;

	return Temp;
}

void PerimeterMacro( void )
{
	/* set up variables  */
	LFile	File;
	LCell	Cell;
	char	STR[NAMESIZE];
	char	STR2[NAMESIZE];
	LTechnology		tech;
	char		units[PAGESIZE];
	double  UNITS;

	/*  work variables  */
	LSelection	selected;
	LObject		obj;
	LShapeType	shape;
	LGeomType	geom;
	LRect		rect;

	LPoint points[100];
	long	num_verts;
	int		i;

	LPoint	diff;
	float		tot_length;

	/*  Display Warning Message  */
	sprintf (STR,"Be sure to select object first.\nRectilinear objects only.");
	LDialog_AlertBox(STR);

	/*  Form default values  */
	Cell = LCell_GetVisible(); 			// the current cell
	File = LCell_GetFile(Cell);			// the current file 

	/*  Grid size and technology size  */
	tech = LFile_GetTechnology( File );
	switch ( tech.unit_type ) {
		case MICRONS: strcpy(units, "MICRONS"); break;
		case MILLIMETERS: strcpy(units, "MILLIMETERS"); break;
		case CENTIMETERS: strcpy(units, "CENTIMETERS"); break;
		case MILS: strcpy(units, "MILS"); break;
		case INCHES: strcpy(units, "INCHES"); break;
		case LAMBDA: strcpy(units, "LAMBDA"); break;
		case OTHER: strcpy(units, "OTHER"); break;
	}
	if( tech.unit_type == LAMBDA ) 
		UNITS =1.0 * tech.num * tech.lambda_num / tech.denom / tech.lambda_denom;
	else
		UNITS = 1.0 * tech.num / tech.denom;

	/*  load input values  */
	selected = LSelection_GetList();
	if (selected == 0){
		LDialog_AlertBox("No Object is selected");
		return;
	}
	obj = LSelection_GetObject( selected );
	shape = LObject_GetShape( obj );
	geom = LObject_GetGeometry( obj );
	num_verts = LVertex_GetCount( obj );
	LVertex_GetArray( obj, points, 100);

	/* CHECK: */

	if ( shape != LBox && shape != LPolygon ) {
		sprintf( STR, "The object you selected is neither a Box or\n");
		strcat(STR, "a polygon type shape.  Please select another object.");
		LDialog_AlertBox(STR);
		return;
	}

	if ( geom != LOrthogonal ) {
		sprintf( STR, "The object you selected is not rectilinear shape\n");
		strcat(STR, "Please select another object.");
		LDialog_AlertBox(STR);
		return;
	}

	if ( num_verts >100 ) {
		sprintf( STR, "The object you selected includes more than\n");
		strcat(STR, "100 vertices.  Please select another object.");
		LDialog_AlertBox(STR);
		return;
	}

	/***********/
BEGIN: 
	/***********/

	tot_length = 0;

	if( shape == LBox ) 
	{
		rect = LBox_GetRect( obj );
		tot_length =  (rect.x1 - rect.x0);
		tot_length += (rect.y1 - rect.y0);
		tot_length *= 2;
	}
	else 
	{
		for( i=1; i < num_verts; i++) 
		{
			diff = pm_LPoint_Subtract( points[i-1], points[i] );
			tot_length += fabs(diff.x) + fabs(diff.y);
		}
		diff = pm_LPoint_Subtract( points[0], points[num_verts-1] );
		tot_length += fabs(diff.x) + fabs(diff.y);
	}

	sprintf( STR,"The perimeter for the object you selected is:\n" );
	sprintf(STR2, "\t%9.3f %s.\n", (tot_length*UNITS), units );
	strcat(STR,STR2);
	sprintf(STR2, "\t(%d internal units.)", (long)tot_length );
	strcat(STR,STR2);
	LDialog_MsgBox( STR );
}	/* End of function : PerimeterMacro */ 


void  perimeter_macro_register ( void ) 
{
	LMacro_BindToHotKey(KEY_F3, "Calculate perimeter of obj.",
							  "PerimeterMacro");
}

}  /* End of Module hierarchy */
perimeter_macro_register ( );

