//======================================================
// Matt Kretchmar
// Rational.h
// October 2022
// This file contains our Rational number class declaration.
//======================================================

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>
using namespace std;

class Rational
{
public:
				Rational 		( void );
				Rational		( int n, int d=1 );
			   ~Rational        ( void );
	string		to_string		( void ) const;
	void		setNumerator	( int n );
	void		setDenominator	( int d );
	int			getNumerator	( void ) const;
	int			getDenominator	( void ) const;
	Rational	operator+		( const Rational r ) const;
	Rational	operator-		( const Rational r ) const;
	Rational	operator*		( const Rational r ) const;
	Rational	operator/		( const Rational r ) const;
	Rational	operator+		( int n ) const;
	Rational	operator-		( int n ) const;
	Rational	operator*		( int n ) const;
	Rational	operator/		( int n ) const;
	Rational	operator-		( void ) const;
	Rational	operator^		( int k ) const;
	Rational	abs				( void ) const;
	Rational	operator=		( const Rational r );
				operator float()	 
	{ return (float)num/den; }
	
	bool		operator==		( const Rational r ) const;
	bool		operator!=		( const Rational r ) const;
	bool		operator>		( const Rational r ) const;
	bool		operator>=		( const Rational r ) const;
	bool		operator<		( const Rational r ) const;
	bool		operator<=		( const Rational r ) const;

	friend ostream & operator<< ( ostream &os, Rational r );
	friend istream & operator>> ( istream &is, Rational &r );


private:
	// data elements
	int			num;
	int			den;
	
	// internal utility methods
	void		normalize		( void );
	int			gcd				( int a, int b);
};

#endif

