#ifndef GUI_H
#define GUI_H

#include <GL/glut.h>
#include "View.h"
#include "cube.h"
#include "plants.h"

void drawGUI(int width, int height, int times, int choice)
{

	int a = width/2; int b = height/2;
	int length = 12; int decalage = 2;
	int itemslength = 250; int itemswidth = 50;

	//Pour afficher l'interface 2D, disable GL_DEPTH_TEST
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, 800, 0.0, 600);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    

	//---------------------------------
	//Une partie est la croix milieu
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f); 
    glBegin(GL_QUADS);
        
		glColor3f(0,0,0);
        glVertex2i(a + length, b + decalage);
        glVertex2i(a - length, b + decalage);
        glVertex2i(a - length, b - decalage);
		glVertex2i(a + length, b - decalage);
    glEnd();
	glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2i(a + decalage, b + length);
        glVertex2i(a - decalage, b + length);
        glVertex2i(a - decalage, b - length);
		glVertex2i(a + decalage, b - length);
    glEnd();

	glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2i(a + itemslength, 0);
        glVertex2i(a - itemslength, 0);
        glVertex2i(a - itemslength, itemswidth);
		glVertex2i(a + itemslength, itemswidth);
    glEnd();

	//---------------------------------
	//Une partie est la choix de texture
	if(choice == 0)
	{
	glBegin(GL_QUADS);
        glColor3f(0,0,0);
			glVertex2i(100 + 10 * 50, 55);
			glVertex2i(100 + 10 * 50, 5);
			glVertex2i(150 + 10 * 50, 5);
			glVertex2i(150 + 10 * 50, 55);
    glEnd();
	}
	else
	{
		glBegin(GL_QUADS);
        glColor3f(0,0,0);
			glVertex2i(100 + choice * 50, 55);
			glVertex2i(100 + choice * 50, 5);
			glVertex2i(150 + choice * 50, 5);
			glVertex2i(150 + choice * 50, 55);
		glEnd();
	}

	//---------------------------------
	//Une partie est tous les textures
	if(times <= 10)
	{
		for(int i = 1; i<10;i++)
		{
			float textureX; 
			float textureY; 
			gettexturecubeforGUI(i+times,textureX,textureY);
			glBegin(GL_QUADS);
				glColor3f(1,1,1);
				glTexCoord2f(textureX+0.060, textureY+0.005); glVertex2i(105 + i * 50, 45);
				glTexCoord2f(textureX+0.060, textureY+0.060); glVertex2i(105 + i * 50, 5);
				glTexCoord2f(textureX+0.005, textureY+0.060); glVertex2i(145 + i * 50, 5);
				glTexCoord2f(textureX+0.005, textureY+0.005); glVertex2i(145 + i * 50, 45);
			glEnd();
		}
		float textureX; 
		float textureY; 
		gettexturecubeforGUI(times,textureX,textureY);
		glBegin(GL_QUADS);
			glColor3f(1,1,1);
			glTexCoord2f(textureX+0.060, textureY+0.005); glVertex2i(105 + 10 * 50, 45);
			glTexCoord2f(textureX+0.060, textureY+0.060); glVertex2i(105 + 10 * 50, 5);
			glTexCoord2f(textureX+0.005, textureY+0.060); glVertex2i(145 + 10 * 50, 5);
			glTexCoord2f(textureX+0.005, textureY+0.005); glVertex2i(145 + 10 * 50, 45);		
		glEnd();
	}
	else
	{
		for(int i = 1; i<10;i++)
		{
			float textureX; 
			float textureY; 
			gettextureplantsforGUI(i+times,textureX,textureY);
			glBegin(GL_QUADS);
				glColor3f(1,1,1);
				glTexCoord2f(textureX+0.060, textureY+0.005); glVertex2i(105 + i * 50, 45);
				glTexCoord2f(textureX+0.060, textureY+0.060); glVertex2i(105 + i * 50, 5);
				glTexCoord2f(textureX+0.005, textureY+0.060); glVertex2i(145 + i * 50, 5);
				glTexCoord2f(textureX+0.005, textureY+0.005); glVertex2i(145 + i * 50, 45);
			glEnd();
		}
		float textureX; 
		float textureY; 
		gettextureplantsforGUI(times,textureX,textureY);
		glBegin(GL_QUADS);
			glColor3f(1,1,1);
			glTexCoord2f(textureX+0.060, textureY+0.005); glVertex2i(105 + 10 * 50, 45);
			glTexCoord2f(textureX+0.060, textureY+0.060); glVertex2i(105 + 10 * 50, 5);
			glTexCoord2f(textureX+0.005, textureY+0.060); glVertex2i(145 + 10 * 50, 5);
			glTexCoord2f(textureX+0.005, textureY+0.005); glVertex2i(145 + 10 * 50, 45);		
		glEnd();
	}
    
	//2d GUI fini, enable GL_DEPTH_TEST
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);// you enable blending function
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
}

#endif