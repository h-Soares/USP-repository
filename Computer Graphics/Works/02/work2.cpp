//*****************************************************
//
// pratica2.cpp
// Trabalhando com polígonos e com objetos 3D
// 
// 
//*****************************************************

#include <GL/glut.h>
#include <iostream>

// função para fazer o desenho
void Desenha(void)
{
    // define a viewport
    glViewport(0, 0, 500, 500);
    
    // limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    // desenha estrela
    // define a cor
    glColor3f(1.0, 0.0, 0.0);
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


   // desenha ampulheta
   // define a cor
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glBegin(GL_POLYGON);
        glVertex2f(250.0, 250.0);  
        // muda a cor
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(400.0, 100.0); 
        glVertex2f(100.0, 100.0); 
        glVertex2f(250.0, 250.0);
        glVertex2f(100.0, 400.0);
        glVertex2f(400.0, 400.0); 
    glEnd();   

// desenha triangulo 3d
    // define a cor
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex3f(200.0, 250.0, 0.0);
        // muda a cor  
        glColor3f(1.0, 0.0, 1.0);
        glVertex3f(100.0, 100.0, 0.0);    
        glVertex3f(100.0, 400.0, 0.0);
    glEnd();

// desenha pirâmide
    // define a cor
    glColor3f(1.0, 0.0, 0.3);
    double zbase = 0.0;
    glBegin(GL_QUADS);
        glVertex3f(100.0, 100.0, zbase);
        glVertex3f(100.0, 400.0, zbase);
        glVertex3f(400.0, 400.0, zbase);
        glVertex3f(400.0, 100.0, zbase);
     glEnd(); 
    
    glColor3f(0.0, 0.9, 0.0);
    double zvertice = 100.0;
    glBegin(GL_TRIANGLES);
        glVertex3f(100.0, 100.0, zbase);
        glVertex3f(100.0, 400.0, zbase);
        glVertex3f(250.0, 250.0, zvertice);
        glVertex3f(100.0, 400.0, zbase);
        glVertex3f(400.0, 400.0, zbase);
        glVertex3f(250.0, 250.0, zvertice);
        glVertex3f(400.0, 400.0, zbase);
        glVertex3f(400.0, 100.0, zbase);
        glVertex3f(250.0, 250.0, zvertice);
        glVertex3f(400.0, 100.0, zbase);
        glVertex3f(100.0, 100.0, zbase);
        glVertex3f(250.0, 250.0, zvertice);
       
    glEnd();

    // desenha vértices da estrela
    // define a cor
    glColor3f(0.0, 0.0, 1.0);
    // define o tamanho do ponto
    glPointSize(4.0);
    glBegin(GL_POINTS);
        glVertex2f(100.0, 100.0);
        glVertex2f(200.0, 250.0);
        glVertex2f(100.0, 400.0);
        glVertex2f(250.0, 300.0);
        glVertex2f(400.0, 400.0);
        glVertex2f(300.0, 250.0);
        glVertex2f(400.0, 100.0);
        glVertex2f(250.0, 200.0);
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
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    
}

int main(int argc, char** argv)
{
    std::cout << "Pratica 2\n";
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // usa apenas um buffer e o sistema rgb

    glutInitWindowPosition(850,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Aula Pratica 2"); // nome da janela

    glutDisplayFunc(Desenha);  // funçao com os dados primitivos. Esta chamada acontece toda vez que a janela precisar ser redesenhada.
    Inicializa(); // inicialização da tela e do fundo. Acontece antes do rendering.
    glutMainLoop(); // inicia a máquina de estados. Processa as msgs do sist operacional (mouse, teclado, etc).
}