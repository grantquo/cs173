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
// default referential
// Initializes a complex number when a complex number reference
// is passed, giving referential parameters functionality within
// the class.
// PARAMS:
//		const Complex &c: a constant, complex number reference
// RETURNS:
//		Nothing, but sets the real and imaginary number values
//		equal to the values within the complex number reference
//==========================================================
				Complex::Complex ( const Complex &c )
{
	real = c.real;
	imag = c.imag;
}

//==========================================================
// operator+
// This series of methods adds addtion functionality to complex
// numbers. This includes different formats of numbers being added.
// PARAMS:
// 		const Complex c: This is an already built complex number in
//		the form a+bi.
//
//		float a: Regular float value that will be added to the real
//		number in the complex number.
// RETURNS:
//		A complex number that is the result of the addition
//		equations.
//==========================================================
Complex			Complex::operator+ ( const Complex &c ) const
{
 	float addend1, addend2;
	addend1 = c.real + real;
	addend2 = c.imag + imag;
	return Complex(addend1, addend2);
}
Complex			Complex::operator+ ( float f ) const
{
	float addend;
	addend = f + real;
	return Complex(addend, imag);
}

//==========================================================
// operator-
//==========================================================
Complex			Complex::operator- ( const Complex &c ) const
{
	float subend1, subend2;
	subend1 = real - c.real;
	subend2 = imag - c.imag;
	return Complex(subend1, subend2);
}
Complex			Complex::operator- ( float f ) const
{
	float subend;
	subend = real - f;
	return Complex(subend, imag);
}

//==========================================================
// operator*
//==========================================================
Complex			Complex::operator* ( const Complex &c ) const
{
	float factor1, factor2;
	factor1 = real*c.real+imag*c.imag*-1;
	factor2 = real*c.imag+imag*c.real;
	return Complex(factor1, factor2);
}
Complex			Complex::operator* ( float f ) const
{
	float factor1, factor2;
	factor1 = f * real;
	factor2 = f * imag;
	return Complex(factor1, factor2);
}

//==========================================================
// operator/
//==========================================================
/*
Complex 		Complex::operator/ ( const Complex &c ) const
{

}
*/
Complex 		Complex::operator/ ( float f ) const
{
	float dividend1, dividend2;
	dividend1 = real / f;
	dividend2 = imag / f;
	return Complex(dividend1, dividend2);
}

//==========================================================
// abs
// Finds the absolute value of a complex number.
// PARAMS:
// 		none
// RETURNS:
// 		Returns the float absolute value of a complex number, which
//		is the square root of the real number sqared plus the
//		imaginary number squared.
//==========================================================
float 		Complex::abs ( void ) const
{

	float ans = sqrt((pow(real, 2))+(pow(imag, 2)));
	return ans;
}

//==========================================================
// operator~
//==========================================================


//==========================================================
// operator-
//==========================================================


//==========================================================
// operator^
//==========================================================


// ==========================================================
// setReal
// Changes the real number value of the complex number it's
// called with.
// PARAMS:
// 		float a: the number that the real number will be changed
// 		to.
// RETURNS:
// 		Nothing, but changes a variable within a complex number.
// ==========================================================
void 			Complex::setReal ( float a )
{
	real = a;
	return;
}

//==========================================================
// getReal
// Returns the real number from the complex number it's called
// with.
// PARAMS:
// 		none
// RETURNS:
// 		Returns the float real number from the complex number.
//==========================================================
float 			Complex::getReal ( void ) const
{
	return real;
}

//==========================================================
// setImag
// Chnages the imaginary number value of the complex number it's
// called with.
// PARAMS:
// 		float a: the number that the imaginary number will be
//		changed to.
// RETURNS:
// 		Nothing,, but changes a variable within a complex number,
//==========================================================
void 			Complex::setImag ( float b )
{
	imag = b;
	return;
}

//==========================================================
// getImag
// Returns the imaginary number from the complex number it's
// called with.
// PARAMS:
// 		none
// RETURNS:
// 		Returns the float imaginary number from the complex
//		number.
//==========================================================
float 			Complex::getImag ( void ) const
{
	return imag;
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
string 			Complex::to_string ( void ) const
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
// operator==
//==========================================================

bool			Complex::operator== ( const Complex &c ) const
{
	if (real==c.real && imag==c.imag)
		return true;
	return false;
}

//==========================================================
// operator!=
//==========================================================
bool			Complex::operator!= ( const Complex &c ) const
{
	if (real!=c.real || imag!=c.imag)
		return true;
	return false;
}

//==========================================================
// operator<
//==========================================================
bool 			Complex::operator< ( const Complex &c ) const
{
	if (Complex(real,imag) < Complex(c.real,c.imag))
		return true;
	return false;
}

//==========================================================
// operator<=
//==========================================================
bool 			Complex::operator<= ( const Complex &c ) const
{
	if (Complex(real,imag) <= Complex(c.real,c.imag))
		return true;
	return false;
}

//==========================================================
// operator>
//==========================================================
bool 			Complex::operator> ( const Complex &c ) const
{
	if (Complex(real,imag) > Complex(c.real,c.imag))
		return true;
	return false;
}

//==========================================================
// operator>=
//==========================================================
bool 			Complex::operator>= ( const Complex &c ) const
{
	if (Complex(real,imag) >= Complex(c.real,c.imag))
		return true;
	return false;
}
