#include "world.h"


bool world::addCube(float x, float y, float z, int t)
{
	vector<cube>::iterator i = cubes.begin();
	for(;i<cubes.end(); i++)
	{
		if(i->getpositionX() == x && i->getpositionY() == y && i->getpositionZ() == z)
		{
			cout << "the position has already existed a cube!" << endl;
			return false;
		}
	}
	cube c(x, y, z, t);
	cubes.push_back(c);
	cout << "created a cube successfully! cube: (" << x << "," << y << "," <<z << ")" <<endl;
	return true;
}


bool world::deleteCube(float x, float y, float z)
{
	vector<cube>::iterator i = cubes.begin();
	for(;i<cubes.end(); i++)
	{
		if(i->getpositionX() == x && i->getpositionY() == y && i->getpositionZ() == z)
		{
			cubes.erase(i);
			cout << "delete a cube successfully! cube: (" << x << "," << y << "," <<z <<")"<<endl;
			return true;
		}
	}
	cout << "the position has no cubes"<< endl;
	return false;
}

void world::generation()
{

}

void world::afficheworld()
{
	vector<cube>::iterator i = cubes.begin();
	for(;i<cubes.end(); i++)
	{
		i->afficheCube();
	}
}