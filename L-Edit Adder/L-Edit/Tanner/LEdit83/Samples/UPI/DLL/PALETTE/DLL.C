#define STRICT
#include <windows.h> 
#include <windowsx.h> 
#include <commctrl.h>
#include "windowsy.h" 
#include "resource.h"


/* Used in Init Dialog to create tool tip */
HINSTANCE l_hInst = NULL;

/* Used in Init Dialog for loading bitmap resources */
HINSTANCE l_hLib = NULL;

/* Used for checking if the layout palette is already displayed */
static int loaded = 0;

/* Used for checking if the Dialog Window has been closed or not */
HWND  l_hDlg;



/* Prototype of all the Call back functions associated with layout palette push buttons */
extern void  GearMacro ( void );
extern void  MosfetMacro ( void );
extern void  PolarArrayMacro ( void );
extern void  SpiralMacro ( void );
extern void  SpringMacro ( void );


/* Layout Palette - Dialog processing functions */
void  DlgOnCommand  ( HWND  hDlg , int  iID , HWND  hwndCtl , UINT  uCodeNotify ) ;
BOOL  OnInitDialog  ( HWND  hDlg , HWND  hwndFocus , long  lInitParam ) ;
void  OnDestroy  ( HWND  hDlg ) ;
void  OnClose  ( HWND  hDlg ) ;


BOOL CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam ) 
{
    switch (message)
    {
        HANDLE_DLG_MSG( hDlg , WM_COMMAND , DlgOnCommand ) ; 
        HANDLE_DLG_MSG( hDlg , WM_INITDIALOG , OnInitDialog ) ;
		//HANDLE_DLG_MSG( hDlg , WM_DESTROY , OnDestroy ) ; 
		//HANDLE_DLG_MSG( hDlg , WM_CLOSE , OnClose ) ; 

    }
    return FALSE ;
}


void  DlgOnCommand  ( HWND  hDlg , int  iID , HWND  hwndCtl , UINT  uCodeNotify )
{
  switch( iID ) 
  { 
    //case IDCANCEL:
     // EndDialog(hDlg , 0)  ;
    //break ;
	case IDC_CLOSE:
		DestroyWindow(hDlg);
		l_hDlg = NULL;
		loaded = 0;
		//PostMessage(hDlg, WM_DESTROY, 0, 0);
     // EndDialog(hDlg , 0)  ;
    break ;
	/*case IDC_BUTTON_3:
		GearMacro();
		break;*/
	case IDC_BUTTON_5:
		MosfetMacro();
		break;
	case IDC_BUTTON_6:
		PolarArrayMacro();
		break;
	case IDC_BUTTON_7:
		SpiralMacro();
		break;
	case IDC_BUTTON_8:
		SpringMacro();
		break;
 
  } 
}
 

/* Fill this array for the Tool Tip text associated with layout palette push buttons */
const char *text[] = {
    /*"Gear",  */
    "Mosfet",
    "Polar Array",
	"Spiral",
     "Spring"
};

void set_tool_tip_text(HWND hToolTip, HWND hDlg, int control_id, int str_index)
{
	TOOLINFO info;

	info.cbSize = sizeof(info);
	info.uFlags = TTF_IDISHWND | TTF_CENTERTIP | TTF_SUBCLASS;
	info.hwnd = hDlg;
	info.uId = (UINT)GetDlgItem(hDlg, control_id);
	info.lpszText = (char *)text[str_index];
	SendMessage(hToolTip, TTM_ADDTOOL, 0, 
					(LPARAM)&info);
}



/* Layout Palette Dialog Box - Initialization */
BOOL  OnInitDialog  ( HWND  hDlg , HWND  hwndFocus , long  lInitParam )
{

	HBITMAP hBmp;
	TOOLINFO info;
	HWND hToolTip; 

	/* Load bit maps for all the push buttons */

	/*hBmp = LoadBitmap(l_hLib, MAKEINTRESOURCE(IDB_BITMAP3));
	SendDlgItemMessage(hDlg, IDC_BUTTON_3, BM_SETIMAGE, 0, (LPARAM)hBmp);
	FreeResource(hBmp);*/


	hBmp = LoadBitmap(l_hLib, MAKEINTRESOURCE(IDB_BITMAP5));
	SendDlgItemMessage(hDlg, IDC_BUTTON_5, BM_SETIMAGE, 0, (LPARAM)hBmp);
	FreeResource(hBmp);


	hBmp = LoadBitmap(l_hLib, MAKEINTRESOURCE(IDB_BITMAP6));
	SendDlgItemMessage(hDlg, IDC_BUTTON_6, BM_SETIMAGE, 0, (LPARAM)hBmp);
	FreeResource(hBmp);


	hBmp = LoadBitmap(l_hLib, MAKEINTRESOURCE(IDB_BITMAP7));
	SendDlgItemMessage(hDlg, IDC_BUTTON_7, BM_SETIMAGE, 0, (LPARAM)hBmp);
	FreeResource(hBmp);


	hBmp = LoadBitmap(l_hLib, MAKEINTRESOURCE(IDB_BITMAP8));
	SendDlgItemMessage(hDlg, IDC_BUTTON_8, BM_SETIMAGE, 0, (LPARAM)hBmp);
	FreeResource(hBmp);





	/* Create a Tool Tip window */
	hToolTip = CreateWindowEx(
		WS_EX_TOPMOST,
		TOOLTIPS_CLASS,
		"No Name",
		TTS_ALWAYSTIP,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL,
		NULL, 
		l_hInst,
		NULL
	);

	// Make Tool Tips for push buttons
	info.cbSize = sizeof(info);
	info.uFlags = TTF_IDISHWND | TTF_CENTERTIP | TTF_SUBCLASS;
	info.hwnd = hDlg;
	info.uId = (UINT)GetDlgItem(hDlg, IDC_BUTTON_B);
	info.lpszText = (char *)text[0];
	SendMessage(hToolTip, TTM_ADDTOOL, 0, 
					(LPARAM)&info);

	/*set_tool_tip_text(hToolTip, hDlg, IDC_BUTTON_3, 1);*/
	set_tool_tip_text(hToolTip, hDlg, IDC_BUTTON_5, 0);
	set_tool_tip_text(hToolTip, hDlg, IDC_BUTTON_6, 1);
	set_tool_tip_text(hToolTip, hDlg, IDC_BUTTON_7, 2);
	set_tool_tip_text(hToolTip, hDlg, IDC_BUTTON_8, 3);
	
    return TRUE ;
}
 

void  OnDestroy  ( HWND  hDlg )
{
	DWORD error;

	if ( hDlg )
  		DestroyWindow( hDlg );
	l_hDlg = NULL;
}
 
void  OnClose  ( HWND  hDlg )
{
	DWORD error;

  	DestroyWindow( hDlg );
	l_hDlg = NULL;
}

/* This function is the one which displays the modeless layout palette dialog box */
void MainFunction(HINSTANCE hInst, HWND hWnd,
										  HINSTANCE hLib)
{
	static HRSRC hResLoad = NULL;
	static DLGTEMPLATE *hTmpl = NULL;
	HWND hDlg = NULL;

	/*if (hDlg != NULL) {
		ShowWindow(hDlg, SW_SHOW);
		return;
	}*/

	/* Initialize file wide global variables */
	l_hLib = hLib;
	InitCommonControls();
	l_hInst = hInst;


	/* Check if the resources have already been loaded */
	if (!loaded) {
		HRSRC hRes;

		hRes = FindResource(hLib, "PaletteDialogBox", RT_DIALOG);
		hResLoad = (HRSRC )LoadResource(hLib, hRes);
		hTmpl = (DLGTEMPLATE *)LockResource(hResLoad);
		//hDlg = CreateDialogIndirect(hInst, hTmpl, hWnd, DlgProc);
		hDlg = CreateDialogIndirect(NULL, hTmpl, NULL, DlgProc);

		if (hDlg == NULL){
			DWORD error = GetLastError();
		}
		l_hDlg = hDlg;
		UnlockResource(hResLoad);
		FreeResource(hRes);
	}
	loaded = 1;

	//DWORD error = GetLastError();
	
	hDlg = l_hDlg;
	ShowWindow(hDlg, SW_NORMAL);

}


BOOL WINAPI DllMain( HANDLE hDLL, DWORD dwReason, LPVOID lpReserved )
{
	switch( dwReason ) {
	case DLL_PROCESS_ATTACH:
		//MessageBox(NULL, "DLL_PROCESS_ATTACH","structur.dll", MB_OK | MB_ICONEXCLAMATION);
		break;

	case DLL_PROCESS_DETACH:
		if ( l_hDlg != NULL ) {
			DestroyWindow(l_hDlg);
			l_hDlg = NULL;
			loaded = 0;
		}
		break;
	}
	return TRUE;

}