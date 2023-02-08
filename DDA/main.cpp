#include<iostream>
#include<graphics.h>
#include<cmath>

int roundNow(float x) {
    if ((x - (int)x) >= 0.5) return (int) x + 1;
    else return (int)x;
}

void drawLine(int a, int b, int c, int d) {
    float x = a, y = b;
    int dx = (c - a), dy = (d - b);
    float m = dy / (float) dx;
    if (fabs(m) < 1) {
        while (x <= c) {
            putpixel(roundNow(x), roundNow(y), RED);
            std::cout << roundNow(x) << ", " << roundNow(y) << std::endl;
            x += 1;
            y += 1;
        }
    } else if(fabs(m) > 1){
        while (y <= d) {
            putpixel(roundNow(x), roundNow(y), RED);
            std::cout << roundNow(x) << ", " << roundNow(y) << std::endl;
            x++;
            y++;
        }
    } else {
        while(y <= d || x <= c) {
            putpixel(roundNow(x), roundNow(y), RED);
            // std::cout << roundNow(x) << ", " << roundNow(y) << std::endl;
            x++;
            y++;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    int a, b, c, d;

    std::cout << "Enter Starting Points" << std::endl;
    std::cin >> a;
    std::cin >> b;

    std::cout << "Enter Ending Points" << std::endl;
    std::cin >> c;
    std::cin >> d;

    initgraph(&gd, &gm, (char *)"");
    drawLine((int)a, (int)b, (int)c, (int)d);
    getch();
    closegraph();
    return 0;    
}