//======================================================
// Matt Kretchmar
// Rational.cpp
// October 2022
// This file contains our Rational number class function
// definitions.
//======================================================

#include "Rational.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


//======================================================
// default constructor
// initializes a Rational object to value 0/1
// PARAMETERS:
// none
// RETURN VALUE:
// none
//======================================================
			Rational::Rational ( void )
{
	num = 0;
	den = 1;
	normalize();
}

//======================================================
// constructor
// Initializes Rational object to value n/d
// where d defaults to 1 if not specified.
// PARAMETERS:
// n : integer numerator
// d : integer denominator with default value 1
// note that setting d=0 results in a runtime error
// RETURN VALUE:
// none
//======================================================
			Rational::Rational ( int n, int d )
{
	num = n;
	den = d;
	normalize();
}

//======================================================
// destructor
// Does nothing useful here.  Placeholder for future
// cleanup if necessary.
// PARAMETERS:
// none
// RETURN VALUE:
// none
//======================================================
			Rational::~Rational ( void )
{
}

//======================================================
// normalize
// Private utility function.
// Make sure our rational number conforms to standards:
// - denominator cannot be 0 (exception)
// - denominator must be postive (switch signs)
// - reduce to lowest common terms
// PARAMETERS:
// none
// RETURN VALUE:
// none
//======================================================
void	Rational::normalize ( void )
{
	// make sure no divide by 0
	if ( den == 0 )
	{
		cout << "Exception: Rational denominator cannot be 0.\n";
		cout << "Exit program.\n";
		exit(1);
	}

	// normalize value of 0 to 0/1
	if ( num == 0 )
		den = 1;

	// if denominator negative, switch signs
	if ( den < 0 )
	{
		num *= -1;
		den *= -1;
	}

	// reduce to lowest terms
	int div = gcd(std::abs(num),std::abs(den));
	if ( div != 1 )
	{
		num /= div;
		den /= div;
	}
}

//======================================================
// gcd
// A private utility routine that computes the greatest common
// devisor of a and b, assuming a,b > 0.
// PARAMETERS
// int a,b where a,b > 0
// RETURN VALUE:
// The greatest common divisor of a and b.
//======================================================
int		Rational::gcd	( int a , int b )
{
	int r = a % b;
	while ( r )
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

//======================================================
// to_string
// Converts the rational to a c++ string object with
// "a/b" as the values.
// PARAMETERS:
// none
// RETURN VALUE:
// string containing "a/b" where a is numerator and
// b is denominator.
//======================================================
string	Rational::to_string ( void ) const
{
	string str;
	str = std::to_string(num) + "/"
	    + std::to_string(den);
	return str;
}


//======================================================
// setNumerator
// Change the numerator to the specified parameter.
// PARAMETERS:
// n - integer value for numerator
// RETURN VALUE:
// none
//======================================================
void	Rational::setNumerator (int n)
{
	num = n;
	normalize();
}

//======================================================
// setDenominator
// Change the denominator to the specified parameter.
// PARAMETERS:
// d - integer value for numerator.  Note that d=0 results
// in a runtime error.
// RETURN VALUE:
// none
//======================================================
void	Rational::setDenominator (int d)
{
	den = d;
	normalize();
}

//======================================================
// getNumerator
// Return the numerator.
// PARAMETERS:
// none
// RETURN VALUE:
// return numerator
//======================================================
int		Rational::getNumerator ( void ) const
{
	return num;
}

//======================================================
// getDenominator
// Return the denominator.
// PARAMETERS:
// none
// RETURN VALUE:
// denominator as integer
//======================================================
int 	Rational::getDenominator ( void ) const
{
	return den;
}

//======================================================
// operator+
// r1 = r2 + r3
// Will take the components of r2 + r3 and return them
// to r1.
// PARAMETERS:
// rational object r
// RETURN VALUE:
// returns sum of *this + r
//======================================================
Rational	Rational::operator+	( const Rational r ) const
{
	Rational ret;

	ret.den = den * r.den;
	ret.num = num*r.den + r.num*den;
	ret.normalize();

	return ret;
}
//======================================================
// operator-
// r1 = r2 - r3
// Will take the components of r2 - r3 and return them
// to r1.
// PARAMETERS:
// rational object r
// RETURN VALUE:
// returns sum of *this - r
//======================================================
Rational	Rational::operator-	( const Rational r ) const
{
	Rational ret;

	ret.den = den * r.den;
	ret.num = num*r.den - r.num*den;
	ret.normalize();

	return ret;
}
//======================================================
// operator*
// r1 = r2 * r3
// Will take the components of r2 * r3 and return them
// to r1.
// PARAMETERS:
// rational object r
// RETURN VALUE:
// returns product of *this * r
//======================================================
Rational	Rational::operator*	( const Rational r ) const
{
	Rational ret;

	ret.den = den * r.den;
	ret.num = num * r.num;
	ret.normalize();

	return ret;
}
//======================================================
// operator/
// r1 = r2 / r3
// Will take the components of r2 / r3 and return them
// to r1.
// PARAMETERS:
// rational object r
// RETURN VALUE:
// returns product of *this * 1/r
//======================================================
Rational	Rational::operator/	( const Rational r ) const
{
	Rational ret;

	ret.den = den * r.num ;
	ret.num = num * r.den;
	ret.normalize();

	return ret;
}
//======================================================
// operator+
// r1 = r2 + n
// Will take the components of r2 + n and return them
// to r1.
// PARAMETERS:
// int n
// RETURN VALUE:
// returns sum of *this + n
// n must first be converted to same denominator as *this
//======================================================
Rational	Rational::operator+	( int n ) const
{
	Rational ret;

	ret.den = den;
	ret.num = num + n*den;
	ret.normalize();

	return ret;
}
//======================================================
// operator-
// r1 = r2 - n
// Will take the components of r2 - n and return them
// to r1.
// PARAMETERS:
// int n
// RETURN VALUE:
// returns sum of *this - n
// n must first be converted to same denominator as *this
//======================================================
Rational	Rational::operator-	( int n ) const
{
	Rational ret;

	ret.den = den;
	ret.num = num - n*den;
	ret.normalize();

	return ret;
}
//======================================================
// operator*
// r1 = r2 * n
// Will take the components of r2 * n and return them
// to r1.
// PARAMETERS:
// int n
// RETURN VALUE:
// returns product of *this * n
//======================================================
Rational	Rational::operator*	( int n ) const
{
	Rational ret;

	ret.den = den;
	ret.num = num * n;
	ret.normalize();

	return ret;
}
//======================================================
// operator/
// r1 = r2 / n
// Will take the components of r2 / n and return them
// to r1.
// PARAMETERS:
// int n
// RETURN VALUE:
// returns product of *this * 1/n
//======================================================
Rational	Rational::operator/	( int n ) const
{
	Rational ret;

	ret.den = den * n;
	ret.num = num;
	ret.normalize();

	return ret;
}
//======================================================
// operator-
// r1 = -r2
// Will take the components of -r2 and return them
// to r1.
// PARAMETERS:
// const Rational object
// RETURN VALUE:
// returns new Rational object with same value of *this
// except numerator sign is swapped.
//======================================================
Rational	Rational::operator-	( void ) const
{
	Rational ret;

	ret.num = -num;
	ret.den = den;
	ret.normalize();

	return ret;
}
//======================================================
// abs
// r1 = abs(r2)
// Will take the components of abs(r2) and return them
// to r1.
// PARAMETERS:
// none
// RETURN VALUE:
// returns same value as *this except with absolute
// value of numerator
//======================================================
Rational	Rational::abs	( void ) const
{
	Rational ret;

	ret.num = std::abs(num);
	ret.den = den;
	ret.normalize();

	return ret;
}
//======================================================
// operator=
// r1 = r2
// Assignment operator
// PARAMETERS:
// const Rational object r
// RETURN VALUE:
// first values of r are assigned to *this and then
// *this is returned
//======================================================
Rational	Rational::operator=	( const Rational r )
{
	num = r.num;
	den = r.den;
	return *this;
}

//======================================================
// exponentiation
// returns *this ^ k where k is an integer
// PARAMETERS:
// int k
// RETURN VALUE:
// returns *this ^ k power.  If k==0, then returns 1/1.
// If k < 0, then returns (1/*this)^|k|
//======================================================
Rational	Rational::operator^		( int k ) const
{
	Rational ret(1,1);
	int n, d;
	if ( k > 0 )
	{
		n = num;
		d = den;
	}
	else
	{
		n = den;
		d = num;
	}

	for ( int i = 0; i < std::abs(k); i++ )
	{
		ret.num *= n;
		ret.den *= d;
	}
	ret.normalize();
	return ret;
}

//======================================================
// operator==
// Returns true if both numerator and denominator are the same.
// PARAMETERS:
// rational object r
// RETURN VALUE:
// true if r and *this have same num and den, false otherwise.
//======================================================
bool	Rational::operator== ( const Rational r ) const
{
	return ( num == r.num && den == r.den );
}

//======================================================
// operator!=
// Returns false if both numerator and denominator are the same.
// PARAMETERS:
// rational object r
// RETURN VALUE:
// false if r and *this have same num and den, true otherwise.
//======================================================

bool	Rational::operator!= ( const Rational r ) const
{
	return !( num == r.num && den == r.den );
}

//======================================================
// operator>
// Returns true of caller > parameter.
// PARAMETERS:
// rational object r
// RETURN VALUE:
// Note that two values (*this and r) must be converted to
// same denominator.  Then we return this->num > r.num
//======================================================

bool	Rational::operator> ( const Rational r ) const
{
	int n1, d, n2;

	d = den * r.den;
	n1 = num * r.den;
	n2 = r.num * den;

	return ( n1 > n2 );
}

//======================================================
// operator>=
// Returns true of caller >= parameter.
// PARAMETERS:
// rational object r
// RETURN VALUE:
// Note that two values (*this and r) must be converted to
// same denominator.  Then we return this->num >= r.num
//======================================================

bool	Rational::operator>= ( const Rational r ) const
{
	int n1, d, n2;

	d = den * r.den;
	n1 = num * r.den;
	n2 = r.num * den;

	return ( n1 >= n2 );
}

//======================================================
// operator<
// Returns true of caller < parameter.
// PARAMETERS:
// rational object r
// RETURN VALUE:
// Note that two values (*this and r) must be converted to
// same denominator.  Then we return this->num < r.num
//======================================================

bool	Rational::operator< ( const Rational r ) const
{
	int n1, d, n2;

	d = den * r.den;
	n1 = num * r.den;
	n2 = r.num * den;

	return ( n1 < n2 );
}

//======================================================
// operator<=
// Returns true of caller <= parameter.
// PARAMETERS:
// rational object r
// RETURN VALUE:
// Note that two values (*this and r) must be converted to
// same denominator.  Then we return this->num <= r.num
//======================================================

bool	Rational::operator<= ( const Rational r ) const
{
	int n1, d, n2;

	d = den * r.den;
	n1 = num * r.den;
	n2 = r.num * den;

	return ( n1 <= n2 );
}

//======================================================
// cout << operator overload
// PARAMETERS:
// ostream os
// Rational object r
// A string is created with value "num/den" from r and then
// this string is inserted into the stream os.
// RETURN VALUE:
// ostream os
// NOTES:
// if value of r is 0, then we print "0"
// if value of r is a/1 then we print "a"
// else we print "a/b"
//======================================================
ostream & operator<< ( ostream &os, Rational r )
{
	if ( r.num == 0 )
		os << "0";
	else if ( r.den == 1 )
		os << r.num;
	else
		os << r.num << "/" << r.den;
	return os;
}

//======================================================
// cin >>
// Overloads the cin istream >> operator to allow
// cin >> r;
// PARAMETERS
// istream is
// Rational r
// RETURN VALUE:
// istream is
// NOTES:
// We scan is for a string of the form "a/b" or "a".
// We then read a into numerator, b into denominator.
// If "/" is missing, then denominator = 1
//======================================================
istream & operator>> ( istream &is, Rational &r )
{
	string s, num_str, den_str;

	is >> s;		// read in the rational as string

	size_t spot = s.find('/');
	if ( spot != string::npos )
	{
		num_str = s.substr(0,spot);
		den_str = s.substr(spot+1,s.size()-spot-1);
	}
	else
	{
		num_str = s;
		den_str = "1";
	}

	r.num = stoi(num_str);
	r.den = stoi(den_str);
	r.normalize();

	return is;
}
