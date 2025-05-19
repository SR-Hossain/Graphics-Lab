#include <GL/glut.h>

void scale(float x) {
    glScalef(x, x, 1.0f); // 2D scaling (z=1 for 2D)
}

// Translate (move) the current graphics by (x,y)
void translate(float x, float y) {
    glTranslatef(x, y, 0.0f); // 2D translation (z=0)
}

// Set a single pixel at (x,y) with current color
void setPixel(float x, float y) {
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}

// Clear the screen to black
void clearScreen() {
    glClear(GL_COLOR_BUFFER_BIT);
}


class Point{
    public:
    float x;
    float y;

    Point(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    Point mirror(){
        Point p; p.x = -y; p.y = x;
        return p;
    }

    void draw(bool isMirrored=false){
        if (isMirrored)setPixel(-y, x);
        else setPixel(x, y);
    }

    void drawTranslated(float xx, float yy) {
        setPixel(x + xx, y + yy);
    }
};


float getSlope(Point p1, Point p2) {
    return (p2.y - p1.y) / (p2.x - p1.x);
}
