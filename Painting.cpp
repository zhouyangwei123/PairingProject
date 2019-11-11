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

#define  block_radius   15//block半径

int goal_num = 1;    //终点个数
int block_num = 40;  //障碍物个数
int graph_X = 640;   //画布长
int graph_Y = 480;   //画布宽
int p_block[50][50];
int p_goal[10][10];
int win_flag;

//*********************  初始化背景板  **********************
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
	initgraph(graph_X, graph_Y);     //初始化画布
	setcolor(WHITE);
	line(160, 240, 480, 240);
	loadimage(&img[0], _T("jpg"), MAKEINTRESOURCE(IDR_JPG1));   //飞行物 img 0
	loadimage(&img[1], _T("jpg"), MAKEINTRESOURCE(IDR_JPG2));   //背景图 img 1
	loadimage(&img[2], _T("jpg"), MAKEINTRESOURCE(IDR_JPG3));   //障碍物 img 2
	loadimage(&img[3], _T("jpg"), MAKEINTRESOURCE(IDR_JPG4));   //按钮   img 3
	loadimage(&img[4], _T("jpg"), MAKEINTRESOURCE(IDR_JPG5));   //终点   img 4
	loadimage(&img[5], _T("jpg"), MAKEINTRESOURCE(IDR_JPG6));   //死亡   img 5
	loadimage(&img[6], _T("jpg"), MAKEINTRESOURCE(IDR_JPG7));   //到时   img 6
	draw_background();
}
//***********************************************************

//*********************  绘制面板  **************************
void draw_background(void)
{
	int px_block = 0;
	int py_block = 0;

	putimage(0,0,&img[1]);

	if (contral_mod_flag == 1)  //鼠标模式下画按键
		draw_button();
	else;
}
//***********************************************************

//**********************  绘制按钮  *************************
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

//***************  显示飞行物位置,判断触边界,碰到则停止  *****************
void draw_pos(void)
{
	draw_background();
	if ((py < 5) || (py > 475)) //碰到上下边界
	{
		vy = 0;
		win_flag = 0;
	}
	if ((px < 5) || (px > 635)) //碰到左右边界
	{
		vx = 0;
		win_flag = 0;
	}

	setcolor(GREEN);
	putimage(px - 15, py - 15, &img[0]);

}
//********************************************************************


//****************** 生成随机障碍物坐标存入数组  *********************
void rand_p_block(void)
{
	int i,j;
	do
	{
		srand((unsigned)time(NULL));
		for (i = 0; i < block_num; i++)
		{
			p_block[0][i] = { rand() % 16 + 3 };  
			p_block[1][i] = { rand() % 13 + 2 };
		}

		for (j = 0; j < goal_num; j++)
		{
			p_goal[0][j] = { 13 };
			p_goal[1][j] = { rand() % 8 + 2 };
		}

	} while (check_path());
}
//**********************************************************************

//*****************************  检测通路  *****************************
int check_path(void)
{
	int i;
	int count = 0;

	for (i = 0; i < block_num; i++)
	{
		if (p_block[0][i] == i + 3)      //如果同一列障碍物多于一半，则返回1，否则返回0
			count++;
		else
			;
		if (count >= block_num / 2)
			return 1;
		else                   
			return 0;
	}
	return 10;
}

//**********************************************************************

//*********************** 绘制地形方块 ************************
void draw_block_goal(void)
{
	int k;
	for (k = 0; k < block_num; k++)
	{
		put_a_block (p_block[0][k] * 30, p_block[1][k] * 30);
	}
	for (k = 0; k < goal_num; k++)
	{
		put_a_goal(600, p_goal[1][k] * 50);
	}

	for (k = 3; k < 20; k++)
	{
		put_a_block(k*30,15);
    }
	for (k = 3; k < 20; k++)
	{
		put_a_block(k * 30, 455);
	}
}


//**************  放置一个障碍物，并判断碰撞  **************
void put_a_block(int block_x, int block_y)
{
	int distance1_x, distance1_y;
	distance1_x = block_x - px;
	distance1_y = block_y - py;
	putimage(block_x - block_radius, block_y - block_radius, &img[2]);
	if ((distance1_x >= (-12 - block_radius ) ) && (distance1_x <= (12 + block_radius) ) && (distance1_y >= ( -12 - block_radius) ) && (distance1_y <= (12 + block_radius) ))
	{
		vx = 0;
		vy = 0;
		win_flag = 0;
	}
}

//***************  放置一个终点，并判断碰撞  ***************
void put_a_goal(int goal_x, int goal_y)
{
	int distance2_x, distance2_y;
	distance2_x = goal_x - px;
	distance2_y = goal_y - py;
	putimage(goal_x - 25, goal_y - 25, &img[4]);
	if (((distance2_x >= -40) && (distance2_x <= 40)) && ((distance2_y >= -40) && (distance2_y <= 40)))
	{
		vx = 0;
		vy = 0;
		win_flag = 1;
	}
}
//**********************************************************


//*******************  康康你死了冒  *****************
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