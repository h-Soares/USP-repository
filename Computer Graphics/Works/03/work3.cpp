//
// Controle do mouse e do teclado:
// Desenha linhas com o botão esquerdo
// Desenha pontos com o botão direito
// Limpa a tela com a tecla c
//
#include <iostream>
#include <GL/glut.h>
#include <math.h>

#define MATRIX_LENGTH 500
#define ARRAY_LENGTH 2

using namespace std;

int matrizPontos[MATRIX_LENGTH][MATRIX_LENGTH];
int vetorVerticesx[ARRAY_LENGTH], vetorVerticesy[ARRAY_LENGTH];
int cont = 0;

void Desenhar() {

    glViewport(0, 0, 500, 500);

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        for (int i = 0; i < ARRAY_LENGTH; i++) {
            if(vetorVerticesx[i] != -1 && vetorVerticesy[i] != -1)
            glVertex2i(vetorVerticesx[i], vetorVerticesy[i]);
        }
    glEnd();

    glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 1.0);
        for (int cordX = 0; cordX < MATRIX_LENGTH; cordX++) {
            for (int cordY = 0; cordY < MATRIX_LENGTH; cordY++) {
                if (matrizPontos[cordX][cordY] == 1) {
                    glVertex2i(cordX, cordY);
                }
            }
        }
    glEnd();

    glFlush();  // renderiza até este ponto
}
//função callback para ações do mouse
void ControleMouse(int button, int state, int x, int y) { 
    
    if (button == GLUT_LEFT_BUTTON and state == GLUT_DOWN) {    // se retirar o state, desenha com o botão esquerdo pressionado  
        vetorVerticesx[0] = x;
        vetorVerticesy[0] = y;
    }
    if (button == GLUT_RIGHT_BUTTON and state == GLUT_DOWN) { 
        vetorVerticesx[1] = x;
        vetorVerticesy[1] = y;

        matrizPontos[x][y] = 1;
    }
    if (button == GLUT_MIDDLE_BUTTON) {
        matrizPontos[x][y] = 1;
    }
    glutPostRedisplay();
}
//função callback para ações do teclado
void ControleTeclado(unsigned char key, int x, int y) { 

    switch (key) {
        case 'C':
        case 'c': 
            for (int cordY = 0; cordY < MATRIX_LENGTH; cordY++) {
                for (int cordX = 0; cordX < MATRIX_LENGTH; cordX++) {
                    matrizPontos[cordX][cordY] = 0;
                }
            }
            for (int i = 0; i < ARRAY_LENGTH; i++) {
                vetorVerticesx[i] = -1;
                vetorVerticesy[i] = -1;
            }
        break;
    }
    glutPostRedisplay();
}

void Inicializar() {
    for (int cordX = 0; cordX < MATRIX_LENGTH; cordX++) {
        for (int cordY = 0; cordY < MATRIX_LENGTH; cordY++) {
            matrizPontos[cordX][cordY] = 0;
        }
    }
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        vetorVerticesx[i] = -1;
        vetorVerticesy[i] = -1;
    }
    
    glClearColor(0.0, 0.75, 0.2, 1.0);
    glPointSize(5);
    glLineWidth(2);
    gluOrtho2D(0.0, 500.0, 500.0, 0.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(430, 130);
    glutCreateWindow("Pratica 3");

    glutKeyboardFunc(ControleTeclado); // Define qual funcao gerencia o comportamento do teclado
    glutMouseFunc(ControleMouse); // Define qual funcao gerencia o comportamento do mouse

    glutDisplayFunc(Desenhar);
    Inicializar();
    glutMainLoop();
}

/* COMO ERA O CÓDIGO ANTES: escrevia muitas linhas e muitos pontos.
//
// Controle do mouse e do teclado:
// Desenha linhas com o botão esquerdo
// Desenha pontos com o botão direito
// Limpa a tela com a tecla c
//
#include <iostream>
#include <GL/glut.h>
#include <math.h>

using namespace std;

int matrizPontos[500][500];
int vetorVerticesx[50], vetorVerticesy[50];
int cont = 0;

void Desenhar() {

    glViewport(0, 0, 500, 500);

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        for (int i = 0; i < cont; i++) {
            if(vetorVerticesx[i] != -1 && vetorVerticesy[i] != -1)
            glVertex2i(vetorVerticesx[i], vetorVerticesy[i]);
        }
    glEnd();

    glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 1.0);
        for (int cordX = 0; cordX < 500; cordX++) {
            for (int cordY = 0; cordY < 500; cordY++) {
                if (matrizPontos[cordX][cordY] == 1) {
                    glVertex2i(cordX, cordY);
                }
            }
        }
    glEnd();

    glFlush();  // renderiza até este ponto
}
//função callback para ações do mouse
void ControleMouse(int button, int state, int x, int y) { 
    
    if (button == GLUT_LEFT_BUTTON and state == GLUT_DOWN) {    // se retirar o state, desenha com o botão esquerdo pressionado  
        vetorVerticesx[cont] = x;
        vetorVerticesy[cont] = y;
        cont += 1;
    }
    if (button == GLUT_RIGHT_BUTTON and state == GLUT_DOWN) { 
        matrizPontos[x][y] = 1;
    }
    if (button == GLUT_MIDDLE_BUTTON) {
        matrizPontos[x][y] = 1;
    }
    glutPostRedisplay();
}
//função callback para ações do teclado
void ControleTeclado(unsigned char key, int x, int y) { 

    switch (key) {
        case 'C':
        case 'c': 
            for (int cordY = 0; cordY < 500; cordY++) {
                for (int cordX = 0; cordX < 500; cordX++) {
                    matrizPontos[cordX][cordY] = 0;
                }
            }
            for (int i = 0; i < 50; i++) {
                vetorVerticesx[i] = -1;
                vetorVerticesy[i] = -1;
            }
        break;
    }
    glutPostRedisplay();
}

void Inicializar() {
    for (int cordX = 0; cordX < 500; cordX++) {
        for (int cordY = 0; cordY < 500; cordY++) {
            matrizPontos[cordX][cordY] = 0;
        }
    }
    for (int i = 0; i < 50; i++) {
        vetorVerticesx[i] = -1;
        vetorVerticesy[i] = -1;
    }
    
    glClearColor(0.0, 0.75, 0.2, 1.0);
    glPointSize(5);
    glLineWidth(2);
    gluOrtho2D(0.0, 500.0, 500.0, 0.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(430, 130);
    glutCreateWindow("Pratica 3");

    glutKeyboardFunc(ControleTeclado); // Define qual funcao gerencia o comportamento do teclado
    glutMouseFunc(ControleMouse); // Define qual funcao gerencia o comportamento do mouse

    glutDisplayFunc(Desenhar);
    Inicializar();
    glutMainLoop();
}

*/