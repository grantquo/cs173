//=================================================
// Matt Kretchmar
// October 2022
// Complex.h
// This file contains the class declaration for the
// Complex number class.
// *** Students should not change this file ever ***
//=================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef COMPLEX
#define COMPLEX

class Complex
{
public:
				Complex		( void );
				Complex 	( float a, float b=0);
				Complex     ( const Complex &c );
/*
			   ~Complex     ( void );
	Complex		operator=	( const Complex &c );
*/
	Complex		operator+	( const Complex &c ) const;
	Complex		operator+	( float f ) const;

	Complex		operator-	( const Complex &c ) const;
	Complex		operator-	( float f ) const;

	Complex		operator*	( const Complex &c ) const;
	Complex		operator*	( float f ) const;
/*
	Complex		operator/	( const Complex &c ) const;
*/
	Complex		operator/	( float f ) const;

	float		abs			( void ) const;
/*
	Complex		operator~	( void ) const;
	Complex		operator-	( void ) const;
	Complex 	operator^	( int k ) const;
*/
	void		setReal		( float a );
	float		getReal		( void ) const;
	void		setImag		( float b );
	float		getImag		( void ) const;
	string		to_string	( void ) const;

	bool		operator==	( const Complex &c ) const;
	bool		operator!=	( const Complex &c ) const;

	bool		operator<	( const Complex &c ) const;
	bool		operator<=	( const Complex &c ) const;

	bool		operator>	( const Complex &c ) const;
	bool		operator>=	( const Complex &c ) const;
/*
	friend ostream & operator<< ( ostream &os, const Complex c );
	friend istream & operator>> ( istream &is, Complex &c );
*/
private:
	float	real;		// real part
	float	imag;		// imaginary part
};

#endif
