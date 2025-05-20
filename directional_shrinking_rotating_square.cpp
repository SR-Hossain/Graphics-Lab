#include <GL/glut.h>

float angle = 0.0f;
float posX = 0.0f, posY = 0.0f;  // Position
float width = 0.5f;               // Half-width (initial width = 1.0)
const float height = 0.5f;        // Fixed half-height

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Translate to current position
    glTranslatef(posX, posY, 0.0f);
    
    // Rotate the square (clockwise)
    glRotatef(-angle, 0.0f, 0.0f, 1.0f);
    
    // Draw the square with current width/height
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(-width, -height);
        glVertex2f(width, -height);
        glVertex2f(width, height);
        glVertex2f(-width, height);
    glEnd();
    
    glutSwapBuffers();
}

void update(int value) {
    angle += 1.0f;
    if (angle > 360) angle -= 360;
    
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // ~60 FPS
}

void specialKeys(int key, int x, int y) {
    float moveStep = 0.05f; // Movement step size
    float shrinkFactor = 0.1f; // Shrink width by 10%

    switch(key) {
        case GLUT_KEY_UP:
            if (posY < 0.8f) {
                posY += moveStep;
                width += width * shrinkFactor;
            }
            break;
        case GLUT_KEY_DOWN:
            if (posY > -0.8f) {
                posY -= moveStep;
                width -= width * shrinkFactor;
            }
            break;
        case GLUT_KEY_LEFT:
            if (posX > -0.8f) {
                posX -= moveStep;
                width -= width * shrinkFactor;
            }
            break;
        case GLUT_KEY_RIGHT:
            if (posX < 0.8f) {
                posX += moveStep;
                width += width * shrinkFactor;
            }
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Directional Shrinking Rotating Square");
    
    init();
    
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(25, update, 0);
    
    glutMainLoop();
    return 0;
}