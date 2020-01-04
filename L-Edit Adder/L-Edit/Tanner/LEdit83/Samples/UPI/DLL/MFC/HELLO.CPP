//File containing the MFC Dialog Class
#include "stdafx.h"
#include "mfcupi.h"
#include "TestDlg.h"

// UPI Header file
#include "ldata.h"

void  HelloWorldMacro (void)
{
	LDialog_MsgBox ( "This Function demonstrates the Use of MFC Dialogs in a UPI Function" );

  CTestDlg aDlg;

  aDlg.DoModal();
}

int  UPI_Entry_Point ( void ) {
	LMacro_Register ( "Hello, World!", "HelloWorldMacro" );

	return 1;
}
