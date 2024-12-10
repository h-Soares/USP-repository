#include <GL/freeglut.h>  // Inclui o cabeçalho do FreeGLUT
#include <iostream>

void initWindow();
void display();

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    initWindow();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
void initWindow() {
    int windowWidth = 500;
    int windowHeight = 500;
    int windowPositionX = (glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2;
    int windowPositionY = (glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2;
    
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(windowPositionX, windowPositionY);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Learning window");

    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}