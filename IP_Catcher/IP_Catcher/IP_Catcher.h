
// IP_Catcher.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CIP_CatcherApp:
// �йش����ʵ�֣������ IP_Catcher.cpp
//

class CIP_CatcherApp : public CWinApp
{
public:
	CIP_CatcherApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CIP_CatcherApp theApp;