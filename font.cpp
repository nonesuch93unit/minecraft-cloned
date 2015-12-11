#include "font.h"

GLvoid font::BuildFont(GLvoid)
{
	HFONT font;		
	HFONT oldfont;

	base = glGenLists(256);		
	font = CreateFont(-24,		
						0,		
						0,		
						0,		
						FW_BOLD,
						FALSE,	
						FALSE,	
						FALSE,	
						ANSI_CHARSET,	
						OUT_TT_PRECIS,	
						CLIP_DEFAULT_PRECIS,	
						ANTIALIASED_QUALITY,	
						FF_DONTCARE|DEFAULT_PITCH,	
						TEXT("Courier New"));	
	oldfont = (HFONT)SelectObject(wglGetCurrentDC(), font);
	wglUseFontBitmaps(wglGetCurrentDC(), 0, 256, base);		
	SelectObject(wglGetCurrentDC(), oldfont);
	DeleteObject(font);

}

void font::glPrint(const char *pstr)
{
	glPushAttrib(GL_LIST_BIT);	
	glListBase(base - 0);		
	glCallLists(strlen(pstr), GL_UNSIGNED_BYTE, pstr);	
	glPopAttrib();				

}

GLvoid font::KillFont(GLvoid)
{
	glDeleteLists(base, 256); 
}