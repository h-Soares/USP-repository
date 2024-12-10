// pratica3b: movimentar os braços do robô
//
#include <GL/glut.h>

#include <iostream>

GLfloat ang = 60.0, angulo;

// desenha braço esquerdo
void DesenhaBracoEsq() {
    glBegin(GL_QUADS);
    // define os vértices do quadrilátero BRAÇO ESQ
    glVertex2f(2.0, 1.0);
    glVertex2f(1.5, 1.5);
    glVertex2f(1.2, 1.5);
    glVertex2f(1.7, 1.0);
    glEnd();
}

// desenha braço direito
void DesenhaBracoDir() {
    glBegin(GL_QUADS);
    // define os vértices do quadrilátero BRAÇO DIR
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.0, 1.0);
    glVertex2f(0.3, 1.0);
    glVertex2f(0.8, 1.5);
    glVertex2f(0.5, 1.5);
    glEnd();
}
void Desenha(void)
{
    // define a viewport
    glViewport(0, 0, 600, 600);
    // limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.0, 0.0, 1.0);
    
    DesenhaBracoDir();
    // CORPO COM BRAÇOS
    glColor3f(0.0, 0.0, 1.0);
    // movimenta braço esquerdo
    glPushMatrix();
        glTranslated(1.5, 1.5, 0);
        glRotated(-angulo, 0, 0, 1);
        glTranslated(-1.5, -1.5, 0);
        DesenhaBracoEsq();
    glPopMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    // define os vértices do quadrilátero CORPO
        glVertex2f(0.5, 0.5);
        glVertex2f(1.5, 0.5);
        glVertex2f(1.5, 1.5);
        glVertex2f(0.5, 1.5);
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    // define os vértices do quadrilátero PERNA DIR
        glVertex2f(0.5, 0.0);
        glVertex2f(0.8, 0.0);
        glVertex2f(0.8, 0.5);
        glVertex2f(0.5, 0.5);
    glEnd();
    glBegin(GL_QUADS);
    // define os vértices do quadrilátero PERNA ESQ
        glVertex2f(1.2, 0.0);
        glVertex2f(1.5, 0.0);
        glVertex2f(1.5, 0.5);
        glVertex2f(1.2, 0.5);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    // define os vértices do triangulo CABEÇA 
        glVertex2f(0.75, 1.5);
        glVertex2f(1.25, 1.5);
        glVertex2f(1.0, 2.0);
    glEnd();

    // executa os comandos opengl
    glFlush();
}
// inicializa parametros de rendering
void Inicializa() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // cor de fundo da janela de visualizaçao
    glMatrixMode(GL_PROJECTION);  // define que as operações serão sobre a matriz de projeção
    glLineWidth(1.0);  // espessura da linha
    gluOrtho2D(-1.0, 3.0, -1.0, 3.0);  // window da câmera
}

//função callback Timer, que será chamada após o tempo especificado
void Timer(int value) { 
    if (value % 2 == 0) {
        // se value for par: rotaciona sent hor
        angulo = -ang;
    } else {     
        // se value for impar: posição inicial
        angulo = 0.0;
    }
    glutPostRedisplay();
    glutTimerFunc(500, Timer, value+1);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    
    glutInitWindowPosition(430, 130);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Pratica 3b");

    glutTimerFunc(500, Timer, 1); // registra a função callback para temporizador

    glutDisplayFunc(Desenha);  // funçao com os dados primitivos
    
    Inicializa(); // inicialização da tela e do fundo
    
    glutMainLoop(); // executa todo o processo
}