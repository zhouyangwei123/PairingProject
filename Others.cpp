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

//**************  ������gameover  ***************
void gameover(void)
{
	char s1[] = "BIG SISTER IS WATCHING U ";
	char s2[] = "     ~ ~  SLAY  ~ ~      ";

	cleardevice();//����
	outtextxy(220, 220, s1);
	outtextxy(250, 250, s2);
	Sleep(1000);
	while (check_esc_music() == 0 )  // ��������ؿ�
	{
		;
	}
	cleardevice();//����
	esc = 1;

}
//***********************************************

void win(void)
{
	cleardevice();//����
	char s1[] = "You Won ~ but no reward ~";
	char s2[] = "     ~ ~  SLAY  ~ ~      ";
	outtextxy(220, 220, s1);
	outtextxy(250, 250, s2);
	Sleep(1000);
	while (check_esc_music() == 0 )  // ��������ؿ�
	{
		;
	}
	cleardevice();//����
	esc = 1;
}
//***********************************************

//*******************  ��������/ֹͣ����  *****************
void music_play(void)
{
		// ������
		mciSendString(_T("open Darkening.mp3 alias mymusic"), NULL, 0, NULL);
		mciSendString(_T("play mymusic"), NULL, 0, NULL);
}
void music_pause(void)
	{
		mciSendString(_T("stop mymusic"), NULL, 0, NULL);
		mciSendString(_T("close mymusic"), NULL, 0, NULL);
	}



//***********************************************************


//*****************  ����ɨ�躯��������Ϊesc��P�����ذ���ֵ������ ch1 *****************
int check_esc_music(void)
{
	int ch2 = 0;
	//******* ֧��esc�˳����ո�ͣ  *******
	if (_kbhit())
	{
		ch2 = _getch();
		if (ch2 == 27)  esc = 1;
		else if (ch2 == 32)
		{
			vx = 0;
			vy = 0;
		}
    //******* ��Ϊ P��p �򲥷�/��ͣ��������*******
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