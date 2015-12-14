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
		textureX = 2 * 0.0625;
		textureY = 15 * 0.0625;
		break;
	case SABLE:
		textureX = 2 * 0.0625;
		textureY = 14 * 0.0625;
		break;
	case WOOD:
		textureX = 4 * 0.0625;
		textureY = 15 * 0.0625;
		break;
	case PIERRE:
		textureX = 0 * 0.0625;
		textureY = 15 * 0.0625;
		break;
	case WATER:
		textureX = 15 * 0.0625;
		textureY = 3 * 0.0625;
		break;
	case BRICK:
		textureX = 7 * 0.0625;
		textureY = 15 * 0.0625;
		break;
	case SNOW:
		textureX = 2 * 0.0625;
		textureY = 11 * 0.0625;
		break;
	case MAGMA:
		textureX = 15 * 0.0625;
		textureY = 0 * 0.0625;
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
		glTexCoord2f(textureX+0.0625, textureY);      glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX+0.0625, textureY+0.0625); glVertex3f(positionX+1, positionY,   positionZ+1);
		glTexCoord2f(textureX,      textureY+0.0625); glVertex3f(positionX,   positionY,   positionZ+1);

		// Gauche
		glTexCoord2f(textureX,      textureY);      glVertex3f(positionX, positionY+1, positionZ);
		glTexCoord2f(textureX+0.0625, textureY);      glVertex3f(positionX, positionY,   positionZ);
		glTexCoord2f(textureX+0.0625, textureY+0.0625); glVertex3f(positionX, positionY,   positionZ+1);
		glTexCoord2f(textureX,      textureY+0.0625); glVertex3f(positionX, positionY+1, positionZ+1);

		// Droite
		glTexCoord2f(textureX,      textureY);      glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX+0.0625, textureY);      glVertex3f(positionX+1, positionY  , positionZ+1);
		glTexCoord2f(textureX+0.0625, textureY+0.0625); glVertex3f(positionX+1, positionY  , positionZ);
		glTexCoord2f(textureX,      textureY+0.0625); glVertex3f(positionX+1, positionY+1, positionZ);

		// Derri¨¨re
		glTexCoord2f(textureX,      textureY);      glVertex3f(positionX+1, positionY+1, positionZ);
		glTexCoord2f(textureX+0.0625, textureY);      glVertex3f(positionX+1, positionY  , positionZ);
		glTexCoord2f(textureX+0.0625, textureY+0.0625); glVertex3f(positionX  , positionY  , positionZ);
		glTexCoord2f(textureX,      textureY+0.0625); glVertex3f(positionX  , positionY+1, positionZ);
	
		// Dessus
		glTexCoord2f(textureX,      textureY);      glVertex3f(positionX  , positionY+1, positionZ);
		glTexCoord2f(textureX+0.0625, textureY);      glVertex3f(positionX  , positionY+1, positionZ+1);
		glTexCoord2f(textureX+0.0625, textureY+0.0625); glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX,      textureY+0.0625); glVertex3f(positionX+1, positionY+1, positionZ);

		// Dessous
		glTexCoord2f(textureX,      textureY);      glVertex3f(positionX+1,positionY, positionZ+1);
		glTexCoord2f(textureX+0.0625, textureY);      glVertex3f(positionX  ,positionY, positionZ+1);
		glTexCoord2f(textureX+0.0625, textureY+0.0625); glVertex3f(positionX  ,positionY, positionZ);
		glTexCoord2f(textureX,      textureY+0.0625); glVertex3f(positionX+1,positionY, positionZ);

	glEnd();
}