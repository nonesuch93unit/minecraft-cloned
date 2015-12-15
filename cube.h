#ifndef CUBE_H
#define CUBE_H

#include <GL/glut.h>
#include <string.h>

#define LAND 0
#define SAND 1
#define WOOD 2
#define PIERRE 3
#define WATER 4
#define BRICK 5
#define SNOW 6
#define MAGMA 7
#define GRASSLAND 8

class cube
{
private:
	float positionX,positionY,positionZ;
	float textureX[6], textureY[6];
	int type;

public:
	cube(){}
	~cube(){}
	cube(float x, float y, float z, int type);
	void afficheCube();
	float getpositionX(){return positionX;}
	float getpositionY(){return positionY;}
	float getpositionZ(){return positionZ;}

};

#endif