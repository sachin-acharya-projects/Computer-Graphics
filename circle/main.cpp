#include<iostream>
#include<graphics.h>
#include<cmath>

void drawCircle(int, int, int);
void symmetry(int, int, int, int);
using namespace std;
int main(){
    int xc, yc, R;
    
    cout << "What are the center coordinates of circle" << endl;
    cin >> xc;
    cin >> yc;

    cout << "What is the radius of circle" << endl;
    cin >> R;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    drawCircle(xc, yc, R);
    getch();
    closegraph();
    return 0;
}

void drawCircle(int xc, int yc, int rad) {
    int x = 0, y = rad;
    int p = 1 - rad;
    symmetry(x, y, xc, yc);
    for (x = 0;y>=x;x++) {
        if (p < 0) p += 2 * x + 3;
        else {
            p += 2 * (x - y) * 5;
            y--;
        }
        symmetry(x, y, xc, yc);
        delay(5);
    }
}

void symmetry(int x, int y, int xc, int yc) {
    putpixel(xc+x,yc+y,GREEN);
    delay(5);

    putpixel(xc+y,yc+x,GREEN);
    delay(5);

    putpixel(xc-y,yc+x,GREEN);
    delay(5);

    putpixel(xc-x,yc+y,GREEN);
    delay(5);

    putpixel(xc-x,yc-y,GREEN);
    delay(5);

    putpixel(xc-y,yc-x,GREEN);
    delay(5);

    putpixel(xc+y,yc-x,GREEN);
    delay(5);

    putpixel(xc+x,yc-y,GREEN);
    delay(50);
}