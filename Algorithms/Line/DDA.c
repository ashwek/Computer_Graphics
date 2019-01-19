/*
	Build for Turbo C++
*/

#include <stdio.h>
#include <graphics.h>
#include <math.h>

int round(double point){
	return (int)( (point - (int)point) >= 0.5 ) ? ceil(point) : floor(point);
}

void dda(double x1, double y1, double x2, double y2){

	double steps = ( abs(x2-x1) > abs(y2-y1) ) ? abs(x2-x1) : abs(y2-y1);
	double Xincr = (x2-x1) / steps;
	double Yincr = (y2-y1) / steps;

	while( steps >= 0 ){

		putpixel(round(x1), round(y1), getcolor());

		x1 += Xincr;
		y1 += Yincr;
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
