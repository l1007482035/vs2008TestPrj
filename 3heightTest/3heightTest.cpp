// 3heightTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "3heightTest.h"
#include "pdf2pdfapi_c.h"

#pragma comment(lib,".\\lib\\Win32\\Pdf2PdfAPI.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����: MFC ��ʼ��ʧ��\n"));
		nRetCode = 1;
	}
	else
	{
		// TODO: �ڴ˴�ΪӦ�ó������Ϊ��д���롣

		TPdf2Pdf* pConverter;
		TPDFCompliance eCompliance;
		TCHAR* szInputPath = "D:\\MyProject\\vs2008TestPrj\\Release\\111.pdf";
		TCHAR* szOutputPath = "D:\\MyProject\\vs2008TestPrj\\Release\\444.pdf";;
		   int iReturnValue = 0;
		// Initialize library
		Pdf2PdfInitialize();
		Pdf2PdfSetLicenseKey("1-UCAE2-XUQBA-DSCW7-5K7HX-VU73D-8Q36H-K94DW");
		// Check license
		if (!Pdf2PdfGetLicenseIsValid())
		{
			_tprintf(_T("No valid license found.\n"));
			return 1;
		}

		eCompliance = ePDFA2b;
		// Create the converter
		pConverter = Pdf2PdfCreateObject();
		// Set compliance level
		Pdf2PdfSetCompliance(pConverter, eCompliance);
		// Convert to PDF/A
		if (!Pdf2PdfConvert(pConverter, szInputPath, _T(""), szOutputPath, _T("1.log")))
		{
			_tprintf(_T("Input file %s could not be converted. msg(%s) (ErrorCode: 0x%08x).\n")
				, szInputPath, Pdf2PdfGetErrorMessage(pConverter), Pdf2PdfGetErrorCode(pConverter));
			iReturnValue = 1;
		}
		else
		{
			_tprintf(_T("Execution successful.\n"));
		}




	}

	return nRetCode;
}
