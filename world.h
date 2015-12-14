#ifndef WORLD_H
#define WORLD_H

#include "cube.h"
#include <vector>
#include <iostream>
using namespace std;

class world
{
public:
	world(){}
	~world(){}
	bool addCube(float x, float y, float z, int t);
	bool deleteCube(float x, float y, float z);
	void generation();
	void afficheworld();

private:
	vector<cube> cubes;
};


#endif