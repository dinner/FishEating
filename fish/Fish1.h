// Fish1.h: interface for the CFish class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FISH1_H__B5C02A8F_BC20_4F3B_BADA_02BED3F68131__INCLUDED_)
#define AFX_FISH1_H__B5C02A8F_BC20_4F3B_BADA_02BED3F68131__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "cv.h"
#include "highgui.h"
class CFish  
{
public:
	void drawToBack5(IplImage *bkImg,IplImage *m_pImg, int y);
	void drawToBack4(IplImage *bkImg,IplImage *m_pImg, int y);
	void drawToBack3(IplImage *bkImg,IplImage *m_pImg, int y);
	void drawToBack2(IplImage *bkImg,IplImage *m_pImg,int y);
	void drawToBack1(IplImage *bkImg,IplImage *m_pImg,int y);
	IplImage * m_fish;
	void runleft();
	void runright();
	void runup();
	void rundown();
	void drawToBack0(IplImage *bkImg,IplImage *m_pImg,int y);
	CvPoint m_pos;
	void drawToBack(IplImage *bkImg,IplImage *m_pImg);
	CFish();
	virtual ~CFish();

};

#endif // !defined(AFX_FISH1_H__B5C02A8F_BC20_4F3B_BADA_02BED3F68131__INCLUDED_)
