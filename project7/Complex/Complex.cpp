//==========================================================
// Grant Gutterman
// 10-21-2022
// Complex.cpp
// This file contains the class implementation for the
// Complex number class.
//==========================================================

#include "Complex.h"
#include <iomanip>
#include <math.h>

//==========================================================
// default constructor
// Initializes a complex number as the real number being 0 if
// nothing is passed.
// PARAMS:
//		none
// RETURNS:
//		Nothing, but sets the values needed for to_string to
//		0 for both the real and imaginary number.
//==========================================================
		Complex::Complex ( void )
{
	real = 0;
	imag = 0;
}

//==========================================================
// default constructor (with params)
// Initializes a complex number when two float numbers are passed,
// as opposed to nothing being passed.
// PARAMS:
//		float a: Number representing the real number
//		float b: Number representing the real number that will be
//		multiplied by i
// RETURNS:
//		Nothing, but sets the right a and b value to the a and b
//		that will be in the complex number "a+bi".
//==========================================================
		Complex::Complex ( float a, float b)
{
	real = a;
	imag = b;
}

//==========================================================

//==========================================================
		Complex::Complex ( const Complex &c )
{
	real = c.real;
	imag = c.imag;
}
//==========================================================
// to_string
// PARAMS:
// 		none
// RETURNS:
// 		a string containing "a+bi" where a and b are
// 		the real and complex parts of the number.  Both
// 		a and b will be with fixed decimal length up to
// 		two places.
//==========================================================
string 	Complex::to_string ( void ) const
{
	stringstream stream;
	stream << fixed << setprecision(3) << real;
	if ( imag >= 0 )
		stream << "+" << fixed << setprecision(3) << imag << "i";
	else
		stream << "-" << fixed << setprecision(3) << fabs(imag) << "i";

	return stream.str();
}

//==========================================================

//==========================================================
Complex		Complex::add ( const Complex c ) const
{
 	float addend;
	addend = c.real + real;
	return Complex(addend, imag);
}
//==========================================================

//==========================================================
Complex		Complex::add ( float a ) const
{
	float addend;
	addend = a + real;
	return Complex(addend, imag);
}


// void		makeCopy	( const Complex c )
// {
//
// }
