//�ƴ�ӡ��������������Ϣ

#ifndef _CloudPrintNetDef_h_415C7ED2_E174_4AD1_9093_28119F8184A5_
#define _CloudPrintNetDef_h_415C7ED2_E174_4AD1_9093_28119F8184A5_

#include "CloudPrintConfig.h"

#define WebServiceDomain						TEXT("www.enetinn.com")		//�ƴ�ӡWebService��������IP
#define WebServicePort							(80)								//�ƴ�ӡWebService�Ķ˿�
#if Enable_Http_Interface
#define WebServiceURL							TEXT("http://www.enetinn.com/cloudprint/serviceHttp/serviceHttp.php")		//�ƴ�ӡHTTP�ӿڵ�����URL
#define WebServiceURLFormat						TEXT("http://%s:%d/cloudprint/serviceHttp/serviceHttp.php")						//�ƴ�ӡHTTP�ӿڵ�����URL�ĸ�ʽ��
#else
#define WebServiceURL							TEXT("http://www.enetinn.com/cloudprint/webservices/service.php")			//�ƴ�ӡWebService������URL
#define WebServiceURLFormat						TEXT("http://%s:%d/cloudprint/webservices/service.php")							//�ƴ�ӡWebService������URL�ĸ�ʽ��
#endif
#define WebServiceTimeout						(1000*15)							//�ƴ�ӡWebService�ĵ��ó�ʱʱ�䣬����
#define ServerDomain							TEXT("www.enetinn.com")	//�ƴ�ӡ���ķ�������������IP
#define ServerPort								5040//(9000)								//�ƴ�ӡ���ķ������Ķ˿�

//�ͻ��������������������
#define ScanQRCodeURL							TEXT("http://www.enetinn.com/cloudprint/mobile/index.php")		//�ƴ�ӡ�ͻ���ɨ���¼�Ĳ�������URL
#define ScanQRCodeFormat						TEXT("http://%s:%d/cloudprint/mobile/index.php")		//�ƴ�ӡ�ͻ���ɨ���¼�Ĳ�������URL
#define ServerBDomain							TEXT("www.enetinn.com")	//�ƴ�ӡ���ķ�����B��������IP
#define ServerBPort								(9001)								//�ƴ�ӡ���ķ�����B�Ķ˿�

#define	UserRegisterURL							TEXT("http://www.enetinn.com/cloudprint/view/pc/user/userregister.php")//�ƴ�ӡ�û�ע��

#endif //_CloudPrintNetDef_h_415C7ED2_E174_4AD1_9093_28119F8184A5_