#ifndef _PDFHELPER_517B7F85_B0C5_480E_B35B_199AC523DB5A_H_ 
#define _PDFHELPER_517B7F85_B0C5_480E_B35B_199AC523DB5A_H_

#ifdef  _AA_DLL_
#define _AA_DLL_EXPORT_		__declspec(dllexport)
#define _AA_DLL_EXPORT_C_ 	extern "C" __declspec(dllexport)
#else
#define _AA_DLL_EXPORT_		__declspec(dllimport)
#define _AA_DLL_EXPORT_C_	extern "C" __declspec(dllimport)
#endif

#include <windows.h>
#include <shlwapi.h>
#include <cstdio>

#include "pdfTypes.h"

class _AA_DLL_EXPORT_ CPdfHelper
{
public:
    /** ������־, add by zmm, 2019.4.17*/
    static void EnableLog(bool bEnabled);

	CPdfHelper();
	CPdfHelper(const char *cPdfFilePath, const char *cOwnerPassword = NULL, const char *cUserPassword = NULL);
	~CPdfHelper();

	BOOL OpenFile(const char *cPdfFilePath, const char *cOwnerPassword = NULL, const char *cUserPassword = NULL);
	void CloseFile();
	BOOL IsOK();
	int GetPageCount();
	const char* GetPdfFilePath();
	BOOL GetBitmap(int nPageIndex, double hDPI, double vDPI, ImageColorMode color,
		int& nWidth, int& nHeight, int& nStride, unsigned char **scan0);	//scan0��ʹ�����,�������FreeBitmapData�ͷ��ڴ�
	void FreeBitmapData(unsigned char *scan0);	//�ͷ�GetBitmap�ӿڷ��ص�λͼ�ڴ�����

	//��ӡpdf��ָ����ӡ��cPrinterName, 
	BOOL PrintToPrinter(const char *cPrinterName, const char *cDocName = NULL,
		int nBeginPage = -1, int nEndPage = -1, int nPagesPerPaper = 1,
		WORD wColor = DMCOLOR_MONOCHROME, WORD wPaperSize = DMPAPER_A4,
		WORD wOrientation = DMORIENT_PORTRAIT, WORD wCopies = 1,
		WORD wCollate = DMCOLLATE_TRUE,
		WORD wDuplex = DMDUP_SIMPLEX, WORD wPaperSource = DMBIN_AUTO,
		WORD wPaperWidth = 0, WORD wPaperHeight = 0,
		BOOL bUseCropBox = FALSE, BOOL bUseFullPage = TRUE,
		BOOL bUsePDFPageSize = TRUE, BOOL bForceGray = FALSE, 
		WaterInfo* pWaterInfo = NULL,
		FPrintProcessCallBack callBack = NULL, 
		PrintProcessCallBackData* pCallBackData = NULL,
		BOOL bPauseJob = FALSE, int* pJobId = NULL,BOOL bImage = FALSE);
    // ��ӡpdf��ָ����ӡ��, add by zmm, 2019.5.13
    BOOL PrintToPrinterZ(ZPrintParams& oParams);

	//��ȡPDF��ָ��ҳ��ҳ������
	BOOL GetPageBox(int nPageIndex, PageBox& box, PageBoxType type = MediaBox);
	int GettPageRotate(int nPageIndex);

	//�ж�ָ����ҳ���Ƿ�Ϊ�հ�ҳ
	BOOL IsBlankPage(int nPageIndex);

	//������ҵ�����û�
	void SetJobUser(const char *cJobUser);

protected:
	void InitEnvironment();
	void SetPagesPerPaper(int nPagesPerPaper);
	BOOL IsBlankBitmap(ImageColorMode color, int nWidth, int nHeight, int nStride, unsigned char *scan0);

public:
	void *m_doc;			//PDFDoc
	void *m_surface;		//cairo_surface_t
	void *m_fileName;		//GooString
	void *m_outputName;		//GooString
	void *m_outputFileName;	//GooString
	void *m_imageFileName;	//GooString
	void *m_ownerPW;		//GooString
	void *m_userPW;			//GooString
	void *m_printer;		//GooString

	int m_firstPage;
	int m_lastPage;
	int m_pagesPerPaper;
	int m_currentPage;

	//
	bool m_png;
	bool m_jpeg;
	bool m_ps;
	bool m_eps;
	bool m_pdf;
	bool m_printToWin32;
	bool m_onePaperPrintCompleted;	//һ��ֽ���ݴ�ӡ���
	bool m_printdlg;
	bool m_svg;
	bool m_tiff;

	bool m_printOnlyOdd;
	bool m_printOnlyEven;
	bool m_singleFile;
	double m_max_resolution;// in PPI, ��:ÿӢ����ӵ�е���������
	double m_x_resolution;// in PPI
	double m_y_resolution;// in PPI
	int m_scaleTo;// in pixels
	int m_x_scaleTo;// in pixels
	int m_y_scaleTo;// in pixels
	int m_crop_x;// in pixels
	int m_crop_y;// in pixels
	int m_crop_w;// in pixels
	int m_crop_h;// in pixels
	bool m_useCropBox;
	bool m_mono;
	bool m_gray;
	bool m_transp;

	bool m_level2;
	bool m_level3;
	bool m_origPageSizes;
	char m_paperSize[15];
	double m_paperWidth;// ��λ: point_p (ָ����poppler �еĵ�λ����),  ����ת����ϵ����ÿӢ��72dpiΪ׼, ��: 1 point_p == 1/72.0 inch
	double m_paperHeight;// ��λ: point_p 
	bool m_noCrop;
	bool m_expand;
	bool m_noShrink;
	bool m_noCenter;
	bool m_duplex;
	char m_tiffCompressionStr[16];

	bool m_setupdlg;

	bool m_useWin32PageSize;	//ǿ��ʹ��DEVMODE�е�dmPaperSize������ʹ��dmPaperWidth��dmPaperLength
	bool m_printing;
	bool m_printingAbort;		//��ӡ����ֹ
	bool m_printingOutOfMemory;	//��ӡ�ڴ治��
	FILE *m_output_file;
	bool m_usePDFPageSize;
	bool m_useFullPage;
	bool m_forceGray;	//ǿ�ƻҶ�(�ڰ�ɫ)��ӡ,
						//ĳЩ��ӡ��(��֪:ʩ��)���ܿ��ƺڰ׺Ͳ�ɫ��ӡ,
						//���ύ��ҵʱ,ǿ�ƽ���ҵ��Ⱦ�ɻҶ�ͼ.

	//
	HDC m_hdc;
	HGLOBAL m_hDevmode;
	HGLOBAL m_hDevnames;
	DEVMODEA *m_devmode;
	char* m_printerName;
	char* m_jobUser;		//��ӡ��ҵ�������û�

	bool m_useWater;
	WaterInfo* m_waterInfo;

	bool m_pauseJob;
	int m_jobId;
	bool m_imagePrint;
};

#endif	//_PDFHELPER_517B7F85_B0C5_480E_B35B_199AC523DB5A_H_