#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "math.h"
#include "Model.h"
#include "Painting.h"

u16    px = 30;
u16    py = 30;             //飞行物位置
int    vx = 0;              //速度横分量
int    vy = 0;              //速度纵分量
int    g = 0;               //重力加速度
int    speed_val = 1;       //单次操作速度改变
double k = 0.000001;        //阻力系数
int    t = 1;               //显示更新时间(ms)




//************************* 输入模式选择 *************************
int choose_input(void)
{
	int ch1 = 0;
	int ch2 = 0;
	char s1[] = "1 : press M -- mouse contral (click button)  ";
	char s2[] = "2 : press K -- keyboard contral (W A S D)";
	char s3[] = "         tip : press SPACE -- STOP ";
	outtextxy(190, 170, s1);
	outtextxy(190, 210, s2);
	outtextxy(190, 300, s3);
	while (1)
	{
		ch1 = _getch();
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
//***************************************************************

//**************** 控制模块，读取鼠标或者键盘输入 ***************
//                    鼠标左键点击按钮区域
//                     键盘使用 W A S D 
void contral_input(int flag)
{
	if (flag == 1)
	{
		//******* 支持esc退出，空格急停  *******
		if (_kbhit())                     
		{
			if (_getch() == 27)  esc=1;
			else if (_getch() == 32)
			{
				vx = 0;
				vy = 0;                          
			}
		}
		//**************************************

		if (MouseHit())//左键按下触发
		{
			MOUSEMSG m = GetMouseMsg();
			draw_button();
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
	//**************************** 键盘 ***************************
	else if (flag == 2)
	{

		if (_kbhit())                       //检测键盘有输入才进入判断，不影响运动流畅性
		{
			switch (_getch())
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
}
   //*****************************************************************




//************************* 擦除飞行物 *******************************
void erase_pos(void)
{
	setcolor(BLACK);
	//circle(px, py, radius);
	rectangle(px,py,px+10,py+10);
}
//********************************************************************

//***************  更新速度，如果超出10像素/帧则限速  ****************
void update_speed(void)
{
	if (vy >= -10 && vx >= -10 && vx <= 10 && vy <= 10)
	{
		;
	}
	else if(vx <= -10)
	
	{
		vx = -10;
		if (vy <= -10)
			vy = -10;
		else if (vy >= 10)
			vy = 10;
	}
	else if (vy <= -10)
	{
		vy = -10;
		if (vx <= -10)
			vx = -10;
		else if (vx >= 10)
			vx = 10;
	}

}
//********************************************************************

//************************ 按速度更新位置坐标 ************************
void change_pos(void)
{
	px += vx * t;
	py += vy * t;
}
//********************************************************************
