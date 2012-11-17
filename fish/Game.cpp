// Game.cpp: implementation of the CGame class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Game.h"  
#include "time.h"
#include<mmsystem.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGame::CGame()
{
	//	m_BKImage=NULL;
	//	m_ShowImage=NULL;
	//  srand((int)time(0));
	for(int i = 0; i < 6; i++)
	{
		live[i] = true;
		count[i] = 0;
	}
	//	m_TotalScore=0;
}

CGame::~CGame()
{
	cvDestroyWindow("Fish");
}

//初始化图片数据和一些变量的数据
void CGame::initialize()
{
	// int position[5];
	m_BKImage = cvLoadImage(".\\pic\\back.bmp");
	int h = m_BKImage->height;
	int w = m_BKImage->width;
	m_ShowImage = cvCreateImage(cvSize(w,h),IPL_DEPTH_8U,3);
	
	/*		m_ShowImage = cvLoadImage(".//pic//back.bmp"); */
	this->Load();
	m_FirstFish.m_fish = cvLoadImage(".\\pic\\FirstFish.bmp");
    m_form = cvLoadImage(".\\pic\\score.bmp");
    m_fish[0] = cvLoadImage(".\\pic\\0.bmp");
    m_fish[1] = cvLoadImage(".\\pic\\1.bmp");
	m_fish[2] = cvLoadImage(".\\pic\\2.bmp");
	m_fish[3] = cvLoadImage(".\\pic\\3.bmp");
	m_fish[4] = cvLoadImage(".\\pic\\4.bmp");
    m_fish[5] = cvLoadImage(".\\pic\\5.bmp");
	/*	for(int i=0;i<5;i++)
	{
	drawfish(m_ShowImage,m_fish[i],i);
	}
	*/
	m_scoreImage[0] = cvLoadImage(".\\pic\\p0.bmp");
    m_scoreImage[1] = cvLoadImage(".\\pic\\p1.bmp");
	m_scoreImage[2] = cvLoadImage(".\\pic\\p2.bmp");
	m_scoreImage[3] = cvLoadImage(".\\pic\\p3.bmp");
    m_scoreImage[4] = cvLoadImage(".\\pic\\p4.bmp");
	m_scoreImage[5] = cvLoadImage(".\\pic\\p5.bmp");
    m_scoreImage[6] = cvLoadImage(".\\pic\\p6.bmp");
	m_scoreImage[7] = cvLoadImage(".\\pic\\p7.bmp");
	m_scoreImage[8] = cvLoadImage(".\\pic\\p8.bmp");
    m_scoreImage[9] = cvLoadImage(".\\pic\\p9.bmp");
	m_FishLife = cvLoadImage(".\\pic\\x3.bmp");
	m_level = cvLoadImage(".\\pic\\x2.bmp");
	change[0] = 2;
	change[1] = 3;
	change[2] = 5;
	change[3] = 7;
	change[4] = 8;
	change[5] = 6;
}

//把游戏的各种图片绘制到背景并绘制将背景打印出来
void CGame::drawImage()
{
	cvNamedWindow("Fish");
    cvCopy(this->m_BKImage,this->m_ShowImage);
	//	m_FirstFish.m_fish = cvLoadImage(".\\pic\\FirstFish.bmp");
	m_FirstFish.drawToBack(m_ShowImage,m_FirstFish.m_fish);
	//	this->Load();
	//	m_Fish[0].drawToBack0(m_ShowImage,m_Fish[0].m_fish,1);
	//	move();
	this->drawformImage(m_ShowImage,m_form);
	for(int i = 0; i < 5; i++)
	{
		drawfish(m_ShowImage,m_fish[i],i);
	}
    m_allImage = this->m_scoreImage[0];
    drawscoreImage(544,15);
    drawscoreImage(524,15);
    m_allImage = this->m_FishLife;
	drawfishlife(600,54,m_ShowImage,m_FishLife);
    drawlevel(590,14,m_ShowImage,m_level);
	for(int j = 0; j < 6; j++)
	{
	   drawToBack(j);
	}
	this->totalscore();
	//  this->drawscoreImage();
	cvShowImage("Fish",m_ShowImage);
	//	cvReleaseImage(&m_ShowImage);
}

//读入被捕食的鱼的图片
void CGame::Load()
{
	m_Fish[0].m_fish = cvLoadImage(".\\pic\\0.bmp");
    m_Fish[1].m_fish = cvLoadImage(".\\pic\\1.bmp");
	m_Fish[2].m_fish = cvLoadImage(".\\pic\\2.bmp");
	m_Fish[3].m_fish = cvLoadImage(".\\pic\\3.bmp");
	m_Fish[4].m_fish = cvLoadImage(".\\pic\\4.bmp");
	m_Fish[5].m_fish = cvLoadImage(".\\pic\\5.bmp");
}

//通过键盘操作大鱼的游动
void CGame::changeItem(int key)
{
	if(key == 'l')
	{
        if(m_FirstFish.m_pos.x<=29)
		{
			this->m_FirstFish.runright();
		}
	}
	else if(key == 'j')
	{
        if(m_FirstFish.m_pos.x>=-23)
		{
			this->m_FirstFish.runleft();
		}
	}
	else if(key == 'k')
	{
		this->m_FirstFish.rundown();
	}
	else if(key == 'i')
	{
		this->m_FirstFish.runup();
	}
}

//小鱼的移动
void CGame::move(int n)
{
	if(n==5)
	{
		this->m_Fish[5].runleft();
	}
	else
	{
		this->m_Fish[n].runright();
	}
}

//绘制小鱼到背景图上
void CGame::drawToBack(int n)
{
	switch(n)
	{
	case 0:
		{
			this->eat(0);
			if(live[0] == FALSE || m_Fish[0].m_pos.x*7+60 >= 640)
			{
				m_Fish[0].m_pos.x = 0;
				live[0] = true;
				change[0] = rand() % 7 + 2;
			}
			m_Fish[0].drawToBack0(m_ShowImage,m_Fish[0].m_fish,change[0]);
			move(0);
			break;
		}
	case 1:
		{
			this->eat(1);
			if(live[1] == FALSE || m_Fish[1].m_pos.x * 6 + 60 >= 640)
			{
				m_Fish[1].m_pos.x = 0;
				live[1] = true;
				change[1] = rand() % 7 + 2;
			}
			m_Fish[1].drawToBack1(m_ShowImage,m_Fish[1].m_fish,change[1]);
			move(1);
			break;
		}
	case 2:
		{
			this->eat(2);
			if(live[2] == FALSE || m_Fish[2].m_pos.x * 3 + 60 >= 640)
			{
				m_Fish[2].m_pos.x = 0;
				live[2] = true;
				change[2] = rand() % 7 + 2;
			}
			m_Fish[2].drawToBack2(m_ShowImage,m_Fish[2].m_fish,change[2]);
			move(2);
			break;
		}
	case 3:
		{
			this->eat(3);
			if(live[3] == FALSE || m_Fish[3].m_pos.x * 5 + 60 >= 640)
			{
				m_Fish[3].m_pos.x = 0;
				live[3] = true;
				change[3] = rand() % 7 + 2;
			}
			m_Fish[3].drawToBack3(m_ShowImage,m_Fish[3].m_fish,change[3]);
			move(3);
			break;
		}
	case 4:
		{
			this->eat(4);
			if(live[4]==FALSE||m_Fish[4].m_pos.x*4+60>=640)
			{
				m_Fish[4].m_pos.x = 0;
				live[4] = true;
				change[4] = rand() % 7 + 2;
			}
			m_Fish[4].drawToBack4(m_ShowImage,m_Fish[4].m_fish,change[4]);
			move(4);
			break;
		}   
	case 5:
		{
			this->eat(5);
			if(live[5]==FALSE||m_Fish[5].m_pos.x*2+580<=0)
			{
				m_Fish[5].m_pos.x = 0;
				live[5] = true;
				change[5] = rand() % 7 + 2;
			}
			m_Fish[5].drawToBack5(m_ShowImage,m_Fish[5].m_fish,change[5]);
			move(5);
			break;
		}   
	}
}


//判断小鱼是否被吃
int CGame::eat(int n)
{
	double x1,x2;
	double y1,y2;
	double x,y;
	double z;
	double DIS;
	switch(n)   
	{
	case 0:
		{
			x1 = m_Fish[0].m_pos.x * 7 + 30; 
			y1 = change[0] * 50 + 25;
			x2 = m_FirstFish.m_pos.x * 10 + 290;
			y2 = m_FirstFish.m_pos.y * 10 + 205;
			x = x2-x1;
			y = y2-y1;
			z = x * x + y * y;
			DIS=sqrt(z);
			//  if(DIS<=20.0||m_Fish[0].m_pos.x*9+60>=640)
			if(DIS <= 20.0)
			{
				count[0]++;
				live[0] = FALSE;
              //  PlaySound("2.wav", NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
			//	PlaySound("2.wav", NULL, SND_FILENAME|SND_NOSTOP);
				// return 1;
               mciSendString("play ./2.wav"," ",0,0);
			}
			else
			{
				;
			}
			break;
		}
	case 1:
		{
			x1 = m_Fish[1].m_pos.x * 6 + 30; 
			y1 = change[1] * 50 + 25;
			x2 = m_FirstFish.m_pos.x * 10 + 290;
			y2 = m_FirstFish.m_pos.y * 10 + 205;
			x = x2-x1;
			y = y2-y1;
			z = x*x+y*y;
			DIS=sqrt(z);
			if(DIS <= 20)
			{
				count[1]++;
				live[1] = FALSE;
				//   return 1;
				mciSendString("play ./2.wav"," ",0,0);
			}
			else
			{
				//   return 0;
				;
			}
			break;
		}
	case 2:
		{
			x1 = m_Fish[2].m_pos.x * 3 + 30; 
			y1 = change[2] * 50 + 25;
			x2 = m_FirstFish.m_pos.x * 10 + 290;
			y2 = m_FirstFish.m_pos.y * 10 + 205;
			x = x2-x1;
			y = y2-y1;
			z = x*x+y*y;
			DIS=sqrt(z);
			if(DIS <= 20)
			{
				//	   return 1;
				count[2]++;
				live[2] = FALSE;
				mciSendString("play ./2.wav"," ",0,0);
			}
			else
			{
				;
			}
			break;
		}
	case 3:
		{
			x1 = m_Fish[3].m_pos.x * 5 + 30; 
			y1 = change[3] * 50 + 25;
			x2 = m_FirstFish.m_pos.x * 10 + 290;
			y2 = m_FirstFish.m_pos.y * 10 + 205;
			x = x2-x1;
			y = y2-y1;
			z = x*x+y*y;
			DIS = sqrt(z);
			if(DIS <= 20)
			{
				count[3]++;
				live[3] = FALSE;
				mciSendString("play ./2.wav"," ",0,0);
			}
			else
			{
				;
			}
			break;
		}
	case 4:
		{
			x1 = m_Fish[4].m_pos.x * 4 + 30; 
			y1 = change[4] * 50 + 25;
			x2 = m_FirstFish.m_pos.x * 10 + 290;
			y2 = m_FirstFish.m_pos.y * 10 + 205;
			x = x2-x1;
			y = y2-y1;
			z = x*x+y*y;
			DIS = sqrt(z);
			if(DIS <= 20)
			{
				count[4]++;
				live[4] = FALSE;
				mciSendString("play ./2.wav"," ",0,0);
			}
			else
			{
				;
			}
			break;
		}
	case 5:
		{
			x1 = m_Fish[5].m_pos.x * 2 + 610; 
			y1 = change[5] * 50 + 25;
			x2 = m_FirstFish.m_pos.x * 10 + 290;
			y2 = m_FirstFish.m_pos.y * 10 + 205;
			x = x2-x1;
			y = y2-y1;
			z = x*x+y*y;
			DIS = sqrt(z);
			if(DIS <= 20)
			{
				count[5]++;
				live[5] = FALSE;
				mciSendString("play ./2.wav"," ",0,0);
			}
			else
			{
				;
			}
			break;
		}
	 }
	 return 0;
}

//将计分栏的图片绘制到背景上
void CGame::drawformImage(IplImage * bkImg,IplImage *m_pImg)
{
	for(int i=0;i<640;i++)
	{
		for(int j=0;j<84;j++)
		{
			{
				CV_IMAGE_ELEM(bkImg,char,j,(i)*3+0)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3);
				CV_IMAGE_ELEM(bkImg,char,j,(i)*3+1)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+1);
				CV_IMAGE_ELEM(bkImg,char,j,(i)*3+2)=CV_IMAGE_ELEM(m_pImg,char,j,(i)*3+2);
			}
		}
	}
}

//将计分栏的可吃小鱼图片绘制到计分栏上
void CGame::drawfish(IplImage *bkImg, IplImage *m_pImg, int n)
{
	int startx = 77+n*52;
	int starty = 0;
	for(int i=0;i<60;i++)
	{
		for(int j=0;j<50;j++)
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

//绘制初始得分分数图片
void CGame::drawscoreImage(int startx, int starty)
{
   	int k;
	for(int i = 0; i < 15; i++)
	{
		k=starty;
		for(int j = 0; j < 30; j++)
		{
			{
				CV_IMAGE_ELEM(m_ShowImage,char, starty + j, (startx + i)*3) = 
					CV_IMAGE_ELEM(m_allImage, char, j, i*3);
				CV_IMAGE_ELEM(m_ShowImage,char, starty + j, (startx + i)*3 + 1) = 
					CV_IMAGE_ELEM(m_allImage, char, j, i*3 + 1);
				CV_IMAGE_ELEM(m_ShowImage,char, starty + j, (startx + i)*3 + 2) = 
					CV_IMAGE_ELEM(m_allImage, char, j, i*3 + 2);
				k++;
			}
		}
	}	
}

//计算总分并且把得分绘制到背景上
void CGame::totalscore()
{
	m_TotalScore=0;
	for(int i=0;i<6;i++)
	{
		// m_TotalScore=count[i]*(i+1)+m_TotalScore;
		m_TotalScore+=count[i]*(i+1);
	}
	int hundred;
	int thousand;
	int myriabit;
	
	if(m_TotalScore<10)
	{
		m_allImage=m_scoreImage[m_TotalScore];
		drawscoreImage(504,15);
	}
	else if(m_TotalScore>=10&&m_TotalScore<100)
	{
		hundred=m_TotalScore%10;
		thousand=m_TotalScore/10;
		m_allImage=m_scoreImage[hundred];
		drawscoreImage(504,15);
		m_allImage=m_scoreImage[thousand];
		drawscoreImage(484,15);
	}
	else if(m_TotalScore>=100&&m_TotalScore<1000)
	{
		hundred=m_TotalScore%100%10;
		thousand=m_TotalScore/10%10;
		myriabit=m_TotalScore/100;
		m_allImage=m_scoreImage[hundred];
		drawscoreImage(504,15);
		m_allImage=m_scoreImage[thousand];
		drawscoreImage(484,15);
		m_allImage=m_scoreImage[myriabit];
		drawscoreImage(464,15);
	}
	
}






