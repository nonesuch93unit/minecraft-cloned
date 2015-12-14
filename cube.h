#ifndef CUBE_H
#define CUBE_H

#include <GL/glut.h>

#define TERRE 0
#define SABLE 1
#define WOOD 2
#define PIERRE 3
#define WATER 4
#define BRICK 5
#define SNOW 6
#define MAGMA 7

class cube
{
private:
	float positionX,positionY,positionZ;
	float textureX, textureY;
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