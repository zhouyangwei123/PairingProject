#include <conio.h>
#include <graphics.h>
#include <time.h>
#include "Model.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"


extern u16     px  ;
extern u16     py  ;             //������λ��
extern int     vx  ;             //�ٶȺ����
extern int     vy  ;             //�ٶ��ݷ���
extern int     g   ;             //�������ٶ�
extern int     ax  ;             //ˮƽ���ٶ�
extern int     ay  ;             //��ֱ���ٶ�
extern int     t   ;             //��ʾ����ʱ��(ms)



int main()
{
	char s[25] = {0};
	int  mod_flag = 0;
	//********** ��ʼ��ͼ�δ���**********
	initgraph(640, 480);     //��ʼ�����
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
		update_speed();    //�����ٶ�
		change_pos();      //λ�øı�
		show_pos();        //λ����ʾˢ��
		Sleep(2);
		erase_pos();
		draw_board();

	}

	// �ر�ͼ�δ���
	closegraph();
	return 0;
}




