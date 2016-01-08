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
	bool vieweraddCube(int t);

private:
	vector<Cube> cubes;

public:
	View viewer;
};


#endif