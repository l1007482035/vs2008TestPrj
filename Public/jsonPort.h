#pragma once

//json��ı������Ҫ����CloudPrintRouterDemo��һ�¡���/MD���͡��ڹ���DLL��ʹ��MFC��

#include "../Public/jsoncpp-src-0.5.0/include/json/json.h"

#ifdef _DEBUG
#pragma comment(lib,"../Public/jsoncpp-src-0.5.0/lib/debug/json.lib")
#else
#pragma comment(lib,"../Public/jsoncpp-src-0.5.0/lib/release/json.lib")
#endif
