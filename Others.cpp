#include<windows.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "math.h"
#include "Model.h"
#include "Painting.h"
#include "resource1.h"
#include "Mydefine.h"
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;/*不要忘了写这句话*/

int  music_flag = 1;
int  ch1 = 0;
extern char esc;                  
 int  limit_time  ;        // second
int  refresh_counter = 0;  //单帧刷新数器

//**************  清屏，gameover  ***************
void gameover(void)
{
	char s1[] = "BIG SISTER IS WATCHING U ";
	char s2[] = "     ~ ~  SLAY  ~ ~      ";
	char s3[] = "  -- IT'S HIGH NOON --   ";

	cleardevice();//清屏
	if (refresh_counter == 0)
	{
		putimage (260, 100, &img[6]); // 到时提示
		outtextxy(250, 260, s3);
		outtextxy(260, 290, s2);
	}
	else 
	{
		putimage (260, 100, &img[5]);// 死亡提示
		outtextxy(230, 260, s1);
		outtextxy(260, 290, s2);
	}
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
	char s1[] = "       You Are Free      ";
	char s2[] = "     (Just Temporary)    ";
	putimage(160, 105, &img[8]); //胜利提示
	outtextxy(250, 65, s1);
	outtextxy(250, 85, s2);
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
	   PlaySound(LPCSTR(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
}
void music_pause(void)
	{
	PlaySound(NULL, NULL, SND_FILENAME);
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

//***************  倒计时器  ********************
void countdown_timer(void)
{
	char s[10] = { 0 };
	sprintf_s(s, _T("%d"), limit_time);
	settextcolor(RED);
	outtextxy(20, 400, s);
	refresh_counter++;
	if ((refresh_counter * ref_time) >= 1000) //刷新次数 * 单次刷新时间 >= 1s 
	{
		refresh_counter = 0;
		if (--limit_time == 0)
			win_flag = 0;
		else
			;
	}
	else
		;
}