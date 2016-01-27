#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "world.h"

class Keyboard
{
private:
	int keys[200];

public:
	Keyboard(){for(int i = 0; i<200;i++) keys[i] = 0;}
	int getkey(char key){return keys[key];}
	void keyboardmovement(World &world);
	void setkeydown(char key){keys[key] = 1;return;}
	void setkeyup(char key){keys[key] = 0;return;}
};

void Keyboard::keyboardmovement(World &world)
{
	float speedmax = 0.3; float coef = 0.1;
	for(int i = 0; i<200; i++)
	{
		if(keys[i])
		{
			switch (i)
			{
				case 'w': 
					world.viewer.speedx += coef * world.viewer.objectX;
					world.viewer.speedz += coef * world.viewer.objectZ;
					
	
					break;
				case 's': 
					world.viewer.speedx += -coef * world.viewer.objectX;
					world.viewer.speedz += -coef * world.viewer.objectZ;
	
					break;
				case 'a': 
					world.viewer.speedx += coef * world.viewer.objectZ;
					world.viewer.speedz += -coef * world.viewer.objectX;
			
					break;
				case 'd': 
					world.viewer.speedx += -coef * world.viewer.objectZ;
					world.viewer.speedz += coef * world.viewer.objectX;
					break;
				case ' ':
					if(world.viewer.speedy > -0.1 && world.viewer.speedy < 0.1)
						world.viewer.speedy = 0.25;
					break;
				case 'q': 
					world.viewer.mypositionY += 0.1 ;
					break;
				case 'e': 
					world.viewer.mypositionY -= 0.1 ;
					break;
				case 'o': 
					exit(0);
					break;
				case 27: 
					world.savetheworld();
					cout << "sucessful to save!" << endl;
					exit(0);
					break;
			}    
		}
	}
	if(world.viewer.speedx > speedmax) world.viewer.speedx = speedmax;
	if(world.viewer.speedx < -speedmax) world.viewer.speedx = -speedmax;
	if(world.viewer.speedz > speedmax) world.viewer.speedz = speedmax;
	if(world.viewer.speedz < -speedmax) world.viewer.speedz = -speedmax;
}

#endif