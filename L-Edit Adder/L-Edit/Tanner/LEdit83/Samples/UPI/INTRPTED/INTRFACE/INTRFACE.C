module interface_module {

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "ldata.h"
#include "demo.h"

void InterfaceMacro( void )
{
	LFile	File;
	LCell	Cell;
	char	STR[PAGESIZE];
	int i;

	/*  input and design variables  */
	char		InputPrompt[LINESIZE];
	char		InputValue[FIELDSIZE];
	char		*pick_list[]={"red", "orange", "white", "yellow", "blue"};

	/*  input box struct  */
	LDialogItem  MultiLineMenuItems[6]= {
		{"The first prompt:", ""},
		{"The second prompt:", ""},
		{"Input prompt lines must not exceed 39--", ""},
		{"  --characters!", ""},
		{"Input fields, not more than 20", ""},
		{"You can assign default values also ->", "default"},
	};


	/*****************************/
	/*  Display Message  */
	/*****************************/
	sprintf (STR,"A message box simply displays a message to the\n");
	strcat(STR,"user.  Nothing fancy about that...");
	LDialog_MsgBox(STR);

	/*****************************/
	/*  Display Warning Message  */
	/*****************************/
	sprintf (STR,"An alert box displays a message and sounds\n");
	strcat (STR, "a tone to alert the user:\n     Good for waking up tired users.\n");
	LDialog_AlertBox(STR);

	/*****************************/
	/*  Input Box  */
	/*****************************/
	sprintf (STR,"An input box allows the program to prompt the ");
	strcat (STR, "user for input values.\nInput is stored to a string ");
	strcat (STR, "and converted, if necessary, to another data type \n");
	strcat (STR, "by the program.  ");
	strcat (STR, "Input line prompts may not exceed 39 chars.");
	LDialog_MsgBox(STR);

	strcpy(InputValue, "");
	sprintf (InputPrompt,"Input your name here:");
	if ( !LDialog_InputBox("LDialog_InputBox", InputPrompt, InputValue))
		return;

	sprintf (STR, "See!  I can understand what you type, %s.", InputValue);
	LDialog_MsgBox( STR );


	/*****************************/
	/*  Display Yes/No Message  */
	/*****************************/

	while (1) {
		sprintf (STR,"The yes/no box waits for the user to selects ");
		strcat( STR, "a yes button \nor a no button.\n");
		strcat (STR, "Do you wish to continue with the demo?\n\n");
		strcat (STR, "(See the blue question mark to the left there.  Cool, huh?)");

		if( LDialog_YesNoBox(STR) ) {
			sprintf (STR,"Great, let's go...\n");
			LDialog_MsgBox( STR );
		}
		else 
		{
			sprintf (STR,"Oh come on.\n   Just stick it out a little bit longer.\n");
			strcat( STR, "      Let's try again...\n");
			LDialog_MsgBox( STR );
			continue;
		}
		break;
	}

	/*****************************/
	/*  Multi-line Input Box  */
	/*****************************/
	while (1){
		strcpy(MultiLineMenuItems[1].value, "");
		if( LDialog_MultiLineInputBox( "LDialog_MultiLineInputBox",
												 MultiLineMenuItems,6) ) ;
		else {
			sprintf (STR,"Hitting cancel is normally wired to exit the program.");
			strcat( STR, " --but here, we'll simply move on to the next item.");
			LDialog_MsgBox( STR );
			break;
		}

		if(! strcmp(MultiLineMenuItems[1].value, "") ) {
			sprintf (STR,"Very good, but try ");
			strcat( STR, "entering your name at the second prompt.");
			LDialog_MsgBox( STR );
			continue;
		}

		if( strcmp(MultiLineMenuItems[1].value, InputValue) ) {
			sprintf (STR,"Hey, thats not the name you entered before.\n");
			strcat( STR, "Try it again --at the SECOND prompt!\n");
			LDialog_MsgBox( STR );
			continue;
		}
		break;
	}/* end of while loop */

	/*****************************/
	/*  The Pick List box      */
	/*****************************/

	sprintf (InputPrompt,"Choose a color that pleases you:");
	i = LDialog_PickList(InputPrompt, pick_list, 5, 1);
	if (i == -1)
		return;

	sprintf (STR,"Yes, %s is a very pretty color. ", pick_list[i]);
	LDialog_MsgBox( STR );

	sprintf (STR,"Well, that's all I have to talk about.\n");
	strcat( STR, "Have fun playing with L-Edit's new UPI features.\n");
	strcat( STR, "Just give Tanner a call if you run into trouble.");
	LDialog_MsgBox( STR );
}	/* End of function : InterfaceMacro */ 

void  interface_macro_register ( void ) 
{
	LMacro_BindToHotKey ( KEY_F4, "Interface Demo", "InterfaceMacro" );
}

}  /* End of Module hierarchy */

interface_macro_register ( );
