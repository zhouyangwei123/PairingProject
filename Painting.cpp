#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "math.h"
#include "Model.h"
#include "Painting.h"
#include "resource1.h"


int graph_X = 640;   //������
int graph_Y = 480;   //������
int radius = 10;     //��ײ�뾶

//*********************��ʼ��������**********************
void panel_init(void)
{
	initgraph(graph_X, graph_Y);     //��ʼ������
	setcolor(WHITE);
	line(160, 240, 480, 240);
	loadimage(&img[0], _T("jpg"), MAKEINTRESOURCE(IDR_JPG1));
	loadimage(&img[1], _T("jpg"), MAKEINTRESOURCE(IDR_JPG2));
	draw_background();
}
//*******************************************************

//*********************�������**************************
void draw_background(void)
{
	putimage(0,0,&img[1]);
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

//***************��ʾ������λ��,�жϴ��߽�,������ֹͣ*****************
void show_pos(void)
{
	draw_background();
	if ((py < 5) || (py > 475)) //�������±߽�
	{
		vy = 0;
	}
	if ((px < 5) || (px > 635)) //�������ұ߽�
	{
		vx = 0;
	}

	setcolor(GREEN);
	putimage(px - 10, py - 10, &img[0]);
	circle(px, py, radius);      //ˢ����ʾ
}
//********************************************************************