#ifndef CUBE_H
#define CUBE_H

#include <GL/glut.h>
#include <string.h>

#define LAND 0
#define GRASSLAND 1
#define SAND 2
#define WOOD 3
#define SAND2 4
#define WATER 5
#define BRICK 6
#define WOOD2 7
#define MAGMA 8
#define BOOKS 9
#define BOX 10
#define YUN 11
#define LEAVES 12
#define PIERRE1 13
#define PIERRE2 14
#define PIERRE3 15
#define PIERRE4 16
#define PIERRE5 17
#define PIERRE6 18
#define PIERRE7 19

class Cube
{
private:
	float positionX,positionY,positionZ;  //-	Les coordonn¨¦es de cube et plant
	int type; //-	Le type de cube et plant
	int chosen; //-	Un identificateur pour juger si un objet est s¨¦lectionn¨¦

public:
	float textureX[6], textureY[6];

public:
	Cube(){}
	~Cube(){}
	Cube(float x, float y, float z, int type);
	void afficheCube();
	float getpositionX(){return positionX;}
	float getpositionY(){return positionY;}
	float getpositionZ(){return positionZ;}
	int gettype(){return type;}
	void choosecube(){chosen = 1;}
	void notchoosecube(){chosen = 0;}
	
};

//Il est affich¨¦ sur la barre d'outils
void gettexturecubeforGUI(int t, float &x, float &y);

#endif