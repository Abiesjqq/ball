#include "ball.h"

//����
void draw_ball(Ball* ball) {
	ball->mass = 3.0 / 4 * PI * pow(ball->radius, 3) * DENSITY;
	setfillcolor(RGB(ball->color.byRed, ball->color.byGreen, ball->color.byBlue));
	setlinecolor(BLACK);
	fillcircle(ball->x, ball->y, ball->radius);
}

//���߽�
void judge_border(Ball* b) {
	if (b->y >= height - b->radius) { //�±߽�
		b->y = height - b->radius;
		b->vy = -(b->vy + 1);
	}
	else if (b->y <= b->radius) { //�ϱ߽�
		b->y = b->radius;
		b->vy = -(b->vy + 1);
	}
	if (b->x >= width - b->radius) { //�ұ߽�
		b->x = width - b->radius;
		b->vx = -(b->vx + 1);
	}
	else if (b->x <= b->radius) { //��߽�
		b->x = b->radius;
		b->vx = -(b->vx + 1);
	}
}

//���ļ����
double distance(Ball b1, Ball b2) {
	return sqrt((b1.x - b2.x) * (b1.x - b2.x) + (b1.y - b2.y) * (b1.y - b2.y));
}

//������ײ
void collide_balls(Ball* b1, Ball* b2) {
	if (distance(*b1, *b2) > b1->radius + b2->radius) return;

	double new_vx1 = ((b1->mass - b2->mass) * b1->vx + 2 * b2->mass * b2->vx) / (b1->mass + b2->mass); //��ȫ������ײ���ٶ�
	double new_vy1 = ((b1->mass - b2->mass) * b1->vy + 2 * b2->mass * b2->vy) / (b1->mass + b2->mass);
	double new_vx2 = ((b2->mass - b1->mass) * b2->vx + 2 * b1->mass * b1->vx) / (b1->mass + b2->mass);
	double new_vy2 = ((b2->mass - b1->mass) * b2->vy + 2 * b1->mass * b1->vy) / (b1->mass + b2->mass);

	b1->vx = new_vx1;
	b1->vy = new_vy1;
	b2->vx = new_vx2;
	b2->vy = new_vy2;

	double overlap = (b1->radius + b2->radius) - distance(*b1, *b2); //�����ص�
	if (overlap > -(1e-3)) {
		double dx = b1->x - b2->x;
		double dy = b1->y - b2->y;
		double cos_lap = dx / overlap;
		double sin_lap = dy / overlap;

		b1->x -= overlap * cos_lap / 2;
		b1->y -= overlap * sin_lap / 2;
		b2->x += overlap * cos_lap / 2;
		b2->y += overlap * sin_lap / 2;
	}
}


//�������ƶ�
void move_ball(Ball* b) {
	b->vy += g;
	b->x += b->vx;
	b->y += b->vy;
	judge_border(b);
}

//�������˶�
void move_all_balls(Ball* bs[], int cnt) {
	BeginBatchDraw();

	cleardevice();

	for (int i = 0;i < cnt;i++) {
		move_ball(bs[i]);

		for (int j = i + 1;j < cnt;j++) {
			collide_balls(bs[i], bs[j]);
		}

		draw_ball(bs[i]);
	}

	EndBatchDraw(0, 0, width, height);

	Sleep(sleep_time);
}