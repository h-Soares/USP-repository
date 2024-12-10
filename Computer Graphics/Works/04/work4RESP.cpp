//*****************************************************
//
// pratica4.cpp
// Visualização 3D
// 
//*****************************************************
#include <gl/glut.h>
#include <iostream>
GLfloat angle, fAspect, largura, altura, xcamera, ycamera, zcamera, 
xtarget, ytarget, ztarget, xup, yup, zup;		

void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

    // Especifica a viewport
	glViewport(0, 0, largura, altura);

	//Desenha objetos 3D (wire-frame)
	//glutSolidTeapot(20.0f);
	//glutWireCube(50.0);
	//glutWireSphere(50, 20, 20);

    glColor3f(1.0f, 0.2f, 0.2f);
    glPushMatrix();
        //glTranslated(0, 0, 0);
        glutWireTeapot(50.0f);  
	    //glColor3f(0.0f, 0.2f, 0.2f); glutWireSphere(50, 20, 20); glColor3f(1.0f, 0.2f, 0.0f); glutWireCube(50.0);
    glPopMatrix();
/*
	// Desenha um cubo utilizando primitivas
	glColor3f(0.7f, 0.4f, 1.0f);
	glBegin(GL_QUADS);			// Face frontal
		glNormal3f(0.0, 0.0, 1.0); 	// Normal da face
		glVertex3f(40.0, 40.0, 80.0);
		glVertex3f(-40.0, 40.0, 80.0);
		glVertex3f(-40.0, -40.0, 80.0);
		glVertex3f(40.0, -40.0, 80.0);
	glEnd();
		glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);			// Face posterior
		glNormal3f(0.0, 0.0, -1.0);	// Normal da face
		glVertex3f(40.0, 40.0, 0.0);
		glVertex3f(40.0, -40.0, 0.0);
		glVertex3f(-40.0, -40.0, 0.0);
		glVertex3f(-40.0, 40.0, 0.0);
	glEnd();
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);			// Face inferior
		glNormal3f(0.0, -1.0, 0.0); 	// Normal da face
		glVertex3f(-40.0, -40.0, 0.0);
		glVertex3f(40.0, -40.0, 0.0);
		glVertex3f(40.0, -40.0, 80.0);
		glVertex3f(-40.0, -40.0, 80.0);
	glEnd();
glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);			// Face lateral esquerda
		glNormal3f(-1.0, 0.0, 0.0); 	// Normal da face
		glVertex3f(-40.0, 40.0, 80.0);
		glVertex3f(-40.0, 40.0, 0.0);
		glVertex3f(-40.0, -40.0, 0.0);
		glVertex3f(-40.0, -40.0, 80.0);
	glEnd();
	
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);			// Face lateral direita
		glNormal3f(1.0, 0.0, 0.0);	// Normal da face
		glVertex3f(40.0, 40.0, 80.0);
		glVertex3f(40.0, -40.0, 80.0);
		glVertex3f(40.0, -40.0, 0.0);
		glVertex3f(40.0, 40.0, 0.0);
	glEnd();
	glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);			// Face superior
		glNormal3f(0.0, 1.0, 0.0);  	// Normal da face
		glVertex3f(-40.0, 40.0, 0.0);
		glVertex3f(-40.0, 40.0, 80.0);
		glVertex3f(40.0, 40.0, 80.0);
		glVertex3f(40.0, 40.0, 0.0);
	glEnd();
*/
	glutSwapBuffers();
}

void Inicializa(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);   //ativa o zBuffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //limpa o zBuffer e o buffer de trás

	angle = 45;
	largura = 600;
    altura = 500;
	fAspect = (GLfloat)largura / (GLfloat)altura;
	xcamera = 0;
    ycamera = 0;
	zcamera = 235;
	xtarget = 0;
	ytarget = 0;
	ztarget = 0;
	xup = 0;
	yup = 1;
	zup = 0;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();
	// Especifica a projeção perspectiva
	gluPerspective(angle, fAspect, 0.1, 1000);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
	//Z saindo do plano !!
	gluLookAt(xcamera, ycamera, zcamera,  // posição da câmera
              xtarget, ytarget, ztarget,          // posição do alvo
              xup, yup, zup);         // vetor UP da câmera
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLint rlargura, GLint raltura)
{
	largura = rlargura;
	altura = raltura; 

	// Para previnir uma divisão por zero
	if (altura == 0) altura = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, largura, altura); 

	// Calcula a correção de aspecto
	fAspect = (GLfloat)largura / (GLfloat)altura;

	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {
            xtarget++;  
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {
            xtarget--; 
		}
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //aplica o zBuffer  
    EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

void TeclasEspeciais(int key, int x, int y)
{
	if (key == GLUT_KEY_UP) {
		ycamera++;
	}
	if (key == GLUT_KEY_DOWN) {
		ycamera--;
	}
	if (key == GLUT_KEY_RIGHT) {
		xcamera++;
	}
	if (key == GLUT_KEY_LEFT) {
		xcamera--;
	}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}
/*
void GerenciaTeclado(unsigned char key, int x, int y) {
	switch (key) {
		case ' ': // restaura posição inicial da camera
			............
			break;
		// movimentacao do observador
		case 'd':
			..............
			break;
		case 'a':
			...............
			break;
	}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}
*/
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	Inicializa();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  //GLUT_DOUBLE trabalha com dois buffers: um para renderização e outro para exibição
	
    glutInitWindowPosition(700,100);
	glutInitWindowSize(largura,altura);
    glutCreateWindow("Aula Pratica 4"); 

	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela); // Função para ajustar o tamanho da tela
    glutMouseFunc(GerenciaMouse);
    //glutKeyboardFunc(GerenciaTeclado); // Define qual funcao gerencia o comportamento do teclado
    glutSpecialFunc(TeclasEspeciais); // Define qual funcao gerencia as teclas especiais
	glutMainLoop();
}