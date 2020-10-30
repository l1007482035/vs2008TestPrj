#ifndef  __PDFA_H__
#define  __PDFA_H__


enum PdfAConformanceLevel
{
	PDF_A_NO = -1,
	PDF_A_1A = 0,
	PDF_A_1B = 1,
	PDF_A_2A = 2,
	PDF_A_2B = 3,
	PDF_A_2U = 4,
	PDF_A_3A = 5,
	PDF_A_3B = 6,
	PDF_A_3U = 7,
	ZUGFeRD = 8,
	ZUGFeRDBasic = 9,
	ZUGFeRDComfort = 10,
	ZUGFeRDExtended = 11,
};

#ifdef _DEBUG
	#import "../Public/lib/debug/Pdf2PdfA.tlb" named_guids raw_interfaces_only
#else
	#import "../Public/lib/release/Pdf2PdfA.tlb" named_guids raw_interfaces_only
#endif



#endif