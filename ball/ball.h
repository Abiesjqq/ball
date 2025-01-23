#ifndef BALL_H
#define BALL_H

#include <windows.h>
#include <graphics.h>

#define PI 3.14
#define DENSITY 1
#define width 800
#define height 600
#define g 0.1
#define sleep_time 10

typedef struct {
	BYTE byRed;
	BYTE byGreen;
	BYTE byBlue;
}Color;

typedef struct ball {
	int x, y, radius;
	char text[10];
	Color color;
	double vx, vy;
	double mass;
}Ball;


void draw_ball(Ball* ball);
void judge_border(Ball* b);
void move_ball(Ball* b);
void move_all_balls(Ball* bs[], int cnt);
double distance(Ball b1, Ball b2);
void collide_balls(Ball* b1, Ball* b2);

#endif
