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
int  mod_flag = 0;            //����ģʽ��־



int main()
{


	//********** ��ʼ��ͼ�δ���**********
	panel_init();                 //����ʼ��
	mod_flag = choose_input();    //����ģʽѡ��

	//***********************************
	while(esc == 0)
	{
		contral_input(mod_flag);  //��ȡ�����������
		update_speed();           //�����ٶ�
		change_pos();             //λ�øı�
		show_pos();               //λ����ʾˢ��
		Sleep(20);
		erase_pos();              //������ͼƬ
		

	}
	// �ر�ͼ�δ��ڣ��˳�
	closegraph();
	return 0;
}









