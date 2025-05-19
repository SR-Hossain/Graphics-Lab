#include "custom.h"
#include<bits/stdc++.h>
using namespace std;

void drawBrasenhamLine(Point start, Point end, bool isMirrored=false){
    float m = getSlope(start, end);

    if (m <= 0 || abs(m)>1){
        cout<<"Not possible, fix the points by mirroring...\n";
    }

    float dy = end.y - start.y;
    float dx = end.x - start.x;

    float d = 2 * dy - dx;


    while (start.x <= end.x) {
        start.draw(isMirrored);
        cout<<-start.y <<' '<<start.x <<'\n';
        start.x += 1;
        if (d >= 0){
            d += 2*dy - 2*dy;
            start.y += 1;
        } else {
            d += 2 * dy;
        }
    }
}


void drawBrasenhamCircle(Point center, int radius) {
    int d = 3 - 2 * radius;

    int x = 0; int y = radius;

    while (x <= y) {
        setPixel(x + center.x, y + center.y);
        setPixel(x + center.x, -y + center.y);
        setPixel(-x + center.x, y + center.y);
        setPixel(-x + center.x, -y + center.y);
        setPixel(y + center.x, x + center.y);
        setPixel(y + center.x, -x + center.y);
        setPixel(-y + center.x, x + center.y);
        setPixel(-y + center.x, -x + center.y);
        if (d >= 0){
            d += 4 * (x-y) + 10;
            y -= 1;
        } else {
            d += 4 * x + 6;
        }
        x += 1;
    }

}