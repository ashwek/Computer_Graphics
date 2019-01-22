/*
	Build for Turbo C++
*/

#include <stdio.h>
#include <graphics.h>
#include <math.h>

int round(float point){
	return (int)(point+0.5);
}

void dda(int x1, int y1, int x2, int y2){

	int steps = ( abs(x2-x1) > abs(y2-y1) ) ? abs(x2-x1) : abs(y2-y1);
	float Xincr = (float)(x2-x1) / steps;
	float Yincr = (float)(y2-y1) / steps;
	float x = (float)x1, y = (float)y1;

	while( steps >= 0 ){

		putpixel(round(x), round(y), getcolor());

		x += Xincr;
		y += Yincr;
		steps--;

	}
}

void main(){

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "../BGI/");

	setbkcolor(WHITE);
	setcolor(BLACK);

	outtextxy(10, 35, "(10, 50)");
	circle(10, 50, 1);
	outtextxy(120, 55, "(120, 50)");
	circle(120, 50, 1);
	dda(10, 50, 120, 50);

	outtextxy(150, 85, "(150, 85)");
	circle(150, 100, 1);
	outtextxy(250, 205, "(250, 205)");
	circle(250, 200, 1);
	dda(150, 100, 250, 200);

	outtextxy(10, 85, "(10, 50)");
	circle(10, 100, 1);
	outtextxy(10, 205, "(120, 50)");
	circle(10, 200, 1);
	dda(10, 100, 10, 200);

	getch();
	closegraph();
}
