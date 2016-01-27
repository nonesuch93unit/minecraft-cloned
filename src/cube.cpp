#include "cube.h"
#include <iostream>
#include <cstring>
using namespace std;

//constructeur d'un cube, et définit les textures de six surfaces
Cube::Cube(float x, float y, float z, int t)
{
	chosen = 0;
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
			textureY[i] = 0  ;
		}
		break;
	case SAND:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 2  ;
			textureY[i] = 1  ;
		}
		break;
	case WOOD:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 4  ;
			textureY[i] = 1  ;
		}
		textureX[4] = 5  ;
		textureY[4] = 1  ;
		textureX[5] = 5  ;
		textureY[5] = 1  ;
		break;
	case SAND2:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 0  ;
			textureY[i] = 11  ;
		}
		break;
	case WATER:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 13  ;
			textureY[i] = 12  ;
		}
		break;
	case BRICK:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 5  ;
			textureY[i] = 14  ;
		}
		break;
	case WOOD2:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 4  ;
			textureY[i] = 0  ;
		}
		break;
	case MAGMA:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 15  ;
			textureY[i] = 15  ;
		}
		break;
	case GRASSLAND:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 3  ;
			textureY[i] = 0  ;
		}
		textureX[4] = 0  ;
		textureY[4] = 0  ;
		textureX[5] = 2  ;
		textureY[5] = 0  ;
		break;
	case BOOKS:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 4  ;
			textureY[i] = 0  ;
		}
		textureX[0] = 4  ;
		textureY[0] = 12  ;
		textureX[3] = 4  ;
		textureY[3] = 12  ;
		break;


	case BOX:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 9  ;
			textureY[i] = 1  ;
		}
		break;
	case YUN:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 2  ;
			textureY[i] = 4  ;
		}

		break;
	case LEAVES:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 5  ;
			textureY[i] = 13  ;
		}
		break;
	case PIERRE1:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 0  ;
			textureY[i] = 1  ;
		}
		break;
	case PIERRE2:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 1  ;
			textureY[i] = 0  ;
		}
		break;
	case PIERRE3:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 4  ;
			textureY[i] = 2  ;
		}
		break;
	case PIERRE4:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 2  ;
			textureY[i] = 3  ;
		}
		break;
	case PIERRE5:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 5  ;
			textureY[i] = 3  ;
		}
		break;
	case PIERRE6:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 6  ;
			textureY[i] = 3  ;
		}
		break;
	case PIERRE7:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 1  ;
			textureY[i] = 2  ;
		}
		break;
	default:
		break;
	}

	//la position final d'un texture
	for(int i = 0; i < 6; i++)
	{
		textureX[i] = 0.0625 * textureX[i];
		textureY[i] = 0.0625 * textureY[i];
	}
}

//requête fonctions de Textures pour le 2d GUI, Il est affiché sur la barre d'outils
void gettexturecubeforGUI(int t, float &x, float &y)
{
	switch (t)
	{
	case LAND:
		x = 2  ;
		y = 0  ;
		break;
	case SAND:
		x = 2  ;
		y = 1  ;
		break;
	case WOOD:
		x = 4  ;
		y = 1  ;
		break;
	case SAND2:
		x = 0  ;
		y = 11  ;
		break;
	case WATER:
		x = 13  ;
		y = 12  ;
		break;
	case BRICK:
		x = 5  ;
		y = 14  ;
		break;
	case WOOD2:
		x = 4  ;
		y = 0  ;
		break;
	case MAGMA:
		x = 15  ;
		y = 15  ;
		break;
	case GRASSLAND:
		x = 3  ;
		y = 0  ;
		break;
	case BOOKS:
		x = 4  ;
		y = 12  ;
		break;


	case BOX:
		x = 9  ;
		y = 1  ;
		break;
	case YUN:
		x = 2  ;
		y = 4  ;
		break;
	case LEAVES:
		x = 5  ;
		y = 13  ;
		break;
	case PIERRE1:
		x = 0  ;
		y = 1  ;
		break;
	case PIERRE2:
		x = 1  ;
		y = 0  ;
		break;
	case PIERRE3:
		x = 4  ;
		y = 2  ;
		break;
	case PIERRE4:
		x = 2  ;
		y = 3  ;
		break;
	case PIERRE5:
		x = 5  ;
		y = 3  ;
		break;
	case PIERRE6:
		x = 6  ;
		y = 3  ;
		break;
	case PIERRE7:
		x = 1  ;
		y = 2  ;
		break;
	default:
		break;
	}

	
		x = 0.0625 * x;
		y = 0.0625 * y;
	
}

//affichage de un cube
void Cube::afficheCube()
{
	if(chosen) // Si un cube est sélectionné, il apparaît autour des lignes rouge
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
		// Devant	  
		glColor3f(1.0f, 1.0f, 1.0f); // 颜色
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.005); glVertex3f(positionX,   positionY+1, positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.005); glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.060); glVertex3f(positionX+1, positionY,   positionZ+1);
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.060); glVertex3f(positionX,   positionY,   positionZ+1);

		// Gauche
		glTexCoord2f(textureX[1]+0.060, textureY[1]+0.005); glVertex3f(positionX, positionY+1, positionZ);
		glTexCoord2f(textureX[1]+0.060, textureY[1]+0.060); glVertex3f(positionX, positionY,   positionZ);
		glTexCoord2f(textureX[1]+0.005, textureY[1]+0.060); glVertex3f(positionX, positionY,   positionZ+1);
		glTexCoord2f(textureX[1]+0.005, textureY[1]+0.005); glVertex3f(positionX, positionY+1, positionZ+1);
																											
		// Droite
		glTexCoord2f(textureX[1]+0.060, textureY[2]+0.005); glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX[1]+0.060, textureY[2]+0.060); glVertex3f(positionX+1, positionY  , positionZ+1);
		glTexCoord2f(textureX[1]+0.005, textureY[2]+0.060); glVertex3f(positionX+1, positionY  , positionZ);
		glTexCoord2f(textureX[1]+0.005, textureY[2]+0.005); glVertex3f(positionX+1, positionY+1, positionZ);
																											
		// Derrière							
		glTexCoord2f(textureX[3]+0.060, textureY[3]+0.005); glVertex3f(positionX+1, positionY+1, positionZ);
		glTexCoord2f(textureX[3]+0.060, textureY[3]+0.060); glVertex3f(positionX+1, positionY  , positionZ);
		glTexCoord2f(textureX[3]+0.005, textureY[3]+0.060); glVertex3f(positionX  , positionY  , positionZ);
		glTexCoord2f(textureX[3]+0.005, textureY[3]+0.005); glVertex3f(positionX  , positionY+1, positionZ);
	
		// Dessus
		glTexCoord2f(textureX[4]+0.005, textureY[4]+0.005); glVertex3f(positionX  , positionY+1, positionZ);
		glTexCoord2f(textureX[4]+0.060, textureY[4]+0.005); glVertex3f(positionX  , positionY+1, positionZ+1);
		glTexCoord2f(textureX[4]+0.060, textureY[4]+0.060); glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX[4]+0.005, textureY[4]+0.060); glVertex3f(positionX+1, positionY+1, positionZ);

		// Dessous
		glTexCoord2f(textureX[5]+0.005, textureY[5]+0.005); glVertex3f(positionX+1,positionY, positionZ+1);
		glTexCoord2f(textureX[5]+0.060, textureY[5]+0.005); glVertex3f(positionX  ,positionY, positionZ+1);
		glTexCoord2f(textureX[5]+0.060, textureY[5]+0.060); glVertex3f(positionX  ,positionY, positionZ);
		glTexCoord2f(textureX[5]+0.005, textureY[5]+0.060); glVertex3f(positionX+1,positionY, positionZ);

	glEnd();

	
}