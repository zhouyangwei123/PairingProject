
//********************  ����������  *********************


//������     -- �Ż���ײ�����������ʱ��Ѫ����������Ч��·����⸴�ӻ���ģʽѡ�񣬣����ӵ��ߣ��Ѷ�ѡ�񣬸�����ͼ

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
int  contral_mod_flag = 0;            //����ģʽ��־



int main()
{
	
	while (1)
	{
		
		rand_p_block();                       //��ʼ������ϰ�������

		//********** ��ʼ��ͼ�δ���**********
		panel_init();                         //����ʼ��
		contral_mod_flag = choose_input();    //����ģʽѡ��

		//***********************************
		while (esc == 0)
		{
			contral_input(contral_mod_flag);  //��ȡ����������룬�ı��ٶ�
			limit_speed();                    //�������
			BeginBatchDraw();
			change_pos();                     //λ�øı�����
			countdown_timer();                //����ʱ��
			draw_pos();                       //λ����ʾˢ��
			draw_block_goal();                //�����ϰ�����յ�
			EndBatchDraw();                   //����������ͼ

			check_status();
			Sleep(ref_time);

		}
		// �ر�ͼ�δ��ڣ��˳�
		closegraph();
		music_pause();
	
	}
	return 0;
}








