// CSmtpTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CSmtp.h"


int _tmain(int argc, _TCHAR* argv[])
{
	bool bError = false;

	try
	{
		CSmtp mail;

		// #define test_gmail_tls
		// 
		// #if defined(test_gmail_tls)
		// 		mail.SetSMTPServer("smtp.gmail.com", 587);
		// 		mail.SetSecurityType(USE_TLS);
		// #elif defined(test_gmail_ssl)
		// 		mail.SetSMTPServer("smtp.gmail.com", 465);
		// 		mail.SetSecurityType(USE_SSL);
		// #elif defined(test_hotmail_TLS)
		// 		mail.SetSMTPServer("smtp.live.com", 25);
		// 		mail.SetSecurityType(USE_TLS);
		// #elif defined(test_aol_tls)
		// 		mail.SetSMTPServer("smtp.aol.com", 587);
		// 		mail.SetSecurityType(USE_TLS);
		// #elif defined(test_yahoo_ssl)
		// 		mail.SetSMTPServer("plus.smtp.mail.yahoo.com", 465);
		// 		mail.SetSecurityType(USE_SSL);
		// #endif

		mail.SetCharSet("GB2312");
		mail.SetSMTPServer("smtp.mxhichina.com", 465);
		mail.SetSecurityType(USE_SSL);

		mail.SetLogin("suprinttest@suprint.canon.com.cn");
		mail.SetPassword("test@123");
		mail.SetSenderName("User");
		mail.SetSenderMail("suprinttest@suprint.canon.com.cn");
		mail.SetReplyTo("DDDD");
		mail.SetSubject("The message");
		mail.AddRecipient("1007482035@qq.com");
		mail.SetXPriority(XPRIORITY_NORMAL);
		mail.SetXMailer("The Bat! (v3.02) Professional");
		mail.AddMsgLine("Hello,");
		mail.AddMsgLine("");
		mail.AddMsgLine("...");
		mail.AddMsgLine("你好,How are you today?");
		mail.AddMsgLine("");
		mail.AddMsgLine("Regards");
		mail.ModMsgLine(5, "regards");
		mail.DelMsgLine(2);
		mail.AddMsgLine("User");

		mail.AddAttachment("E:\\testdoc\\北京-维也纳.pdf");
		//mail.AddAttachment("c:\\test2.exe");
		//mail.AddAttachment("c:\\test3.txt");
		mail.Send();
	}
	catch (ECSmtp e)
	{
		std::cout << "Error: " << e.GetErrorText().c_str() << ".\n";
		bError = true;
	}
	if (!bError)
		std::cout << "Mail was send successfully.\n";
	return 0;
}

