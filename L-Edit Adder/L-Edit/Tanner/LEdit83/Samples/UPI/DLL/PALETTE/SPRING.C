#include <stdlib.h>
#include <math.h>
#include "ldata.h"

void  SpringMacro ( void )
{
	/********************************************************************/
	/* Draws spring then compresses and stretches.                      */
	/********************************************************************/
	float        PI = 3.141592654;
	float        STEP = 2.0 * PI / 45.0;
	long         Fold_Segments, Folds, P, P_Max;
	float        Length, Omega, Phase, Thickness, Width, Width0, X;
	float        Center_Line [ 501 ];
	LObject      Polygon;
	LPoint       Points [ 1002 ];
	LCell        Cell_Draw   = LCell_GetVisible( );
	LFile        File_Draw   = LCell_GetFile( Cell_Draw);
	LPoint       Translation = LCursor_GetPosition ( );
	LDialogItem  Dialog_Items [ 4 ] = { { "Length       ", "600.0" },
	                                    { "Width        ", "800.0" },
	                                    { "Folds        ", "5    " },
	                                    { "Thickness    ", "50.0 " } };
	/********************************************************************/

	if(LLayer_Find (File_Draw, "Metal1") == NULL)
	{
		LDialog_AlertBox("There is no Metal1 layer.\nMake sure Metal1 is in the layer map!");
		return;
	}

	do {
		if ( !LDialog_MultiLineInputBox ( "Spring Properties", Dialog_Items, 4 ))
			return;
		Length        = atof ( Dialog_Items [ 0 ].value );
		Width0        = atof ( Dialog_Items [ 1 ].value );
		Folds         = atol ( Dialog_Items [ 2 ].value );
		Thickness     = atof ( Dialog_Items [ 3 ].value );
	} while ( 1000 / ( 2 * Folds ) < 2 );
	
	for ( Phase = 2.0 * PI; Phase > -STEP / 2.0; Phase -= STEP ) {
		Width = Width0 * ( 1.0 + 0.5 * sin ( Phase ) );
		Omega = PI * ( float ) Folds / Width;
		for ( P = 0; P <= 500; P++ ) {
			X = P * Width / 500;
			Center_Line [ P ] = Length * sin ( Omega * X ) / 2.0 + 0.5;
			if ( Center_Line [ P ] < 0.0 ) Center_Line [ P ] -= 1.0;
			Points [ P ].x = Translation.x
								  + X + 0.5 * Thickness * cos ( Omega * X );
			Points [ P ].y = Translation.y + Center_Line [ P ]
								  - fabs ( 0.5 * Thickness * sin ( Omega * X ) );
			Points [ 1001 - P ].x = Translation.x
											+ X - 0.5 * Thickness * cos ( Omega * X );
			Points [ 1001 - P ].y = Translation.y + Center_Line [ P ]
											+ fabs (0.5 * Thickness * sin ( Omega * X ));
		}
		Polygon = LPolygon_New ( Cell_Draw,
									LLayer_Find (File_Draw, "Metal1"), Points, 1002 );
		if ( Phase >= 2.0 * PI - STEP / 2.0 )
			LCell_SetView ( Cell_Draw, LCell_GetMbb ( Cell_Draw ) );
		LCell_MakeVisible ( Cell_Draw );
		LCell_HomeView( Cell_Draw);
		if ( Phase >= STEP / 2.0 ) LObject_Delete ( Cell_Draw, Polygon );
	}
} 
