#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "math.h"
#include "Model.h"
#include "Painting.h"
#include "resource1.h"


int graph_X = 640;   //画布长
int graph_Y = 480;   //画布宽

//*********************初始化背景板**********************
void panel_init(void)
{
	initgraph(graph_X, graph_Y);     //初始化画布
	setcolor(WHITE);
	line(160, 240, 480, 240);
	//draw_button();
	loadimage(&img, _T("jpg"), MAKEINTRESOURCE(IDR_JPG1));
}
//*******************************************************

//*********************绘制面板**************************
void draw_panel(void)
{
	line(160, 0, 160, 480);
	line(480, 0, 480, 480);
	line(160, 240, 480, 240);
	rectangle(100, 280, 150, 330);
	rectangle(30, 350, 80, 400);
	rectangle(170, 350, 220, 400);
	rectangle(100, 420, 150, 470);
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
