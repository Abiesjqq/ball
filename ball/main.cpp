#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include "ball.h"


int main() {
	initgraph(width, height, 1); //初始化界面

	int ball_count = 6;
	Ball ball1 = { width / 3,height / 5,40,"hhh",{232,211,192} };//初始化小球
	draw_ball(&ball1);	
	Ball ball2 = { width / 2,height / 4,40,"hhh",{207,195,169} };
	draw_ball(&ball2);
	Ball ball3 = { width / 3,height / 3,40,"hhh",{132,155,145} };
	draw_ball(&ball3);
	Ball ball4 = { width / 2,height / 2,40,"hhh",{194,206,182} };
	draw_ball(&ball4);
	Ball ball5 = { width / 7,height / 4,40,"hhh",{181,124,130} };
	draw_ball(&ball5);
	Ball ball6 = { width / 4,height / 3,40,"hhh",{136,135,141} };
	draw_ball(&ball6);
	Ball* balls[] = { &ball1,&ball2,&ball3,&ball4,&ball5,&ball6 };

	srand((unsigned)time(NULL));
	for (int i = 0;i < ball_count;i++) { //随机生成速度
		balls[i]->vx = (rand() / (double)RAND_MAX) * 20 - 10;
		balls[i]->vy = (rand() / (double)RAND_MAX) * 20 - 10;
	}

	while (1) {
		move_all_balls(balls, ball_count);
	}

	closegraph();
	return 0;
}


