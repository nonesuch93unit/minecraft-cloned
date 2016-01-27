#ifndef SKYBOX_H
#define SKYBOX_H

#include <GL/glut.h>

#define TAILLE 64

void drawskybox()
{
	float x[6], y[6];
	x[0] = 10 * 0.0625 ; y[0] = 12 * 0.0625;
	x[1] = 9 * 0.0625 ; y[1] = 12 * 0.0625;
	x[2] = 11 * 0.0625 ; y[2] = 12 * 0.0625;
	x[3] = 12 * 0.0625 ;  y[3] = 12 * 0.0625;
	x[4] = 10 * 0.0625 ; y[4] = 13 * 0.0625;
	x[5] = 10 * 0.0625 ; y[5] = 11 * 0.0625;
	
	//affichage de skybox
	glBegin(GL_QUADS);					   
		// Devant						    
		glColor3f(1.0f, 1.0f, 1.0f); // ÑÕÉ«
		glTexCoord2f(x[0]+0.060, y[0]+0.060); glVertex3f(-TAILLE/2, TAILLE/2, TAILLE/2);
		glTexCoord2f(x[0]+0.005, y[0]+0.060); glVertex3f(TAILLE/2, TAILLE/2, TAILLE/2);
		glTexCoord2f(x[0]+0.005, y[0]+0.005); glVertex3f(TAILLE/2, -TAILLE/2,  TAILLE/2);
		glTexCoord2f(x[0]+0.060, y[0]+0.005); glVertex3f(-TAILLE/2, -TAILLE/2, TAILLE/2);

		// Gauche
		glTexCoord2f(x[1]+0.005, y[1]+0.060); glVertex3f(-TAILLE/2, TAILLE/2, -TAILLE/2);
		glTexCoord2f(x[1]+0.005, y[1]+0.005); glVertex3f(-TAILLE/2, -TAILLE/2,   -TAILLE/2);
		glTexCoord2f(x[1]+0.060, y[1]+0.005); glVertex3f(-TAILLE/2, -TAILLE/2,   TAILLE/2);
		glTexCoord2f(x[1]+0.120, y[1]+0.060); glVertex3f(-TAILLE/2, TAILLE/2, TAILLE/2);

		// Droite
		glTexCoord2f(x[1]+0.005, y[2]+0.060); glVertex3f(TAILLE/2, TAILLE/2, TAILLE/2);
		glTexCoord2f(x[1]+0.005, y[2]+0.005); glVertex3f(TAILLE/2, -TAILLE/2  , TAILLE/2);
		glTexCoord2f(x[1]+0.060, y[2]+0.005); glVertex3f(TAILLE/2, -TAILLE/2  , -TAILLE/2);
		glTexCoord2f(x[1]+0.060, y[2]+0.060); glVertex3f(TAILLE/2, TAILLE/2, -TAILLE/2);
																						
		// Derri¨¨re																		
		glTexCoord2f(x[3]+0.005, y[3]+0.060); glVertex3f(TAILLE/2, TAILLE/2, -TAILLE/2);
		glTexCoord2f(x[3]+0.005, y[3]+0.005); glVertex3f(TAILLE/2, -TAILLE/2  , -TAILLE/2);
		glTexCoord2f(x[3]+0.060, y[3]+0.005); glVertex3f(-TAILLE/2  , -TAILLE/2  , -TAILLE/2);
		glTexCoord2f(x[3]+0.060, y[3]+0.060); glVertex3f(-TAILLE/2  , TAILLE/2, -TAILLE/2);
	
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