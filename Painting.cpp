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
	loadimage(&img[0], _T("jpg"), MAKEINTRESOURCE(IDR_JPG1));   //������ img 0
	loadimage(&img[1], _T("jpg"), MAKEINTRESOURCE(IDR_JPG2));   //����ͼ img 1
	loadimage(&img[2], _T("jpg"), MAKEINTRESOURCE(IDR_JPG3));   //�ϰ��� img 2
	loadimage(&img[3], _T("jpg"), MAKEINTRESOURCE(IDR_JPG4));   //��ť   img 3
	draw_background();
}
//*******************************************************

//*********************�������**************************
void draw_background(void)
{
	int i;
	int px_block = 0;
	int py_block = 0;
	putimage(0,0,&img[1]);
	if(mod_flag == 1)
		draw_button();
	for (i = 0; i < 15; i++)
	{
		putimage(px_block + i * 50, py_block , &img[2] );
	}
}
//*******************************************************

//**********************���ư�ť*************************
void draw_button(void)
{

	setcolor(WHITE);
	rectangle(100, 280, 150, 330);
	putimage(100, 280, &img[3]);

	rectangle(30, 350, 80, 400);
	putimage(30, 350, &img[3]);

	rectangle(170, 350, 220, 400);
	putimage(170, 350, &img[3]);

	rectangle(100, 420, 150, 470);
	putimage(100, 420, &img[3]);

}
//*******************************************************

//***************��ʾ������λ��,�жϴ��߽�,������ֹͣ*****************
void draw_pos(void)
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

//************************* ���������� *******************************
void erase_pos(void)
{
	setcolor(BLACK);
	//circle(px, py, radius);
	rectangle(px, py, px + 10, py + 10);
}
//********************************************************************