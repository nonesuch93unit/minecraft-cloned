#include "world.h"


bool World::addCube(float x, float y, float z, int t)
{
	int xx,yy,zz;
	(x < 0 && x != (int)x) ? xx = (int)x - 1 : xx = (int)x;
	(y < 0 && y != (int)y) ? yy = (int)y - 1 : yy = (int)y;
	(z < 0 && z != (int)z) ? zz = (int)z - 1 : zz = (int)z;

	if(existCube(xx,yy,zz))
	{
		cout << "the position has already existed a cube!" << endl;
		return false;
	}
	if(existplants(xx,yy,zz))
	{
		cout << "the position has already existed a plant!" << endl;
		return false;
	}
	Cube c(xx, yy, zz, t);
	int num = 1000000*(MAX+xx) + 1000*(MAX+yy) + (MAX+zz);
	cubes.insert(map<int, Cube> :: value_type(num, c));
	cout << "created a cube successfully! cube: (" << x << "," << y << "," <<z << ")" <<endl;
	return true;
}

void World::addCubereplace(float x, float y, float z, int t)
{
	int xx,yy,zz;
	(x < 0 && x != (int)x) ? xx = (int)x - 1 : xx = (int)x;
	(y < 0 && y != (int)y) ? yy = (int)y - 1 : yy = (int)y;
	(z < 0 && z != (int)z) ? zz = (int)z - 1 : zz = (int)z;

	int num = 1000000*(MAX+xx) + 1000*(MAX+yy) + (MAX+zz);
	if(cubes.find(num) != cubes.end())
	{
		//cout << "replaced!" << endl;
		cubes.erase(num);
	}
	
	if(plants.find(num) != plants.end())
	{
		//cout << "replaced!" << endl;
		plants.erase(num);
	}
	
	Cube c(xx, yy, zz, t);
	cubes.insert(map<int, Cube> :: value_type(num, c));
	//cout << "created a cube successfully! cube: (" << x << "," << y << "," <<z << ")" <<endl;
}

bool World::deleteCube(float x, float y, float z)
{
	int xx,yy,zz;
	(x < 0 && x != (int)x) ? xx = (int)x - 1 : xx = (int)x;
	(y < 0 && y != (int)y) ? yy = (int)y - 1 : yy = (int)y;
	(z < 0 && z != (int)z) ? zz = (int)z - 1 : zz = (int)z;

	int num = 1000000*(MAX+xx) + 1000*(MAX+yy) + (MAX+zz);
	if(cubes.find(num) != cubes.end())
	{
		cubes.erase(num);
		cout << "delete a cube successfully! cube: (" << x << "," << y << "," <<z <<")"<<endl;
		return true;
	}	
	cout << "the position has no cubes"<< endl;
	return false;
}

bool World::existCube(float x, float y, float z)
{
	int xx,yy,zz;
	(x < 0 && x != (int)x) ? xx = (int)x - 1 : xx = (int)x;
	(y < 0 && y != (int)y) ? yy = (int)y - 1 : yy = (int)y;
	(z < 0 && z != (int)z) ? zz = (int)z - 1 : zz = (int)z;
	int num = 1000000*(MAX+xx) + 1000*(MAX+yy) + (MAX+zz);
	if(cubes.find(num) != cubes.end())
	{
		return true;
	}
	return false;
}

bool World::addplants(float x, float y, float z, int t)
{
	int xx,yy,zz;
	(x < 0 && x != (int)x) ? xx = (int)x - 1 : xx = (int)x;
	(y < 0 && y != (int)y) ? yy = (int)y - 1 : yy = (int)y;
	(z < 0 && z != (int)z) ? zz = (int)z - 1 : zz = (int)z;

	if(existCube(xx,yy,zz))
	{
		cout << "the position has already existed a cube!" << endl;
		return false;
	}
	if(existplants(xx,yy,zz))
	{
		cout << "the position has already existed a plant!" << endl;
		return false;
	}
	Plants p(xx, yy, zz, t);
	int num = 1000000*(MAX+xx) + 1000*(MAX+yy) + (MAX+zz);
	plants.insert(map<int, Plants> :: value_type(num, p));
	cout << "created a cube successfully! cube: (" << x << "," << y << "," <<z << ")" <<endl;
	return true;
}

void World::addplantsreplace(float x, float y, float z, int t)
{
	int xx,yy,zz;
	(x < 0 && x != (int)x) ? xx = (int)x - 1 : xx = (int)x;
	(y < 0 && y != (int)y) ? yy = (int)y - 1 : yy = (int)y;
	(z < 0 && z != (int)z) ? zz = (int)z - 1 : zz = (int)z;

	int num = 1000000*(MAX+xx) + 1000*(MAX+yy) + (MAX+zz);
	if(cubes.find(num) != cubes.end())
	{
		//cout << "replaced!" << endl;
		cubes.erase(num);
	}
	
	if(plants.find(num) != plants.end())
	{
		//cout << "replaced!" << endl;
		plants.erase(num);
	}
	
	Plants p(xx, yy, zz, t);
	plants.insert(map<int, Plants> :: value_type(num, p));
	//cout << "created a cube successfully! cube: (" << x << "," << y << "," <<z << ")" <<endl;
}

bool World::deleteplants(float x, float y, float z)
{
	int xx,yy,zz;
	(x < 0 && x != (int)x) ? xx = (int)x - 1 : xx = (int)x;
	(y < 0 && y != (int)y) ? yy = (int)y - 1 : yy = (int)y;
	(z < 0 && z != (int)z) ? zz = (int)z - 1 : zz = (int)z;

	int num = 1000000*(MAX+xx) + 1000*(MAX+yy) + (MAX+zz);
	if(plants.find(num) != plants.end())
	{
		plants.erase(num);
		cout << "delete a cube successfully! cube: (" << x << "," << y << "," <<z <<")"<<endl;
		return true;
	}	
	cout << "the position has no cubes"<< endl;
	return false;
}

bool World::existplants(float x, float y, float z)
{
	int xx,yy,zz;
	(x < 0 && x != (int)x) ? xx = (int)x - 1 : xx = (int)x;
	(y < 0 && y != (int)y) ? yy = (int)y - 1 : yy = (int)y;
	(z < 0 && z != (int)z) ? zz = (int)z - 1 : zz = (int)z;
	int num = 1000000*(MAX+xx) + 1000*(MAX+yy) + (MAX+zz);
	if(plants.find(num) != plants.end())
	{
		return true;
	}
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
	addplants(0,1,0,1);
}

void World::afficheworld()
{
	map<int,Cube>::iterator i = cubes.begin();
	for(;i!=cubes.end(); i++)
	{
		i->second.afficheCube();
	}
	map<int,Plants>::iterator j = plants.begin();
	for(;j!=plants.end(); j++)
	{
		j->second.affichePlants();
	}
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

void World::vieweraddplants(int t)
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
			addplants(a,b,c,1);
			return;
		}
	}
}

void World::viewerdelete()
{
	if(chosen)
	{
		deleteCube(chosenx,choseny,chosenz);
		deleteplants(chosenx,choseny,chosenz);
	}
}

void World::viewerchoose()
{
	map<int,Cube>::iterator i = cubes.begin();
	for(;i!=cubes.end(); i++)
	{
		i->second.notchoosecube();
		chosen = 0;
	}
	map<int,Plants>::iterator j = plants.begin();
	for(;j!=plants.end(); j++)
	{
		j->second.notchooseplants();
		chosen = 0;
	}

	float x, y, z;
	int xlast = -MAX; int ylast = -MAX; int zlast = -MAX;
	for(int k = 1; k <= 25; k++)
	{
		x = viewer.mypositionX + k*1.0/2 * viewer.objectX;
		y = viewer.mypositionY + k*1.0/2 * viewer.objectY;
		z = viewer.mypositionZ + k*1.0/2 * viewer.objectZ;

		int xx,yy,zz;
		(x < 0 && x != (int)x) ? xx = (int)x - 1 : xx = (int)x;
		(y < 0 && y != (int)y) ? yy = (int)y - 1 : yy = (int)y;
		(z < 0 && z != (int)z) ? zz = (int)z - 1 : zz = (int)z;

		if(xlast == xx && ylast == yy && zlast == zz) continue;
		else
		{
			xlast = xx;
			ylast = yy;
			zlast = zz;
		}
		int num = 1000000*(MAX+xx) + 1000*(MAX+yy) + (MAX+zz);

		if(cubes.find(num)!=cubes.end())
		{
			cubes[num].choosecube();
			chosenx = xx; 
			choseny = yy;
			chosenz = zz;
			chosen = 1;
			return;
		}
		
		if(plants.find(num)!=plants.end())
		{
			plants[num].chooseplants();
			chosenx = xx; 
			choseny = yy;
			chosenz = zz;
			chosen = 1;
			return;
		}
	}
}

