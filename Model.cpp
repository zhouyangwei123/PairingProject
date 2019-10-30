#include <graphics.h>
#include "math.h"
#include "Model.h"
#include<stdio.h>
#include <conio.h>

u16    px = 100;
u16    py = 100;            //飞行物位置
int    vx = 0;              //速度横分量
int    vy = 1;              //速度纵分量
int    g = 0;              //重力加速度
int    ax = 0;              //水平阻力
int    ay = 0;              //垂直阻力
int    t = 2;              //显示更新时间(s)
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
void pos_erase(void)
{
	setcolor(BLACK);
	circle(px, py, radius);
}

//更新速度，如果超出5像素/帧则停止
void update_speed(void)
{
	if ( vy>= -5 && vx>= -5 && vx <= 5  && vy <= 5) 
	{
		vx = vx - ax * t;
		vy = vy - ay * t;
	}
	else
	{
		vx = 0;
		vy = 0;
	}
}

//按速度更新位置坐标
void pos_change(void)
{
	px += vx * t;
	py += vy * t;
}

//输入模式选择
int choose_input(void)
{
	int ch1 = 0;
	int ch2 = 0;
	char s[] = "press M start mouse contral ";
	outtextxy(240, 200, s);
	
	while (1)
	{
		ch1 = _getch();
		if (ch1 == 77 || ch1 == 109)
		{
			clearrectangle(230,250,300,250);
			return 1;
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

				if ((m.x > 160) && (m.x < 480) && (m.y < 240) && (m.y > 0))
				{
					vy -= 1;
				}
				if ((m.x > 160) && (m.x < 480) && (m.y > 240) && (m.y < 480))
				{
					vy += 1;
				}
				if ((m.x <= 640) && (m.x >= 480) && (m.y <= 480) && (m.y >= 0))
				{
					vx += 1;
				}
				if ((m.x <= 160) && (m.x >= 0) && (m.y <= 480) && (m.y >= 0))
				{
					vx -= 1;
				}
				break;
			}
			FlushMouseMsgBuffer();
		}
	}
	else if (flag == 2)
	{

	}
}