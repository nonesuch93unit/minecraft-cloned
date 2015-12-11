<<<<<<< HEAD
#ifndef FONT_H
#define FONT_H

=======
>>>>>>> origin/master
#include <GL/glut.h>
#include<Windows.h>

class font
{
private:
	GLuint base;

public:
	GLvoid BuildFont(GLvoid);
	void glPrint(const char *pstr);
	GLvoid KillFont(GLvoid);

};

<<<<<<< HEAD
#endif
=======
>>>>>>> origin/master
