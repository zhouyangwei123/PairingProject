#include <graphics.h>
#include "math.h"
#include "Model.h"

u16      px = 100;
u16      py = 100;            //飞行物位置
float    vx = 0;              //速度横分量
float    vy = 0;              //速度纵分量
float    g = 6.5;             //重力加速度
float    ax = 0;              //水平加速度
float    ay = g;              //垂直加速度
u16      t = 2;            //显示更新时间(s)

//显示飞行物位置
void show_pos(void)
{
	setcolor(GREEN);
	circle(px,py,30);
	Sleep(t*1000);
	setcolor(BLACK);
	circle(px, py, 30);
}

//更新vx速度
void update_speed(void)
{
	vx = vx + ax * t;
	vy = vy + ay * t;
	
}


void pos_change(void)
{
	px += ax * t;
	py += ay * t;
}