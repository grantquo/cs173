// =============================================
// Grant Gutterman
// 10-10-22
// main.cpp
// Driver/ main tester file for a c++ classes practice.
// =============================================

#include <iostream>

using namespace std;

// class declaration
class Rational{

public:
                Rational        ( void );
                Rational        ( int n, int d );
    string      to_string       ( void );

// methods here
private:
    int     num;
    int     den;


    // implementation details
};

// =============================================
// default constructor
// PARAMS:
// none
// RETURNS:
// none
// Sets numerator=0 and denominator=1
// =============================================

                Rational::Rational ( void )
{
    num = 0;
    den = 1;
}

// =============================================
// constructor(n, d)
// PARAMS:
//      n - user's inputted numerator
//      d - user's inputted denominator
// RETURNS:
// none
// Sets numerator = to user defined n and denominator = to user defined b
// =============================================

                Rational::Rational ( int n, int d )
{
    num = n;
    den = d;
}

// =============================================
// to_string constructor
// PARAMS:
// none
// RETURNS:
// a string of form "a/b"
// Prints the rational object into a string of form "a/b" where a is numerator
// and b is denominator.
// =============================================

string          Rational::to_string ( void )
{
    string s;
    s = std::to_string(num) + "/" + std::to_string(den);
    return s;
}

int main ( void ){

    Rational r1;
    Rational r2(5,2);
    cout << "r1 = " << r1.to_string() << endl;
    cout << "r2 = " << r2.to_string() << endl;


    return 0;
}
