#include <stdio.h>
#include <graphics.h>

void raster_scan();
void scan_line(int y, int polygon_color);
int check_edges(int s, int e, int y, int polygon_color);
void duplicate(int *x, int y);
void fill_color(int x1, int y, int x2, int color);

void main(){

    int gd = DETECT, gm;
    int shape2[] = {200,100, 150,140, 175,170, 200,160, 225,170, 250,140, 200,100};
    int shape1[] = {40,50, 40,100, 60,80, 100,100, 120,80, 140,100, 140,80, 160,80, 160,50, 180,70, 200,40, 60,40, 80,60, 40,50};
    initgraph(&gd, &gm, "../BGI/");

    setbkcolor(WHITE);
    setcolor(BLACK);
    setfontcolor(BLACK);

    drawpoly(sizeof(shape1)/sizeof(int)/2, shape1);
    drawpoly(sizeof(shape2)/sizeof(int)/2, shape2);
    raster_scan(getcolor());

    getchar();
    closegraph();
}

void raster_scan(int polygon_color){

    int y;
    for(y = 0; y < getmaxy(); y++){
        scan_line(y, polygon_color);
    }

}

void scan_line(int y, int polygon_color){

    int x = 0, length = 0, direction;
    int x1 = -1, x2 = -1;
    int s, e;

    while( x < getmaxx() ){
        if( getpixel(x, y) == polygon_color ){
            s = x;
            if( length == 0 ){
                duplicate(&x, y);
                e = x;
                x1 = x+1;
                switch( check_edges(s, e, y, polygon_color) ){
                    case 1:
                        if( s == e ) length = 1;
                        else length = 0;
                        break;
                    case 2:
                        length = 1;
                        break;
                }
            }
            else {
                x2 = x;
                fill_color(x1, y, x2, polygon_color);
                duplicate(&x, y);
                e = x;
                switch( check_edges(s, e, y, polygon_color) ){
                    case 0:
                        x1 = x+1;
                        break;
                    case 1:
                        if( s == e ) length = 0;
                        else x1 = x+1;
                        break;
                    case 2:
                        length = 0;
                        break;
                }
            }
        }
        x++;
    }
}

int check_edges(int s, int e, int y, int polygon_color){

    int x, su = 0, sd = 0, eu = 0, ed = 0;

    if( getpixel(s, y-1) == polygon_color && getpixel(s, y+1) == polygon_color )
        return 1;   //Vertical Line at Start pixel

    if( getpixel(e, y-1) == polygon_color && getpixel(e, y+1) == polygon_color )
        return 1;   //Vertial Line at End pixel

    // Start point - Above
    if( getpixel(s-1, y-1) == polygon_color || getpixel(s, y-1) == polygon_color || getpixel(s+1, y-1) == polygon_color ){
        su = 1;
    }

    // Start point - Below
    if( getpixel(s-1, y+1) == polygon_color || getpixel(s, y+1) == polygon_color || getpixel(s+1, y+1) == polygon_color ){
        sd = 1;
    }

    // End point - Above
    if( getpixel(e-1, y-1) == polygon_color || getpixel(e, y-1) == polygon_color || getpixel(e+1, y-1) == polygon_color ){
        eu = 1;
    }

    // End point - Below
    if( getpixel(e-1, y+1) == polygon_color || getpixel(e, y+1) == polygon_color || getpixel(e+1, y+1) == polygon_color ){
        ed = 1;
    }

    if(( su == 1 && ed == 1) || ( sd == 1 && eu == 1)) return 2;
    else return 0;

}

void fill_color(int x1, int y, int x2, int color){

    for(; x1 < x2; x1++){
        putpixel(x1, y, CYAN);
    }

}

void duplicate(int *x, int y){

    while( getpixel(*x, y) == getpixel((*x)+1, y) )
        (*x)++;

}
