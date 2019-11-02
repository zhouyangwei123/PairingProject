#include <conio.h>
#include <graphics.h>
#include <time.h>
#include "Model.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include"resource1.h"


extern u16     px  ;
extern u16     py  ;             //飞行物位置
extern int     vx  ;             //速度横分量
extern int     vy  ;             //速度纵分量
extern int     g   ;             //重力加速度
extern int     ax  ;             //水平加速度
extern int     ay  ;             //垂直加速度
extern int     t   ;             //显示更新时间(ms)
extern IMAGE   img;
void draw_button(void);

int main()
{
	char s[25] = {0};
	int  mod_flag = 0;
	
	
	
	//********** 初始化图形窗口**********
	initgraph(640, 480);     //初始化面板
	setcolor(WHITE);
	line(160,240,480,240);
	draw_button();
	//loadimage(&img, _T("C:\\Users\\Administrator\\Desktop\\software_engi\\Pairing_Project\\PairingProject\\img\\head.jpg"));
	loadimage( &img, _T("jpg"), MAKEINTRESOURCE(IDR_JPG1) );
	mod_flag = choose_input();

	//***********************************
	while(1)
	{
		draw_button();
		contral_input(mod_flag);
		update_speed();    //更新速度
		change_pos();      //位置改变
		show_pos();        //位置显示刷新
		Sleep(2);
		erase_pos();       //擦除旧图片
		draw_board();      //画面板
		

	}

	// 关闭图形窗口
	closegraph();
	return 0;
}


void draw_button(void)
{
	setcolor(WHITE);
	rectangle(100, 280, 150, 330);
	rectangle(30, 350, 80, 400);
	rectangle(170, 350, 220, 400);
	rectangle(100, 420, 150, 470);
}







