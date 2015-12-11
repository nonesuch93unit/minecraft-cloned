#include "cube.h"

cube::cube(float x, float y, float z, int t)
{
	positionX = x;
	positionY = y;
	positionZ = z;
	type = t;
	switch (t)
	{
	case TERRE:
		textureX = 0.01;
		textureY = 0.01;
		break;
	case SABLE:
		textureX = 0.07;
		textureY = 0.01;
		break;
	default:
		break;
	}
}

void cube::afficheCube()
{
	glBegin(GL_QUADS);
		// Devant
		glColor3f(1.0f, 1.0f, 1.0f); // ÑÕÉ«
		glTexCoord2f(textureX,      textureY);      glVertex3f(positionX,   positionY+1, positionZ+1);
		glTexCoord2f(textureX+0.05, textureY);      glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX+0.05, textureY+0.05); glVertex3f(positionX+1, positionY,   positionZ+1);
		glTexCoord2f(textureX,      textureY+0.05); glVertex3f(positionX,   positionY,   positionZ+1);

		// Gauche
		glTexCoord2f(textureX,      textureY);      glVertex3f(positionX, positionY+1, positionZ);
		glTexCoord2f(textureX+0.05, textureY);      glVertex3f(positionX, positionY,   positionZ);
		glTexCoord2f(textureX+0.05, textureY+0.05); glVertex3f(positionX, positionY,   positionZ+1);
		glTexCoord2f(textureX,      textureY+0.05); glVertex3f(positionX, positionY+1, positionZ+1);

		// Droite
		glTexCoord2f(textureX,      textureY);      glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX+0.05, textureY);      glVertex3f(positionX+1, positionY  , positionZ+1);
		glTexCoord2f(textureX+0.05, textureY+0.05); glVertex3f(positionX+1, positionY  , positionZ);
		glTexCoord2f(textureX,      textureY+0.05); glVertex3f(positionX+1, positionY+1, positionZ);

		// Derri¨¨re
		glTexCoord2f(textureX,      textureY);      glVertex3f(positionX+1, positionY+1, positionZ);
		glTexCoord2f(textureX+0.05, textureY);      glVertex3f(positionX+1, positionY  , positionZ);
		glTexCoord2f(textureX+0.05, textureY+0.05); glVertex3f(positionX  , positionY  , positionZ);
		glTexCoord2f(textureX,      textureY+0.05); glVertex3f(positionX  , positionY+1, positionZ);
	
		// Dessus
		glTexCoord2f(textureX,      textureY);      glVertex3f(positionX  , positionY+1, positionZ);
		glTexCoord2f(textureX+0.05, textureY);      glVertex3f(positionX  , positionY+1, positionZ+1);
		glTexCoord2f(textureX+0.05, textureY+0.05); glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX,      textureY+0.05); glVertex3f(positionX+1, positionY+1, positionZ);

		// Dessous
		glTexCoord2f(textureX,      textureY);      glVertex3f(positionX+1,positionY, positionZ+1);
		glTexCoord2f(textureX+0.05, textureY);      glVertex3f(positionX  ,positionY, positionZ+1);
		glTexCoord2f(textureX+0.05, textureY+0.05); glVertex3f(positionX  ,positionY, positionZ);
		glTexCoord2f(textureX,      textureY+0.05); glVertex3f(positionX+1,positionY, positionZ);

	glEnd();
}