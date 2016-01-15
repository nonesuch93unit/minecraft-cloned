#ifndef MOUSE_H
#define MOUSE_H

#include "world.h"

class Mouse
{
private:
	//int button;

public:
	void rightclick(World &world, int button);
	void mousemove(World &world, int x, int y, int width, int height);
};

void Mouse::rightclick(World &world, int button)
{
	if(button == 2) 
		world.vieweraddCube(1); 
	return;
}

void Mouse::mousemove(World &world, int x, int y, int width, int height)
{
	int centerX = width/2;
	int centerY = height/2;
	//cout << x << " " << y << endl;
	float ang = 0; float coefy = 0.7;
	ang = 0.003 * (x - centerX);
	coefy = 0.007 * (y - centerY);
	if(ang < 0) ang = -ang;
	if(coefy < 0) coefy = -coefy;

	if(x - centerX < 0)
	{
		world.viewer.objectX = cos(ang) * world.viewer.objectX + sin(ang) * world.viewer.objectZ;
		world.viewer.objectZ = -sin(ang) * world.viewer.objectX + cos(ang) * world.viewer.objectZ;
	}
	if(x - centerX > 0)
	{
		world.viewer.objectX = cos(-ang) * world.viewer.objectX + sin(-ang) * world.viewer.objectZ;
		world.viewer.objectZ = -sin(-ang) * world.viewer.objectX + cos(-ang) * world.viewer.objectZ;
	}
	if(y - centerY > 0)
	{
		world.viewer.objectY -= coefy;
	}
	if(y - centerY < 0)
	{
		world.viewer.objectY += coefy;
	}
	cout << ang << endl;
	
	if (x != centerX || y != centerY) glutWarpPointer(centerX, centerY);
}

#endif

