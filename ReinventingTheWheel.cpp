//#####################################################
//**************  ����Ϊ���߰���ĺ���  ***************
//#####################################################

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "math.h"
#include "Model.h"
#include "Painting.h"
#include "resource1.h"

//**************  ������gameover  ***************
void gameover(void)
{
	cleardevice();//����
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
	cleardevice();//����
	char s1[] = "Sor ~ Not yet completed ~";
	char s2[] = "     ~ ~  SLAY  ~ ~      ";
	outtextxy(220, 220, s1);
	outtextxy(250, 250, s2);
	while (getchar())
	{
		;
	}
}