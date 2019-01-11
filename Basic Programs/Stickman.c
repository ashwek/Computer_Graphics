#include <stdio.h>
#include <graphics.h>

void main(){

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    circle(150, 100, 30);  //Face
    ellipse(135, 95, 0, 360, 2, 4); // Left Eye
    ellipse(135, 90, 200, 340, 2, 4); // Left EyeBrow
    ellipse(165, 95, 0, 360, 2, 4); // Right Eye
    ellipse(165, 90, 200, 340, 2, 4); // Left EyeBrow
    line(150, 102, 150, 108);  //Nose
    arc(150, 110, 45, 135, 10);  //Smile

    line(150, 130, 150, 250);  //Body

    line(150, 170, 110, 180);  //Left Upper Arm
    line(110, 180, 80, 150);  //Left Lower Arm

    line(150, 170, 175, 220);  //Right Arm

    line(150, 250, 120, 330); //Left Leg
    line(120, 330, 110, 330); //Left Foot

    line(150, 250, 180, 330); //Right Leg
    line(180, 330, 190, 330); //Right Foot

    getchar();
    closegraph();

}
