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

//**************  清屏，gameover  ***************
void gameover(void)
{
	cleardevice();//清屏
	char s1[] = "BIG SISTER IS WATCHING U ";
	char s2[] = "     ~ ~  SLAY  ~ ~      ";
	outtextxy(220, 220, s1);
	outtextxy(250, 250, s2);
	while (getchar())
	{
		;
	}
}
//***********************************************

void win(void)
{
	cleardevice();//清屏
	char s1[] = "Sor ~ Not yet completed ~";
	char s2[] = "     ~ ~  SLAY  ~ ~      ";
	outtextxy(220, 220, s1);
	outtextxy(250, 250, s2);
	while (getchar())
	{
		;
	}
}