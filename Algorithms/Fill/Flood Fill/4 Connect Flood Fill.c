#include <stdio.h>
#include <graphics.h>

void FF4(int x, int y, int bg, int c){

	if( getpixel(x, y) == bg ){
		putpixel(x, y, c);
		FF4(x+1, y, bg, c);
		FF4(x, y+1, bg, c);
		FF4(x-1, y, bg, c);
		FF4(x, y-1, bg, c);
	}
}

void main(){

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "../BGI/");

	circle(200, 200, 30);
	FF4(200, 200, getbkcolor(), getcolor());

	getch();
	closegraph();
}
