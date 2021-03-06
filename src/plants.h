#ifndef PLANTS_H
#define PLANTS_H

#include <GL/glut.h>

#define PLANT1 20
#define PLANT2 21
#define PLANT3 22
#define PLANT4 23
#define PLANT5 24
#define PLANT6 25
#define PLANT7 26
#define PLANT8 27
#define PLANT9 28
#define PLANT0 29

class Plants
{
private:
	float positionX,positionY,positionZ; //-	Les coordonn��es de cube et plant
	int type; //-	Le type de cube et plant
	int chosen; //-	Un identificateur pour juger si un objet est s��lectionn��

public:
	float textureX, textureY;

public:
	Plants(){}
	~Plants(){}
	Plants(float x, float y, float z, int type);
	void affichePlants();
	float getpositionX(){return positionX;}
	float getpositionY(){return positionY;}
	float getpositionZ(){return positionZ;}
	int gettype(){return type;}
	void chooseplants(){chosen = 1;}
	void notchooseplants(){chosen = 0;}
};

//Il est affich�� sur la barre d'outils
void gettextureplantsforGUI(int type, float &x, float &y);

#endif