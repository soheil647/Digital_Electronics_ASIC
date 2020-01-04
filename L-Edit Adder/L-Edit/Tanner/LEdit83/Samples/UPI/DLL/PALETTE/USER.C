#define STRICT
#include "windows.h"

#include "ldata.h"


/********************************************************************/
extern void	LWindow_GetParameters(void **hInst, void **hWnd, void **hLib);
void MainFunction(HINSTANCE hInst, HWND hWnd, HINSTANCE hLib);

/********************************************************************/
HINSTANCE hAppInst=NULL;
HWND hParentWnd=NULL;
HINSTANCE hUserDll=NULL;


/********************************************************************/    
void  LayoutPalette ( void ) 
{
	MainFunction(hAppInst, hParentWnd, hUserDll);
}


/********************************************************************/    
int  UPI_Entry_Point ( void ) 
{
	LWindow_GetParameters( (void**)&hAppInst, (void**)&hParentWnd, (void**)&hUserDll);
       
     LMacro_Register ( "Layout Palette", "LayoutPalette" );
	return 1;

}
	 
