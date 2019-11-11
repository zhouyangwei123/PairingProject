
//********************  待更新问题  *********************


//待更新     -- 优化碰撞体积，增加限时，血量，互动音效，路经检测复杂化，模式选择，，增加道具，难度选择，更新贴图

//*******************************************************


#include <conio.h>
#include <graphics.h>
#include <time.h>
#include "Model.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "resource1.h"
#include "painting.h"
#include "Mydefine.h"

#pragma comment(lib,"Winmm.lib")

IMAGE   img[10];
char    esc = 0;
int  contral_mod_flag = 0;            //控制模式标志



int main()
{
	
	while (1)
	{
		
		rand_p_block();                       //初始化随机障碍物坐标

		//********** 初始化图形窗口**********
		panel_init();                         //面板初始化
		contral_mod_flag = choose_input();    //控制模式选择

		//***********************************
		while (esc == 0)
		{
			contral_input(contral_mod_flag);  //读取鼠标或键盘输入，改变速度
			limit_speed();                    //检查限速
			BeginBatchDraw();
			change_pos();                     //位置改变坐标
			countdown_timer();                //倒计时器
			draw_pos();                       //位置显示刷新
			draw_block_goal();                //生成障碍物和终点
			EndBatchDraw();                   //结束批量绘图

			check_status();
			Sleep(ref_time);

		}
		// 关闭图形窗口，退出
		closegraph();
		music_pause();
	
	}
	return 0;
}








