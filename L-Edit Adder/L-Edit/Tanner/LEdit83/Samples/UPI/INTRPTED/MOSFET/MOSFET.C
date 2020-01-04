module mosfet_module {

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ldata.h"

#define Assigned(Ptr) ((Ptr)!=NULL)
#define NotAssigned(Ptr) ((Ptr)==NULL)

// Electronic Elements Function
LCoord GrowAmount;

//  MOSIS Design Rules Constraints
long Poly_Cnt_Spacing = 2;			// MOSIS DRC 6.4
long Poly_MinWidth = 8;				//  (not DRC --user's choice)
long Poly_MinLength = 2;			// MOSIS DRC 3.1
long Poly_extn_from_Act = 2;		// MOSIS DRC 3.3
long Cnt_Cnt_Spacing	= 2;			// MOSIS DRC 5.3, 6.3, 13.2
long Cnt_MinWidth = 2;				// MOSIS DRC 5.1, 6.1, 13.1, 16.1
long Act_overlap_Poly = 3;			// MOSIS DRC 3.4
long Act_overlap_Cnt = 1;			// MOSIS DRC 6.2.b
long Sel_overlap_Act = 2;			// MOSIS DRC 4.2
long Met1_overlap_ActCnt = 1;		// MOSIS DRC 7.4

LLayer Layer_ActiveContact;
LLayer Layer_Active;
LLayer Layer_Select;
LLayer Layer_Poly;
LLayer Layer_Metal1;
LGrid GridSettings;

//*************************************************************************
// Function Name    : Copy_BoxObj
// Parameters       : Cell - The cell in which the object exists. 
//                    Obj - The object whose MBB is copied.
//                    Layer - Layer to put the new object on.
//                    grow - grow amount.
// Description      : This routine makes a copy of an object's MBB.  The 
//								user may define the layer to make the copy on and 
//								may grow the object.  The growth value is in 
//								internal units and is added to the dimensions of 
//								the box (i.e. it will expand the box X units 
//								outward--it is not a % factor).
// Returns          : The new object created.
//*************************************************************************
//  Revision History
//   ??/??/19?? - ??? - Created function.
//*************************************************************************
LObject Copy_BoxObj(LCell Cell, LObject Obj, LLayer Layer, LCoord grow)
{	
	// Check if proper parameters were passed.
	if(NotAssigned(Cell) || NotAssigned(Obj) || NotAssigned(Layer))
	{
		assert(Assigned(Cell));
		assert(Assigned(Obj));
		assert(Assigned(Layer));
		return(NULL);
	}

	LRect	Box = LBox_GetRect(Obj);
	Box.x1	+= grow*2;
	Box.y1	+= grow*2;
	Obj		 = LBox_New(Cell, Layer, Box.x0, Box.y0, Box.x1, Box.y1);

	assert(Assigned(Obj));

	return(Obj);
} // End of Function:  Copy_BoxObj

//*************************************************************************
// Function Name    : Translate
// Parameters       : Cell - The cell in which the object exists. 
//                    Obj - The object to translate.
//                    x_amt - X amount of the translation.
//                    y_amt - Y amount of the translation.
// Description      : This routine simply translates an object to a new 
//							  location.  The displacement is given in internal 
//							  units for both X and Y.
// Returns          : Nothing.
//*************************************************************************
//  Revision History
//   ??/??/19?? - ??? - Created function.
//*************************************************************************
void Translate(LCell Cell, LObject Obj, LCoord x_amt, LCoord y_amt)
{
	// Check if proper parameters were passed.
	if(NotAssigned(Cell) || NotAssigned(Obj))
	{
		assert(Assigned(Cell));
		assert(Assigned(Obj));
		return;
	}

	LRect Moved_Box;
	LRect Box = LBox_GetRect(Obj);

	Moved_Box.x0 = Box.x0 + x_amt;
	Moved_Box.x1 = Box.x1 + x_amt;
	Moved_Box.y0 = Box.y0 + y_amt;
	Moved_Box.y1 = Box.y1 + y_amt;

	LStatus stat = LBox_Set(Cell, Obj, Moved_Box);
	assert(stat = LStatusOK);

} // End of Function:  Translate

//*************************************************************************
// Function Name    : Draw_Contact_SCAM1
// Parameters       : Cell - The cell in which to draw the object.
//                    X - X location of the contact.
//                    Y - Y location of the contact.
// Description      : This routine draws a simple contact from active to 
//								Metal1 (SCAM1).  It constructs the minimum possible
//								SCAM1 geometry allowed by the process technology.
//							 The routine employs a generic set of variables which
//								allow it to be used with more than one technology.
//								The user must simply assign technology specific
//								values to the appropriate variables.
//							 For this particular version, the variables have been
//								assigned as external variable declaration found at
//								the beginning of this module.  The are specific to
//								the MOSIS Technology.
//							 Contact X and Y location is passed to the routine
//								from the outside.
//							 A box Object of the contact's Metal1 box is returned.
//								This, because it will be useful to the user
//								employing this routine to build greater structures.
// Returns          : A box Object of the contact's Metal1 box is returned.
//*************************************************************************
//  Revision History
//   ??/??/19?? - ??? - Created function.
//*************************************************************************
LObject Draw_Contact_SCAM1(LCell Cell, LCoord X, LCoord Y)
{
	assert(Assigned(Cell));

	LObject Obj_Cnt, Obj_Act, Obj_Sel, Obj_Met1;

	// BEGIN
	// Make Active-Contact object for SCAM1 structure.
	Obj_Cnt = LBox_New(Cell, Layer_ActiveContact,  
								X - GridSettings.locator_scaling, 
								Y - GridSettings.locator_scaling, 
								X + GridSettings.locator_scaling, 
								Y + GridSettings.locator_scaling);
	assert(Assigned(Obj_Cnt));
	
	// Make Active object for SCAM1 structure.
	GrowAmount = Act_overlap_Cnt;
	Obj_Act = Copy_BoxObj(Cell, Obj_Cnt, Layer_Active, GrowAmount);
	Translate(Cell, Obj_Act, -GrowAmount, -GrowAmount);

	// Make NSelect object for SCAM1 structure.
	GrowAmount = Sel_overlap_Act;
	Obj_Sel = Copy_BoxObj(Cell, Obj_Act, Layer_Select, GrowAmount);
	Translate(Cell, Obj_Sel, -GrowAmount, -GrowAmount);

	// Make Metal1 object for SCAM1 structure.
	GrowAmount = Met1_overlap_ActCnt;
	Obj_Met1 = Copy_BoxObj(Cell, Obj_Cnt, Layer_Metal1, GrowAmount);
	Translate(Cell, Obj_Met1, -GrowAmount, -GrowAmount);

	return(Obj_Met1);
} // End of Function:  Draw_Contact_SCAM1

//*************************************************************************
// Function Name    : Mosfet_Draw
// Parameters       : Cell_Draw
//                    Point_Center
//                    long Channel_Width
//                    long Channel_Length
// Description      : This routine draws an NPN MOSFET.  It constructs the
//								minimum possible MOSFET geometry allowed by the 
//								process technology.  A generic set of variables is
//								employed which allow this function to be employed
//								for more than one technology.  Values assigned to 
//								the variables are made in external variable 
//								declaration statements found above and are specific
//								to only one process Technology.
//							 The values assigned presently are for the MOSIS 
//								technology.  Channel width and length are 
//								determined interactively.
//							 This could be modified later to optionally draw a 
//								PNP MOSFET, to rotate the structure, and/or to work 
//								with include files which contains values for all
//								technology DRC information for a particular process.
// Returns          : Nothing
//*************************************************************************
//  Revision History
//   ??/??/19?? - ??? - Created function.
//*************************************************************************
void Mosfet_Draw(LCell Cell_Draw, LPoint Point_Center, 
					  unsigned long Channel_Width, unsigned long Channel_Length)
{
	LCoord  X, Y, CntY;
	LCoord  Poly_Width, Poly_Length;
	LCoord  Start, Stop;
	LObject Obj_Poly,  Obj_Act,  Obj_Sel;
	int     i;
	LCoord  Offset;

	// Transistor Construction.
	X = Point_Center.x;
	Y = Point_Center.y;

	// MOSFET construction variables.
	//  Set Poly dimensions which includes the poly-extension-from-gate distance.
	Poly_Width = Channel_Length;
	Poly_Length = Channel_Width + 2 * Poly_extn_from_Act;

	// Center-to-center placement spacing between Channel and Src/Drn Contacts
	//  in X direction.
	LCoord Cnt_XPlcmt = Poly_Cnt_Spacing + ((Poly_Width + Cnt_MinWidth) / 2);

	// Center-to-center placement spacing between adjacent Src/Drn Contact
	//  in Y direction.
	LCoord Cnt_YPlcmt = Cnt_Cnt_Spacing + Cnt_MinWidth;

	// Distance inside Active mask to place the Src/Drn Contacts.
	LCoord Cnt_inside_Plcmt = Act_overlap_Cnt + (Cnt_MinWidth / 2);

	// Make Poly mask for Gate structure.
	Obj_Poly = LBox_New(Cell_Draw, Layer_Poly, X , Y, 
							  X + Poly_Width, Y + Poly_Length);

	// Move lower-left corner of Channel to PointCenter.
	Translate(Cell_Draw, Obj_Poly, 0, -Poly_extn_from_Act);

	// Make Active mask for Gate structure.
	Obj_Act = LBox_New(Cell_Draw, Layer_Active, X - Act_overlap_Poly, Y, 
							 X + Channel_Length + Act_overlap_Poly, Y + Channel_Width);
	assert(Assigned(Obj_Act));

	// Make N-Select mask for Gate structure.
	GrowAmount = Sel_overlap_Act;
	Obj_Sel = Copy_BoxObj(Cell_Draw, Obj_Act, Layer_Select, GrowAmount);
	Translate(Cell_Draw, Obj_Sel, -GrowAmount, -GrowAmount);

	// Build Source/Gate structures.
	//  Set starting point at bottom-center edge of Channel.
	X = X + (Channel_Length / 2);
	Y = Y;

	Start  = Y + Cnt_inside_Plcmt;
	Stop   = Y + Channel_Width - Cnt_inside_Plcmt;
	Offset = (Stop-Start) % Cnt_YPlcmt;

	for(i = 0; (CntY = Start + i * Cnt_YPlcmt) <= Stop; i++)
	{
		Draw_Contact_SCAM1(Cell_Draw, X + Cnt_XPlcmt, CntY + Offset);
		Draw_Contact_SCAM1(Cell_Draw, X - Cnt_XPlcmt, CntY);
	}

} // End of Function:  Mosfet_Draw


//*************************************************************************
// Function Name    : MosfetMacro
// Parameters       : None.
// Description      : This macro establishes the dialogue box and accepts 
//								the user input.  The actual drawing is done by the
//								function "Mosfet_Draw" which is executed at the end
//								of this macro.
// Returns          : Nothing.
//*************************************************************************
//  Revision History
//   ??/??/19?? - ??? - Created function.
//*************************************************************************
void MosfetMacro(void)
{
	static char szActiveContactLayer[256] = "Active Contact";
	static char szActiveLayer[256] = "Active";
	static char szSelectLayer[256] = "N Select";
	static char szPolyLayer[256] = "Poly";
	static char szMetal1Layer[256] = "Metal1";
	static unsigned long Channel_Width = 20;
	static unsigned long Channel_Length = 2;

	LCell Cell_Draw = LCell_GetVisible();
	if(NotAssigned(Cell_Draw))
	{
		LDialog_MsgBox("Error:  Couldn't find the visible cell.");
	}

	LDialogItem   Dialog_Items[7];
	LPoint        Point_Center = LCursor_GetPosition();

	strcpy(Dialog_Items[0].prompt, "Channel Width:");
	strcpy(Dialog_Items[1].prompt, "Channel Length:");
	strcpy(Dialog_Items[2].prompt, "Active Contact Layer:");
	strcpy(Dialog_Items[3].prompt, "Active Layer:");
	strcpy(Dialog_Items[4].prompt, "Select Layer:");
	strcpy(Dialog_Items[5].prompt, "Polysilicon Layer:");
	strcpy(Dialog_Items[6].prompt, "Metal1 Layer:");

	sprintf(Dialog_Items[0].value, "%lu", Channel_Width);
	sprintf(Dialog_Items[1].value, "%lu", Channel_Length);
	strcpy(Dialog_Items[2].value, szActiveContactLayer);
	strcpy(Dialog_Items[3].value, szActiveLayer);
	strcpy(Dialog_Items[4].value, szSelectLayer);
	strcpy(Dialog_Items[5].value, szPolyLayer);
	strcpy(Dialog_Items[6].value, szMetal1Layer);
	
	if(!LDialog_MultiLineInputBox("MOSFET Parameters", Dialog_Items, 7))
	{
		return;
	}

	LFile File = LCell_GetFile(Cell_Draw);
	assert(Assigned(File));
	
	if(LFile_GetGrid(File, &GridSettings) == NULL)
	{
		LDialog_MsgBox("Failed to get the Grid Settings.");
		return;
	}

	strcpy(szActiveContactLayer, Dialog_Items[2].value);
	strcpy(szActiveLayer, Dialog_Items[3].value);
	strcpy(szSelectLayer, Dialog_Items[4].value);
	strcpy(szPolyLayer, Dialog_Items[5].value);
	strcpy(szMetal1Layer, Dialog_Items[6].value);

	Layer_ActiveContact = LLayer_Find(File, szActiveContactLayer);
	if(NotAssigned(Layer_ActiveContact))
	{
		char szMsg[512];
		sprintf(szMsg, "Error:  Couldn't find the Active Contact Layer in the TDB File.\nLayer:  \"%s\"\nPlease check the spelling and make sure the layer exists!",
				  szActiveContactLayer);
		LDialog_MsgBox(szMsg);
		return;
	}
	
	Layer_Active = LLayer_Find(File, szActiveLayer);
	if(NotAssigned(Layer_Active))
	{
		char szMsg[512];
		sprintf(szMsg, "Error:  Couldn't find the Active Layer in the TDB File.\nLayer:  \"%s\"\nPlease check the spelling and make sure the layer exists!",
				  szActiveLayer);
		LDialog_MsgBox(szMsg);
		return;
	}

	Layer_Select = LLayer_Find(File, szSelectLayer);
	if(NotAssigned(Layer_Select))
	{
		char szMsg[512];
		sprintf(szMsg, "Error:  Couldn't find the Select Layer in the TDB File.\nLayer:  \"%s\"\nPlease check the spelling and make sure the layer exists!",
				  szSelectLayer);
		LDialog_MsgBox(szMsg);
		return;
	}

	Layer_Poly = LLayer_Find(File, szPolyLayer);
	if(NotAssigned(Layer_Poly))
	{
		char szMsg[512];
		sprintf(szMsg, "Error:  Couldn't find the Polysilicon Layer in the TDB File.\nLayer:  \"%s\"\nPlease check the spelling and make sure the layer exists!",
				  szPolyLayer);
		LDialog_MsgBox(szMsg);
		return;
	}

	Layer_Metal1 = LLayer_Find(File, szMetal1Layer);
	if(NotAssigned(Layer_Metal1))
	{
		char szMsg[512];
		sprintf(szMsg, "Error:  Couldn't find the Metal1 Layer in the TDB File.\nLayer:  \"%s\"\nPlease check the spelling and make sure the layer exists!",
				  szMetal1Layer);
		LDialog_MsgBox(szMsg);
		return;
	}

	Channel_Width = strtoul(Dialog_Items[0].value, NULL, 10);
	Channel_Length = strtoul(Dialog_Items[1].value, NULL, 10);

	Poly_Cnt_Spacing = 2 * GridSettings.locator_scaling;
	Poly_MinWidth = 8 * GridSettings.locator_scaling;
	Poly_MinLength = 2 * GridSettings.locator_scaling;
	Poly_extn_from_Act = 2 * GridSettings.locator_scaling;
	Cnt_Cnt_Spacing = 2 * GridSettings.locator_scaling;
	Cnt_MinWidth = 2 * GridSettings.locator_scaling;
	Act_overlap_Poly = 3 * GridSettings.locator_scaling;
	Act_overlap_Cnt = 1 * GridSettings.locator_scaling;
	Sel_overlap_Act = 2 * GridSettings.locator_scaling;
	Met1_overlap_ActCnt = 1 * GridSettings.locator_scaling;
	
	Mosfet_Draw(Cell_Draw, Point_Center, Channel_Width * GridSettings.locator_scaling, 
													 Channel_Length* GridSettings.locator_scaling);
	LCell_MakeVisible(Cell_Draw);

} // End of Function:  MosfetMacro


int mosfet_macro_register()
{
	LMacro_BindToHotKey(KEY_F2, "Transistor, N-channel", "MosfetMacro");
	return 1;
} // End of Function:  UPI_Entry_Point

}  /* End of Module hierarchy */

mosfet_macro_register();