#pragma once
#include <graphics.h>

extern IMAGE   img[10];

void panel_init(void); //��ʼ��������
void draw_background(void); //���������
void draw_button(void);//����ť
void draw_pos(void);
void erase_pos(void);
void put_a_block(int block_x, int block_y);
void put_a_goal(int, int);
void draw_block_goal(void);
void rand_p_block(void);
void gameover(void);
void win(void);
