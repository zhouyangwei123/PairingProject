#include <conio.h>
#include <graphics.h>
#include <time.h>
#include "Model.h"


extern u16    px  ;
extern u16    py  ;             //飞行物位置
extern u16    vx  ;             //速度横分量
extern u16    vy  ;             //速度纵分量
extern u16    g   ;             //重力加速度
extern u16    ax  ;             //水平加速度
extern u16    ay  ;             //垂直加速度
extern u16    t   ;             //显示更新时间(ms)



int main()
{
	//********** 初始化图形窗口**********
	initgraph(640, 480);     //初始化面板
	setcolor(WHITE	);
	line(160,0,160,480);
	line(480,0,480,480);
	line(160,240,480,240);
	//***********************************
	while(1)
	{

		update_speed(); //更新速度
		pos_change();      //位置改变
		show_pos();        //位置显示刷新
		Sleep(t*100);
		pos_erase();

	}

	// 关闭图形窗口
	closegraph();
	return 0;
}




