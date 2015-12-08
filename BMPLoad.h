#include <iostream>
#include <GL/glut.h>
using namespace std;

// Lire l'image bmp
// Les caract¨¦ristiques d'image(largeur,hauteur et data)
class Image
{
public:
    int sizeX;
    int sizeY;
    char *data;
};


int ImageLoad(char *filename, Image *image) //leture un image. retour 1 si echec, return 0 si reussir
{
    FILE *file;
    unsigned long size; // Longueur d'image
    unsigned long i;   	// Compter
    unsigned short int planes;
    unsigned short int bpp;
    char temp;            

    if ((file = fopen(filename, "rb")) == NULL)
    {
        cout << "File Not Found: " << filename<< endl;
        return 0;
    }

	// Ombre la t¨ºte du fichier£¬lire la largueur et hauteur
    fseek(file, 18, SEEK_CUR);

	// Lire la largeur
    if ((i = fread(&image->sizeX, 4, 1, file)) != 1)
    {
        cout << "Error reading width from " << filename<< endl;
        return 0;
    }
    cout << "Width of  " <<  filename << ":" <<  image->sizeX<< endl;
    
	// Lire la hauteur
    if ((i = fread(&image->sizeY, 4, 1, file)) != 1)
    {
       cout << "Error reading height from " <<  filename<< endl;
        return 0;
    }
    cout << "Height of  " << filename << ":"<< image->sizeY;

	// Calculer la longueur(24bits ou 3bytes chaque pixel)
    size = image->sizeX * image->sizeY * 3;


    if ((fread(&planes, 2, 1, file)) != 1)
    {
        cout << "Error reading planes from" <<  filename << endl;
        return 0;
    }

    if (planes != 1)
    {
        cout << "Planes from " <<  filename <<" is not 1: "  << planes<< endl;
        return 0;
    }

    if ((i = fread(&bpp, 2, 1, file)) != 1)
    {
        cout << "Error reading bpp from " << filename<< endl;
        return 0;
    }
    if (bpp != 24)
    {
        cout <<"Bpp from "<< filename<<" is not 24: " << bpp<< endl;
        return 0;
    }

	// Ombre les fichiers d't¨ºtes restants
    fseek(file, 24, SEEK_CUR);


    image->data = (char*) malloc (size);
    if (image->data == NULL)
    {
        cout << "Error allocating memory for color-corrected image data" << endl;
        return 0;
    }

    if ((i = fread(image->data, size, 1, file)) != 1)
    {
        cout << "Error reading image data from " << filename<< endl;
        return 0;
    }

	// Changer des couleurs bgr -> rgb
    for (i = 0; i < size; i += 3)
    {
        temp = image->data[i];
        image->data[i] = image->data[i+2];
        image->data[i+2] = temp;
    }


    return 1;
}