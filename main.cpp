#include <iostream>
#include <GL/glut.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BMPLoad.h"
#include "View.h"

using namespace std;

// La texture que on va utiliser
GLuint texture;
GLfloat g_angle = 0; 
view v;

// Lire bitmaps et le transformer en textures
void LoadGLTextures()
{
    Image *image1 = new Image;
    if (image1 == NULL)
    {
        printf("Error allocating space for image");
        exit(0);
    }    

    if (!ImageLoad("texture.bmp", image1))
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

//===========================Partie OpenGL=========================
// Initialiser les paramètres du OpenGL
void init()
{
    LoadGLTextures(); // Lire une texture
    glEnable(GL_TEXTURE_2D);
	// Définir de la couleur d'effacement du framebuffer en blanc
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); 
    glClearDepth(1.0);                     
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
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
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
 glLoadIdentity(); 

 gluLookAt(v.mypositionX,v.mypositionY,v.mypositionZ,
	 v.mypositionX + v.objectX,v.mypositionY + v.objectY,v.mypositionZ + v.objectZ,
	 0.0,1.0,0.0);  
//glTranslatef(0.0f, 0.0f, 0.0f);
//glRotatef(g_angle, 0.0, 1.0f, 0.0f);
//g_angle += 1.0f;

  // Dessiner un cube
 glRotatef(g_angle, 1.0, 0.0f, 0.0f);
 glBegin(GL_QUADS);
	// Devant
    glTexCoord2f(0.01f, 0.01f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.06f, 0.01f); glVertex3f( 1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.06f, 0.06f); glVertex3f( 1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.01f, 0.06f); glVertex3f(-1.0f,-1.0f, 1.0f);

	// Gauche
    glTexCoord2f(0.01f, 0.01f); glVertex3f(-1.0f, 1.0f,-1.0f);
    glTexCoord2f(0.06f, 0.01f); glVertex3f(-1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.06f, 0.06f); glVertex3f(-1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.01f, 0.06f); glVertex3f(-1.0f, 1.0f, 1.0f);

	// Droite
    glTexCoord2f(0.06f, 0.01f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.06f, 0.06f); glVertex3f(1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.01f, 0.06f); glVertex3f(1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.01f, 0.01f); glVertex3f(1.0f, 1.0f,-1.0f);

	// Derrière
    glTexCoord2f(0.06f, 0.01f); glVertex3f( 1.0f, 1.0f,-1.0f);
    glTexCoord2f(0.06f, 0.06f); glVertex3f( 1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.01f, 0.06f); glVertex3f(-1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.01f, 0.01f); glVertex3f(-1.0f, 1.0f,-1.0f);
	
	// Dessus
    glTexCoord2f(0.01f, 0.06f); glVertex3f(-1.0f, 1.0f,-1.0f);
    glTexCoord2f(0.01f, 0.01f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.06f, 0.01f); glVertex3f( 1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.06f, 0.06f); glVertex3f( 1.0f, 1.0f,-1.0f);

	// Dessous
    glTexCoord2f(0.06f, 0.06f); glVertex3f( 1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.01f, 0.06f); glVertex3f(-1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.01f, 0.01f); glVertex3f(-1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.06f, 0.01f); glVertex3f( 1.0f,-1.0f,-1.0f);

 glEnd();

 
 
 glutSwapBuffers(); 
}


void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h); // Définir la fenêtre OpenGL
	//gluLookAt(0,0,5,0,0,0,0,0,1);
	//gluLookAt(0,2,0,0,0,0,0,1,0);
    glMatrixMode(GL_PROJECTION); // Modifier la pile de Projection
    glLoadIdentity();

    if (h == 0) h = 1; // L'exception quand h=0
    gluPerspective(45.0f,(GLfloat) w / (GLfloat)h , 0.5f, -1000.0f);

    glMatrixMode(GL_MODELVIEW);// On retourne a la pile modelview
    glLoadIdentity();
}

//-----------------------------------
//Clavier 
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
		case 'w': 
			v.mypositionX += 0.05 * v.objectX;
			v.mypositionZ += 0.05 * v.objectZ;
            break;
		case 's': 
			v.mypositionX -= 0.05 * v.objectX;
			v.mypositionZ -= 0.05 * v.objectZ;
            break;
		case 'a': 
			v.mypositionX += 0.05 * v.objectX;
			v.mypositionZ -= 0.05 * v.objectZ;
            break;
		case 'd': 
			v.mypositionX -= 0.05 * v.objectX;
			v.mypositionZ += 0.05 * v.objectZ;
            break;
        case 'q': 
			v.mypositionY += 0.1 ;
            break;
        case 'e': 
			v.mypositionY -= 0.1 ;
            break;
		case 27: 
            exit(0);
            break;
    }    
}

//------------------------------------
// Cliquer sur la souris
void MouseEvent(int button, int state, int x, int y)
{
}

//-------------------------------------
// Bouger la souris
void MotionMove(int x,int y)
{
	cout << x << " " << y << endl;
	if(x - v.m_lastx > 0)
	{
		v.objectX += 1 * sin(1);
		v.objectZ -= 1 - 1 * cos(1);
	}
	if(x - v.m_lastx < 0)
	{
		v.objectX -= 1 * sin(1);
		v.objectZ += 1 - 1 * cos(1);
	}
	v.m_lastx = x;
	v.m_lasty = y;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Minecraft");
    init();
    glutTimerFunc(20,timer,0);// Définir le temps pour mise à jour
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(MouseEvent);
    glutMotionFunc(MotionMove);
    glutMainLoop();

    return 0;
}
