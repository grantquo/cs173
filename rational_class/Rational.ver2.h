//======================================================
// Matt Kretchmar
// October 2022
// Rational.h
// Class declaration for Rational.
//======================================================

#include <iostream>
#include <string>
using namespace std;


#ifndef RATIONAL
#define RATIONAL

// class declaration
class Rational
{
public:
					Rational 		( void );
					Rational 		( int n, int d = 1 );
	string			to_string		( void );
	void			setDenominator  ( int d );
	void			setNumerator    ( int n );
	int				getNumerator   	( void );
	int				getDenominator 	( void );

private:
	int				num;
	int				den;
	void			normalize		( void );

};

#endif
