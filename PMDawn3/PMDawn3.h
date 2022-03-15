
// PMDawn3.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPMDawn3App:
// See PMDawn3.cpp for the implementation of this class
//

class CPMDawn3App : public CWinApp
{
public:
	CPMDawn3App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPMDawn3App theApp;
