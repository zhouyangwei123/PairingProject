#include <conio.h>
#include <graphics.h>
#include <time.h>
#include "Model.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "resource1.h"
#include "painting.h"

IMAGE   img[10];
char esc = 0;
int  mod_flag = 0;            //控制模式标志



int main()
{


	//********** 初始化图形窗口**********
	panel_init();                 //面板初始化
	mod_flag = choose_input();    //控制模式选择

	//***********************************
	while(esc == 0)
	{
		contral_input(mod_flag);  //读取鼠标或键盘输入
		update_speed();           //更新速度
		change_pos();             //位置改变
		show_pos();               //位置显示刷新
		Sleep(20);
		erase_pos();              //擦除旧图片
		

	}
	// 关闭图形窗口，退出
	closegraph();
	return 0;
}









