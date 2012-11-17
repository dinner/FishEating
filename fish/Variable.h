// Variable.h: interface for the CVariable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VARIABLE_H__CFAB1870_34A4_456C_A38E_8989CDF2BE60__INCLUDED_)
#define AFX_VARIABLE_H__CFAB1870_34A4_456C_A38E_8989CDF2BE60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "Game.h"
#include "cv.h"
#include "highgui.h"
class CVariable  
{
public:
	IplImage * m_level;
	void drawlevel(int startx,int starty,IplImage *bkImg,IplImage *m_pImg);
	void drawfishlife(int startx,int starty,IplImage *bkImg,IplImage *m_pImg);
	IplImage * m_FishLife;
	CVariable();
	virtual ~CVariable();
     
};

#endif // !defined(AFX_VARIABLE_H__CFAB1870_34A4_456C_A38E_8989CDF2BE60__INCLUDED_)
