#include <conio.h>
#include <graphics.h>
#include <time.h>
#include "Model.h"


extern u16      px  ;
extern u16      py  ;             //������λ��
extern float    vx  ;             //�ٶȺ����
extern float    vy  ;             //�ٶ��ݷ���
extern float    g   ;             //�������ٶ�
extern float    ax  ;             //ˮƽ���ٶ�
extern float    ay  ;             //��ֱ���ٶ�
extern u16      t   ;             //��ʾ����ʱ��(ms)



int main()
{
	//********** ��ʼ��ͼ�δ���**********
	initgraph(640, 480);     //��ʼ�����
	//***********************************
	while(1)
	{

		update_speed(); //�����ٶ�
		pos_change();      //λ�øı�
		show_pos();        //λ����ʾˢ��
	;

	}

	// �ر�ͼ�δ���
	closegraph();
	return 0;
}




