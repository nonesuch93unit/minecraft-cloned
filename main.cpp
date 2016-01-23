#pragma comment(lib, "WINMM.LIB")

#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <GL/glut.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "View.h"
#include "font.h"
#include "cube.h"
#include "world.h"
#include "keyboard.h"
#include "mouse.h"
#include "GUI.h"
#include "skybox.h"
#include "plants.h"
#include <SOIL.h>

using namespace std;

// La texture que on va utiliser
GLuint texture1;
GLuint skybox;
GLfloat g_angle = 0; 
GLint width=0,height=0;
Font fond;
World world;
Keyboard keyboard;
Mouse mouse;

// Lire bitmaps et le transformer en textures

void LoadGLTexture()
{
	int w = 256; int h = 256;
	    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	unsigned char * image = SOIL_load_image("terrain.png", &w, &h, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	
}


// Initialiser les paramètres du OpenGL
void init()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Minecraft");
	
    glEnable(GL_TEXTURE_2D);
	// Définir de la couleur d'effacement du framebuffer en blanc                  
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
	glutSetCursor(GLUT_CURSOR_NONE); 
	glutIgnoreKeyRepeat(1);
	glEnable(GL_BLEND);// you enable blending function
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f); 
    glClearDepth(1.0);   

	LoadGLTexture(); // Lire une texture
	fond.BuildFont();
	world.generation();
	
}

//------------------------------------
// Définir le temps de rafraîchissement
void timer(int p)
{
    glutPostRedisplay();
    glutTimerFunc(20, timer, 0);
}


void display()
{

	keyboard.keyboardmovement(world);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glLoadIdentity(); 
	gluLookAt(world.viewer.mypositionX,world.viewer.mypositionY,world.viewer.mypositionZ,
			  world.viewer.mypositionX + world.viewer.objectX,world.viewer.mypositionY + world.viewer.objectY,world.viewer.mypositionZ + world.viewer.objectZ,
			  0.0,1.0,0.0);  

	// Dessiner un cube
	glRotatef(g_angle, 1.0, 0.0f, 0.0f);


	
	//skyboxinit();
	world.viewerMovement();
	world.viewerchoose();
	world.afficheworld();

	
	//cout << world.viewer.objectX << " " << world.viewer.objectY << " " << world.viewer.objectZ << endl;
	
	
	//2d GUI
	drawGUI(width, height);
	// Render your 2D text
	//glColor3f(0.0f, 0.0f, 0.0f); // 颜色
	//glRasterPos2f(0,2); // 输出位置
	//fond.glPrint("rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr");  // 输出文字到屏幕

	glutSwapBuffers(); 
}

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
	if(button == 0)
		mouse.leftclick(world,button);
	if(button == 2)
		mouse.rightclick(world,button);
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
