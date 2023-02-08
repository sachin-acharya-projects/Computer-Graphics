#include<iostream>
#include<graphics.h>
#include<cmath>

struct coordinates
{
    int x;
    int y;
};
void drawEllipse(int, int, int, int);
using namespace std;
int main(){
    int rX, rY, h, k;
    cout << "What are the radius Rx and Ry?" << endl;
    cin >> rX;
    cin >> rY;

    cout << "What are the center of ellipse?" << endl;
    cin >> h;
    cin >> k;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    drawEllipse(rX, rY, h, k);
    getch();
    closegraph();
    return 0;
}
void drawEllipse(int rx, int ry, int h, int k) {
    int x = 0, y = ry, a = 0, b = 0, i, j;
    coordinates ellipseCoords[8][64];
    int p = ry * ry - rx * rx * ry + (rx * rx) / 4;
    while (2 * ry * ry * x < 2 * rx * rx * y)
    {
        ellipseCoords[0][a] = {.x = x + h, .y = y + k};
        ellipseCoords[3][a] = {.x = x + h, .y = -y + k};
        ellipseCoords[4][a] = {.x = -x + h, .y = -y + k};
        ellipseCoords[7][a] = {.x = -x + h, .y = y + k};

        if (p < 0) p += 2 * ry * ry * (++x) + ry * ry;
        else p += 2 * ry * ry * (++x) - 2 * rx * rx * (--y) + ry * ry;
        ++a;
    }
    
    p = (ry * ry) * ((float)x + 1 / 2) * ((float)x + 1 / 2) + (rx * rx) * (y - 1) * (y - 1) - (rx * rx) * (ry * ry);
    while(y > 0) {
        ellipseCoords[1][b] = {.x = x + h, .y = y + k};   // R2
        ellipseCoords[2][b] = {.x = x + h, .y = -y + k};  // R3
        ellipseCoords[5][b] = {.x = -x + h, .y = -y + k}; // R6
        ellipseCoords[6][b] = {.x = -x + h, .y = y + k};  // R7
        if (p > 0)
        {
            p += -2 * rx * rx * (--y) + rx * rx;
        }
        else
        {
            p += 2 * ry * ry * (++x) - 2 * rx * rx * (--y) - rx * rx;
        }
        ++b;
    }

    for (i = 0; i < 8; i++)
    {
        cout << "\n\nRegion " << i + 1 << endl;
        j = 0;
        if (i == 0 || i == 3 || i == 4 || i == 7)
        {
            while (j < a)
            {
                x = ellipseCoords[i][j].x, y = ellipseCoords[i][j].y;
                putpixel(x, y, WHITE);
                cout << "(" << x << ", " << y << ")" << endl;
                j++;
            }
        }
        else
        {
            while (j < b)
            {
                x = ellipseCoords[i][j].x, y = ellipseCoords[i][j].y;
                putpixel(x, y, WHITE);
                cout << "(" << x << ", " << y << ")" << endl;
                j++;
            }
        }
    }
}