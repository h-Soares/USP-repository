//*****************************************************
//
// pratica5.cpp
// Iluminação
// 
//*****************************************************
#include <GL/glut.h>
#include <iostream>
GLfloat angle, fAspect, largura, altura, xcamera, ycamera, zcamera;

void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Especifica a viewport
	glViewport(0, 0, largura, altura);

	//Desenha objetos 3D 
	//glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidTeapot(50.0f);
	//glutSolidCube(50.0f);

	// Desenha um cubo utilizando primitivas
    // OBSERVE que cada face é desenhada com os vértices no sentido anti-horário
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);			// Face frontal
		glNormal3f(0.0, 0.0, 1.0); 	// Normal da face --> usada para a ilumininação
		glVertex3f(40.0, 40.0, 80.0);
		glVertex3f(-40.0, 40.0, 80.0);
		glVertex3f(-40.0, -40.0, 80.0);
		glVertex3f(40.0, -40.0, 80.0);
	glEnd();
		glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);			// Face posterior
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(40.0, 40.0, 0.0);
		glVertex3f(40.0, -40.0, 0.0);
		glVertex3f(-40.0, -40.0, 0.0);
		glVertex3f(-40.0, 40.0, 0.0);
	glEnd();
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);			// Face inferior
		glNormal3f(0.0, -1.0, 0.0);
		glVertex3f(-40.0, -40.0, 0.0);
		glVertex3f(40.0, -40.0, 0.0);
		glVertex3f(40.0, -40.0, 80.0);
		glVertex3f(-40.0, -40.0, 80.0);
	glEnd();
	glColor3f(0.0f, 0.9f, 0.0f);
	glBegin(GL_QUADS);			// Face lateral esquerda
		glNormal3f(-1.0, 0.0, 0.0);
		glVertex3f(-40.0, 40.0, 80.0);
		glVertex3f(-40.0, 40.0, 0.0);
		glVertex3f(-40.0, -40.0, 0.0);
		glVertex3f(-40.0, -40.0, 80.0);
	glEnd();
	glColor3f(0.0f, 0.9f, 0.0f);
	glBegin(GL_QUADS);			// Face lateral direita
		glNormal3f(1.0, 0.0, 0.0);
		glVertex3f(40.0, 40.0, 80.0);
		glVertex3f(40.0, -40.0, 80.0);
		glVertex3f(40.0, -40.0, 0.0);
		glVertex3f(40.0, 40.0, 0.0);
	glEnd();
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);			// Face superior
		glNormal3f(0.0, 1.0, 0.0);
		glVertex3f(-40.0, 40.0, 0.0);
		glVertex3f(-40.0, 40.0, 80.0);
		glVertex3f(40.0, 40.0, 80.0);
		glVertex3f(40.0, 40.0, 0.0);
	glEnd();

	glutSwapBuffers();
}

void Inicializa(void)
{
    GLfloat luzAmbiente[4]={0.2, 0.2, 0.2, 1.0};   // {R, G, B, alfa}
	GLfloat luzDifusa[4]={0.5, 0.5, 0.5, 1.0};	   // o 4o componente, alfa, controla a opacidade/transparência da luz
	GLfloat luzEspecular[4]={1, 1, 1, 1.0};
	GLfloat posicaoLuz[4]={200.0, 200.0, 100.0, 1.0};  // aqui o 4o componente indica o tipo de fonte:
                                                    // 0 para luz direcional (no infinito) e 1 para luz pontual (em x, y, z)
	GLfloat posicaoLuz2[4]={-200.0, 200.0, 100.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0, 1.0, 1.0, 1.0}; 
	GLint especMaterial = 100;     // 0 a 128
	//GLfloat emissao[4]={0.5, 0.5, 0.5, 1.0}; 

 	// Especifica a cor de fundo da janela
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	// Habilita e define o modelo de colorização 
	glShadeModel(GL_SMOOTH);  // modelo de GOURAUD: a cor de cada ponto da primitiva é interpolada a partir dos vértices
    //glShadeModel(GL_FLAT);  // a cor de cada primitiva é única em todos os pontos

	// Define a refletância do material 
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
	// Define a emissão de luz pelo objeto
	//glMaterialfv(GL_FRONT, GL_EMISSION, emissao);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

	glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz2);

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);  
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);
	
	//glDepthFunc(GL_LESS); // O fragmento mais próximo será desenhado
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //aplica o zBuffer	
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
	gluLookAt(xcamera, ycamera, zcamera,  // posição da câmera
              0, 0, 0,          // posição do alvo
              0, 1, 0);         // vetor UP da câmera
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
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;  //glEnable(GL_LIGHT1);  glDisable(GL_LIGHT0); 
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //aplica o zBuffer  
    EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}
// Função callback chamada para gerenciar teclas especiais
void TeclasEspeciais(int key, int x, int y)
{
	if (key == GLUT_KEY_UP) {
		ycamera += 10;  
	}
	if (key == GLUT_KEY_DOWN) {
		ycamera -= 10;  
	}
	if (key == GLUT_KEY_RIGHT) {
		xcamera += 10;  
	}
	if (key == GLUT_KEY_LEFT) {
		xcamera -= 10;  
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //aplica o zBuffer  
    EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}
// Função callback chamada para gerenciar teclado
void GerenciaTeclado(unsigned char key, int x, int y) {
	switch (key) {
		case ' ': // restaura posição inicial da camera
			ycamera = 80;
            xcamera = 80;
            zcamera = 300;
			angle = 45;
			break;
		// movimentacao da camera em z
		case 'w':
			zcamera += 10;  
			break;
        case 's':
			zcamera -= 10;  
			break;
		
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //aplica o zBuffer  
    EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  //GLUT_DOUBLE trabalha com dois buffers: um para renderização e outro para exibição
															   //GLUT_DEPTH habilita o  depth-buffering
    glutInitWindowPosition(700,100);
    largura = 600;
    altura = 500;
	glutInitWindowSize(largura,altura);
	fAspect = (GLfloat)largura / (GLfloat)altura;
    ycamera = 80;
    xcamera = 80;
    zcamera = 300;
	angle = 45;
    glutCreateWindow("Aula Pratica 4"); 

	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela); // Função para ajustar o tamanho da tela
    glutMouseFunc(GerenciaMouse);
    glutKeyboardFunc(GerenciaTeclado); // Define qual funcao gerencia o comportamento do teclado
    glutSpecialFunc(TeclasEspeciais); // Define qual funcao gerencia as teclas especiais
	Inicializa();
	glutMainLoop();
}