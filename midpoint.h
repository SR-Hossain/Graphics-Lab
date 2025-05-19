#include "custom.h"
#include<bits/stdc++.h>
using namespace std;


void drawMidpointEllipse(Point center, int a, int b) {
    int x = 0, y = b; 
    int dx = 2 * b * b;
    int dy = 2 * a * a;
    int d = b * b + a * a * b - 0.25 * a * a;

    while (dx * x <= dy * y) {
        setPixel(x + center.x, y + center.y);
        setPixel(x + center.x, -y + center.y);
        setPixel(-x + center.x, y + center.y);
        setPixel(-x + center.x, -y + center.y);
        x += 1;
        if (d >= 0) {
            y -= 1;
            d += dx * x + b * b - dy * y;
        } else {
            d += dx * x + b * b;
        }
    }

    d = b*b*(x + 0.5) *(x+0.5) + a*a*(y-1)*(y-1) - a*a*b*b;

    while (y >= 0) {
        setPixel(x + center.x, y + center.y);
        setPixel(x + center.x, -y + center.y);
        setPixel(-x + center.x, y + center.y);
        setPixel(-x + center.x, -y + center.y);
        y -= 1;
        if (d >= 0) {
            x += 1;
            d += - dy * y + a * a + dx * x;
        } else {
            d += - dy * y + a * a;
        }
    }



}



void drawMidpointCircle(Point center, int radius) {
    int d = 1 - radius;

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
            d += 2 * (x-y) + 5;
            y -= 1;
        } else {
            d += 2 * x + 3;
        }
        x += 1;
    }

}