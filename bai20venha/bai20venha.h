
// bai20venha.h : main header file for the bai20venha application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cbai20venhaApp:
// See bai20venha.cpp for the implementation of this class
//

class Cbai20venhaApp : public CWinApp
{
public:
	Cbai20venhaApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cbai20venhaApp theApp;
