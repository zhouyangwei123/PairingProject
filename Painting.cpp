#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "math.h"
#include "Model.h"
#include "Painting.h"
#include "resource1.h"


int graph_X = 640;   //画布长
int graph_Y = 480;   //画布宽
int radius = 10;     //碰撞半径

//*********************初始化背景板**********************
void panel_init(void)
{
	initgraph(graph_X, graph_Y);     //初始化画布
	setcolor(WHITE);
	line(160, 240, 480, 240);
	loadimage(&img[0], _T("jpg"), MAKEINTRESOURCE(IDR_JPG1));
	loadimage(&img[1], _T("jpg"), MAKEINTRESOURCE(IDR_JPG2));
	draw_background();
}
//*******************************************************

//*********************绘制面板**************************
void draw_background(void)
{
	putimage(0,0,&img[1]);
}
//*******************************************************

//**********************绘制按钮*************************
void draw_button(void)
{

	setcolor(WHITE);
	rectangle(100, 280, 150, 330);
	rectangle(30, 350, 80, 400);
	rectangle(170, 350, 220, 400);
	rectangle(100, 420, 150, 470);
}
//*******************************************************

//***************显示飞行物位置,判断触边界,碰到则停止*****************
void show_pos(void)
{
	draw_background();
	if ((py < 5) || (py > 475)) //碰到上下边界
	{
		vy = 0;
	}
	if ((px < 5) || (px > 635)) //碰到左右边界
	{
		vx = 0;
	}

	setcolor(GREEN);
	putimage(px - 10, py - 10, &img[0]);
	circle(px, py, radius);      //刷新显示
}
//********************************************************************