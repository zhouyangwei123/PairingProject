#include <conio.h>
#include <graphics.h>
#include <time.h>
#include "Model.h"


extern u16    px  ;
extern u16    py  ;             //������λ��
extern u16    vx  ;             //�ٶȺ����
extern u16    vy  ;             //�ٶ��ݷ���
extern u16    g   ;             //�������ٶ�
extern u16    ax  ;             //ˮƽ���ٶ�
extern u16    ay  ;             //��ֱ���ٶ�
extern u16    t   ;             //��ʾ����ʱ��(ms)



int main()
{
	//********** ��ʼ��ͼ�δ���**********
	initgraph(640, 480);     //��ʼ�����
	setcolor(WHITE	);
	line(160,0,160,480);
	line(480,0,480,480);
	line(160,240,480,240);
	//***********************************
	while(1)
	{

		update_speed(); //�����ٶ�
		pos_change();      //λ�øı�
		show_pos();        //λ����ʾˢ��
		Sleep(t*100);
		pos_erase();

	}

	// �ر�ͼ�δ���
	closegraph();
	return 0;
}




