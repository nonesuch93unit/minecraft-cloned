#ifndef WORLD_H
#define WORLD_H

#include "cube.h"
#include "View.h"
#include <map>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "plants.h"
#include <fstream>
using namespace std;

#define MAX 16

class World
{
public:
	World(){}
	~World(){}
	bool addCube(float x, float y, float z, int t);
	void addCubereplace(float x, float y, float z, int t);
	bool deleteCube(float x, float y, float z);
	bool existCube(float x, float y, float z);

	bool addplants(float x, float y, float z, int t);
	void addplantsreplace(float x, float y, float z, int t);
	bool deleteplants(float x, float y, float z);
	bool existplants(float x, float y, float z);

	void generation();
	void afficheworld();
	

	bool collision();
	void viewerMovement();
	void vieweraddCube(int t);
	void vieweraddplants(int t);

	void viewerdelete();
	void viewerchoose();

	void savetheworld();
	void readtheworld();


private:
	map<int,Cube> cubes;
	map<int,Plants> plants;
	int chosenx; int choseny; int chosenz;
	int frontx; int fronty; int frontz;
	int chosen;

public:
	View viewer;
};


#endif