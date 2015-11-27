#include <iostream>
#include <GL/glut.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


GLuint texture[1];

struct Image
{
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
};
typedef struct Image Image;


int ImageLoad(char *filename, Image *image)
{
    FILE *file;
    unsigned long size; 
    unsigned long i;   
    unsigned short int planes;
    unsigned short int bpp;
    char temp;            

    if ((file = fopen(filename, "rb")) == NULL)
    {
        printf("File Not Found: %s\n", filename);
        return 0;
    }


    fseek(file, 18, SEEK_CUR);


    if ((i = fread(&image->sizeX, 4, 1, file)) != 1)
    {
        printf("Error reading width from %s. \n", filename);
        return 0;
    }
    printf("Width of %s: %lu\n", filename, image->sizeX);
    

    if ((i = fread(&image->sizeY, 4, 1, file)) != 1)
    {
        printf("Error reading height from %s. \n", filename);
        return 0;
    }
    printf("Height of %s: %lu\n", filename, image->sizeY);


    size = image->sizeX * image->sizeY * 3;


    if ((fread(&planes, 2, 1, file)) != 1)
    {
        printf("Error reading planes from %s. \n", filename);
        return 0;
    }

    if (planes != 1)
    {
        printf("Planes from %s is not 1: %u\n", filename, planes);
        return 0;
    }

    if ((i = fread(&bpp, 2, 1, file)) != 1)
    {
        printf("Error reading bpp from %s. \n", filename);
        return 0;
    }
    if (bpp != 24)
    {
        printf("Bpp from %s is not 24: %u\n", filename, bpp);
        return 0;
    }


    fseek(file, 24, SEEK_CUR);


    image->data = (char*) malloc (size);
    if (image->data == NULL)
    {
        printf("Error allocating memory for color-corrected image data");
        return 0;
    }

    if ((i = fread(image->data, size, 1, file)) != 1)
    {
        printf("Error reading image data from %s. \n", filename);
        return 0;
    }

  
    for (i = 0; i < size; i += 3)
    {
        temp = image->data[i];
        image->data[i] = image->data[i+2];
        image->data[i+2] = temp;
    }


    return 1;
}

void LoadGLTextures()
{
    Image *image1 = new Image;
    if (image1 == NULL)
    {
        printf("Error allocating space for image");
        exit(0);
    }    

    if (!ImageLoad("texture.bmp", image1))
        exit(1);

    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY,
            0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
}

GLfloat g_angle = 0; 
void init()
{
  
    LoadGLTextures();
    glEnable(GL_TEXTURE_2D); 

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); 
    glClearDepth(1.0);                     
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
}


void timer(int p)
{
    glutPostRedisplay();
    glutTimerFunc(20, timer, 0);
}


void display()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
 glLoadIdentity(); 


 glTranslatef(0.0f, 0.0f, -6.0f);
 glRotatef(g_angle, 0.0, 1.0f, 0.0f);
 g_angle += 1.0f;


 glRotatef(g_angle, 1.0, 0.0f, 0.0f);
 glBegin(GL_QUADS);
    glTexCoord2f(0.01f, 0.01f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.06f, 0.01f); glVertex3f( 1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.06f, 0.06f); glVertex3f( 1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.01f, 0.06f); glVertex3f(-1.0f,-1.0f, 1.0f);

    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f,-1.0f);
    glTexCoord2f(0.0625f, 0.0f); glVertex3f(-1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.0625f, 0.0625f); glVertex3f(-1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0625f); glVertex3f(-1.0f, 1.0f, 1.0f);

    glTexCoord2f(0.0625f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0625f, 0.0625f); glVertex3f(1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0625f); glVertex3f(1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f,-1.0f);

    glTexCoord2f(0.0625f, 0.0f); glVertex3f( 1.0f, 1.0f,-1.0f);
    glTexCoord2f(0.0625f, 0.0625f); glVertex3f( 1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.0f, 0.0625f); glVertex3f(-1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f,-1.0f);
 
    glTexCoord2f(0.0f, 0.0625f); glVertex3f(-1.0f, 1.0f,-1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0625f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0625f, 0.0625f); glVertex3f( 1.0f, 1.0f,-1.0f);

    glTexCoord2f(0.0625f, 0.0625f); glVertex3f( 1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0625f); glVertex3f(-1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.0625f, 0.0f); glVertex3f( 1.0f,-1.0f,-1.0f);

 glEnd();

 gluLookAt(5,5,0,0,-1,0,0,1,0);

 glutSwapBuffers(); 
}


void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (h == 0) h = 1; 
    gluPerspective(45.0f,(GLfloat) w / (GLfloat)h , 0.5f, -1000.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27: 
            exit(0);
            break;
    }    
}


void MouseEvent(int button, int state, int x, int y)
{
}


void MotionMove(int x,int y)
{
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Minecraft");
    init();
    glutTimerFunc(20,timer,0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(MouseEvent);
    glutMotionFunc(MotionMove);
    glutMainLoop();

    return 0;
}
