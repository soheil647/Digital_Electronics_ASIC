module goto_module {

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ldata.h"
#include "demo.h"
	
LPoint GetCenter(LRect rect, LPoint CellCenter)
{
	LPoint center;

	/* Find the center of the port */
	center.x = ((rect.x0 + rect.x1) / 2);
	center.y = ((rect.y0 + rect.y1) / 2);
	center.x -= CellCenter.x;
	center.y -= CellCenter.y;
	return (center);
}


LPoint GetCellCenter(LCell cell)
{
	LRect outline;
	LPoint center;

	outline = LCell_GetMbb ( cell );
	center.x = ( outline.x0 + outline.x1 ) / 2;
	center.y = ( outline.y0 + outline.y1 ) / 2;
	return (center);
}


LRect  Translate_Rect( LRect rect, LCoord x_amt, LCoord y_amt)   
{
	LRect	Moved_Rect;

	Moved_Rect.x0 = rect.x0 + x_amt;
	Moved_Rect.x1 = rect.x1 + x_amt;
	Moved_Rect.y0 = rect.y0 + y_amt;
	Moved_Rect.y1 = rect.y1 + y_amt;

	return( Moved_Rect );
	}



LPoint LPoint_Subtract(LPoint Point1, LPoint Point2)
{

	LPoint Temp;

	Temp.x = Point1.x - Point2.x;
	Temp.y = Point1.y - Point2.y;

	return Temp;
}

double GetUnits( LFile ffile)
{
	LGrid   ggrid;
	double   UNITS;
	char	unit_name[NAMESIZE];

	LFile_GetGrid( ffile, &ggrid );
	UNITS = 1.0 / ggrid.locator_scaling ;
	return (UNITS);
}


void GotoMacro( void )
{
/* set up variables  */
	LFile	draw_file;
	LCell	draw_cell;
   LGrid   ggrid;
	LTechnology		tech;
	char	unit_name[NAMESIZE];
	double   UNITS;
	LPoint	not_relative = {0,0};

 	/*  work variables  */
    LPoint  view_center, cursor_location;
	LRect	rect, view_rect;
	LPoint	goto_location, diff;

/**************************/
/*  Form default values  */
/**************************/
	draw_cell = LCell_GetVisible(); 			// the current cell
	draw_file = LCell_GetFile(draw_cell);			// the current file 

/* set up size and technology size  */
	UNITS = GetUnits( draw_file ) ;

/* set up current view vars  */
	view_rect = LCell_GetView( draw_cell );
	view_center = GetCenter( view_rect, not_relative );
   cursor_location = LCursor_GetPosition();

/* assign default input values  */    
	LDialogItem  Menu_Items[2]= {
		{"X coordinate to goto	(locator units):", "" },
      {"Y coordinate          (locator units):", ""},
	};    
	
	sprintf(Menu_Items[0].value,"%9.2f", (float) (cursor_location.x * UNITS) ) ;
   sprintf(Menu_Items[1].value,"%9.2f", (float) (cursor_location.y * UNITS) );

  	if ( LDialog_MultiLineInputBox( "GoTo Parameters", Menu_Items, 2 ) ) {
		goto_location.x = (long)(atof( Menu_Items[0].value)/UNITS);
      goto_location.y = (long)(atof( Menu_Items[1].value)/UNITS);
	}
	else return;

	diff = LPoint_Subtract( goto_location, view_center );
	rect  = Translate_Rect( view_rect, diff.x, diff.y);  

   LCell_SetView( draw_cell , rect);
}	/* End of function : GotoMacro */ 

void  goto_macro_register ( void ) 
{
	LMacro_BindToHotKey(KEY_G, "Go to view location", "GotoMacro");
}

}  /* End of Module hierarchy */

goto_macro_register ( );
