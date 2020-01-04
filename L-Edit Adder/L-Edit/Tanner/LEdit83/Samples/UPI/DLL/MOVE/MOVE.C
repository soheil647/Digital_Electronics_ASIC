#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ldata.h"
#include "demo.h"

 float MyGetUnits( LFile ffile) {
	LGrid   ggrid;
	float   UNITS;
	char	unit_name[NAMESIZE];

	LFile_GetGrid( ffile, &ggrid );

      UNITS = 1.0 / ggrid.locator_scaling ;

	return (UNITS);
}

#define	DEFAULT_X "5"
#define	DEFAULT_Y "8"

void MoveMacro( void )
{
	/* set up variables  */
	LFile	File;
	LCell	Cell;
	char	STR[NAMESIZE];
	char	STR2[NAMESIZE];
	LTechnology		tech;
	char		units[PAGESIZE];
	float  UNITS;
	LRect	rect;


	/*  work variables  */
	LPoint  cursor_location, move_location, diff;
	float	 x, y;
	long delta_x, delta_y;
	LSelection	selected;

	LDialogItem  Menu_Items[2]= {
		{"X Distance:", ""},
		{"Y Distance:", ""},
	};

	/*  Display Warning Message  */
	sprintf (STR,"Be sure to select objects first.");
	LDialog_AlertBox(STR);

	/*  Form default values  */
	Cell = LCell_GetVisible(); 			// the current cell
	File = LCell_GetFile(Cell);			// the current file 
	rect = LCell_GetView( Cell);

	/* set up size and technology size  */
	UNITS = MyGetUnits( File );

	/*   assign default input values  */    
	strcpy(Menu_Items[0].value, DEFAULT_X );
	strcpy(Menu_Items[1].value, DEFAULT_Y );

	/* get input parameters */
	if ( LDialog_MultiLineInputBox( "Move By", Menu_Items, 2 ) ) {
		x = atof( Menu_Items[0].value);
		y = atof( Menu_Items[1].value);
		delta_x = (long)(x/UNITS);
		delta_y = (long)(y/UNITS);
	}
	else
		return;

	selected = LSelection_GetList();
	if(! selected ) 
	{
		sprintf( STR, "You must first select the items you wish to move.");
		LDialog_AlertBox( STR );
		return;
	}

	LSelection_Move( delta_x, delta_y);
	LDisplay_Refresh();
}/* End of function : MoveMacro */ 

int  UPI_Entry_Point ( void ) 
{
	LMacro_BindToHotKey(KEY_F5, "Move selected items", "MoveMacro");

	return 1;
}