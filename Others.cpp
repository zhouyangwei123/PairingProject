#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "math.h"
#include "Model.h"
#include "Painting.h"
#include "resource1.h"
#include "Mydefine.h"

int music_flag = 1;
int ch1 = 0;

//**************  清屏，gameover  ***************
void gameover(void)
{
	char s1[] = "BIG SISTER IS WATCHING U ";
	char s2[] = "     ~ ~  SLAY  ~ ~      ";

	cleardevice();//清屏
	outtextxy(220, 220, s1);
	outtextxy(250, 250, s2);
	Sleep(1000);
	while (check_esc_music() == 0 )  // 按任意键重开
	{
		;
	}
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
	Sleep(1000);
	while (check_esc_music() == 0 )  // 按任意键重开
	{
		;
	}
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


//*****************  按键扫描函数，若不为esc或P，返回按键值并更新 ch1 *****************
int check_esc_music(void)
{
	int ch2 = 0;
	//******* 支持esc退出，空格急停  *******
	if (_kbhit())
	{
		ch2 = _getch();
		if (ch2 == 27)  esc = 1;
		else if (ch2 == 32)
		{
			vx = 0;
			vy = 0;
		}
    //******* 若为 P或p 则播放/暂停背景音乐*******
		else if (ch2 == 112 || ch2 == 80)
		{
			if (music_flag)
			{
				music_flag = 0;
				music_pause();
			}
			else if (music_flag != 1)
			{
				music_flag = 1;
				music_play();
			}
		}
		else
			ch1 =  ch2;
			return ch2;
	}
	else return 0;
}
//***************************************************************************************