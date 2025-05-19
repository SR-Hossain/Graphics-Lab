
// #include "brasenham.h"
// #include "midpoint.h"
#include "line_clipping.h"

void display() {
    clearScreen();
    scale(1);
    glColor3f(1, 0, 0);
    glPointSize(5);
    Point p1(-7, 10);
    // Point p2(-3, 4);

    // Point p3 = p1.mirror();
    // Point p4 = p2.mirror();

    // drawBrasenhamLine(p3, p4, true);

    // Draw clipping window
    drawWindow();
    
    // Define some test lines (red = original, green = clipped)
    vector<pair<Point, Point>> lines = {
        {Point(50, 50), Point(60, 250)},   // Diagonal crossing window
        {Point(150, 50), Point(150, 350)},  // Vertical line
        {Point(50, 150), Point(350, 150)},  // Horizontal line
        {Point(50, 350), Point(350, 50)},   // Diagonal crossing opposite
        {Point(200, 50), Point(200, 350)}   // Vertical through center
    };
    
    // Draw original lines (red)
    glColor3f(1.0, 0.0, 0.0);
    for (auto& line : lines) {
        glBegin(GL_LINES);
            glVertex2f(line.first.x, line.first.y);
            glVertex2f(line.second.x, line.second.y);
        glEnd();
    }
    
    // Draw clipped lines (green)
    glColor3f(0.0, 1.0, 0.0);
    for (auto& line : lines) {
        cohen_sutherland(line.first, line.second);
    }


    // drawBrasenhamCircle(p1, 5);

    // drawMidpointEllipse(p1, 10, 5);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Simple GLUT Example");
    gluOrtho2D(0, 400, 0, 400);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
