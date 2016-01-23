#ifndef PLANTS_H
#define PLANTS_H

#include <GL/glut.h>

class Plants
{
private:
	float positionX,positionY,positionZ;
	int type;
	float textureX, textureY;
	int chosen;

public:
	Plants(){}
	~Plants(){}
	Plants(float x, float y, float z, int type);
	void affichePlants();
	float getpositionX(){return positionX;}
	float getpositionY(){return positionY;}
	float getpositionZ(){return positionZ;}
	void chooseplants(){chosen = 1;}
	void notchooseplants(){chosen = 0;}
};

#endif