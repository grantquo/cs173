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
