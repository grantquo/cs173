//======================================================
// Matt Kretchmar
// October 2022
// main.cpp
// A driver file for our Rational class.
//======================================================

#include <iostream>
using namespace std;
#include "Rational.h"




int main ( void )
{
	Rational r1;
	Rational r2(5,2);
	Rational r3(7);

	cout << "r1 = " << r1.to_string() << endl;
	cout << "r2 = " << r2.to_string() << endl;
	cout << "r3 = " << r3.to_string() << endl;

	//r1.setDenominator(-3);
	//r1.setNumerator(6);
	//cout << "r1 = " << r1.to_string() << endl;

	//int n = r1.getNumerator();
	//int d = r1.getDenominator();
	//cout << "r1 num = " << n << " r1 den = " << d << endl;

	r1 = r2.add(r3);
	cout << "r1 = " << r1.to_string() << endl;

	return 0;
}
