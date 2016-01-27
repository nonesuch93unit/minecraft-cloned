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
	//--------------------------
	//-	Ajouter et suprimer les cubes and plants: 
	bool addCube(float x, float y, float z, int t);
	void addCubereplace(float x, float y, float z, int t);
	bool deleteCube(float x, float y, float z);
	bool existCube(float x, float y, float z);

	bool addplants(float x, float y, float z, int t);
	void addplantsreplace(float x, float y, float z, int t);
	bool deleteplants(float x, float y, float z);
	bool existplants(float x, float y, float z);

	//-------------------------------
	//-	Affichage de le monde virtuel:
	void generation();
	void afficheworld();
	
	//--------------------------
	//-	La collision
	bool collision();

	//--------------------------
	//les operations de viewers
	void viewerMovement();
	void vieweraddCube(int t);
	void vieweraddplants(int t);
	void viewerdelete();
	void viewerchoose();

	//-------------------------------
	//Lire et conserver un monde
	void savetheworld();
	void readtheworld();


private:
	map<int,Cube> cubes; //-	Enregitre les cubes et plants
	map<int,Plants> plants;
	int chosenx; int choseny; int chosenz; int chosen; //-	Un identificateur pour juger si un objet est s¨¦lectionn¨¦ et les coordonn¨¦es
	int frontx; int fronty; int frontz; //-	Le cube ou plante avant le cube choix
	

public:
	View viewer;  //-	Le point de vue
};


#endif