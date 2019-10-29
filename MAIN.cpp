#include <conio.h>
#include <graphics.h>
#include <time.h>
#include "Model.h"


extern u16      px  ;
extern u16      py  ;             //飞行物位置
extern float    vx  ;             //速度横分量
extern float    vy  ;             //速度纵分量
extern float    g   ;             //重力加速度
extern float    ax  ;             //水平加速度
extern float    ay  ;             //垂直加速度
extern u16      t   ;             //显示更新时间(ms)



int main()
{
	//********** 初始化图形窗口**********
	initgraph(640, 480);     //初始化面板
	//***********************************
	while(1)
	{

		update_speed(); //更新速度
		pos_change();      //位置改变
		show_pos();        //位置显示刷新
	;

	}

	// 关闭图形窗口
	closegraph();
	return 0;
}




