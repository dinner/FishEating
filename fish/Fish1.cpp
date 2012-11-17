// Fish1.cpp: implementation of the CFish class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Fish1.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFish::CFish()
{
    m_pos = cvPoint(0,0);
}

CFish::~CFish()
{
	
}

//��ʳ�����ͼƬ����
void CFish::drawToBack(IplImage *bkImg,IplImage *m_pImg)
{
	int startx = m_pos.x * 10 + 240;
	int starty = m_pos.y * 10 + 170;
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<73;j++)
		{
			if(!(CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+0)==0  &&
				CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+1)==0  &&
				CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+2)==0)  )
			{
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3+0)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3);
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3+1)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+1);
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3+2)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+2);
			}
		}
	}
}

//��0�����ͼƬ����
void CFish::drawToBack0(IplImage *bkImg,IplImage *m_pImg,int y)
{
	int startx = m_pos.x * 7;
    int starty = m_pos.y * 10 + y * 50;
	for(int i=0;i<60;i++)
	{
		for(int j=0;j<50;j++)
		{
			if(!(CV_IMAGE_ELEM(m_pImg,char,j,(i)*3)==0&&
				CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+1)==0&&
				CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+2)==0)
				)
			{
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3);
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3+1)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+1);
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3+2)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+2);
			}
		}
	}
}

//�������ƶ�
void CFish::rundown()
{
	if(m_pos.y<24)
	{
		m_pos.y++;
	} 
}

//�������ƶ�
void CFish::runup()
{
	if(m_pos.y>-9)
	{
		m_pos.y--;
	}
}
 
//�������ƶ�
void CFish::runright()
{
	m_pos.x++;
}

//�������ƶ�
void CFish::runleft()
{
	m_pos.x--;
}

//���Ƶ�һ����
void CFish::drawToBack1(IplImage *bkImg,IplImage *m_pImg,int y)
{
	int startx = m_pos.x * 6;
    int starty = m_pos.y * 15 + y * 50;
	for(int i=0;i<60;i++)
	{
		for(int j=0;j<50;j++)
		{
			if(!(CV_IMAGE_ELEM(m_pImg,char,j,(i)*3)==0&&
				CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+1)==0&&
				CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+2)==0)
				)
			{
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3);
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3+1)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+1);
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3+2)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+2);
			}
		}
	}
}

//���Ƶڶ�����
void CFish::drawToBack2(IplImage *bkImg, IplImage *m_pImg, int y)
{
	int startx = m_pos.x * 3;
    int starty = m_pos.y * 20 + y * 50;
	for(int i=0;i<60;i++)
	{
		for(int j=0;j<50;j++)
		{
			if(!(CV_IMAGE_ELEM(m_pImg,char,j,(i)*3)==0&&
				CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+1)==0&&
				CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+2)==0)
				)
			{
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3);
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3+1)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+1);
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3+2)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+2);
			}
		}
	}
}

//���Ƶ�������
void CFish::drawToBack3(IplImage *bkImg, IplImage *m_pImg, int y)
{
	int startx = m_pos.x * 5;
    int starty = m_pos.y * 25 + y * 50;
	for(int i=0;i<60;i++)
	{
		for(int j=0;j<50;j++)
		{
			if(!(CV_IMAGE_ELEM(m_pImg,char,j,(i)*3)==0&&
				CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+1)==0&&
				CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+2)==0)
				)
			{
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3);
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3+1)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+1);
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3+2)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+2);
			}
		}
	}
}

//���Ƶ�������
void CFish::drawToBack4(IplImage *bkImg, IplImage *m_pImg, int y)
{
	int startx = m_pos.x * 4;
    int starty = m_pos.y * 20 + y*50;
	for(int i=0;i<60;i++)
	{
		for(int j=0;j<50;j++)
		{
			if(!(CV_IMAGE_ELEM(m_pImg,char,j,(i)*3)==0&&
				CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+1)==0&&
				CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+2)==0)
				)
			{
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3);
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3+1)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+1);
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3+2)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+2);
			}
		}
	}
}

//���Ƶ�������
void CFish::drawToBack5(IplImage *bkImg, IplImage *m_pImg, int y)
{
   	int startx = m_pos.x * 2 + 580;
    int starty = m_pos.y * 20 + y*50;
	for(int i=0;i<60;i++)
	{
		for(int j=0;j<50;j++)
		{
			if(!(CV_IMAGE_ELEM(m_pImg,char,j,(i)*3)==0&&
				CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+1)==0&&
				CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+2)==0)
				)
			{
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3);
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3+1)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+1);
				CV_IMAGE_ELEM(bkImg,char,starty+j,(startx+i)*3+2)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+2);
			}
		}
	}
}
