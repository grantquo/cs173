//==========================================================
// Grant Gutterman
// 10-28-2022
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
				Complex::Complex ( float a, float b )
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
// ~Complex
// Destructor function for the Complex number class that clears
// data within the class for storage space.
// PARAMS:
// 		none
// RETURNS:
//		Nothing, but clears all previous data or storage taken
// 		by the Complex class.
//==========================================================
				Complex::~Complex ( void )
{
}

//==========================================================
// operator=
// This is an assignment function that allows for Complex
// numbers to be reassigned to another Complex number, instead
// of creating an entirely new one.
// PARAMS:
//		const Complex &c : A complex number inputted through
//		reference.
// RETURNS:
//		Returns a new Complex number that is assigned a new real
//==========================================================
Complex 		Complex::operator= ( const Complex &c )
{
	real = c.real;
	imag = c.imag;
	return Complex(real, imag);
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
//		equation.
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
// This adds subtraction functions to Complex numbers, allowing
// subtraction either by other Complex numbers or by floats.
// PARAMS:
// 		const Complex c: This is an already built complex number in
//		the form a+bi.
//
//		float a: Regular float value that will be added to the real
//		number in the complex number.
// RETURNS:
//		A complex number that is the result of the subtraction
//		equation.
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
// Two functions that give multiplication functionality
// to Complex numbers. This allow for multiplication by
// either another Complex number or by a float.
// PARAMS:
// 		const Complex c: This is an already built complex number in
//		the form a+bi.
//
//		float a: Regular float value that will be added to the real
//		number in the complex number.
// RETURNS:
//		A complex number that is the result of the multiplication
//		equation.
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
// Two functions that allow for Complex number division.
// This operator can allow for division by either another
// Complex number, or a float.
// PARAMS:
// 		const Complex c: This is an already built complex number in
//		the form a+bi.
//
//		float a: Regular float value that will be added to the real
//		number in the complex number.
// RETURNS:
//		A complex number that is the result of the division
//		equation.
//==========================================================
Complex 		Complex::operator/ ( const Complex &c ) const
{
	float numreal = (real*c.real) + (imag*c.imag);
	float numimag = (real*c.imag) - (imag*c.real);
	float denom = pow(c.real, 2) + pow(c.imag, 2);
	float newreal = numreal/denom, newimag = numimag/denom;
	return Complex(newreal, newimag);
}
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
// Sets an operator defined by ~ before a Complex number to
// the conjugate, and calculates the conjugate of the
// number.
// PARAMS:
//		none
// RETURNS:
//		A new complex number that is the conjugate of another
//		complex number.
//==========================================================
Complex 		Complex::operator~ ( void ) const
{
	float newimag;
	newimag = imag*-1;
	return Complex(real, newimag);
}

//==========================================================
// operator-
// Sets the - operator when placed before a Complex number
// to take the reciprocal of that Complex number.
// PARAMS:
//		none
// RETURNS:
//		A new complex number that is the negative of another
//		complex number.
//==========================================================
Complex 		Complex::operator- ( void ) const
{
	float newreal, newimag;
	newreal = real*-1;
	newimag = imag*-1;
	return Complex(newreal, newimag);
}

//==========================================================
// operator^
// Sets the ^ operator to take the exponent of a complex
// number. Then calculates the complex number result. It does
// a specific method of taking the exponent based on if the
// exponent is 1, 0, -1 or any numbers outside of that range.
// PARAMS:
//		int k : Integer that is the exponent of a complex
//		number.
// RETURNS:
// 		A complex number result of the exponentiation.
//==========================================================
Complex 		Complex::operator^ ( int k ) const
{
	if (k == 0)
		return Complex(1,0);
	else if (k == 1)
		return Complex(real, imag);
	else if (k == -1)
	{
		float conjugreal = real, conjugimag = imag*-1;
		float denom = pow(real, 2)+pow(imag, 2);
		float expreal = conjugreal/denom, expimag = conjugimag/denom;
		return Complex(expreal,expimag);
	}
	else if (k < -1)
	{
		float denomreal, denomimag;
		denomreal = pow(real, k*-1) - pow(imag, k*-1);
		denomimag = 2*real*imag;
		float numreal, numimag;
		numreal = denomreal;
		numimag = denomimag*-1;
		float denom = denomreal*denomreal + denomimag*denomimag;
		float expreal = numreal/denom, expimag = numimag/denom;
		return Complex(expreal, expimag);
	}
	float expreal, expimag;
	expreal = pow(real, k) - pow(imag, k);
	expimag = 2*real*imag;
	return Complex(expreal, expimag);
}

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
// Boolean function for == comparisons between complex numbers.
// PARAMS:
//		const Complex &c : A complex number inputted through
//		reference.
// RETURNS:
// 		A boolean "true" or "false" for if the condition is met.
//==========================================================

bool			Complex::operator== ( const Complex &c ) const
{
	if (real==c.real && imag==c.imag)
		return true;
	return false;
}

//==========================================================
// operator!=
// Boolean function for != comparisons between complex numbers.
// PARAMS:
//		const Complex &c : A complex number inputted through
//		reference.
// RETURNS:
// 		A boolean "true" or "false" for if the condition is met.
//==========================================================
bool			Complex::operator!= ( const Complex &c ) const
{
	if (real!=c.real || imag!=c.imag)
		return true;
	return false;
}

//==========================================================
// operator<
// Boolean function for < comparisons between complex numbers.
// PARAMS:
//		const Complex &c : A complex number inputted through
//		reference.
// RETURNS:
// 		A boolean "true" or "false" for if the condition is met.
//==========================================================
bool 			Complex::operator< ( const Complex &c ) const
{
	Complex c1 = Complex(real, imag), c2 = Complex(c.real, c.imag);
	float abc1 = c1.abs();
	float abc2 = c2.abs();
	if (abc1 < abc2)
		return true;
	return false;
}

//==========================================================
// operator<=
// Boolean function for <= comparisons between complex numbers.
// PARAMS:
//		const Complex &c : A complex number inputted through
//		reference.
// RETURNS:
// 		A boolean "true" or "false" for if the condition is met.
//==========================================================
bool 			Complex::operator<= ( const Complex &c ) const
{
	Complex c1 = Complex(real, imag), c2 = Complex(c.real, c.imag);
	float abc1 = c1.abs();
	float abc2 = c2.abs();
	if (abc1 <= abc2)
		return true;
	return false;
}

//==========================================================
// operator>
// Boolean function for > comparisons between complex numbers.
// PARAMS:
//		const Complex &c : A complex number inputted through
//		reference.
// RETURNS:
// 		A boolean "true" or "false" for if the condition is met.
//==========================================================
bool 			Complex::operator> ( const Complex &c ) const
{
	Complex c1 = Complex(real, imag), c2 = Complex(c.real, c.imag);
	float abc1 = c1.abs();
	float abc2 = c2.abs();
	if (abc1 > abc2)
		return true;
	return false;
}

//==========================================================
// operator>=
// Boolean function for >= comparisons between complex numbers.
// PARAMS:
//		const Complex &c : A complex number inputted through
//		reference.
// RETURNS:
// 		A boolean "true" or "false" for if the condition is met.
//==========================================================
bool 			Complex::operator>= ( const Complex &c ) const
{
	Complex c1 = Complex(real, imag), c2 = Complex(c.real, c.imag);
	float abc1 = c1.abs();
	float abc2 = c2.abs();
	if (abc1 >= abc2)
		return true;
	return false;
}

//==========================================================
// ostream & operator<<
// PARAMS:
//		ostream &os : a reference to the << operator that will
//		contain an output in string form.
//		const Complex &c : A complex number inputted through
//		reference.
// RETURNS:
//		os : a cout / ostream that outputs a formatted Complex number.
//==========================================================
				ostream & operator<< ( ostream &os, const Complex c )
{

	if (c.real == 0 && c.imag > 0)
	{
		os << 0 << "+" << c.imag << "i";
		return os;
	}
	else if ((c.real > 0 || c.real < 0) && c.imag < 0)
	{
		os << setprecision(3) << c.real << c.imag << "i";
		return os;
	}
	else if (c.real == 0 && c.imag < 0)
	{
		os << c.imag << "i";
		return os;
	}
	else if (c.imag == 0)
	{
		os << fixed << setprecision(3) << c.real;
		return os;
	}
	os << fixed << setprecision(3) << c.real << "+" << c.imag << "i";
	return os;
}

//==========================================================
// istream & operator>>
// PARAMS:
//		istream &is : a reference to the >> operator that will
//		contain an input in string form of the complex number.
//		const Complex &c : A complex number inputted through
//		reference.
// RETURNS:
//		is : a cin / istream that inputs a formatted Complex number.
//==========================================================
 				istream & operator>> ( istream &is, Complex &c )
{
	string fullInput;
	string temp;
	float inputReal, inputImag;


	is >> fullInput;
	int fullInputLen = fullInput.length();
	if (fullInput.find("i") == string::npos)
	{
		inputReal = stof(fullInput);
		c.real = inputReal;
		c.imag = 0;
		return is;
	}
	// is there exists an imag, loop through everything but i's pos
	for (int j=0; j < fullInputLen-1; j++)
	{
		if (fullInput[j] == '-' || fullInput[j] == '+')
		{
			// have either read real's sign or read all of real
			if (j!=0)
			{
				// real has no sign and imag does
				string realsubstr = fullInput.substr(0,j);
				inputReal =  stof(realsubstr);
				c.real = inputReal;
				string imagsubstr = fullInput.substr(j, fullInputLen-1);
				inputImag = stof(imagsubstr);
				c.imag = inputImag;
				return is;
			}
			else
			{
				for (int x=0; x < fullInputLen-1; x++)
				{
					if ((fullInput[x] == '+' || fullInput[x] == '-') && x != 0)
					{
						// real and imag have a sign preceding
						string realsubstr = fullInput.substr(0, x);
						inputReal = stof(realsubstr);
						c.real = inputReal;
						string imagsubstr = fullInput.substr(x, fullInputLen-1);
						inputImag = stof(imagsubstr);
						c.imag = inputImag;
						return is;
					}
				}
				// have no real and only imag
				inputImag = stof(fullInput);
				c.real = 0;
				c.imag = inputImag;
				return is;
			}
		}
	}
	return is;
}
