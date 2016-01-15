#ifndef GUI_H
#define GUI_H

#include <GL/glut.h>
#include "View.h"

void draw(View viewer)
{
	glBegin(GL_QUADS);
	// Devant
	glColor3f(1.0f, 1.0f, 1.0f); // ÑÕÉ«
    glTexCoord2f(0.01f, 0.01f); glVertex3f(-1.0f, 6.0f, 1.0f);
    glTexCoord2f(0.06f, 0.01f); glVertex3f( 1.0f, 6.0f, 1.0f);
    glTexCoord2f(0.06f, 0.06f); glVertex3f( 1.0f,4.0f, 1.0f);
    glTexCoord2f(0.01f, 0.06f); glVertex3f(-1.0f,4.0f, 1.0f);

	// Gauche
    glTexCoord2f(0.07f, 0.01f); glVertex3f(-1.0f, 6.0f,-1.0f);
    glTexCoord2f(0.12f, 0.01f); glVertex3f(-1.0f,4.0f,-1.0f);
    glTexCoord2f(0.12f, 0.06f); glVertex3f(-1.0f,4.0f, 1.0f);
    glTexCoord2f(0.07f, 0.06f); glVertex3f(-1.0f, 6.0f, 1.0f);

	// Droite
    glTexCoord2f(0.07f, 0.01f); glVertex3f(1.0f, 6.0f, 1.0f);
    glTexCoord2f(0.12f, 0.01f); glVertex3f(1.0f,4.0f, 1.0f);
    glTexCoord2f(0.12f, 0.06f); glVertex3f(1.0f,4.0f,-1.0f);
    glTexCoord2f(0.07f, 0.06f); glVertex3f(1.0f, 6.0f,-1.0f);

	// Derri¨¨re
    glTexCoord2f(0.07f, 0.01f); glVertex3f( 1.0f, 6.0f,-1.0f);
    glTexCoord2f(0.12f, 0.01f); glVertex3f( 1.0f,4.0f,-1.0f);
    glTexCoord2f(0.12f, 0.06f); glVertex3f(-1.0f,4.0f,-1.0f);
    glTexCoord2f(0.07f, 0.06f); glVertex3f(-1.0f, 6.0f,-1.0f);
	
	// Dessus
    glTexCoord2f(0.07f, 0.01f); glVertex3f(-1.0f, 6.0f,-1.0f);
    glTexCoord2f(0.12f, 0.01f); glVertex3f(-1.0f, 6.0f, 1.0f);
    glTexCoord2f(0.12f, 0.06f); glVertex3f( 1.0f, 6.0f, 1.0f);
    glTexCoord2f(0.07f, 0.06f); glVertex3f( 1.0f, 6.0f,-1.0f);

	// Dessous
    glTexCoord2f(0.07f, 0.01f); glVertex3f( 1.0f,4.0f, 1.0f);
    glTexCoord2f(0.12f, 0.01f); glVertex3f(-1.0f,4.0f, 1.0f);
    glTexCoord2f(0.12f, 0.06f); glVertex3f(-1.0f,4.0f,-1.0f);
    glTexCoord2f(0.07f, 0.06f); glVertex3f( 1.0f,4.0f,-1.0f);

	glEnd();
}

#endif