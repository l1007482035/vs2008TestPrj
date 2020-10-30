#ifndef _LmPrintStationCommDef_H_A9C189B3_0FFE_4026_8247_14EFE044029B_
#define _LmPrintStationCommDef_H_A9C189B3_0FFE_4026_8247_14EFE044029B_

#define LmProcessParamMemMapName		_T("Global\\{1C7897E4-ABB4-409f-B6F6-05192CC789F8}")

typedef struct tag_LmProcessParam
{
	DWORD dwPrinterIndex;
	DWORD dwProcessId;
	DWORD dwInstanceState;
	DWORD dwRunState;
	char pszPrinterName[MAX_PATH];
	char pszModuleExePath[MAX_PATH];
}LmProcessParam, *PLmProcessParam;

//��ҵ��ӡ����̹���ʵ����������״̬
enum LM_Instance_State
{
	LM_Instance_State_Orig	= 0,	//��ʼ״̬
	LM_Instance_State_Run	= 1,	//����
	LM_Instance_State_Stop	= 2,	//ֹͣ
	LM_Instance_State_Disable	= 3		//ʵ������
};

//��ҵ��ӡ���������״̬
enum LM_Run_State
{
	LM_Run_State_UnKnown	= 0,	//δ֪
	LM_Run_State_Running	= 1,	//������
	LM_Run_State_Stoped		= 2,	//��ֹͣ
	LM_Run_State_RunningAndAbnormal		= 3,	//���е������쳣
	LM_Run_State_ExceptionExit			= 4,	//�쳣�˳�
	LM_Run_State_ParameterErrorExit		= 5,	//���������˳�
	LM_Run_State_MultiInstanceExit		= 6,	//��ʵ���쳣�˳�
	LM_Run_State_NormalExit				= 7,	//�����˳�
	LM_Run_State_Exiting				= 8,	//�����˳�
	LM_Run_State_Starting				= 9,	//��������
	LM_Run_State_Disable				= 10,	//ʵ�������ã�Ҫ������ʵ��
	LM_Run_State_MAX					= 11	//���ֵ
};

static TCHAR *gc_LM_Run_State_Table[] = {
	TEXT("δ֪"),
	TEXT("������"),
	TEXT("��ֹͣ"),
	TEXT("�������쳣"),
	TEXT("�쳣�˳�"),
	TEXT("���������˳�"),
	TEXT("��ʵ���쳣�˳�"),
	TEXT("���˳�"),
	TEXT("�����˳�"),
	TEXT("��������"),
	TEXT("�ѽ���")
};


#define MAX_PRINTER_COUNT		128			//�����ƴ�ӡ������

#define LmPrintStationEXE		TEXT("LmPrintStation.exe")
#define LmPrintStationSetFile	TEXT("config\\settings.ini")
#define LmPrintStationRunState	TEXT("LmPrintStationRunState")	//����������ҵ��ӡ���������״̬�Ľڡ�[A=B],A��ʾ��ӡ���ţ�B��ʾ��ӡ������״̬
#define LmPrintStationRunPid	TEXT("LmPrintStationRunPid")	//����������ҵ��ӡ���������״̬�Ľڡ�[A=B],A��ʾ��ӡ���ţ�B��ʾ��ӡ�����ID
#define LmPrintStationMap		TEXT("LmPrintStationMap")		//����������ҵ��ӡ���������Ϣ��[A=B],A��ʾ��ӡ���ţ�B��ʾ��ӡ��󶨵Ĵ�ӡ����
#define LmPrintStationMgr		TEXT("LmPrintStationMgr")		//
#define LmPrintStationHelper	TEXT("LmPrintStationHelper")	//

//�����в�����LmPrintStation.exe [��������] [��ӡ�����] [��ӡ����]��
#define LmPrintStationStartFlag		TEXT("/Start")		//�����ʽһ��LmPrintStation.exe /Start	1	LmX860
#define LmPrintStationStartFlag2	TEXT("-Start")		//�����ʽ����LmPrintStation.exe /Start
#define LmPrintStationReStartFlag	TEXT("/ReStart")	//�����ʽһ��LmPrintStation.exe /ReStart	1	LmX860
#define LmPrintStationReStartFlag2	TEXT("-ReStart")	//�����ʽ����LmPrintStation.exe /ReStart
#define LmPrintStationStopFlag		TEXT("/Stop")		//�����ʽ����LmPrintStation.exe /Stop	1
#define LmPrintStationStopFlag2		TEXT("-Stop")
#define LmPrintStationCheckRunStateFlag		TEXT("/CheckRunState")	//�����ʽ�ģ�LmPrintStation.exe /CheckRunState	1
#define LmPrintStationCheckRunStateFlag2	TEXT("-CheckRunState")	//����ֵ�ο���LM_Run_State

#define LmPrintStationRunWaitTimeMS	5000	//��ӡ���������Ĭ�ϵȴ�ʱ��

#define LmPrintStationQuitCmd		TEXT("quit")		//�˳�������ָ��

#endif //_LmPrintStationCommDef_H_A9C189B3_0FFE_4026_8247_14EFE044029B_