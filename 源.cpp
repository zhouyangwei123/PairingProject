#include "graphics.h"		// ���� EasyX ͼ�ο�
#include  "conio.h"
int main()
{
	initgraph(640, 480);
	circle(100, 100, 60);	// ��Բ��Բ��(100, 100)���뾶 60
	_getch();				// �����������
	closegraph();			// �ر�ͼ�ν���
	return 1;
}