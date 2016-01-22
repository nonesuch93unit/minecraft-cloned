#ifndef SKYBOX_H
#define SKYBOX_H

#include <GL/glut.h>

#define TAILLE 320

void skyboxinit()
{
	float x[6], y[6];
	x[0] = 12 * 0.0625 ; y[0] = 7 * 0.0625;
	x[1] = 10 * 0.0625 ; y[1] = 7 * 0.0625;
	x[2] = 14 * 0.0625 ; y[2] = 7 * 0.0625;
	x[3] = 8 * 0.0625 ;  y[3] = 7 * 0.0625;
	x[4] = 12 * 0.0625 ; y[4] = 9 * 0.0625;
	x[5] = 12 * 0.0625 ; y[5] = 5 * 0.0625;
	glBegin(GL_QUADS);					   
		// Devant						    
		glColor3f(1.0f, 1.0f, 1.0f); // ÑÕÉ«
		glTexCoord2f(x[0]+0.120, y[0]+0.120); glVertex3f(-TAILLE/2, TAILLE/2, TAILLE/2);
		glTexCoord2f(x[0]+0.005, y[0]+0.120); glVertex3f(TAILLE/2, TAILLE/2, TAILLE/2);
		glTexCoord2f(x[0]+0.005, y[0]+0.005); glVertex3f(TAILLE/2, -TAILLE/2,  TAILLE/2);
		glTexCoord2f(x[0]+0.120, y[0]+0.005); glVertex3f(-TAILLE/2, -TAILLE/2, TAILLE/2);

		// Gauche
		glTexCoord2f(x[1]+0.005, y[1]+0.120); glVertex3f(-TAILLE/2, TAILLE/2, -TAILLE/2);
		glTexCoord2f(x[1]+0.005, y[1]+0.005); glVertex3f(-TAILLE/2, -TAILLE/2,   -TAILLE/2);
		glTexCoord2f(x[1]+0.120, y[1]+0.005); glVertex3f(-TAILLE/2, -TAILLE/2,   TAILLE/2);
		glTexCoord2f(x[1]+0.120, y[1]+0.120); glVertex3f(-TAILLE/2, TAILLE/2, TAILLE/2);

		// Droite
		glTexCoord2f(x[1]+0.005, y[2]+0.120); glVertex3f(TAILLE/2, TAILLE/2, TAILLE/2);
		glTexCoord2f(x[1]+0.005, y[2]+0.005); glVertex3f(TAILLE/2, -TAILLE/2  , TAILLE/2);
		glTexCoord2f(x[1]+0.120, y[2]+0.005); glVertex3f(TAILLE/2, -TAILLE/2  , -TAILLE/2);
		glTexCoord2f(x[1]+0.120, y[2]+0.120); glVertex3f(TAILLE/2, TAILLE/2, -TAILLE/2);
																						
		// Derri¨¨re																		
		glTexCoord2f(x[3]+0.005, y[3]+0.120); glVertex3f(TAILLE/2, TAILLE/2, -TAILLE/2);
		glTexCoord2f(x[3]+0.005, y[3]+0.005); glVertex3f(TAILLE/2, -TAILLE/2  , -TAILLE/2);
		glTexCoord2f(x[3]+0.120, y[3]+0.005); glVertex3f(-TAILLE/2  , -TAILLE/2  , -TAILLE/2);
		glTexCoord2f(x[3]+0.120, y[3]+0.120); glVertex3f(-TAILLE/2  , TAILLE/2, -TAILLE/2);
	
		// Dessus
		glTexCoord2f(x[4]+0.005, y[4]+0.005); glVertex3f(-TAILLE/2  , TAILLE/2, -TAILLE/2);
		glTexCoord2f(x[4]+0.060, y[4]+0.005); glVertex3f(-TAILLE/2  , TAILLE/2, TAILLE/2);
		glTexCoord2f(x[4]+0.060, y[4]+0.060); glVertex3f(TAILLE/2, TAILLE/2, TAILLE/2);
		glTexCoord2f(x[4]+0.005, y[4]+0.060); glVertex3f(TAILLE/2, TAILLE/2, -TAILLE/2);

		// Dessous
		glTexCoord2f(x[5]+0.005, y[5]+0.005); glVertex3f(TAILLE/2,-TAILLE/2, TAILLE/2);
		glTexCoord2f(x[5]+0.060, y[5]+0.005); glVertex3f(-TAILLE/2  ,-TAILLE/2, TAILLE/2);
		glTexCoord2f(x[5]+0.060, y[5]+0.060); glVertex3f(-TAILLE/2  ,-TAILLE/2, -TAILLE/2);
		glTexCoord2f(x[5]+0.005, y[5]+0.060); glVertex3f(TAILLE/2,-TAILLE/2, -TAILLE/2);

	glEnd();
}

#endif