#include <windows.h>
#include <iostream>
#include <GL/glut.h>
#include <SOIL.h>

#include "font.h"
#include "cube.h"
#include "plants.h"
#include "View.h"
#include "world.h"

#include "keyboard.h"
#include "mouse.h"
#include "GUI.h"
#include "skybox.h"

using namespace std;

// La texture que on va utiliser
GLuint texture;
GLint width=0,height=0;
Font fond;
World world;
Keyboard keyboard;
Mouse mouse;
int choice; //le cube choisi 
int page; // le page choisi

//----------------------------------
// Lire png et le transformer en textures
void LoadGLTexture()
{
	int w = 1024; int h = 1024;
	glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	unsigned char * image = SOIL_load_image("texture.png", &w, &h, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	
}

//------------------------------------
// Initialiser les paramètres du OpenGL
void init()
{
	//window initialisation
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Minecraft");
	
	//parametre de opengl
    glEnable(GL_TEXTURE_2D);               
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
	glutSetCursor(GLUT_CURSOR_NONE); 
	glutIgnoreKeyRepeat(1);
	glEnable(GL_BLEND);// you enable blending function
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

	// Définir de la couleur d'effacement du framebuffer en blanc   
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f); 
    glClearDepth(1.0);   

	LoadGLTexture(); // Lire une texture
	fond.BuildFont(); //initialisation de font
	world.readtheworld();
	choice = 1;
	page = 0;
	//world.generation();
}

//------------------------------------
// Définir le temps de rafraîchissement
void timer(int p)
{
    glutPostRedisplay();
    glutTimerFunc(20, timer, 0);
}

//----------------------------------------
//construction de la scène
void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glLoadIdentity(); 
	gluLookAt(world.viewer.mypositionX,world.viewer.mypositionY,world.viewer.mypositionZ,
			  world.viewer.mypositionX + world.viewer.objectX,world.viewer.mypositionY + world.viewer.objectY,world.viewer.mypositionZ + world.viewer.objectZ,
			  0.0,1.0,0.0);  //point de vue

	keyboard.keyboardmovement(world);
	drawskybox();
	world.viewerMovement();
	world.viewerchoose();

	//3d scène
	world.afficheworld();

	//2d GUI
	drawGUI(width, height, page, choice);

	// Render your 2D text
	//glColor3f(0.0f, 0.0f, 0.0f); 
	//glRasterPos2f(0,2); 
	//fond.glPrint("rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr"); 

	//cout << world.viewer.objectX << " " << world.viewer.objectY << " " << world.viewer.objectZ << endl;
	//cout << world.viewer.objectX * world.viewer.objectX + world.viewer.objectZ * world.viewer.objectZ << endl;
	glutSwapBuffers(); 
}

//-------------------------------------
//changement de la demension
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h); // Définir la fenêtre OpenGL
    glMatrixMode(GL_PROJECTION); // Modifier la pile de Projection
    glLoadIdentity();

    if (h == 0) h = 1; // L'exception quand h=0
	width = w; height = h;
    gluPerspective(45.0f,(GLfloat) w / (GLfloat)h , 0.5f, -1000.0f);

    glMatrixMode(GL_MODELVIEW);// On retourne a la pile modelview
    glLoadIdentity();
}

//-----------------------------------
//Clavier 
void keydown(unsigned char key, int x, int y)
{
	//controle de choix de cube
	if(key >= '0' && key <= '9') choice = key-'0';
	if(key == '-') page -= 10;
	if(key == '=') page += 10;
	page = (page + 30) % 30;
	
	keyboard.setkeydown(key);
}

void keyup(unsigned char key, int x, int y)
{
	keyboard.setkeyup(key);
}

//------------------------------------
// Cliquer sur la souris
void MouseEvent(int button, int state, int x, int y)
{
	if(button == 0 && state == 1)
		mouse.leftclick(world,button);
	if(button == 2 && state == 1)
		mouse.rightclick(world,button,choice+page);
}

//-------------------------------------
// Bouger la souris
void MotionMove(int x,int y)
{
	mouse.mousemove(world,x,y,width,height);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    init();
    glutTimerFunc(20,timer,0);// Définir le temps pour mise à jour
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keydown);
	glutKeyboardUpFunc(keyup);
    glutMouseFunc(MouseEvent);
    glutPassiveMotionFunc(MotionMove);
    glutMainLoop();
    return 0;
}
