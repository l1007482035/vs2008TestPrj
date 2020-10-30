//云打印网络连接配置信息

#ifndef _CloudPrintNetDef_h_415C7ED2_E174_4AD1_9093_28119F8184A5_
#define _CloudPrintNetDef_h_415C7ED2_E174_4AD1_9093_28119F8184A5_

#include "CloudPrintConfig.h"

#define WebServiceDomain						TEXT("www.enetinn.com")		//云打印WebService的域名、IP
#define WebServicePort							(80)								//云打印WebService的端口
#if Enable_Http_Interface
#define WebServiceURL							TEXT("http://www.enetinn.com/cloudprint/serviceHttp/serviceHttp.php")		//云打印HTTP接口的完整URL
#define WebServiceURLFormat						TEXT("http://%s:%d/cloudprint/serviceHttp/serviceHttp.php")						//云打印HTTP接口的完整URL的格式化
#else
#define WebServiceURL							TEXT("http://www.enetinn.com/cloudprint/webservices/service.php")			//云打印WebService的完整URL
#define WebServiceURLFormat						TEXT("http://%s:%d/cloudprint/webservices/service.php")							//云打印WebService的完整URL的格式化
#endif
#define WebServiceTimeout						(1000*15)							//云打印WebService的调用超时时间，毫秒
#define ServerDomain							TEXT("www.enetinn.com")	//云打印中心服务器的域名、IP
#define ServerPort								5040//(9000)								//云打印中心服务器的端口

//客户端与服务器的连接配置
#define ScanQRCodeURL							TEXT("http://www.enetinn.com/cloudprint/mobile/index.php")		//云打印客户端扫码登录的不带参数URL
#define ScanQRCodeFormat						TEXT("http://%s:%d/cloudprint/mobile/index.php")		//云打印客户端扫码登录的不带参数URL
#define ServerBDomain							TEXT("www.enetinn.com")	//云打印中心服务器B的域名、IP
#define ServerBPort								(9001)								//云打印中心服务器B的端口

#define	UserRegisterURL							TEXT("http://www.enetinn.com/cloudprint/view/pc/user/userregister.php")//云打印用户注册

#endif //_CloudPrintNetDef_h_415C7ED2_E174_4AD1_9093_28119F8184A5_