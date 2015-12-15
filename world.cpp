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

void world::addCube2(float x, float y, float z, int t)
{
	vector<cube>::iterator i = cubes.begin();
	for(;i<cubes.end(); i++)
	{
		if(i->getpositionX() == x && i->getpositionY() == y && i->getpositionZ() == z)
		{
			//cout << "replaced!" << endl;
			cubes.erase(i);
			cube c(x, y, z, t);
			cubes.push_back(c);
			return;
		}
	}
	cube c(x, y, z, t);
	cubes.push_back(c);
	//cout << "created a cube successfully! cube: (" << x << "," << y << "," <<z << ")" <<endl;
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
	for(int j = -3; j<0;j++)
	{
		for(int i = -10; i < 10;i++)
		{
			for(int k = -10; k < 10; k++)
			{
				addCube2(i,j,k,WATER);
			}
		}
	}
	for(int j = -3; j<1;j++)
	{
		for(int i = -5; i < 5;i++)
		{
			for(int k = -5; k < 5; k++)
			{
				if(i+k+2*j < 3 && 2*i+2*j-k < 7 && -i+2*j+k < 6 && -3*i+2*j- k < 6)
					addCube2(i,j,k,SAND);
			}
		}
	}
	
	srand((unsigned)time(NULL));

}

void world::afficheworld()
{
	vector<cube>::iterator i = cubes.begin();
	for(;i<cubes.end(); i++)
	{
		i->afficheCube();
	}
}