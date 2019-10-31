#include <graphics.h>
#include "math.h"
#include "Model.h"
#include<stdio.h>
#include <conio.h>

u16    px = 100;
u16    py = 100;            //飞行物位置
int    vx = 0;              //速度横分量
int    vy = 0;              //速度纵分量
int     g = 0;              //重力加速度
int    speed_val = 1;             //单次操作速度改变
double  k = 0.000001;              //阻力系数
int    t = 1;              //显示更新时间(ms)
u16    radius = 10;

//显示飞行物位置,判断触边界
void show_pos(void)
{
	
    if(( py<10 ) || ( py>470 )) //碰到上下边界
	{
		vy = 0;
	}
    if ((px < 10) || (px > 630)) //碰到左右边界
	{
		vx = 0;
	}
	
	setcolor(GREEN);
	circle(px, py, radius);      //刷新显示


}
//擦除飞行物
void erase_pos(void)
{
	setcolor(BLACK);
	circle(px, py, radius);
}

//更新速度，如果超出5像素/帧则停止
void update_speed(void)
{
	if (vy >= -10 && vx >= -10 && vx <= 10 && vy <= 10)
	{

		/*
		if (vx >= 0)
		{
			vx -= vx * k;
		}
		else if (vx < 0)
		{
			vx += vx * k;
		}
		if (vy >= 0)
		{
			vy -= vy * k;
		}
		else if (vy < 0)
		{
			vy += vy * k;
		}
		*/

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

//按速度更新位置坐标
void change_pos(void)
{
	px += vx * t;
	py += vy * t;
}

//输入模式选择
int choose_input(void)
{
	int ch1 = 0;
	int ch2 = 0;
	char s1[] = "press M choose mouse contral ";
	char s2[] = "press K choose keyboard contral";
	outtextxy(240, 200, s1);
	outtextxy(230, 260, s2);
	
	while (1)
	{
		ch1 = _getch();
		if (ch1 == 77 || ch1 == 109)    //if input M or m
		{
			clearrectangle(230,250,300,250);
			return 1;
		}
		else if(ch1 == 75|| ch1 == 107 ) //if input K or k
		{
			clearrectangle(230, 250, 300, 250);
			return 2;
		}
	}
}

//控制模块
void contral_input(int flag)
{
	if (flag == 1)
	{
		if (MouseHit())
		{
			MOUSEMSG m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN://左键按下触发

				if ((m.x > 100) && (m.x < 150) && (m.y < 330) && (m.y > 280))    //↑
				{
					vy -= speed_val;
				}
				if ((m.x > 100) && (m.x < 150) && (m.y > 440) && (m.y < 470))  //↓
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
	else if (flag == 2)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 119: vy -= speed_val; break;
			case 115: vy += speed_val; break;
			case 97: vx -= speed_val; break;
			case 100: vx += speed_val; break;
			}
		}
	}
}

void draw_board(void)
{line(160, 0, 160, 480);
	line(480, 0, 480, 480);
	line(160, 240, 480, 240);	rectangle(100, 280, 150, 330);
	rectangle(30, 350, 80, 400);
	rectangle(170, 350, 220, 400);
	rectangle(100, 420, 150, 470);
}