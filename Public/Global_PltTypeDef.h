//add by zfq,2013.01.16
//�ն����͵���չ���壬ԭ�е���global.h�ж���

#pragma once

#ifdef  _AA_DLL_
#	define _AA_DLL_EXPORT_		__declspec(dllexport)
#	define _AA_DLL_EXPORT_C_ 	extern "C" __declspec(dllexport)
#else
#	define _AA_DLL_EXPORT_		__declspec(dllimport)
#	define _AA_DLL_EXPORT_C_	extern "C" __declspec(dllimport)
#endif


//�ն�����
#if 0
#	define ISEC_PLT_CLT			1		//�ͻ���
#	define ISEC_PLT_MGR			2		//�����
#	define ISEC_PLT_SVR			3		//����
#	define ISEC_PLT_PRT			4		//��ӡվ��
#	define ISEC_PLT_TOOL		5		//����
#	define ISEC_PRT_CHARGE_TOOL	6		//��ֵ����
#	define ISEC_PLT_WEB			7		//web����
#endif

#define ISEC_PLT_PrtCenterSvr	10		//��ӡ���й����
#define ISEC_PLT_TRANSCRIPT_IMPORT_TOOL	11	//�ɼ����빤��




