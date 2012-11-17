// fish.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Game.h"
#include "Variable.h"
#include "cv.h"
#include "highgui.h"
#include <Windows.h>
#include <Mmsystem.h>

CGame game;
//CVariable game;
int main(int argc, char* argv[])
{
    PlaySound("1.wav", NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
    game.initialize();	
	while(1)
	{
	int key = cvWaitKey(100);
	if(key==VK_ESCAPE)
	{
		break;
	}
	else
	{
    game.drawImage();
	game.changeItem(key);
	}
	}
	for(int i=0;i<6;i++)
	{
	  // printf("%d ",game.count[i]);
	  cout<<"��"<<(i+1)<<"����ı��Ե�������"<<game.count[i]<<endl;
	}
	cout<<"�����ܵ÷��ǣ�"<<game.m_TotalScore*100<<endl;
	cvWaitKey(0);
	return 0;
}
