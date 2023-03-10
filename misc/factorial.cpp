// ============================================
// Grant Gutterman
// 09-13-2022
// factorial.cpp
// This program computes factorials using functions.
// ============================================

#include <iostream>
using namespace std;

// You use function declarations before main.

int factorial ( int m );
int superSum ( int m );
int recursFact ( int m );

int main ( void ){

    int n, fact;
    cout << "Enter n: ";
    cin >> n;
    fact = factorial(n);
    cout << n << "! = " << fact << endl;

    sum = superSum(n);
    cout << "superSum(" << n << ") = "<< sum << endl;

    return  0;
}

// ============================================
// factorial
// This function computes and return m factorial
// PARAMs:
// - m : any non-negative integer
// RETURN:
// - m!
// ============================================

int factorial ( int m )
{
    int f = 1;

    for ( int i=2 i < = m; i++)
        f = f*i;

    return f;

}

// ============================================
// recursFact
// This function computes recursively and return m factorial
// PARAMs:
// - m : any non-negative integer
// RETURN:
// - m!
// ============================================

int recursFact ( int m )
{
    if ( m < 2 )
        return 1;
    else
        return m * recursFact(m-1);

}

// ============================================
// superSum
// This function computes and returns the superSum of m
// = 1 + 2 + 3 + ... + m
// PARAMs:
// - m : any non-negative integer
// RETURN:
// - 1+2+3+...+m
// ============================================

int superSum ( int m )
{
    int s = 0;
    for ( int i = 1; i <= m; i++)
        s = s + i;
    return s;
}
