     module Contact_module {

#include "ldata.h"

     void  Contact_Active_Metal1 ( ) {
     /********************************************************************/
    LCoord  X, Y;
	LCell   Cell_Now     = LCell_GetVisible ( );
	LFile   File_Now     = LCell_GetFile ( Cell_Now );
	LGrid	Grid_Now;
	
	LLayer  Layer_Active = LLayer_Find ( File_Now, "Active" );
	if(!Layer_Active)
	{
		LDialog_AlertBox("There is no Active layer.\nMake sure Active is in the layer map!");
		return;
	}

	LLayer  Layer_Metal1 = LLayer_Find ( File_Now, "Metal1" );
	if(!Layer_Metal1)
	{
		LDialog_AlertBox("There is no Metal1 layer.\nMake sure Metal1 is in the layer map!");
		return;
	}

	LLayer  Layer_ActCnt = LLayer_Find ( File_Now, "Active Contact" );
	if(!Layer_ActCnt)
	{
		LDialog_AlertBox("There is no Active Contact layer.\nMake sure Active Contact is in the layer map!");
		return;
	}

	LLayer  Layer_N_Sel  = LLayer_Find ( File_Now, "N Select" );
	if(!Layer_N_Sel)
	{
		LDialog_AlertBox("There is no N Select layer.\nMake sure N Select is in the layer map!");
		return;
	}

	
	LPoint  Point_Cursor = LCursor_GetPosition ( );
       

	X = Point_Cursor.x;
	Y = Point_Cursor.y;

	LFile_GetGrid(File_Now, &Grid_Now);
	long locator_scale = Grid_Now.locator_scaling;

	LBox_New ( Cell_Now, Layer_ActCnt, -1 * locator_scale + X, -1 * locator_scale + Y,  1 * locator_scale + X,  1 * locator_scale + Y );
	LBox_New ( Cell_Now, Layer_Metal1, -2 * locator_scale + X, -2 * locator_scale + Y,  2 * locator_scale + X,  2 * locator_scale + Y );
	LBox_New ( Cell_Now, Layer_Active, -3 * locator_scale + X, -3 * locator_scale + Y,  3 * locator_scale + X,  3 * locator_scale + Y );
	LBox_New ( Cell_Now, Layer_N_Sel , -5 * locator_scale + X, -5 * locator_scale + Y,  5 * locator_scale + X,  5 * locator_scale + Y );
     }

     void  cnt_main ( void ) {
     /********************************************************************/
       LMacro_BindToHotKey ( KEY_F1,
         "Contact, Active-Metal1", "Contact_Active_Metal1" );
     }

     /********************************************************************/
     /********************************************************************/
     }
     cnt_main ( );
