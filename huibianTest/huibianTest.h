
// huibianTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// ChuibianTestApp:
// �йش����ʵ�֣������ huibianTest.cpp
//

class ChuibianTestApp : public CWinAppEx
{
public:
	ChuibianTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern ChuibianTestApp theApp;