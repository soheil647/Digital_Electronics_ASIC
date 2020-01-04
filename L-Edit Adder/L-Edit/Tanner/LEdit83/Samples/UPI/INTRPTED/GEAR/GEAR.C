module gear {
	
#include "ldata.h"
#include <stdlib.h>
#include <math.h>

void  GearMacro ( void )
{
  LPoint       Polygon [ 100 ];
  float        Angle2, Angle3, R2, R3, Tooth_Angle;
  LCoord       R_Inner, R_Outer, Teeth_Count, Teeth_Width, Tooth;
  LCell        Cell_Draw   = LCell_GetVisible ( );
  LFile        File_Draw   = LCell_GetFile ( Cell_Draw );
  LPoint       Translation = LCursor_GetPosition ( );
  LDialogItem  Dialog_Items [ 3 ] = { { "Inner Radius", "175" },
                                      { "Outer Radius", "200" },
                                      { "Teeth Count ", "15 " } };

/********************************************************************/

  if(LLayer_Find(File_Draw, "Metal1") == NULL)
  {
	LDialog_AlertBox("There is no Metal1 layer.\nMake sure Metal1 is in the layer map!");
	return;
  }

  do { 
    if ( !LDialog_MultiLineInputBox ( "Gear Properties", Dialog_Items, 3 ))
		 return;
    R_Inner     = atol ( Dialog_Items [ 0 ].value );
    R_Outer     = atol ( Dialog_Items [ 1 ].value );
    Teeth_Count = atol ( Dialog_Items [ 2 ].value );
    Teeth_Width = 6.283185307 * R_Inner / ( 2 * Teeth_Count );
  } while ( ( Teeth_Count < 3 ) || ( Teeth_Count >  25      )
         || ( Teeth_Width < 2 ) || ( R_Inner     >= R_Outer )
         || ( R_Inner     < 2 ) );
  for ( Tooth = 0; Tooth < Teeth_Count; Tooth++ ) {
    Tooth_Angle = 6.283185307 * Tooth / Teeth_Count;
    R2 = sqrt ( R_Outer * R_Outer + Teeth_Width * Teeth_Width / 4.0 );
    R3 = sqrt ( R_Inner * R_Inner + Teeth_Width * Teeth_Width / 4.0 );
    Angle2 = atan2 ( Teeth_Width / 2.0, R_Outer );
    Angle3 = atan2 ( Teeth_Width / 2.0, R_Inner );
    Polygon [ 4 * Tooth + 0 ] = LPoint_Set (
      R3 * sin ( Tooth_Angle - Angle3 ) + Translation.x,
      R3 * cos ( Tooth_Angle - Angle3 ) + Translation.y );
    Polygon [ 4 * Tooth + 1 ] = LPoint_Set (
      R2 * sin ( Tooth_Angle - Angle2 ) + Translation.x,
      R2 * cos ( Tooth_Angle - Angle2 ) + Translation.y );
    Polygon [ 4 * Tooth + 2 ] = LPoint_Set (
      R2 * sin ( Tooth_Angle + Angle2 ) + Translation.x,
      R2 * cos ( Tooth_Angle + Angle2 ) + Translation.y );
    Polygon [ 4 * Tooth + 3 ] = LPoint_Set (
      R3 * sin ( Tooth_Angle + Angle3 ) + Translation.x,
      R3 * cos ( Tooth_Angle + Angle3 ) + Translation.y );
  } 
  LPolygon_New ( Cell_Draw, LLayer_Find ( File_Draw, "Metal1" ),
    Polygon, 4 * Teeth_Count );
  LCell_MakeVisible ( Cell_Draw );
  LCell_HomeView(Cell_Draw);
}

void  gear_macro_register ( void )
{
   LMacro_BindToHotKey ( KEY_F10, "Gear", "GearMacro" );
}

}
gear_macro_register();
