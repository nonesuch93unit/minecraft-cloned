#ifndef CUBE_H
#define CUBE_H

#include <GL/glut.h>

#define TERRE 0
#define SABLE 1
#define BOIS 2
#define PIERRE 3

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

};

#endif