#include <stdlib.h>
#include <math.h>
#include "ldata.h"

void  SpiralMacro ( void )
{
	/********************************************************************/
	/* Draws spiral, rotates in 4 degree increments.  1995-11-27 Croft  */
	/********************************************************************/
	float        Angle, Angle0, Radius, Radius0, Rotation, Rings,
	Ring_Spacing, Ring_Width, Rotations;
	long         P, Points_Total, Ring_Segments;
	float        TWO_PI = 6.283185307;
	float        STEP   = 0.069813170;
	LPoint       Points [ 1002 ];
	LObject      Polygon;
	LCell        Cell_Draw   = LCell_GetVisible( );
	LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
	LPoint       Translation = LCursor_GetPosition ( );
	LDialogItem  Dialog_Items [ 6 ] = { { "Start Radius ", "50.0" },
	{ "Rings        ", "4.0 " },
	{ "Ring Segments", "50  " },
	{ "Ring Spacing ", "50.0" },
	{ "Ring Width   ", "25.0" },
	{ "Rotations    ", "0.0 " } };
	/********************************************************************/

	if(LLayer_Find (File_Draw, "Poly") == NULL)
	{
		LDialog_AlertBox("There is no Poly layer.\nMake sure Poly is in the layer map!");
		return;
	}

	do {
		if ( !LDialog_MultiLineInputBox ( "Spiral Properties", Dialog_Items, 6 ))
			return;
		Radius0       = atof ( Dialog_Items [ 0 ].value );
		Rings         = atof ( Dialog_Items [ 1 ].value );
		Ring_Segments = atol ( Dialog_Items [ 2 ].value );
		Ring_Spacing  = atof ( Dialog_Items [ 3 ].value );
		Ring_Width    = atof ( Dialog_Items [ 4 ].value );
		Rotations     = atof ( Dialog_Items [ 5 ].value );
	} while ( ( Ring_Segments > 500 / Rings  )
				 || ( Ring_Segments < 3            )
				 || ( Ring_Width    > Ring_Spacing ) );
	Points_Total = Rings * Ring_Segments;
	for ( Angle0 = TWO_PI * Rotations; Angle0 >= 0.0; Angle0 -= STEP ) {
		for ( P = 0; P <= Points_Total; P++ ) {
			Angle  = Angle0 + TWO_PI * P / Ring_Segments;
			Radius = Radius0 + Ring_Spacing * ( Angle - Angle0 ) / TWO_PI;
			Points [ P ].x = Translation.x + Radius * cos ( Angle );
			Points [ P ].y = Translation.y + Radius * sin ( Angle );
			Points [ 2 * Points_Total + 1 - P ].x = Translation.x
				+ ( Radius + Ring_Width ) * cos ( Angle );
			Points [ 2 * Points_Total + 1 - P ].y = Translation.y
				+ ( Radius + Ring_Width ) * sin ( Angle );
		}
		Polygon = LPolygon_New ( Cell_Draw, LLayer_Find (
			File_Draw, "Poly" ), Points, 2 * Points_Total + 2 );
		if ( Angle0 > TWO_PI * Rotations - STEP / 2.0 )
			LCell_SetView ( Cell_Draw, LCell_GetMbb ( Cell_Draw ) );
		if ( Angle0 >= STEP ) LObject_Delete ( Cell_Draw, Polygon );
	}
} 