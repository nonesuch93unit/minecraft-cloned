#ifndef PLANTS_H
#define PLANTS_H

#include <GL/glut.h>

class Plants
{
private:
	float positionX,positionY,positionZ;
	int type;
	float textureX, textureY;

public:
	Plants(float x, float y, float z, int type);
	void affichePlants();
};

#endif