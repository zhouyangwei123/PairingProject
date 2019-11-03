#pragma once

#define u16 unsigned int
#define u8 unsigned char

extern char esc ;
extern u16     px;
extern u16     py;             //飞行物位置
extern int     vx;             //速度横分量
extern int     vy;             //速度纵分量
extern int     g;             //重力加速度
extern int     ax;             //水平加速度
extern int     ay;             //垂直加速度
extern int     t;             //显示更新时间(ms)
extern int     radius;        //半径


int   choose_input(void);
void  show_pos(void);
void  update_speed (void);
void  change_pos(void);
void  erase_pos(void);
void contral_input(int);

