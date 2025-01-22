#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

int main() {
	int width = 800;
	int height = 600;
	int x = width / 2;
	int y = height / 4;
	int radius = 20;
	int vx = 0;
	int vy = 2;
	int g = 1;
	int sleep_time = 3;

	initgraph(width, height, 1); //初始化界面和小球位置
	fillcircle(x, y, radius);


	while (1) {
		vy += g; //y方向加速度
		x += vx;y += vy;

		if (y >= height - radius) { //检查边界
			y = height - radius;
			vy = -(vy + 1);
			printf("vy=%d\n", vy);
		}
		else if (y <= radius) {
			y = radius;
			vy = -(vy + 1);
		}
		if (x >= width - radius) {
			x = width - radius;
			vx = -(vx + 1);
		}
		else if (x <= radius) {
			x = radius;
			vx = -(vx + 1);
		}

		cleardevice(); //重新绘制小球
		fillcircle(x, y, radius);

		Sleep(sleep_time);

	}
	closegraph();
	return 0;
}