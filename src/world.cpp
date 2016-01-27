#include "world.h"


bool World::addCube(float x, float y, float z, int t)
{
	//Prenant la partie enti¨¨re
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
	int num = 1000000*(MAX+xx) + 1000*(MAX+yy) + (MAX+zz);  // enregistrer une hash relation
	cubes.insert(map<int, Cube> :: value_type(num, c));
	cout << "created a cube successfully! cube: (" << x << "," << y << "," <<z << ")" <<endl;
	return true;
}

void World::addCubereplace(float x, float y, float z, int t)
{
	//Prenant la partie enti¨¨re
	int xx,yy,zz;
	(x < 0 && x != (int)x) ? xx = (int)x - 1 : xx = (int)x;
	(y < 0 && y != (int)y) ? yy = (int)y - 1 : yy = (int)y;
	(z < 0 && z != (int)z) ? zz = (int)z - 1 : zz = (int)z;

	int num = 1000000*(MAX+xx) + 1000*(MAX+yy) + (MAX+zz);
	if(cubes.find(num) != cubes.end()) // chercher avec la hash relation
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
	//Prenant la partie enti¨¨re
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
	//Prenant la partie enti¨¨re
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
	//Prenant la partie enti¨¨re
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
	//Prenant la partie enti¨¨re
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
	//Prenant la partie enti¨¨re
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
	//Prenant la partie enti¨¨re
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
				addCubereplace(i,j,k,SAND);
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
					addCubereplace(i,j,k,GRASSLAND);
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
	float x = viewer.mypositionX;
	float y = viewer.mypositionY;
	float z = viewer.mypositionZ;
	int xx,yy,zz;
	(x < 0 && x != (int)x) ? xx = (int)x - 1 : xx = (int)x;
	(y < 0 && y != (int)y) ? yy = (int)y - 1 : yy = (int)y;
	(z < 0 && z != (int)z) ? zz = (int)z - 1 : zz = (int)z;

	if(existCube(viewer.mypositionX, viewer.mypositionY-2, viewer.mypositionZ) && viewer.speedy < 0)
	{
		int num = 1000000*(MAX+xx) + 1000*(MAX+yy-2) + (MAX+zz);

		if(cubes.find(num)->second.gettype() != WATER && cubes.find(num)->second.gettype() != MAGMA) //l'eau et magma n'ont pas les collisions
			viewer.speedy = 0;
		//return true;
	}
	if(existCube(viewer.mypositionX, viewer.mypositionY+1, viewer.mypositionZ) && viewer.speedy > 0)
	{
		int num = 1000000*(MAX+xx) + 1000*(MAX+yy+1) + (MAX+zz);

		if(cubes.find(num)->second.gettype() != WATER && cubes.find(num)->second.gettype() != MAGMA)
		viewer.speedy = 0;
		//return true;
	}
	//
	if(existCube(viewer.mypositionX+1, viewer.mypositionY-1, viewer.mypositionZ) && viewer.speedx > 0)
	{
		int num = 1000000*(MAX+xx+1) + 1000*(MAX+yy-1) + (MAX+zz);

		if(cubes.find(num)->second.gettype() != WATER && cubes.find(num)->second.gettype() != MAGMA)
		viewer.speedx = 0;
		//return true;
	}
	if(existCube(viewer.mypositionX-1, viewer.mypositionY-1, viewer.mypositionZ) && viewer.speedx < 0)
	{
		int num = 1000000*(MAX+xx-1) + 1000*(MAX+yy-1) + (MAX+zz);

		if(cubes.find(num)->second.gettype() != WATER && cubes.find(num)->second.gettype() != MAGMA)
		viewer.speedx = 0;
		//return true;
	}
	if(existCube(viewer.mypositionX, viewer.mypositionY-1, viewer.mypositionZ+1) && viewer.speedz > 0)
	{
		int num = 1000000*(MAX+xx) + 1000*(MAX+yy-1) + (MAX+zz+1);

		if(cubes.find(num)->second.gettype() != WATER && cubes.find(num)->second.gettype() != MAGMA)
		viewer.speedz = 0;
		//return true;
	}
	if(existCube(viewer.mypositionX, viewer.mypositionY-1, viewer.mypositionZ-1) && viewer.speedz < 0)
	{
		int num = 1000000*(MAX+xx) + 1000*(MAX+yy-1) + (MAX+zz-1);

		if(cubes.find(num)->second.gettype() != WATER && cubes.find(num)->second.gettype() != MAGMA)
		viewer.speedz = 0;
		//return true;
	}
	//
	if(existCube(viewer.mypositionX+1, viewer.mypositionY, viewer.mypositionZ) && viewer.speedx > 0)
	{
		int num = 1000000*(MAX+xx+1) + 1000*(MAX+yy) + (MAX+zz);

		if(cubes.find(num)->second.gettype() != WATER && cubes.find(num)->second.gettype() != MAGMA)
		viewer.speedx = 0;
		//return true;
	}
	if(existCube(viewer.mypositionX-1, viewer.mypositionY, viewer.mypositionZ) && viewer.speedx < 0)
	{
		int num = 1000000*(MAX+xx-1) + 1000*(MAX+yy) + (MAX+zz);

		if(cubes.find(num)->second.gettype() != WATER && cubes.find(num)->second.gettype() != MAGMA)
		viewer.speedx = 0;
		//return true;
	}
	if(existCube(viewer.mypositionX, viewer.mypositionY, viewer.mypositionZ+1) && viewer.speedz > 0)
	{
		int num = 1000000*(MAX+xx) + 1000*(MAX+yy) + (MAX+zz+1);

		if(cubes.find(num)->second.gettype() != WATER && cubes.find(num)->second.gettype() != MAGMA)
		viewer.speedz = 0;
		//return true;
	}
	if(existCube(viewer.mypositionX, viewer.mypositionY, viewer.mypositionZ-1) && viewer.speedz < 0)
	{
		int num = 1000000*(MAX+xx) + 1000*(MAX+yy) + (MAX+zz-1);

		if(cubes.find(num)->second.gettype() != WATER && cubes.find(num)->second.gettype() != MAGMA)
		viewer.speedz = 0;
		//return true;
	}

	//---------------------
	if(viewer.mypositionY-2 < -MAX && viewer.speedy < 0)
	{
		viewer.speedy = 0;
		//return true;
	}
	if(viewer.mypositionY+1 > MAX && viewer.speedy > 0)
	{
		viewer.speedy = 0;
		//return true;
	}
	//
	if(viewer.mypositionX+1 > MAX && viewer.speedx > 0)
	{
		viewer.speedx = 0;
		//return true;
	}
	if(viewer.mypositionX-1 < -MAX && viewer.speedx < 0)
	{
		viewer.speedx = 0;
		//return true;
	}
	if(viewer.mypositionZ+1 > MAX && viewer.speedz > 0)
	{
		viewer.speedz = 0;
		//return true;
	}
	if(viewer.mypositionZ-1 < -MAX && viewer.speedz < 0)
	{
		viewer.speedz = 0;
		//return true;
	}
	return false;
}

void World::viewerMovement()
{
	collision();
	viewer.movement();
}

void World::vieweraddCube(int t)
{
	if(chosen)
	{
		float x = viewer.mypositionX;
		float y = viewer.mypositionY;
		float z = viewer.mypositionZ;
		int xx,yy,zz;
		(x < 0 && x != (int)x) ? xx = (int)x - 1 : xx = (int)x;
		(y < 0 && y != (int)y) ? yy = (int)y - 1 : yy = (int)y;
		(z < 0 && z != (int)z) ? zz = (int)z - 1 : zz = (int)z;

		if(xx == frontx && yy == fronty && zz == frontz) return;
		if(xx == frontx && yy-1 == fronty && zz == frontz) return;
		addCube(frontx,fronty,frontz,t);
	}
}

void World::vieweraddplants(int t)
{
	if(chosen)
	{
		float x = viewer.mypositionX;
		float y = viewer.mypositionY;
		float z = viewer.mypositionZ;
		int xx,yy,zz;
		(x < 0 && x != (int)x) ? xx = (int)x - 1 : xx = (int)x;
		(y < 0 && y != (int)y) ? yy = (int)y - 1 : yy = (int)y;
		(z < 0 && z != (int)z) ? zz = (int)z - 1 : zz = (int)z;

		if(xx == frontx && yy == fronty && zz == frontz) return;
		if(xx == frontx && yy-1 == fronty && zz == frontz) return;
		addplants(frontx,fronty,frontz,t);
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
	//initialisation
	map<int,Cube>::iterator i = cubes.begin();
	for(;i!=cubes.end(); i++)
	{
		i->second.notchoosecube();
	}
	map<int,Plants>::iterator j = plants.begin();
	for(;j!=plants.end(); j++)
	{
		j->second.notchooseplants();
	}
	chosen = 0;
	chosenx = 0; choseny = 0; chosenz = 0;
	frontx = -MAX; fronty = -MAX; frontz = -MAX;

	float x, y, z;
	int xlast = -MAX; int ylast = -MAX; int zlast = -MAX;
	for(int k = 1; k <= 80; k++)
	{
		// On a fait un ligne a partir de la position
		x = viewer.mypositionX + k*1.0/5 * viewer.objectX;
		y = viewer.mypositionY + k*1.0/5 * viewer.objectY;
		z = viewer.mypositionZ + k*1.0/5 * viewer.objectZ;

		int xx,yy,zz;
		(x < 0 && x != (int)x) ? xx = (int)x - 1 : xx = (int)x;
		(y < 0 && y != (int)y) ? yy = (int)y - 1 : yy = (int)y;
		(z < 0 && z != (int)z) ? zz = (int)z - 1 : zz = (int)z;

		if(xlast == xx && ylast == yy && zlast == zz) continue;
		
		int num = 1000000*(MAX+xx) + 1000*(MAX+yy) + (MAX+zz); // hash cherche

		if(cubes.find(num)!=cubes.end())
		{
			cubes[num].choosecube();
			chosenx = xx; 
			choseny = yy;
			chosenz = zz;
			frontx = xlast;
			fronty = ylast;
			frontz = zlast;
			chosen = 1;
			return;
		}
		
		if(plants.find(num)!=plants.end())
		{
			plants[num].chooseplants();
			chosenx = xx; 
			choseny = yy;
			chosenz = zz;
			frontx = xlast;
			fronty = ylast;
			frontz = zlast;
			chosen = 1;
			return;
		}

		
		xlast = xx;
		ylast = yy;
		zlast = zz;
		
	}
}

void World::savetheworld()
{
	ofstream outFile("save.txt",ios::out);
	outFile << viewer.mypositionX << " " << viewer.mypositionY << " " << viewer.mypositionZ << " ";
	outFile << viewer.objectX << " " << viewer.objectY << " " << viewer.objectZ << endl;

	map<int,Cube>::iterator i = cubes.begin();
	for(;i!=cubes.end(); i++)
	{
		outFile << i->second.getpositionX() << " " << i->second.getpositionY() << " " << i->second.getpositionZ() << " " << i->second.gettype() << endl;
	}
	outFile << 1000 << " " << 1000 << " " << 1000 << " " << 1000 << endl;
	map<int,Plants>::iterator j = plants.begin();
	for(;j!=plants.end(); j++)
	{
		outFile << j->second.getpositionX() << " " << j->second.getpositionY() << " " << j->second.getpositionZ() << " " << j->second.gettype() << endl;
	}
	outFile << endl;
}

void World::readtheworld()
{
	ifstream inFile("save.txt", ios::in);
	inFile >>  viewer.mypositionX >> viewer.mypositionY >> viewer.mypositionZ;
	inFile >> viewer.objectX >> viewer.objectY >> viewer.objectZ;

	int a,b,c,d;
	while(1)
	{
		inFile >> a >> b >> c >> d;
		if(a != 1000)
		{
			addCubereplace(a,b,c,d);
			continue;
		}
		else
			break;
	}
	while(1)
	{
		if(inFile.eof()) break;
		inFile >> a >> b >> c >> d;
		addplantsreplace(a,b,c,d);
	}
}