//=================================================
// Matt Kretchmar
// driver.cpp
// This file tests the Complex class
// This is the actual file I will test your program
// against for Part 1.  You can compare your output
// to my program output.
//=================================================

#include <iostream>
#include <iomanip>
#include <string>
#include "Complex.h"
using namespace std;

int main ( void )
{
	Complex c1;
	Complex c2(3);
	Complex c3(0,-4);
	Complex c4(c2);
	Complex c5(-4.5,-3.1);

	cout << "Basic constructors: \n";
	cout << "c1 = " << c1.to_string() << endl;
	cout << "c2 = " << c2.to_string() << endl;
	cout << "c3 = " << c3.to_string() << endl;
	cout << "c4 = " << c4.to_string() << endl;
	cout << "c5 = " << c5.to_string() << endl;

	cout << "\nAddition: \n";
	c4 = c2 + c3;
	cout << "c4 = " << c2.to_string() << " + " << c3.to_string() << " = " << c4.to_string() << endl;
	c4 = c2 + 4.5;
	cout << "c4 = " << c2.to_string() << " + " << 4.5 << " = " << c4.to_string() << endl;
	c4 = c2 + 4;
	cout << "c4 = " << c2.to_string() << " + " << 4 << " = " << c4.to_string() << endl;

	cout << "\nSubtraction: \n";
	c4 = c2 - c3;
	cout << "c4 = " << c2.to_string() << " - " << c3.to_string() << " = " << c4.to_string() << endl;
	c4 = c2 - 4.5;
	cout << "c4 = " << c2.to_string() << " - " << 4.5 << " = " << c4.to_string() << endl;
	c4 = c2 - 4;
	cout << "c4 = " << c2.to_string() << " - " << 4 << " = " << c4.to_string() << endl;

	cout << "\nMultiplication: \n";
	c2.setReal(2);
	c2.setImag(3);
	c3.setReal(4);
	c3.setImag(-5);
	c4 = c2 * c3;
	cout << "c4 = " << c2.to_string() << " * " << c3.to_string() << " = " << c4.to_string() << endl;
	c4 = c2 * 4.5;
	cout << "c4 = " << c2.to_string() << " * " << 4.5 << " = " << c4.to_string() << endl;
	c4 = c2 * 4;
	cout << "c4 = " << c2.to_string() << " * " << 4 << " = " << c4.to_string() << endl;

	cout << "\nDivision: \n";
	c2.setReal(2);
	c2.setImag(3);
	c3.setReal(4);
	c3.setImag(-5);
/*
	c4 = c2 / c3;
	cout << "c4 = " << c2 << " / " << c3 << " = " << c4 << endl;
*/
	c4 = c2 / 4.5;
	cout << "c4 = " << c2.to_string() << " / " << 4.5 << " = " << c4.to_string() << endl;
	c4 = c2 / 4;
	cout << "c4 = " << c2.to_string() << " / " << 4 << " = " << c4.to_string() << endl;
/*
	cout << "\noperators: \n";
	Complex c7(3,-4);
	float f = c7.abs();
	cout << "abs of " << c7 << " = " << f << endl;
	cout << "~c of " << c7 << " = " << ~c7 << endl;
	cout << "-c of " << c7 << " = " << -c7 << endl;
	cout << "-c of " << c1 << " = " << -c1 << endl;

	cout << "\nExponentiation: \n";
	c2.setReal(2);
	c2.setImag(3);
	c4 = c2^0;
	cout << "c4 = " << c2 << "^" << 0 << " = " << c4 << endl;
	c4 = c2^1;
	cout << "c4 = " << c2 << "^" << 1 << " = " << c4 << endl;
	c4 = c2^2;
	cout << "c4 = " << c2 << "^" << 2 << " = " << c4 << endl;
	c4 = c2^-1;
	cout << "c4 = " << c2 << "^" << -1 << " = " << c4 << endl;
	c4 = c2^-2;
	cout << "c4 = " << c2 << "^" << -2 << " = " << c4 << endl;
*/
	cout << "\nSetter and Getter: \n";
	c5.setReal(3);
	c5.setImag(2);
	cout << "c5 = " << c5.getReal() << "+" <<c5.getImag() << "i\n";
/*
	cout << "\nAssignment: \n";
	Complex c6;
	c6 = c4 = c1;
	cout << "c6 = c4 = c1 = " << c6 << endl;
	cout << "c4 = " << c4 << endl;
*/
	c1 = Complex(2,3);
	c2 = Complex(2,4);
	cout << "\nComparisons\n";
	cout << "c1 = " << c1.to_string() << endl;
	cout << "c2 = " << c2.to_string() << endl;
	cout << "c1 == c1 " << (c1.to_string()==c1.to_string()) << endl;

	cout << "c1 != c1 " << (c1.to_string()!=c1.to_string()) << endl;
	cout << "c1 == c2 " << (c1.to_string()==c2.to_string()) << endl;
	cout << "c1 != c2 " << (c1.to_string()!=c2.to_string()) << endl;

	cout << "c1 <  c2 " << (c1.to_string()< c2.to_string()) << endl;
	cout << "c1 <= c2 " << (c1.to_string()<=c2.to_string()) << endl;
/*
	cout << "c1 >  c2 " << (c1> c2) << endl;
	cout << "c1 >= c2 " << (c1>=c2) << endl;
*/
	cout << "c1 <  c1 " << (c1.to_string()< c1.to_string()) << endl;
	cout << "c1 <= c1 " << (c1.to_string()<=c1.to_string()) << endl;
/*
	cout << "c1 >  c1 " << (c1> c1) << endl;
	cout << "c1 >= c1 " << (c1>=c1) << endl;

/*
	cout << "\ntesting cin \n";
	do
	{
		cout << "Enter complex (0 to quit): ";
		cin >> c4;
		cout << "Entered " << c4 << endl;
	} while ( c4.abs() != 0 );
*/

	return 0;
}
