#include <graphics.h>
#include "math.h"
#include "Model.h"

u16    px = 100;
u16    py = 100;            //飞行物位置
u16    vx = 0;              //速度横分量
u16    vy = 0;              //速度纵分量
u16    g = 6;              //重力加速度
u16    ax = 0;              //水平加速度
u16    ay = g;              //垂直加速度
u16    t = 2;              //显示更新时间(s)

//显示飞行物位置
void show_pos(void)
{
	if ((px >= 30) && (py >= 30) && (px <= 610) && (py <= 450))
	{
		;
	}
	else if (px < 30)
	{
		px = 30;
	}
	else if (px > 610)
	{
		px = 610;
	}
	else if (py < 30)
	{
		py = 30;
	}
	else if (py > 450)
	{
		px = 450;
	}
	setcolor(GREEN);
	circle(px, py, 30);


}
//擦除飞行物
void pos_erase(void)
{
	setcolor(BLACK);
	circle(px, py, 30);
}

//更新vx速度
void update_speed(void)
{
	vx = vx + ax * t;
	vy = vy + ay * t;

}

//按加速度更新位置坐标
void pos_change(void)
{
	px += ax * t;
	py += ay * t;
}

//根据输入改变加速度
void F_input(void)
{
	MOUSEMSG m = GetMouseMsg();
	if ((m.x > 160) && (m.x < 480) && (m.y < 240) && (m.y > 0))
	{
		ax += -10;
	}
	else if ((m.x > 160) && (m.x < 480) && (m.y >= 240) && (m.y <= 480))
	{
		ax += 10;
	}
	else if ((m.x <= 160) && (m.x >= 0) && (m.y <= 480))
	{
		ay += -10;
	}
	else if ((m.x <= 160) && (m.x >= 0) && (m.y <= 480))
	{
		ay += 10;
	}
	else
		;

}