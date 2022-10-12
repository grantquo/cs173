//======================================================
// Matt Kretchmar
// October 2022
// Rational.cpp
// Class methods definitions for Rational
//======================================================

#include <iostream>
#include <string>
using namespace std;
#include "Rational.h"


//======================================================
// default constructor
// PARAMETERS
// none
// RETURN VALUE
// none
// Sets numerator=0 and denominator=1
//======================================================
		Rational::Rational ( void )
{
	num = 0;
	den = 1;
}

//======================================================
// constructor(n,d)
// PARAMETERS
// n - integer numerator
// d - integer denominator
// RETURN VALUE
// none
// Sets numerator=n and denominator=d
//======================================================
		Rational::Rational ( int n, int d )
{
	num = n;
	den = d;
	normalize();
}

//======================================================
// to_string
// Prints the Rational object into a string of form
// "a/b" where a is numerator and b is denominator
// PARAMETERS:
// none
// RETURN VALUE:
// a string of form "a/b"
//======================================================
string		Rational::to_string ( void )
{
	string s;
	s = std::to_string(num) + "/" + std::to_string(den);
	return s;
}

//======================================================
// setDenominator
// PARAMETERS:
// d - integer value for the denominator
// RETURN VALUE:
// none
//======================================================
void		Rational::setDenominator ( int d )
{
	den = d;
	normalize();
}

//======================================================
// setNumeratopr
// PARAMETERS:
// n - integer value for the numerator
// RETURN VALUE:
// none
//======================================================
void		Rational::setNumerator ( int n )
{
	num = n;
}

//======================================================
// getNumerator
// PARAMETERS:
// none
// RETURN VALUE:
// n - returns integer value for the numerator
//======================================================

int			Rational::getNumerator ( void )
{
	return num;
}

//======================================================
// getDenominator
// PARAMETERS:
// none
// RETURN VALUE:
// d - returns integer value for the denominator
//======================================================

int			Rational::getDenominator ( void )
{
	return den;
}

//======================================================
// normalize
// Make sure our Rational number comforms to the required
// values and formats.
// PARAMETERS none
// RETURN VALUE none
// but may change the Rational object values
// 1) Make sure denominator not 0, quit if so
//
//======================================================
void		Rational::normalize ( void )
{
	if ( den == 0 )
	{
		cout << "Error: divide by zero not permitted\n";
		exit(1);
	}
}














