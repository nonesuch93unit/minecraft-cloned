#include "plants.h"

//constructeur d'un plante, et définit les textures de surfaces
Plants::Plants(float x, float y, float z, int type)
{
	chosen = 0;
	positionX = x;
	positionY = y;
	positionZ = z;
	this->type = type;

	switch (type)
	{
	case PLANT1:
		textureX = 12;
		textureY = 0;
		break;
	case PLANT2:
		textureX = 13;
		textureY = 0;
		break;
	case PLANT3:
		textureX = 15;
		textureY = 0;
		break;
	case PLANT4:
		textureX = 12;
		textureY = 1;
		break;
	case PLANT5:
		textureX = 13;
		textureY = 1;
		break;
	case PLANT6:
		textureX = 15;
		textureY = 3;
		break;
	case PLANT7:
		textureX = 15;
		textureY = 4;
		break;
	case PLANT8:
		textureX = 15;
		textureY = 5;
		break;
	case PLANT9:
		textureX = 4;
		textureY = 14;
		break;
	case PLANT0:
		textureX = 2;
		textureY = 14;
		break;
	}

	//la position final d'un texture
	textureX = textureX * 0.0625; textureY = textureY * 0.0625;
}

//requête fonctions de Textures pour le 2d GUI, Il est affiché sur la barre d'outils
void Plants::affichePlants()
{			
	if(chosen) // Si un plante est sélectionné, il apparaît autour des lignes rouge
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
		glColor3f(1.0f, 1.0f, 1.0f); // 颜色
		glTexCoord2f(textureX+0.060, textureY+0.005); glVertex3f(positionX+0.12,   positionY+1, positionZ+0.88);
		glTexCoord2f(textureX+0.005, textureY+0.005); glVertex3f(positionX+0.88, positionY+1,   positionZ+0.12);
		glTexCoord2f(textureX+0.005, textureY+0.060); glVertex3f(positionX+0.88, positionY,     positionZ+0.12);
		glTexCoord2f(textureX+0.060, textureY+0.060); glVertex3f(positionX+0.12,   positionY,   positionZ+0.88);

		glTexCoord2f(textureX+0.060, textureY+0.005); glVertex3f(positionX+0.12,   positionY+1,   positionZ+0.12);
		glTexCoord2f(textureX+0.005, textureY+0.005); glVertex3f(positionX+0.88, positionY+1,     positionZ+0.88);
		glTexCoord2f(textureX+0.005, textureY+0.060); glVertex3f(positionX+0.88, positionY,       positionZ+0.88);
		glTexCoord2f(textureX+0.060, textureY+0.060); glVertex3f(positionX+0.12,   positionY,     positionZ+0.12);
	glEnd();

	
}

//affichage de un plante
void gettextureplantsforGUI(int type, float &textureX, float &textureY)
{
	switch (type)
	{
	case PLANT1:
		textureX = 12;
		textureY = 0;
		break;
	case PLANT2:
		textureX = 13;
		textureY = 0;
		break;
	case PLANT3:
		textureX = 15;
		textureY = 0;
		break;
	case PLANT4:
		textureX = 12;
		textureY = 1;
		break;
	case PLANT5:
		textureX = 13;
		textureY = 1;
		break;
	case PLANT6:
		textureX = 15;
		textureY = 3;
		break;
	case PLANT7:
		textureX = 15;
		textureY = 4;
		break;
	case PLANT8:
		textureX = 15;
		textureY = 5;
		break;
	case PLANT9:
		textureX = 4;
		textureY = 14;
		break;
	case PLANT0:
		textureX = 2;
		textureY = 14;
		break;
	}
	textureX *= 0.0625;
	textureY *= 0.0625;
}