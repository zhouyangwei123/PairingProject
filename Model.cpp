#include <graphics.h>
#include "math.h"
#include "Model.h"

u16      px = 100;
u16      py = 100;            //������λ��
float    vx = 0;              //�ٶȺ����
float    vy = 0;              //�ٶ��ݷ���
float    g = 6.5;             //�������ٶ�
float    ax = 0;              //ˮƽ���ٶ�
float    ay = g;              //��ֱ���ٶ�
u16      t = 2;            //��ʾ����ʱ��(s)

//��ʾ������λ��
void show_pos(void)
{
	setcolor(GREEN);
	circle(px,py,30);
	Sleep(t*1000);
	setcolor(BLACK);
	circle(px, py, 30);
}

//����vx�ٶ�
void update_speed(void)
{
	vx = vx + ax * t;
	vy = vy + ay * t;
	
}


void pos_change(void)
{
	px += ax * t;
	py += ay * t;
}