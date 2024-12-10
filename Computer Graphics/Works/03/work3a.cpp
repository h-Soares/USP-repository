//
// animações
//
#include <iostream>
#include <GL/glut.h>
#include <math.h>

using namespace std;

int angulo = 0;
double dx = 0, dy = 0;

void DesenhaQuadrantes() {
    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2i(-500, 0);
        glVertex2i(500, 0);
        glVertex2i(0, 500);
        glVertex2i(0, -500);
    glEnd();
}

void DesenhaQuadrado() {
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 1.0);
        glVertex2i(350, 100);
        glVertex2i(450, 100);
        glColor3f(1.0, 1.0, 0.0);
        glVertex2i(450, 200);
        glVertex2i(350, 200);
    glEnd();
}

void DesenhaTriangulo() {
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2i(200, 100);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2i(300, 100);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2i(250,300);
    glEnd();
}
void DesenhaEstrela() {
    glColor3f(0.6, 0.0, 0.0);
    glBegin(GL_POLYGON);   
        glVertex2f(250.0, 300.0); 
        glVertex2f(400.0, 400.0);
        glVertex2f(300.0, 250.0); 
        glVertex2f(400.0, 100.0);
        glVertex2f(250.0, 200.0);
        glVertex2f(100.0, 100.0);
        glVertex2f(200.0, 250.0);
        glVertex2f(100.0, 400.0);
   glEnd();
}
void Desenhar() {

    glViewport(0, 0, 700, 700);
    glClear(GL_COLOR_BUFFER_BIT);

    DesenhaQuadrantes();

    DesenhaQuadrado(); // quadrado original 

    // desenha estrela rotacionada
    glPushMatrix();
        glTranslated(250,250,0);
        glRotated(-angulo, 0, 0, 1);
        glTranslated(-250,-250,0);
        DesenhaEstrela(); // estrela  rotacionada
    glPopMatrix();

    //quadrado: escala e rotação em torno do seu centro
    glPushMatrix();
        glTranslated(400, 150, 0); 
        glScaled(0.5,0.5,0);
        glRotated(angulo, 0,0,1);
        glTranslated(-400, -150, 0); 
        DesenhaQuadrado(); // quadrado escalado e rotacionado
    glPopMatrix();

    //quadrado: translação 
    glPushMatrix();
        glTranslated(-dx, -dy, 0); 
        DesenhaQuadrado(); // quadrado transladado
    glPopMatrix();

    //DesenhaTriangulo(); // triangulo original
    glPushMatrix();
        glTranslated(200,100,0);
        glRotated(-angulo, 0, 0, 1);
        glTranslated(-200,-100,0);
        DesenhaTriangulo(); // triangulo  rotacionado
    glPopMatrix();

    glFlush();
}
//função callback que será chamada após o tempo especificado
void ControleTempo(int value) {
    angulo += 15;
    dx += 10;
    dy += 5;
    // Redesenha a cena e executa o timer novamente para ter uma animacao continua
    glutPostRedisplay();
    glutTimerFunc(100, ControleTempo, 1); 
}

void Inicializar() {
    glClearColor(0.95, 0.95, 0.95, 1.0);
    glLineWidth(1.0);
    gluOrtho2D(-300.0, 600.0, -300.0, 600.0); // left, right, bottom, top
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(200, 0);
    glutCreateWindow("Pratica 3a");

    glutTimerFunc(100, ControleTempo, 1);  // registra a função callback para temporizador

    glutDisplayFunc(Desenhar);
    Inicializar();
    glutMainLoop();
}