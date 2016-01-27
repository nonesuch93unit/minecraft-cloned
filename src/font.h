#ifndef FONT_H
#define FONT_H

#include <GL/glut.h>
#include<Windows.h>

class Font
{
private:
	GLuint base;

public:
	GLvoid BuildFont(GLvoid);
	void glPrint(const char *pstr);
	GLvoid KillFont(GLvoid);

};

#endif