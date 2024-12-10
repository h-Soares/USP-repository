//*****************************************************
//
// pratica6.cpp
// Curva de Bezier e Hermite
// 
//*****************************************************
#include <gl/glut.h>
#include <iostream>
#include <math.h>
using namespace std;

GLfloat angle, fAspect, xcamera, ycamera, zcamera, Bx[4], By[4], Bz[4], Px, Py, Pz;
int  largura, altura;
string curve_type;

float calculaPontoHermite(char c, float t){
	switch (c){
		case 'x':
			return ((2.0 * pow(t, 3.0) - 3 * pow(t, 2.0) + 1) * Bx[0] + (-2.0 * pow(t, 3.0) + 3 * pow(t, 2.0)) * Bx[1] + (pow(t, 3.0) - 2 * pow(t, 2.0) + t) * Bx[2] + (pow(t, 3.0) - pow(t, 2.0)) * Bx[3]);
			break;
		case 'y':
			return ((2.0 * pow(t, 3.0) - 3 * pow(t, 2.0) + 1) * By[0] + (-2.0 * pow(t, 3.0) + 3 * pow(t, 2.0)) * By[1] + (pow(t, 3.0) - 2 * pow(t, 2.0) + t) * By[2] + (pow(t, 3.0) - pow(t, 2.0)) * By[3]);
			break;
		case 'z':
			return ((2.0 * pow(t, 3.0) - 3 * pow(t, 2.0) + 1) * Bz[0] + (-2.0 * pow(t, 3.0) + 3 * pow(t, 2.0)) * Bz[1] + (pow(t, 3.0) - 2 * pow(t, 2.0) + t) * Bz[2] + (pow(t, 3.0) - pow(t, 2.0)) * Bz[3]);
			break;
	}
}

// Função calcula o valor do ponto ao longo da curva
// Recebe como parametro o eixo onde está calculando (variável 'c'), podendo ser no eixo X, Y e Z, e o valor de t.
float calculaPontoBezier(char c, float t){
	switch (c){
		case 'x':
			return (pow(1.0 - t, 3.0) * Bx[0] + 3.0 * t * pow(1.0 - t, 2.0) * Bx[1] + 3.0 * pow(t, 2.0) * (1.0 - t) * Bx[2] + pow(t, 3.0) * Bx[3]);
			break;
		case 'y':
			return (pow(1.0 - t, 3.0) * By[0] + 3.0 * t * pow(1.0 - t, 2.0) * By[1] + 3.0 * pow(t, 2.0) * (1.0 - t) * By[2] + pow(t, 3.0) * By[3]);
			break;
		case 'z':
			return (pow(1.0 - t, 3.0) * Bz[0] + 3.0 * t * pow(1.0 - t, 2.0) * Bz[1] + 3.0 * pow(t, 2.0) * (1.0 - t) * Bz[2] + pow(t, 3.0) * Bz[3]);
			break;
	}
}


void Desenha(void){
	glClear(GL_COLOR_BUFFER_BIT);
 
	if(curve_type == "BEZIER") {
	// Desenha os pontos de controle e as linhas que os unem
	glColor3f(1.0f, 0.06, 0.6f);
	glBegin(GL_LINE_STRIP);
		glVertex3f(Bx[0], By[0], Bz[0]);
		glVertex3f(Bx[1], By[1], Bz[1]);
		glVertex3f(Bx[2], By[2], Bz[2]);
		glVertex3f(Bx[3], By[3], Bz[3]);
	glEnd();
		// Calcula os pontos e desenha a curva de bezier
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_LINE_STRIP);
			for (GLdouble t=0; t<=1.0; t+=0.01) {
				Px = calculaPontoBezier('x', t);
				Py = calculaPontoBezier('y', t);
				Pz = calculaPontoBezier('z', t);
				glVertex3f(Px, Py, Pz);
			}
		glEnd();	
	} else if(curve_type == "HERMITE") {
		// Calcula os pontos e desenha a curva de hermite
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_LINE_STRIP);
			for (GLdouble t=0; t<=1.0; t+=0.01) {
				Px = calculaPontoHermite('x', t);
				Py = calculaPontoHermite('y', t);
				Pz = calculaPontoHermite('z', t);
				glVertex3f(Px, Py, Pz);
			}
		glEnd();	
	}

	glutSwapBuffers();
}

void Inicializa(void){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	angle = 45;
}

void EspecificaParametrosVisualizacao(void){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(angle, fAspect, 0.1, 500);
	glLineWidth(2);
	glPointSize(5);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(xcamera, ycamera, zcamera, 5, 5, 0, 0, 1, 0);
}

void AlteraTamanhoJanela(GLint largura, GLint altura){
	if (altura == 0) altura = 1;

	glViewport(0, 0, largura, altura);

	fAspect = (GLfloat)largura / (GLfloat)altura;

	EspecificaParametrosVisualizacao();
}
// Função callback chamada para gerenciar teclas especiais
void TeclasEspeciais(int key, int x, int y)
{
	if (key == GLUT_KEY_UP) {
		ycamera += 1;  
	}
	if (key == GLUT_KEY_DOWN) {
		ycamera -= 1;  
	}
	if (key == GLUT_KEY_RIGHT) {
		xcamera += 1;  
	}
	if (key == GLUT_KEY_LEFT) {
		xcamera -= 1;  
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //aplica o zBuffer  
    EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}
// Função callback chamada para gerenciar teclado
void GerenciaTeclado(unsigned char key, int x, int y) {
	switch (key) {
		case ' ': // restaura posição inicial da camera
			ycamera = 5;
            xcamera = 5;
            zcamera = 20;
			angle = 45;
			break;
		// movimentacao da camera em z
		case 'w':
			zcamera += 1;  
			break;
        case 's':
			zcamera -= 1;  
			break;
		
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //aplica o zBuffer  
    EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(700,100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Pratica 6");
	
	largura = 10;
    altura = 10;
	ycamera = 5;
    xcamera = 5;
    zcamera = 20;
	Inicializa();
	glutReshapeFunc(AlteraTamanhoJanela);
	
	//Entrada dos pontos pelo controle do usuario
	cout << "Digite as coordenadas x, y, z do primeiro pronto de controle:"<< std::endl;
	cin >> Bx[0] >> By[0] >> Bz[0];

	cout << "Digite as coordenadas x, y, z do segundo pronto de controle:"<< std::endl;
	cin >> Bx[1] >> By[1] >> Bz[1];

	cout << "Digite as coordenadas x, y, z do terceiro pronto de controle:"<< std::endl;
	cin >> Bx[2] >> By[2] >> Bz[2];

	cout << "Digite as coordenadas x, y, z do quarto pronto de controle:"<< std::endl;
	cin >> Bx[3] >> By[3] >> Bz[3];

	cout << "Digite o tipo da curva (BEZIER ou HERMITE): ";
	cin >> curve_type;

	glutKeyboardFunc(GerenciaTeclado); 
    glutSpecialFunc(TeclasEspeciais); 
	glutDisplayFunc(Desenha);
	glutMainLoop();
}