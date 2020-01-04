// mfcupi.h : main header file for the MFCUPI DLL
//

#if !defined(AFX_MFCUPI_H__933F76A5_54B5_11D3_AB23_0060081C82F7__INCLUDED_)
#define AFX_MFCUPI_H__933F76A5_54B5_11D3_AB23_0060081C82F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMfcupiApp
// See mfcupi.cpp for the implementation of this class
//

class CMfcupiApp : public CWinApp
{
public:
	CMfcupiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfcupiApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CMfcupiApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCUPI_H__933F76A5_54B5_11D3_AB23_0060081C82F7__INCLUDED_)
