#pragma once
#include <graphics.h>

#define u16 unsigned int
#define u8 unsigned char
#define ref_time  10  //����ˢ��ʱ��
#define lim_time  15  //��Ϸʱ��

extern  IMAGE  img[10];

extern char    esc;
extern u16     px;
extern u16     py;            //������λ��
extern int     vx;            //�ٶȺ����
extern int     vy;            //�ٶ��ݷ���
extern int     g;             //�������ٶ�
extern int     ax;            //ˮƽ���ٶ�
extern int     ay;            //��ֱ���ٶ�
extern int     t;             //��ʾ����ʱ��(ms)
extern int     block_radius;  //�ϰ���뾶
extern int     contral_mod_flag; //����ģʽ��־, 1:��ꣻ2�����̣�3��esc
extern int     music_flag;    //���ֲ��ű�־ 1������ 0��ֹͣ
extern int     ch1 ;          //����������
extern int     win_flag;      //
extern int     limit_time;
