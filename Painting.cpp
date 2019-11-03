#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "math.h"
#include "Model.h"
#include "Painting.h"
#include "resource1.h"


int graph_X = 640;   //������
int graph_Y = 480;   //������

//*********************��ʼ��������**********************
void panel_init(void)
{
	initgraph(graph_X, graph_Y);     //��ʼ������
	setcolor(WHITE);
	line(160, 240, 480, 240);
	//draw_button();
	loadimage(&img, _T("jpg"), MAKEINTRESOURCE(IDR_JPG1));
}
//*******************************************************

//*********************�������**************************
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

//**********************���ư�ť*************************
void draw_button(void)
{
	setcolor(WHITE);
	rectangle(100, 280, 150, 330);
	rectangle(30, 350, 80, 400);
	rectangle(170, 350, 220, 400);
	rectangle(100, 420, 150, 470);
}
//*******************************************************
