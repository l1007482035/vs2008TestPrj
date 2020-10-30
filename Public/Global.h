// Global.h: interface for the CRscObj class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_GLOBAL_)
#define _GLOBAL_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



#ifdef  _AA_DLL_
	#define _AA_DLL_EXPORT_		__declspec(dllexport)
	#define _AA_DLL_EXPORT_C_ 	extern "C" __declspec(dllexport)
#else
	#define _AA_DLL_EXPORT_		__declspec(dllimport)
	#define _AA_DLL_EXPORT_C_	extern "C" __declspec(dllimport)
#endif

#define PRODUCT_REGISTY_KEY				_T("SOFTWARE\\iSecStar")			//ע����ֵ
#define PROJECT_REGISTY_KEY				_T("SOFTWARE\\iSecStar")		//ע����ֵ
#define PROJECT_PATH					_T("\\iSecStar")

#define REMOTE_START_PORT			7010	//Զ�̿����˿�
#define POLICY_TCP_PORT				5020
#define DBSVR_TCP_PORT				5021	//���ݷ�����


#ifndef __STR1__
#define __STR2__(x) #x
#define __STR1__(x) __STR2__(x)
#define __LOC__ __FILE__ "("__STR1__(__LINE__)") : "
#endif

#pragma warning(disable : 4996)
#pragma warning(disable : 4251)
#pragma warning(disable : 4275)
#pragma warning(disable : 4200)


//#define XAB_TEST_MODE

//ϵͳ���Ӱ汾
#define ISEC_EDU	0x1
#define ISEC_STD	0x2
#define ISEC_ENT	0x4
#define ISEC_ADV	0x8
#define ISEC_ALL	0xF



//��Ʒ�ڲ����
#define ISEC_PRINT_CODE		_T("iSecPrint")
#define ISEC_INTRANET_CODE	_T("iSecIntranet")

//��Ʒ�ڲ�����
#define ISEC_PRINT		0x100
#define ISEC_INTRANET	0x200
#define ISEC_CRPT		0x400

//��ӡϵͳ
#define ISEC_PRINT_ALL		0x10f
#define ISEC_PRINT_EDU		0x101
#define ISEC_PRINT_STD		0x102
#define ISEC_PRINT_ENT		0x104
#define ISEC_PRINT_ADV		0x108

//��������
#define ISEC_INTRANET_ALL	0x207
#define ISEC_INTRANET_STD	0x201
#define ISEC_INTRANET_ENT	0x202
#define ISEC_INTRANET_ADV	0x204
//�ĵ�����
#define ISEC_CRPT_ALL		0x407
#define ISEC_CRPT_STD		0x401
#define ISEC_CRPT_ENT		0x402
#define ISEC_CRPT_ADV		0x404


//�ն�����
#define ISEC_PLT_CLT			1		//�ͻ���
#define ISEC_PLT_MGR			2		//�����
#define ISEC_PLT_SVR			3		//����
#define ISEC_PLT_PRT			4		//��ӡվ��
#define ISEC_PLT_TOOL			5		//����
#define ISEC_PRT_CHARGE_TOOL	6		//��ֵ����
#define ISEC_PLT_WEB			7		//web����

//��Ϊ����
#define ISEC_CLT_PRINT		MAKELONG(ISEC_PRINT,ISEC_PLT_CLT)
#define ISEC_CLT_INTRANET	MAKELONG(ISEC_INTRANET,ISEC_PLT_CLT)
#define ISEC_CLT_CRPT		MAKELONG(ISEC_CRPT,ISEC_PLT_CLT)

#define IsPrintProduct(dw)		(ISEC_PRINT&dw)
#define IsIntranetProduct(dw)	(ISEC_INTRANET&dw)

#ifndef _DEBUG
#define ISEC_ENABLE_ENCRYPT
//#define DEF_ISEC_VER_STD
#endif
#endif // !defined(_GLOBAL_)
