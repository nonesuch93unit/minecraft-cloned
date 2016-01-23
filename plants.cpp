#include "plants.h"

Plants::Plants(float x, float y, float z, int type)
{
	chosen = 0;
	positionX = x;
	positionY = y;
	positionZ = z;
	this->type = type;
	textureX = 12 * 0.0625; textureY = 0 * 0.0625;
}												 

void Plants::affichePlants()
{			
	if(chosen)
	{
		glColor3f(1.0f,0.0f,0.0f); 
		glBegin(GL_LINES);  
			glVertex3f(positionX-0.01,positionY-0.01,positionZ-0.01);     glVertex3f(positionX+1.01,positionY-0.01,positionZ-0.01);  
			glVertex3f(positionX-0.01,positionY-0.01,positionZ-0.01);     glVertex3f(positionX-0.01,positionY+1.01,positionZ-0.01);  
			glVertex3f(positionX-0.01,positionY+1.01,positionZ-0.01);     glVertex3f(positionX+1.01,positionY+1.01,positionZ-0.01);  
			glVertex3f(positionX+1.01,positionY-0.01,positionZ-0.01);     glVertex3f(positionX+1.01,positionY+1.01,positionZ-0.01);  

			glVertex3f(positionX-0.01,positionY-0.01,positionZ+1.01);     glVertex3f(positionX+1.01,positionY-0.01,positionZ+1.01);  
			glVertex3f(positionX-0.01,positionY-0.01,positionZ+1.01);     glVertex3f(positionX-0.01,positionY+1.01,positionZ+1.01);  
			glVertex3f(positionX-0.01,positionY+1.01,positionZ+1.01);     glVertex3f(positionX+1.01,positionY+1.01,positionZ+1.01);  
			glVertex3f(positionX+1.01,positionY-0.01,positionZ+1.01);     glVertex3f(positionX+1.01,positionY+1.01,positionZ+1.01);  

			glVertex3f(positionX-0.01,positionY-0.01,positionZ-0.01);     glVertex3f(positionX-0.01,positionY-0.01,positionZ+1.01);  
			glVertex3f(positionX-0.01,positionY+1.01,positionZ-0.01);     glVertex3f(positionX-0.01,positionY+1.01,positionZ+1.01);  
			glVertex3f(positionX+1.01,positionY-0.01,positionZ-0.01);     glVertex3f(positionX+1.01,positionY-0.01,positionZ+1.01);  
			glVertex3f(positionX+1.01,positionY+1.01,positionZ-0.01);     glVertex3f(positionX+1.01,positionY+1.01,positionZ+1.01); 
		glEnd(); 
	}

	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 1.0f); // ÑÕÉ«
		glTexCoord2f(textureX+0.060, textureY+0.005); glVertex3f(positionX,   positionY+1, positionZ+1);
		glTexCoord2f(textureX+0.005, textureY+0.005); glVertex3f(positionX+1, positionY+1, positionZ);
		glTexCoord2f(textureX+0.005, textureY+0.060); glVertex3f(positionX+1, positionY,   positionZ);
		glTexCoord2f(textureX+0.060, textureY+0.060); glVertex3f(positionX,   positionY,   positionZ+1);

		glTexCoord2f(textureX+0.060, textureY+0.005); glVertex3f(positionX,   positionY+1, positionZ);
		glTexCoord2f(textureX+0.005, textureY+0.005); glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX+0.005, textureY+0.060); glVertex3f(positionX+1, positionY,   positionZ+1);
		glTexCoord2f(textureX+0.060, textureY+0.060); glVertex3f(positionX,   positionY,   positionZ);
	glEnd();

	
}