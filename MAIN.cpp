#include <conio.h>
#include <graphics.h>
#include <time.h>
#include "Model.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include"resource1.h"


extern u16     px  ;
extern u16     py  ;             //������λ��
extern int     vx  ;             //�ٶȺ����
extern int     vy  ;             //�ٶ��ݷ���
extern int     g   ;             //�������ٶ�
extern int     ax  ;             //ˮƽ���ٶ�
extern int     ay  ;             //��ֱ���ٶ�
extern int     t   ;             //��ʾ����ʱ��(ms)
extern IMAGE   img;
void draw_button(void);

int main()
{
	char s[25] = {0};
	int  mod_flag = 0;
	
	
	
	//********** ��ʼ��ͼ�δ���**********
	initgraph(640, 480);     //��ʼ�����
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
		update_speed();    //�����ٶ�
		change_pos();      //λ�øı�
		show_pos();        //λ����ʾˢ��
		Sleep(2);
		erase_pos();       //������ͼƬ
		draw_board();      //�����
		

	}

	// �ر�ͼ�δ���
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







