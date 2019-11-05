//#####################################################
//**************  以下为乱七八糟的函数  ***************
//#####################################################

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "math.h"
#include "Model.h"
#include "Painting.h"
#include "resource1.h"

int music_flag = 1;

//**************  清屏，gameover  ***************
void gameover(void)
{
	cleardevice();//清屏
	char s1[] = "BIG SISTER IS WATCHING U ";
	char s2[] = "     ~ ~  SLAY  ~ ~      ";
	outtextxy(220, 220, s1);
	outtextxy(250, 250, s2);
	Sleep(3000);
	cleardevice();//清屏
	esc = 1;

}
//***********************************************

void win(void)
{
	cleardevice();//清屏
	char s1[] = "You Won ~ but no reward ~";
	char s2[] = "     ~ ~  SLAY  ~ ~      ";
	outtextxy(220, 220, s1);
	outtextxy(250, 250, s2);
	Sleep(3000);
	cleardevice();//清屏
	esc = 1;
}
//***********************************************

//*******************  播放音乐/停止播放  *****************
void music_play(void)
{
		// 打开音乐
		mciSendString(_T("open Darkening.mp3 alias mymusic"), NULL, 0, NULL);
		mciSendString(_T("play mymusic"), NULL, 0, NULL);
}
void music_pause(void)
	{
		mciSendString(_T("stop mymusic"), NULL, 0, NULL);
		mciSendString(_T("close mymusic"), NULL, 0, NULL);
	}



//***********************************************************

void check_esc_music(void)
{
	//******* 支持esc退出，空格急停  *******
	if (_kbhit())
	{
		if (_getch() == 27)  esc = 1;
		else if (_getch() == 32)
		{
			vx = 0;
			vy = 0;
		}
		else if (_getch() == 112 || _getch() == 80)
		{
			music_flag = 0;
			music_pause();
		}
	}
}