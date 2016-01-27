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
	float positionX,positionY,positionZ;
	int type;
	int chosen;

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

void gettexture(int t, float &x, float &y);

#endif