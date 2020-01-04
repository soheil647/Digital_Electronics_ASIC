module chg_layer_module {

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ldata.h"
#include "demo.h"


void ChnglayerMacro ( void )  {
/* set up variables  */
	LFile	File;
	LCell	Cell;
	char	STR[NAMESIZE];

	/*  work variables  */
	LSelection	selected;
	LLayer	srclayer , layer;
	char 		layername[NAMESIZE];

	char Prompt[NAMESIZE];
	char Input_Item[FIELDSIZE];

/*****************************/
/*  Display Warning Message  */
/*****************************/
   sprintf (STR,"Be sure to select objects first.");
	LDialog_AlertBox(STR);

/**************************/
/*  Form default values  */
/**************************/
	Cell = LCell_GetVisible(); 			// the current cell
	File = LCell_GetFile(Cell);			// the current file 

/*   assign default input values  */    
	layer = LLayer_GetList( File );
	strcpy(layername, LLayer_GetName(layer, layername, NAMESIZE ) );

	strcpy(Prompt, "Target layer for selected items:") ;
	sprintf(Input_Item, "%s", layername) ;

	while ( 1 ) {
		if ( LDialog_InputBox( "Target Layer", Prompt, Input_Item ) ) 
      	layer= LLayer_Find( File, Input_Item ) ;
		else
			return;
     
		selected = LSelection_GetList();
		if(! selected ) 
		{
			sprintf( STR, "You must first select the items you wish to move.");
			LDialog_AlertBox( STR );
			return;
		}
      if(! layer ) 
	   {
		   sprintf( STR, "The layer you entered does not exist in this file.");
		   LDialog_AlertBox( STR );
		   continue;
		}
		break; /* Come out of the while loop */
	}/* end of while loop*/
	
	for( ; selected != 0l; selected = LSelection_GetNext( selected) ) 
	{
		srclayer =	LSelection_GetLayer( selected );
		LSelection_ChangeLayer( srclayer, layer );
	}

	LDisplay_Refresh;
}	/* End of function : move */ 


void  chnglayr_macro_register ( void ) 
{
	LMacro_BindToHotKey(KEY_L, "Change Layer",
							  "ChnglayerMacro");
}

}  /* End of Module hierarchy */
chnglayr_macro_register ( );
