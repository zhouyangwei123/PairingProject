#pragma once

#define u16 unsigned int
#define u8 unsigned char

extern char esc ;
extern u16     px;
extern u16     py;            //������λ��
extern int     vx;            //�ٶȺ����
extern int     vy;            //�ٶ��ݷ���
extern int     g;             //�������ٶ�
extern int     ax;            //ˮƽ���ٶ�
extern int     ay;            //��ֱ���ٶ�
extern int     t;             //��ʾ����ʱ��(ms)
extern int     radius;        //�뾶
extern int     mod_flag ;     //����ģʽ��־

int   choose_input(void);
void  limit_speed(void);
void  change_pos(void);
void  contral_input(int);

