#ifndef GUI_H
#define GUI_H

#include <GL/glut.h>
#include "View.h"

void drawGUI(int width, int height)
{
	int a = width/2; int b = height/2;
	int length = 12; int decalage = 2;
	int itemslength = 250; int itemswidth = 50;

	glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, 800, 0.0, 600);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    glBegin(GL_QUADS);
        
		glColor4f(0,0,0,0.4);
        glVertex2i(a + length, b + decalage);
        glVertex2i(a - length, b + decalage);
        glVertex2i(a - length, b - decalage);
		glVertex2i(a + length, b - decalage);
    glEnd();
	glBegin(GL_QUADS);
        glColor4f(0,0,0,0.4);
        glVertex2i(a + decalage, b + length);
        glVertex2i(a - decalage, b + length);
        glVertex2i(a - decalage, b - length);
		glVertex2i(a + decalage, b - length);
    glEnd();

	glBegin(GL_QUADS);
        glColor4f(0.5,0.5,0.5,1);
        glVertex2i(a + itemslength, 0);
        glVertex2i(a - itemslength, 0);
        glVertex2i(a - itemslength, itemswidth);
		glVertex2i(a + itemslength, itemswidth);
    glEnd();

	for(int i = 0; i<10;i++)
	{
		glBegin(GL_QUADS);
			glColor4f(1,1,1,1);
			glVertex2i(155 + i * 50, 45);
			glVertex2i(155 + i * 50, 5);
			glVertex2i(195 + i * 50, 5);
			glVertex2i(195 + i * 50, 45);
		glEnd();
	}
    
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    
    glEnable(GL_DEPTH_TEST);
}

#endif