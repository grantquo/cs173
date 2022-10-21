//======================================================
// Matt Kretchmar
// main.cpp
// October 2022
// Test driver for our Rational number class
//======================================================

#include <iostream>
#include <string>
#include "Rational.h"

using namespace std;

int main ( void )
{
	Rational r1;
	cout << "r1 = " << r1 << endl;
	
	Rational r2(10,4);
	cout << "r2 = " << r2 << endl;
	
	Rational r3(6);
	cout << "r3 = " << r3 << endl;
	
	r1.setNumerator(4);
	r1.setDenominator(-12);
	cout << "r1 num = " << r1.getNumerator() << endl;
	cout << "r1 den = " << r1.getDenominator() << endl;
	
	Rational r4;
	r4 = r1 + r2;
	cout << "r4 = " << r1 << " + " <<  r2 << " = " << r4 << endl;
	
	r4 = r1 - r2;
	cout << "r4 = r1 - r2 = " << r4 << endl;
	
	r4 = r1 * r2;
	cout << "r4 = r1 * r2 = " << r4 << endl;
	
	r4 = r1 / r2;
	cout << "r4 = r1 / r2 = " << r4 << endl;
	
	r4 = r2 + 3;
	cout << "r4 = r2 + 3 = " << r4 << endl;
	
	r4 = r2 - 3;
	cout << "r4 = r2 - 3 = " << r4 << endl;
	
	r4 = r2 * 3;
	cout << "r4 = r2 * 3 = " << r4 << endl;
	
	r4 = r2 / 3;
	cout << "r4 = r2 / 3 = " << r4 << endl;
	
	r4 = -r2;
	cout << "r4 = -r2 = " << r4 << endl;
	
	r4 = r1.abs();
	cout << "r4 = r1.abs() = " << r4 << endl;
	
	r4 = r2;
	cout << "r4 = r2 = " << r4 << endl;
	
	r4 = r2^3;
	cout << "r4 = r2^3 = " << r4 << endl;
	
	r4 = r2^-3;
	cout << "r4 = r2^-3 = " << r4 << endl;
	
	r4 = r2^0;
	cout << "r4 = r2^0 = " << r4 << endl;
	
	cout << "r4 == r2 = " << (r4==r2) << endl;
	cout << "r4 == r4 = " << (r4==r4) << endl;
	cout << "r4 != r2 = " << (r4!=r2) << endl;
	cout << "r4 != r4 = " << (r4!=r4) << endl;
	
	r1 = Rational(5,2);
	r2 = Rational(9,4);
	
	cout << "\nr1 = " << r1 << endl;
	cout << "r2 = " << r2 << endl;
	
	cout << "r1 > r2 = " << (r1>r2) << endl;
	cout << "r1 >= r2 = " << (r1>=r2) << endl;
	cout << "r1 > r1 = " << (r1>r1) << endl;
	cout << "r1 >= r1 = " << (r1>=r1) << endl;
	
	cout << "\nr1 < r2 = " << (r1<r2) << endl;
	cout << "r1 <= r2 = " << (r1<=r2) << endl;
	cout << "r1 < r1 = " << (r1<r1) << endl;
	cout << "r1 <= r1 = " << (r1<=r1) << endl;

	//cout << "Enter value for r1 (a/b):";
	//cin >> r1;	
	//cout << "r1 = " << r1 << endl;
	
	float f = (float)r2;
	cout << "r2 as float = " << f << endl;
	f = r1;
	cout << "r1 as float = " << f << endl;
	
	return 0;
}
