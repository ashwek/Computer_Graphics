#include<stdio.h>
#include<graphics.h>

void PrintPoints(int Xc, int x, int Yc, int y){

	putpixel(Xc+x, Yc+y, getcolor());  //Q4
	putpixel(Xc+y, Yc+x, getcolor());  //Q4 - Reverse

	putpixel(Xc-x, Yc-y, getcolor());  //Q2
	putpixel(Xc-y, Yc-x, getcolor());  //Q2 - Reverse

	putpixel(Xc+x, Yc-y, getcolor());  //Q1
	putpixel(Xc+y, Yc-x, getcolor());  //Q1 - Reverse

	putpixel(Xc-x, Yc+y, getcolor());  //Q3
	putpixel(Xc-y, Yc+x, getcolor());  //Q3 - Reverse

}

void MidPointCircle(int Xc, int Yc, int r){

	int x = 0, y = r;
	int Pk = (5/4) - r;

	PrintPoints(Xc, x, Yc, y);
	do{

		if( Pk < 0 ){
			Pk = Pk + 2*x + 3;
		}
		else {
			Pk = Pk + 2*x - 2*y + 5;
			y--;
		}

		x++;
		PrintPoints(Xc, x, Yc, y);
	}while( x < y );
}

void main(){

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "../BGI/");

	MidPointCircle(100, 100, 80);

	getch();
	closegraph();
}
