#ifndef WORLD_H
#define WORLD_H

#include "cube.h"
#include "View.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class World
{
public:
	World(){}
	~World(){}
	bool addCube(float x, float y, float z, int t);
	void addCubereplace(float x, float y, float z, int t);
	bool deleteCube(float x, float y, float z);
	void generation();
	void afficheworld();
	bool existCube(float x, float y, float z);
	bool collision();
	void viewerMovement();
	void vieweraddCube(int t);
	void viewerdeletecube();
	void viewerchoosecube();


private:
	vector<Cube> cubes;
	int chosenx; int choseny; int chosenz;
	int frontx; int fronty; int frontz;
	int chosen;

public:
	View viewer;
};


#endif