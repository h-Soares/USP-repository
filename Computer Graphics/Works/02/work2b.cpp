#include <iostream>
#include <GL/glut.h>
#include <math.h>

using namespace std;

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
        glColor3f(0.0, 0.0, 0.0);
        glVertex2i(350, 100);
        glVertex2i(450, 100);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2i(450, 200);
        glVertex2i(350, 200);
    glEnd();
}

void DesenhaTriangulo() {
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2i(200, 100);
        glVertex2i(300, 100);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2i(250,300);
    glEnd();
}

void Desenhar() {

    glViewport(0, 0, 1000, 1000);

    glClear(GL_COLOR_BUFFER_BIT);

    DesenhaQuadrantes();

    DesenhaQuadrado(); // quadrado original 
    glPushMatrix(); //para isolar as transf a apenas um objeto
    // gira o quadrado 90 graus e aplica a escala 1/2, considerando o ponto que configura o seu centro (450, 150) 
        glTranslated(400, 150, 0);
        glScaled(0.5, 0.5, 0);
        glRotated(90, 0, 0, 1);
        glTranslated(-400, -150, 0);
        DesenhaQuadrado(); // quadrado escalado
    glPopMatrix(); //para isolar as transf a apenas um objeto

    DesenhaTriangulo(); // triangulo original
    double angulo;
    angulo = -90.0;
    glPushMatrix(); // girar -90 graus em torno do vértice (200, 100) do triângulo. Ordem das operações: de cima para baixo !
        glTranslated(200, 100, 0);
        glRotated(angulo, 0, 0, 1);
        glTranslated(-200, -100, 0);
        DesenhaTriangulo(); // triangulo  rotacionado
    glPopMatrix();

    glFlush();
}

void Inicializar() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glLineWidth(2.0);
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0); // left, right, bottom, top
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Pratica 2b - Transformacoes Geometricas");

    glutDisplayFunc(Desenhar);
    Inicializar();
    glutMainLoop();
}