#pragma once

#define u16 unsigned int
#define u8 unsigned char
#include <graphics.h>

extern  IMAGE  img[10];

extern char    esc;
extern u16     px;
extern u16     py;            //飞行物位置
extern int     vx;            //速度横分量
extern int     vy;            //速度纵分量
extern int     g;             //重力加速度
extern int     ax;            //水平加速度
extern int     ay;            //垂直加速度
extern int     t;             //显示更新时间(ms)
extern int     block_radius;  //障碍物半径
extern int     contral_mod_flag;      //控制模式标志
extern int     music_flag;    //音乐播放标志 1：播放 0：停止
extern int     ch1 ;          //键盘输入量
extern int     win_flag;      //康康你死了没
