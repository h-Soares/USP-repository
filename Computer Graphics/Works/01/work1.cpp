//*****************************************************
//
// pratica1.cpp
// Um programa OpenGL simples que abre uma janela GLUT
// e desenha duas linhas cruzadas
// e um quadrado
// 
//*****************************************************

#include <GL/glut.h>
#include <iostream>

// função para fazer o desenho
void Desenha(void)
{
    // define a viewport |
    glViewport(0, 0, 500, 500);

    // limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLineWidth(3.0);

    // define a cor
    glColor3f(0.0, 0.0, 0.0);
    // desenha um polígono
     glBegin(GL_POLYGON);
        // define os vértices
        glVertex2f(100.0, 100.0);
        glVertex2f(400.0, 100.0);
        glVertex2f(400.0, 400.0);
        glVertex2f(100.0, 400.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(100, 400);
        glVertex2f(400, 400);
        glVertex2f(250, 0);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    //desenha linhas
    glBegin(GL_LINES);
        // define os vértices
        // linha 1
        glVertex2f(100.0, 100.0);
        glVertex2f(400.0, 400.0);
        // linha 2
        glVertex2f(100.0, 400.0);
        glVertex2f(400.0, 100.0);
    glEnd();

    // executa os comandos opengl
    glFlush();
}

// inicializa parametros
void Inicializa(void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // usa apenas um buffer e o sistema rgb

    glutInitWindowPosition(800,200);
    glutInitWindowSize(500,500);
    glutCreateWindow("Aula Pratica 1"); // nome da janela
    // cor de fundo da janela de visualizaçao
    glClearColor(1.0, 1.0, 1.0, 1.0);
    // window da câmera
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    std::cout << "Pratica 1\n";
    
    Inicializa(); // inicialização da tela e do fundo
    glutDisplayFunc(Desenha);  // funçao com os dados primitivos
    glutMainLoop(); // executa todo o processo
}