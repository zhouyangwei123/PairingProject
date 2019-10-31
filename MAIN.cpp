#include <conio.h>
#include <graphics.h>
#include <time.h>
#include "Model.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"


extern u16     px  ;
extern u16     py  ;             //飞行物位置
extern int     vx  ;             //速度横分量
extern int     vy  ;             //速度纵分量
extern int     g   ;             //重力加速度
extern int     ax  ;             //水平加速度
extern int     ay  ;             //垂直加速度
extern int     t   ;             //显示更新时间(ms)



int main()
{
	char s[25] = {0};
	int  mod_flag = 0;
	//********** 初始化图形窗口**********
	initgraph(640, 480);     //初始化面板
	setcolor(WHITE);
	line(160,0,160,480);
	line(480,0,480,480);
	line(160,240,480,240);
	rectangle(100,280,150,330);
	rectangle(30,350,80,400);
	rectangle(170,350,220,400);
	rectangle(100,420,150,470);

	mod_flag = choose_input();
	//***********************************
	while(1)
	{
		
		contral_input(mod_flag);
		update_speed();    //更新速度
		change_pos();      //位置改变
		show_pos();        //位置显示刷新
		Sleep(2);
		erase_pos();
		draw_board();

	}

	// 关闭图形窗口
	closegraph();
	return 0;
}




