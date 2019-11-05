#pragma once

#define u16 unsigned int
#define u8 unsigned char

extern char    esc ;
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
extern int     music_flag ;    //���ֲ��ű�־ 1������ 0��ֹͣ

int   choose_input(void);
void  limit_speed(void);
void  change_pos(void);
void  contral_input(int);
void  music_play(void);
void  music_pause(void);
void  check_esc_music(void);

