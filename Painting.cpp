#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h> 
#include <time.h>
#include "math.h"
#include "Model.h"
#include "Painting.h"
#include "resource1.h"
#include "Mydefine.h"

int lim_time = 100;
int goal_num = 1;    //�յ����
int block_num = 100; //�ϰ������
int block_len = 30;  //�ϰ���߳�
int goal_len = 50;   //�յ�߳�
int graph_X = 800;   //������
int graph_Y = 800;   //������
int p_block[150][150];
int p_goal[10][10];
int win_flag;

//*********************  ��ʼ��������  **********************
void panel_init(void)
{

	int music_flag = 1;
	contral_mod_flag = 0;
	esc = 0;
	px = 30;
	py = 30;
	win_flag = 3;
	limit_time = lim_time;

	music_play();
	initgraph(graph_X, graph_Y);     //��ʼ������
	setcolor(WHITE);
	line(graph_X/4, graph_Y/2, graph_Y*3/4, graph_Y/2);
	loadimage(&img[0], _T("jpg"), MAKEINTRESOURCE(IDR_JPG1));   //������ img 0
	loadimage(&img[1], _T("jpg"), MAKEINTRESOURCE(IDR_JPG2));   //����ͼ img 1
	loadimage(&img[2], _T("jpg"), MAKEINTRESOURCE(IDR_JPG3));   //�ϰ��� img 2
	loadimage(&img[3], _T("jpg"), MAKEINTRESOURCE(IDR_JPG4));   //��ť   img 3
	loadimage(&img[4], _T("jpg"), MAKEINTRESOURCE(IDR_JPG5));   //�յ�   img 4
	loadimage(&img[5], _T("jpg"), MAKEINTRESOURCE(IDR_JPG6));   //����   img 5
	loadimage(&img[6], _T("jpg"), MAKEINTRESOURCE(IDR_JPG7));   //��ʱ   img 6
	loadimage(&img[7], _T("jpg"), MAKEINTRESOURCE(IDR_JPG8));   //��ʼ   img 7
	loadimage(&img[8], _T("jpg"), MAKEINTRESOURCE(IDR_JPG9));   //ʤ��   img 8

	draw_background();
}
//***********************************************************

//*********************  �������  **************************
void draw_background(void)
{


	if (contral_mod_flag == 1)  //���ģʽ�»�����
	{
		putimage(0, 0, &img[1]);
		draw_button();
	}
	else if(contral_mod_flag == 2)
	{
		putimage(0, 0, &img[1]);
	}
	else 
	{
		putimage(0, 0, &img[7]);
	}
}
//***********************************************************

//**********************  ���ư�ť  *************************  #######  ���ģ�����  #######
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
//***********************************************************

//***************  ��ʾ������λ��,�жϴ��߽�,������ֹͣ  *****************
void draw_pos(void)
{
	draw_background();
	if ((py < 5) || (py > graph_Y - 5 )) //�������±߽�
	{
		vy = 0;
		win_flag = 0;
	}
	if ((px < 5) || (px > graph_X - 5)) //�������ұ߽�
	{
		vx = 0;
		win_flag = 0;
	}

	setcolor(GREEN);
	putimage(px - 15, py - 15, &img[0]);

}
//********************************************************************


//****************** ��������ϰ��������������  *********************
void rand_p_block(void)
{
	int i,j;
	do
	{
		srand((unsigned)time(NULL));
		for (i = 0; i < block_num; i++)
		{
			p_block[0][i] = { rand() % (graph_X / block_len - 2) + 2 };  //���㵥��/�����귶Χ
			p_block[1][i] = { rand() % (graph_Y / block_len - 2) + 2 };
		}

		for (j = 0; j < goal_num; j++)
		{
			p_goal[0][j] = { graph_X / block_len - 2 };
			p_goal[1][j] = { rand() %  (graph_Y / block_len - 2)  + 2 };
		}

	} while (check_path());
}
//**********************************************************************

//*****************************  ���ͨ·  *****************************
int check_path(void)
{
	int i;
	int path_count = 0;

	for (i = 0; i < block_num; i++)
	{
		if (p_block[0][i] == i + 3)      //���ͬһ���ϰ������һ�룬�򷵻�1�����򷵻�0
			path_count++;
		else
			;
		if (path_count >= block_num / 2)
			return 1;
		else                   
			return 0;
	}
	return 10;
}

//**********************************************************************

//*********************** ���Ƶ��η��� ************************
void draw_block_goal(void)
{
	int k;
	for (k = 0; k < block_num; k++)
	{
		put_a_block (p_block[0][k] * block_len, p_block[1][k] * block_len);
	}
	for (k = 0; k < goal_num; k++)
	{
		put_a_goal( graph_Y - block_len, p_goal[1][k] * goal_len);
	}

	for (k = 2; k < graph_X / block_len  ; k++)                   //���ϱ߷�һ���ϰ�
	{
		put_a_block(k * block_len, block_len/2);  
    }
	for (k = 2; k < graph_X / block_len ; k++)                   //���±߷�һ���ϰ�
	{
		put_a_block(k * block_len, graph_Y - block_len/2);
	}
	countdown_timer();                //����ʱ��
}


//**************  ����һ���ϰ�����ж���ײ  **************
void put_a_block(int block_x, int block_y)
{
	int distance1_x, distance1_y;
	distance1_x = block_x - px;
	distance1_y = block_y - py;
	putimage(block_x - block_len / 2 , block_y - block_len / 2, &img[2]);
	if (
		(distance1_x >= (-12 - block_len / 2) ) &&
		(distance1_x <= ( 12 + block_len / 2) ) && 
		(distance1_y >= (-12 - block_len / 2) ) &&
		(distance1_y <= ( 12 + block_len / 2) )
		)
	{
		vx = 0;
		vy = 0;
		win_flag = 0;
	}
}

//***************  ����һ���յ㣬���ж���ײ  ***************
void put_a_goal(int goal_x, int goal_y)
{
	int distance2_x, distance2_y;
	distance2_x = goal_x - px;
	distance2_y = goal_y - py;
	putimage(goal_x - goal_len / 2 , goal_y - goal_len / 2 , &img[4]);
	//**************  �ж���ײ  *****************
	if (
		 ((distance2_x >= - (goal_len - 10)) && ( distance2_x <= goal_len - 10 ) ) &&
		 ((distance2_y >= - (goal_len - 10)) && ( distance2_y <= goal_len - 10 ) ) 
		)
	{
		vx = 0;
		vy = 0;
		win_flag = 1;
	}
}
//**********************************************************


//*******************  �����Ϸ����  *****************
void check_status(void)
{
	if (win_flag == 0)
		gameover();
	else if (win_flag == 1)
		win();
	else
		;
}
//*****************************************************