#include <stdio.h>
#include <graphics.h>
#include <math.h>

void bres(int x1, int y1, int x2, int y2){

	int dx = abs(x2-x1), dy = abs(y2-y1);
	int Pk;
	int Yincr = ( y2 > y1) ? 1 : -1;

	putpixel(x1, y1, getcolor());
	Pk = 2*dy - dx;

	do{
		if( Pk < 0 ){
			Pk = Pk + 2*dy;
		}
		else {
			Pk = Pk + 2*dy -2*dx;
			y1 += Yincr;
		}
		x1++;
		putpixel(x1, y1, getcolor());

	}while( x1 != x2 && y1 != y2 );

}

void main(){

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "../BGI/");

	setbkcolor(WHITE);
	setcolor(BLACK);

	outtextxy(10, 10, "(10, 20)");
	circle(10,20, 1);
	outtextxy(90, 95, "(90, 90)");
	circle(90, 90, 1);
	bres(10, 20, 90, 90);

	circle(250, 20, 1);
	outtextxy(250, 10, "(250, 20)");
	bres(90, 90, 250, 20);
	getch();
	closegraph();
}
