#ifndef MOUSE_H
#define MOUSE_H

#include "world.h"

class Mouse
{
private:
	//int button;

public:
	void leftclick(World &world, int button);
	void rightclick(World &world, int button, int type);
	void mousemove(World &world, int x, int y, int width, int height);
};

void Mouse::leftclick(World &world, int button)
{
	world.viewerdelete(); 
}

void Mouse::rightclick(World &world, int button, int type)
{
	if(type < 20)
		world.vieweraddCube(type); 
	else 
		world.vieweraddplants(type);
}

void Mouse::mousemove(World &world, int x, int y, int width, int height)
{
	int centerX = width/2;
	int centerY = height/2;
	//cout << x << " " << y << endl;
	float ang = 0; float coefy = 0;
	ang = 0.0025 * (x - centerX);
	coefy = 0.002 * (y - centerY);
	if(ang < 0) ang = -ang;
	if(coefy < 0) coefy = -coefy;

	if(x - centerX < 0)
	{
		float x = world.viewer.objectX;
		float z = world.viewer.objectZ;
		world.viewer.objectX = cos(ang) * x + sin(ang) * z;
		world.viewer.objectZ = -sin(ang) * x + cos(ang) * z;
	}
	if(x - centerX > 0)
	{
		float x = world.viewer.objectX;
		float z = world.viewer.objectZ;
		world.viewer.objectX = cos(-ang) * x + sin(-ang) * z;
		world.viewer.objectZ = -sin(-ang) * x + cos(-ang) * z;
	}
	if(y - centerY > 0)
	{
		world.viewer.objectY -= sin(coefy);
	}
	if(y - centerY < 0)
	{
		world.viewer.objectY += sin(coefy);
	}
	//cout << ang << endl;
	
	if (x != centerX || y != centerY) glutWarpPointer(centerX, centerY);
}

#endif

