#ifndef VIEW_H
#define VIEW_H

class View
{
public:
	View();
	~View();
	void movement();

public:
	float mypositionX;
	float mypositionY;
	float mypositionZ;
	float objectX;
	float objectY;
	float objectZ;
	float speedx;
	float speedy;
	float speedz;
	float accelerx;
	float accelery;
	float accelerz;
};

#endif
