#ifndef VIEW_H
#define VIEW_H

class View
{
public:
	View();
	~View();
	void movement();

public:
	float mypositionX; //	Les coordonn¨¦es
	float mypositionY;
	float mypositionZ;
	float objectX;  //	Les coordonn¨¦es
	float objectY;
	float objectZ;
	float speedx;  //	Le vitesse
	float speedy;
	float speedz;
	float accelerx;  // 	L¡¯ acc¨¦l¨¦ration
	float accelery;
	float accelerz;
};

#endif
