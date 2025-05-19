#include "custom.h"
#include <bits/stdc++.h>
using namespace std;


// Clipping window coordinates
const int X_MIN = 100, X_MAX = 300;
const int Y_MIN = 100, Y_MAX = 300;

// Region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

int computeCode(double x, double y) {
    int code = INSIDE;
    
    if (x < X_MIN) code |= LEFT;
    else if (x > X_MAX) code |= RIGHT;
    if (y < Y_MIN) code |= BOTTOM;
    else if (y > Y_MAX) code |= TOP;
    
    return code;
}

void cohen_sutherland(Point p1, Point p2) {
    
    bool accept = false;
    
    while (true) {
        int code1 = computeCode(p1.x, p1.y);
        int code2 = computeCode(p2.x, p2.y);

        if (!code1 and !code2){
            accept = true;
            break;
        } else if (code1 & code2) {
            accept = false;
            break;
        } else {
            int codeOut = code1 ? code1 : code2;
            float x, y;
            float m = getSlope(p1, p2);

            if (codeOut & TOP) {
                y = Y_MAX;
                x = p1.x + (y - p1.y) / m;
            } else if (codeOut & BOTTOM) {
                y = Y_MIN;
                x = p1.x + (y - p1.y) / m;
            } else if (codeOut & LEFT) {
                x = X_MIN;
                y = p1.y + (x - p1.x) * m;
            } else {
                x = X_MAX;
                y = p1.y + (x - p1.x) * m;
            }

            if (codeOut == code1) {
                p1.x = x;
                p1.y = y;
            } else {
                p2.x = x;
                p2.y = y;
            }
        }
    }

    if (accept) {
        glBegin(GL_LINES);
            glVertex2d(p1.x, p1.y);
            glVertex2d(p2.x, p2.y);
        glEnd();
    }
}


void drawWindow() {
    glColor3f(1.0, 1.0, 1.0); // White
    glBegin(GL_LINE_LOOP);
        glVertex2i(X_MIN, Y_MIN);
        glVertex2i(X_MAX, Y_MIN);
        glVertex2i(X_MAX, Y_MAX);
        glVertex2i(X_MIN, Y_MAX);
    glEnd();
}

