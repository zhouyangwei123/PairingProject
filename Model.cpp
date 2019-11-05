//********************  待更新问题  *********************
// 随机生成部分，不可以封路
//
//*******************************************************

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "math.h"
#include "Model.h"
#include "Painting.h"
#include "Mydefine.h"

u16    px = 15;
u16    py = 15;             //飞行物位置
int    vx = 0;              //速度横分量
int    vy = 0;              //速度纵分量
int    g = 0;               //重力加速度
int    speed_val = 1;       //单次操作速度改变
double k = 0.000001;        //阻力系数
int    t = 1;               //显示更新时间(ms)



#define    speed_max   3      //最大限速



//************************* 输入模式选择 *************************
int choose_input(void)
{

	int ch2 = 0;
	char s1[] = "1 : press M -- mouse contral (click button)  ";
	char s2[] = "2 : press K -- keyboard contral (W A S D)";
	char s3[] = "        tip1: press SPACE -- STOP ";
	char s4[] = "        tip2: press P -- Pause Music ";
	outtextxy(190, 170, s1);
	outtextxy(190, 210, s2);
	outtextxy(190, 300, s3);
	outtextxy(190, 320, s4);
	while (1)
	{
		if (check_esc_music())
		{
			if (ch1 == 77 || ch1 == 109)    //if input M or m
			{
				cleardevice();//清屏
				return 1;
			}
			else if (ch1 == 75 || ch1 == 107) //if input K or k
			{
				cleardevice();//清屏
				return 2;
			}
			else if (ch1 == 27)
			{
				esc = 1;
				return 3;
			}
		
		}
	}
}
//***************************************************************

//**************** 控制模块，读取鼠标或者键盘输入 ***************
//                    鼠标左键点击按钮区域
//                     键盘使用 W A S D 
void contral_input(int flag)
{
	//*********************鼠标模式************************
	if (flag == 1)
	{
	check_esc_music();
		//**************************************

		if (MouseHit())//左键按下触发
		{
			MOUSEMSG m = GetMouseMsg();
		
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:

				if ((m.x > 100) && (m.x < 150) && (m.y < 330) && (m.y > 280))    //↑
				{
					vy -= speed_val;
				}
				if ((m.x > 100) && (m.x < 150) && (m.y > 440) && (m.y < 470))    //↓
				{
					vy += speed_val;
				}
				if ((m.x <= 220) && (m.x >= 170) && (m.y <= 400) && (m.y >= 350))//→
				{
					vx += speed_val;
				}
				if ((m.x <= 80) && (m.x >= 30) && (m.y <= 420) && (m.y >= 350))  //←
				{
					vx -= speed_val;
				}
				break;
			}
			FlushMouseMsgBuffer();
		}
	}
	//************************************************************* 

	//**************************** 键盘 ***************************
	else if (flag == 2)
	{
		
			switch (check_esc_music()) //检测键盘有输入才进入判断，不影响运动流畅性
			{
			case 27 : esc = 1 ;                     //esc退出
			case 119: vy -= speed_val; break;       //↑
			case 115: vy += speed_val; break;       //↓
			case 97 : vx -= speed_val; break;       //←
			case 100: vx += speed_val; break;       //→
			case 32 : 
				vx = 0;
				vy = 0;                             //急停
	
			} 
	
	}
}
   //*****************************************************************


//***************  更新速度，如果超出5像素/帧则限速  ****************
void limit_speed(void)
{
	if (vy >= -speed_max && vx >= -speed_max && vx <= speed_max && vy <= speed_max)
	{
		;
	}
    if(vx < - speed_max)
	{
		vx = -speed_max;	
	}

    if (vx > speed_max)
	{
		vx = speed_max;
	}

	if (vy < -speed_max)
	{
		vy = -speed_max;
	}

    if (vy > speed_max)
	{
		vy = speed_max;
	}

}
//********************************************************************

//************************ 按速度更新位置坐标 ************************
void change_pos(void)
{
	px += vx * t;
	py += vy * t;
}
//********************************************************************、

