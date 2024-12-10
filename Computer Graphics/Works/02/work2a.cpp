//*****************************************************
//
// pratica2a.cpp
// Criando uma circunferência parametrizada
// Interagindo com o usuário pelo teclado
// 
//*****************************************************

#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

int nPontos;
double raio;
double Xc, Yc;

// função para fazer o desenho
void Desenha(void)
{
    // define a viewport
    glViewport(0, 0, 500, 500);
    
    // limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    // define a cor
    glColor3f(0.0, 0.0, 1.0);
    
// desenha circunferência
    glBegin(GL_POLYGON);
        double x = 0, y = 0, theta = 0, deltatheta = 0;
        deltatheta = 2 * M_PI / nPontos; // uma volta toda dividida pelo numero de pontos
        for (int i = 0; i < nPontos; i++) {
            x = raio * cos(theta) + Xc; 
            y = raio * sin(theta) + Yc; 
            glVertex2i(x, y);
            theta += deltatheta;
        }
    glEnd();

    // pontos de referência para visualização
    glColor3f(1.0, 0.5, 0.0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
        glVertex2f(100.0, 100.0);
        glVertex2f(100.0, 400.0);
        glVertex2f(400.0, 400.0);
        glVertex2f(400.0, 100.0);
        glVertex2f(250.0, 250.0);
    glEnd();
    
    // executa os comandos opengl
    glFlush();
}

// inicializa parametros de rendering
void Inicializa(void)
{
    // cor de fundo da janela de visualizaçao
    glClearColor(1.0, 1.0, 1.0, 1.0);
    // espessura da linha
    glLineWidth(5.0);
    // window da camera
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
    
}

int main(int argc, char** argv)
{
    cout << "Pratica 2a\n";

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // usa apenas um buffer e o sistema rgb

    glutInitWindowPosition(850,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Aula Pratica 2a"); // nome da janela

    cout << "Digite a qtde de pontos: ";
    cin >> nPontos;
    cout << nPontos << std::endl;
    cout << "Digite o tamanho do raio: ";
    cin >> raio;
    cout << "Digite a coordenada X do centro: ";
    cin >> Xc;
    cout << "Digite a coordenada Y do centro: ";
    cin >> Yc;

    
    glutDisplayFunc(Desenha);  // funçao com os dados primitivos. Esta chamada acontece toda vez que a janela precisar ser redesenhada.
    Inicializa(); // inicialização da tela e do fundo. Acontece antes do rendering.
    glutMainLoop(); // inicia a máquina de estados. Processa as msgs do sist operacional (mouse, teclado, etc).
}