#include "world.h"


bool World::addCube(float x, float y, float z, int t)
{
	(x < 0 && x != (int)x) ? x = (int)x - 1 : x = (int)x;
	(y < 0 && y != (int)y) ? y = (int)y - 1 : y = (int)y;
	(z < 0 && z != (int)z) ? z = (int)z - 1 : z = (int)z;

	if(existCube(x,y,z))
	{
		cout << "the position has already existed a cube!" << endl;
		return false;
	}
	Cube c(x, y, z, t);
	cubes.push_back(c);
	cout << "created a cube successfully! cube: (" << x << "," << y << "," <<z << ")" <<endl;
	return true;
}

void World::addCubereplace(float x, float y, float z, int t)
{
	(x < 0 && x != (int)x) ? x = (int)x - 1 : x = (int)x;
	(y < 0 && y != (int)y) ? y = (int)y - 1 : y = (int)y;
	(z < 0 && z != (int)z) ? z = (int)z - 1 : z = (int)z;
	vector<Cube>::iterator i = cubes.begin();
	for(;i<cubes.end(); i++)
	{
		if(i->getpositionX() == x && i->getpositionY() == y && i->getpositionZ() == z)
		{
			//cout << "replaced!" << endl;
			cubes.erase(i);
			Cube c(x, y, z, t);
			cubes.push_back(c);
			return;
		}
	}
	Cube c(x, y, z, t);
	cubes.push_back(c);
	//cout << "created a cube successfully! cube: (" << x << "," << y << "," <<z << ")" <<endl;
}

bool World::deleteCube(float x, float y, float z)
{
	(x < 0 && x != (int)x) ? x = (int)x - 1 : x = (int)x;
	(y < 0 && y != (int)y) ? y = (int)y - 1 : y = (int)y;
	(z < 0 && z != (int)z) ? z = (int)z - 1 : z = (int)z;
	vector<Cube>::iterator i = cubes.begin();
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

void World::generation()
{
	for(int j = -3; j<0;j++)
	{
		for(int i = -10; i < 10;i++)
		{
			for(int k = -10; k < 10; k++)
			{
				addCubereplace(i,j,k,WATER);
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
					addCubereplace(i,j,k,SAND);
			}
		}
	}
	
	srand((unsigned)time(NULL));

}

void World::afficheworld()
{
	vector<Cube>::iterator i = cubes.begin();
	for(;i<cubes.end(); i++)
	{
		i->afficheCube();
	}
}

bool World::existCube(float x, float y, float z)
{
	(x < 0 && x != (int)x) ? x = (int)x - 1 : x = (int)x;
	(y < 0 && y != (int)y) ? y = (int)y - 1 : y = (int)y;
	(z < 0 && z != (int)z) ? z = (int)z - 1 : z = (int)z;
	vector<Cube>::iterator i = cubes.begin();
	for(;i<cubes.end(); i++)
	{
		if(i->getpositionX() == x && i->getpositionY() == y && i->getpositionZ() == z)
		{
			return true;
		}
	}
	return false;
}

bool World::collision()
{
	if(existCube(viewer.mypositionX, viewer.mypositionY-2, viewer.mypositionZ) && viewer.speedy < 0)
	{
		viewer.speedy = 0;
		return true;
	}
	if(existCube(viewer.mypositionX, viewer.mypositionY+1, viewer.mypositionZ) && viewer.speedy > 0)
	{
		viewer.speedy = 0;
		return true;
	}
	//
	if(existCube(viewer.mypositionX+1, viewer.mypositionY-1, viewer.mypositionZ) && viewer.speedx > 0)
	{
		viewer.speedx = 0;
		return true;
	}
	if(existCube(viewer.mypositionX-1, viewer.mypositionY-1, viewer.mypositionZ) && viewer.speedx < 0)
	{
		viewer.speedx = 0;
		return true;
	}
	if(existCube(viewer.mypositionX, viewer.mypositionY-1, viewer.mypositionZ+1) && viewer.speedz > 0)
	{
		viewer.speedz = 0;
		return true;
	}
	if(existCube(viewer.mypositionX, viewer.mypositionY-1, viewer.mypositionZ-1) && viewer.speedz < 0)
	{
		viewer.speedz = 0;
		return true;
	}
	//
	if(existCube(viewer.mypositionX+1, viewer.mypositionY, viewer.mypositionZ) && viewer.speedx > 0)
	{
		viewer.speedx = 0;
		return true;
	}
	if(existCube(viewer.mypositionX-1, viewer.mypositionY, viewer.mypositionZ) && viewer.speedx < 0)
	{
		viewer.speedx = 0;
		return true;
	}
	if(existCube(viewer.mypositionX, viewer.mypositionY, viewer.mypositionZ+1) && viewer.speedz > 0)
	{
		viewer.speedz = 0;
		return true;
	}
	if(existCube(viewer.mypositionX, viewer.mypositionY, viewer.mypositionZ-1) && viewer.speedz < 0)
	{
		viewer.speedz = 0;
		return true;
	}
	return false;
}

void World::viewerMovement()
{
	if(!collision())
	{
		viewer.movement();
	}
}

void World::vieweraddCube(int t)
{
	float a, b, c;
	for(int i = 2; i <= 5; i++)
	{
		a = viewer.mypositionX + i * viewer.objectX;
		b = viewer.mypositionY + i * viewer.objectY;
		c = viewer.mypositionZ + i * viewer.objectZ;
		if(existCube(a,b,c))
		{
			a = viewer.mypositionX + (i-0.5) * viewer.objectX;
			b = viewer.mypositionY + (i-0.5) * viewer.objectY;
			c = viewer.mypositionZ + (i-0.5) * viewer.objectZ;
			addCube(a,b,c,1);
			return;
		}
	}
}

void World::viewerdeletecube()
{
	if(chosen)
		deleteCube(chosenx,choseny,chosenz);
}

void World::viewerchoosecube()
{
	vector<Cube>::iterator i = cubes.begin();
	for(;i<cubes.end(); i++)
	{
		i->notchoosecube();
		chosen = 0;
	}

	float x, y, z;
	for(int j = 2; j <= 5; j++)
	{
		x = viewer.mypositionX + j * viewer.objectX;
		y = viewer.mypositionY + j * viewer.objectY;
		z = viewer.mypositionZ + j * viewer.objectZ;

		(x < 0 && x != (int)x) ? x = (int)x - 1 : x = (int)x;
		(y < 0 && y != (int)y) ? y = (int)y - 1 : y = (int)y;
		(z < 0 && z != (int)z) ? z = (int)z - 1 : z = (int)z;

		vector<Cube>::iterator i = cubes.begin();
		for(;i<cubes.end(); i++)
		{
			if(i->getpositionX() == x && i->getpositionY() == y && i->getpositionZ() == z)
			{
				i->choosecube();
				chosenx = x; 
				choseny = y;
				chosenz = z;
				chosen = 1;
				return;
			}
		}
	}
}