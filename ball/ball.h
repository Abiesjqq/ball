#ifndef BALL_H
#define BALL_H

#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

const double PI = 3.14;
const int DENSITY = 1;
const int width = 800;
const int height = 600;
const int g = 0;
int vx = 5;
int vy = 7;
int radius = 40;
int sleep_time = 6;


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
