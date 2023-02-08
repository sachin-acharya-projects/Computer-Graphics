#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;
bool condition(int x, int y, int v) {
    // x = x_0, y = x_n, v = x
    if (x < y) return v <= y;
    else return v >= y;
}
void drawLine(int a, int b, int c, int d) {
    int x = a, y = b;
    int dx = (c - a), dy = (d - b);
    float m = dy / (float)dx;
    int p;

    if (fabs(m) < 1){
        p = 2 * fabs(dy) - fabs(dx);
        while (condition(a, c, x)) {
            putpixel(x, y, WHITE);
            cout << x << ", " << y << endl;
            if (x > c) x--;
            else if (x < c) x++;
            else break;

            if (p < 0) p += 2 * fabs(dy);
            else {
                if (y < d) y++;
                else if (y > d) y--;
                p += 2 * fabs(dy) - 2 * fabs(dx);
            }
        }
    } else {
        p = 2 * fabs(dx) - fabs(dy);
        while (condition(b, d, y)) {
            putpixel(x, y, WHITE);
            cout << x << ", " << y << endl;

            if (y > d) y--;
            else if (y < d) y++;
            else break;

            if (p < 0) {
                p += 2 * fabs(dx);
            } else {
                if (x < c) x++;
                else if (x > c) x--;
                p += 2 * fabs(dx) - 2 * fabs(dy);
            }
        }
    }
}
int main(){
    int gd = DETECT, gm;
    int a, b, c, d;

    cout << "What are the starting points? " << endl;
    cin >> a;
    cin >> b;
    
    cout << "What are the ending points? " << endl;
    cin >> c;
    cin >> d;

    initgraph(&gd, &gm, (char *)"");
    drawLine(a, b, c, d);
    getch();
    closegraph();
    return 0;
}