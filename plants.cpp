#include "plants.h"

Plants::Plants(float x, float y, float z, int type)
{
	positionX = x;
	positionY = y;
	positionZ = z;
	this->type = type;
	textureX = 0 * 0.0625; textureY = 3 * 0.0625;
}												 

void Plants::affichePlants()
{
	glBegin(GL_QUADS);
		// Devant
		glColor3f(1.0f, 1.0f, 1.0f); // ��ɫ
		glTexCoord2f(textureX+0.005, textureY+0.060); glVertex3f(positionX,   positionY+1, positionZ+1);
		glTexCoord2f(textureX+0.060, textureY+0.060); glVertex3f(positionX+1, positionY+1, positionZ);
		glTexCoord2f(textureX+0.060, textureY+0.005); glVertex3f(positionX+1, positionY,   positionZ);
		glTexCoord2f(textureX+0.005, textureY+0.005); glVertex3f(positionX,   positionY,   positionZ+1);

		glTexCoord2f(textureX+0.005, textureY+0.060); glVertex3f(positionX,   positionY+1, positionZ);
		glTexCoord2f(textureX+0.060, textureY+0.060); glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX+0.060, textureY+0.005); glVertex3f(positionX+1, positionY,   positionZ+1);
		glTexCoord2f(textureX+0.005, textureY+0.005); glVertex3f(positionX,   positionY,   positionZ);
	glEnd();
}