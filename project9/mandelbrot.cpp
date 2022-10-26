//=====================================================================
// Code borrowed and adapted from Farouk Ounane
// https://medium.com/farouk-ounanes-home-on-the-internet/mandelbrot-set-in-c-from-scratch-c7ad6a1bf2d9
//=====================================================================
#include <iostream>
#include <fstream>
#include "Complex.h"

using namespace std;

float width = 1200;
float height = 1200; 


//=====================================================================
// Returns a value in the range 0 to 255 depending on how fast
// the complex number point blows up or does not. 
//=====================================================================

int value ( Complex point )
{
	Complex z;
	
	int num_iter = 0;
	while ( z.abs() < 2 && num_iter <= 20 )
	{
		z = z * z + point;
		num_iter++;
	}
	if ( num_iter < 20 )
		return (255*num_iter)/20;
	else
		return 0;
}


//=====================================================================
//=====================================================================
int main ()  {

    ofstream my_Image ("mandelbrot.ppm");


    if (my_Image.is_open ()) 
    {
        my_Image << "P3\n" << width << " " << height << " 255\n";
        for (int i = 0; i < width; i++) 
        {
            for (int j = 0; j < height; j++)  
            {
            	float real = (float)i / width - 1.5;
            	float imag = (float)j / height - 0.5;
            	Complex c(real,imag);
                int val = value(c);
                my_Image << 0 << ' ' << 0 << ' ' << val << "\n";
            }
        }
        my_Image.close();
    }
    else
      cout << "Could not open the file";
    
    return 0;
}

