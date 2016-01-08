#include "cube.h"
#include <iostream>
#include <cstring>
using namespace std;

Cube::Cube(float x, float y, float z, int t)
{
	positionX = x;
	positionY = y;
	positionZ = z;
	type = t;
	switch (t)
	{
	case LAND:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 2  ;
			textureY[i] = 15  ;
		}
		break;
	case SAND:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 2  ;
			textureY[i] = 14  ;
		}
		break;
	case WOOD:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 4  ;
			textureY[i] = 15  ;
		}
		break;
	case PIERRE:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 0  ;
			textureY[i] = 15  ;
		}
		break;
	case WATER:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 15  ;
			textureY[i] = 3  ;
		}
		break;
	case BRICK:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 7  ;
			textureY[i] = 15  ;
		}
		break;
	case SNOW:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 2  ;
			textureY[i] = 11  ;
		}
		break;
	case MAGMA:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 15  ;
			textureY[i] = 0  ;
		}
		break;
	case GRASSLAND:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 2  ;
			textureY[i] = 15  ;
		}
		break;
	default:
		break;
	}

	for(int i = 0; i < 6; i++)
	{
		textureX[i] = 0.0625 * textureX[i];
		textureY[i] = 0.0625 * textureY[i];
	}
}

void Cube::afficheCube()
{
	glBegin(GL_QUADS);
		// Devant
		glColor3f(1.0f, 1.0f, 1.0f); // ÑÕÉ«
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.005); glVertex3f(positionX,   positionY+1, positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.005); glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.060); glVertex3f(positionX+1, positionY,   positionZ+1);
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.060); glVertex3f(positionX,   positionY,   positionZ+1);

		// Gauche
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.005); glVertex3f(positionX, positionY+1, positionZ);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.005); glVertex3f(positionX, positionY,   positionZ);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.060); glVertex3f(positionX, positionY,   positionZ+1);
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.060); glVertex3f(positionX, positionY+1, positionZ+1);

		// Droite
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.005); glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.005); glVertex3f(positionX+1, positionY  , positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.060); glVertex3f(positionX+1, positionY  , positionZ);
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.060); glVertex3f(positionX+1, positionY+1, positionZ);

		// Derri¨¨re
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.005); glVertex3f(positionX+1, positionY+1, positionZ);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.005); glVertex3f(positionX+1, positionY  , positionZ);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.060); glVertex3f(positionX  , positionY  , positionZ);
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.060); glVertex3f(positionX  , positionY+1, positionZ);
	
		// Dessus
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.005); glVertex3f(positionX  , positionY+1, positionZ);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.005); glVertex3f(positionX  , positionY+1, positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.060); glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.060); glVertex3f(positionX+1, positionY+1, positionZ);

		// Dessous
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.005); glVertex3f(positionX+1,positionY, positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.005); glVertex3f(positionX  ,positionY, positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.060); glVertex3f(positionX  ,positionY, positionZ);
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.060); glVertex3f(positionX+1,positionY, positionZ);

	glEnd();
}