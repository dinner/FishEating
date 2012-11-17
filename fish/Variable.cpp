// Variable.cpp: implementation of the CVariable class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Variable.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVariable::CVariable()
{

}

CVariable::~CVariable()
{

}

//将大鱼的生命数绘制到计分栏上
void CVariable::drawfishlife(int startx,int starty,IplImage *bkImg,IplImage *m_pImg)
{
   	int k;
	for(int i = 0; i < 10; i++)
	{
		k=starty;
		for(int j = 0; j < 20; j++)
		{
			{
				CV_IMAGE_ELEM(bkImg,char, starty + j, (startx + i)*3) = 
					CV_IMAGE_ELEM(m_pImg, char, j, i*3);
				CV_IMAGE_ELEM(bkImg,char, starty + j, (startx + i)*3 + 1) = 
					CV_IMAGE_ELEM(m_pImg, char, j, i*3 + 1);
				CV_IMAGE_ELEM(bkImg,char, starty + j, (startx + i)*3 + 2) = 
					CV_IMAGE_ELEM(m_pImg, char, j, i*3 + 2);
				k++;
			}
		}
	}	
}

//将关卡绘制到计分栏上
void CVariable::drawlevel(int startx,int starty,IplImage *bkImg,IplImage *m_pImg)
{
	int k;
	for(int i = 0; i < 30; i++)
	{
		k=starty;
		for(int j = 0; j < 30; j++)
		{
			{
				CV_IMAGE_ELEM(bkImg,char, starty + j, (startx + i)*3) = 
					CV_IMAGE_ELEM(m_pImg, char, j, i*3);
				CV_IMAGE_ELEM(bkImg,char, starty + j, (startx + i)*3 + 1) = 
					CV_IMAGE_ELEM(m_pImg, char, j, i*3 + 1);
				CV_IMAGE_ELEM(bkImg,char, starty + j, (startx + i)*3 + 2) = 
					CV_IMAGE_ELEM(m_pImg, char, j, i*3 + 2);
				k++;
			}
		}
	}	
}
