#ifndef BMPLOAD_H
#define BMPLOAD_H

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
    char *data1;
	char *data2;

public:
	int ImageLoad(char *filename) //leture un image. retour 1 si echecl, return 0 si reussir
	{
		FILE *file;
		unsigned long size1; // Longueur d'image
		unsigned long size2; // Longueur d'image
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
		if ((i = fread(&sizeX, 4, 1, file)) != 1)
		{
			cout << "Error reading width from " << filename<< endl;
			return 0;
		}
		//cout << "Width of  " <<  filename << ":" <<  sizeX<< endl;
    
		// Lire la hauteur
		if ((i = fread(&sizeY, 4, 1, file)) != 1)
		{
		   cout << "Error reading height from " <<  filename<< endl;
			return 0;
		}
		//cout << "Height of  " << filename << ":"<< sizeY;

		// Calculer la longueur(24bits ou 3bytes chaque pixel)
		size1 = sizeX * sizeY * 3;
		size2 = sizeX * sizeY * 4;

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


		data1 = (char*) malloc (size1);
		data2 = (char*) malloc (size2);
		if (data1 == NULL)
		{
			cout << "Error allocating memory for color-corrected image data" << endl;
			return 0;
		}

		if ((i = fread(data1, size1, 1, file)) != 1)
		{
			cout << "Error reading image data from " << filename<< endl;
			return 0;
		}

		// Changer des couleurs bgr -> rgb
		for (i = 0; i < size1; i += 3)
		{
			temp = data1[i];
			data1[i] = data1[i+2];
			data1[i+2] = temp;
		}

		int k = 0;
		for (i = 0; i < size1; i ++)
		{
			if(k % 4 == 3)
				data2[k] = 1;
			else
				data2[k] = data1[i];
			k++;
		}


		return 1;
	}
};


#endif