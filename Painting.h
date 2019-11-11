#pragma once

// ÉùÃ÷»æÍ¼º¯Êý


void panel_init(void); //³õÊ¼»¯±³¾°°å
void draw_background(void); //±³¾°°å»æÖÆ
void draw_button(void);//»­°´Å¥
void draw_pos(void);
void put_a_block(int block_x, int block_y);
void put_a_goal(int, int);
void draw_block_goal(void);
void rand_p_block(void);
int  check_path(void);
void countdown_timer(void);
