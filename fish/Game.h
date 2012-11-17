// Game.h: interface for the CGame class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAME_H__1843E0B1_B0F7_43AC_9147_C8A6EBED0C6A__INCLUDED_)
#define AFX_GAME_H__1843E0B1_B0F7_43AC_9147_C8A6EBED0C6A__INCLUDED_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Fish1.h"
#include "cv.h"
#include "highgui.h"
#include <iostream.h>
#include "Variable.h"

class CGame : public CVariable
{
public:
//	IplImage * m_FishLife;
	IplImage * m_allImage;
	int m_TotalScore;
	void totalscore();
	void drawscoreImage(int startx,int starty);
	IplImage * m_scoreImage[10];
	int count[6];
	int change[6];
	bool live[6];
	IplImage * m_fish[6];
	void drawfish(IplImage * bkImg,IplImage * m_pImg,int n);
	IplImage * m_form;
	void drawformImage(IplImage * bkImg,IplImage *m_pImg);
	int  eat(int n);
	void drawToBack(int n);
	void move(int n);
	void changeItem(int key);
	void Load();
	CFish m_Fish[6];
	CFish m_FirstFish;
	void drawImage();
	IplImage * m_ShowImage;
	IplImage * m_BKImage;
	void initialize();
	CGame();
	virtual ~CGame();

};


#endif // !defined(AFX_GAME_H__1843E0B1_B0F7_43AC_9147_C8A6EBED0C6A__INCLUDED_)
