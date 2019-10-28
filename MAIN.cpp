#include "graphics.h"		// 引用 EasyX 图形库
#include  "conio.h"
int main()
{
	initgraph(640, 480);
	circle(100, 100, 60);	// 画圆，圆心(100, 100)，半径 60
	_getch();				// 按任意键继续
	closegraph();			// 关闭图形界面
	return 1;
}