#pragma comment(lib, "WINMM.LIB")

#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <GL/glut.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BMPLoad.h"
#include "View.h"
#include "font.h"
#include "cube.h"
#include "world.h"
#include "keyboard.h"
#include "mouse.h"

using namespace std;

// La texture que on va utiliser
GLuint texture;
GLfloat g_angle = 0; 
GLint width=0,height=0;
Font fond;
World world;
Keyboard keyboard;
Mouse mouse;

// Lire bitmaps et le transformer en textures
void LoadGLTextures()
{
    Image *image1 = new Image;
    if (image1 == NULL)
    {
        printf("Error allocating space for image");
        exit(0);
    }    

    if (!image1->ImageLoad("texture1.bmp"))
        exit(1);

	// Créer des textures
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	// 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image,
    // y size from image, 
    // border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY,
            0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
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

	

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f); 
    glClearDepth(1.0);   

	 LoadGLTextures(); // Lire une texture
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
	//glTranslatef(0.0f, 0.0f, 0.0f);
	//glRotatef(g_angle, 0.0, 1.0f, 0.0f);
	//g_angle += 1.0f;
	// Dessiner un cube
	glRotatef(g_angle, 1.0, 0.0f, 0.0f);
	//glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    //glClear(GL_COLOR_BUFFER_BIT);
 

 /* glBegin(GL_QUADS);
	// Devant
	glColor3f(1.0f, 1.0f, 1.0f); // 颜色
    glTexCoord2f(0.01f, 0.01f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.06f, 0.01f); glVertex3f( 1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.06f, 0.06f); glVertex3f( 1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.01f, 0.06f); glVertex3f(-1.0f,-1.0f, 1.0f);

	// Gauche
    glTexCoord2f(0.07f, 0.01f); glVertex3f(-1.0f, 1.0f,-1.0f);
    glTexCoord2f(0.12f, 0.01f); glVertex3f(-1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.12f, 0.06f); glVertex3f(-1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.07f, 0.06f); glVertex3f(-1.0f, 1.0f, 1.0f);

	// Droite
    glTexCoord2f(0.07f, 0.01f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.12f, 0.01f); glVertex3f(1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.12f, 0.06f); glVertex3f(1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.07f, 0.06f); glVertex3f(1.0f, 1.0f,-1.0f);

	// Derrière
    glTexCoord2f(0.07f, 0.01f); glVertex3f( 1.0f, 1.0f,-1.0f);
    glTexCoord2f(0.12f, 0.01f); glVertex3f( 1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.12f, 0.06f); glVertex3f(-1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.07f, 0.06f); glVertex3f(-1.0f, 1.0f,-1.0f);
	
	// Dessus
    glTexCoord2f(0.07f, 0.01f); glVertex3f(-1.0f, 1.0f,-1.0f);
    glTexCoord2f(0.12f, 0.01f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.12f, 0.06f); glVertex3f( 1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.07f, 0.06f); glVertex3f( 1.0f, 1.0f,-1.0f);

	// Dessous
    glTexCoord2f(0.07f, 0.01f); glVertex3f( 1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.12f, 0.01f); glVertex3f(-1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.12f, 0.06f); glVertex3f(-1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.07f, 0.06f); glVertex3f( 1.0f,-1.0f,-1.0f);

	glEnd();*/
	world.viewerMovement();
	world.afficheworld();



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
