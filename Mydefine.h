#pragma once

#define u16 unsigned int
#define u8 unsigned char
#include <graphics.h>

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
extern int     contral_mod_flag;      //����ģʽ��־
extern int     music_flag;    //���ֲ��ű�־ 1������ 0��ֹͣ
extern int     ch1 ;          //����������
extern int     win_flag;      //����������û
