#include"View.h"

View::View()
{
	mypositionX = 0;
	mypositionY = 8;
	mypositionZ = 8;
	objectX = 0;
	objectY = 0;
	objectZ = -1;
	speedx = 0;
	speedy = 0;
	speedz = 0;
	accelerx = 0;
	accelery = -0.01;
	accelerz = 0;
	m_lastx = 0;
	m_lasty = 0;
}

View::~View()
{
}

void View::movement()
{
	if(speedx != 0 || speedz != 0)
	{
		accelerx = -0.1 * speedx;
		accelerz = -0.1 * speedz;
	}
	mypositionX += speedx;
	mypositionY += speedy;
	mypositionZ += speedz;
	speedx += accelerx;
	speedy += accelery;
	speedz += accelerz;
	
}