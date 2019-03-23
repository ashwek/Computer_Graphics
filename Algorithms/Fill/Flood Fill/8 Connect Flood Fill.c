#include <stdio.h>
#include <graphics.h>

void FF8(int x, int y, int bg, int c){

	if( getpixel(x, y) == bg ){
		putpixel(x, y, c);
		FF8(x+1, y, bg, c);
		FF8(x, y+1, bg, c);
		FF8(x-1, y, bg, c);
		FF8(x, y-1, bg, c);
		FF8(x+1, y+1, bg, c);
		FF8(x+1, y-1, bg, c);
		FF8(x-1, y+1, bg, c);
		FF8(x-1, y-1, bg, c);
	}
}

void main(){

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "../BGI/");

	rectangle(30, 50, 150, 120);
	FF8(100, 100, getbkcolor(), getcolor());

	getchar();
	closegraph();
}
