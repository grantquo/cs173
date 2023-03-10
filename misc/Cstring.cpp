// ===================================================
// Grant Gutterman
// 09-23-22
// Cstring.cpp
// Project file for C-style string practice.

#include <iostream>
#include <string>

using namespace std;

const int MAX=20;

void printASCII ( char s[] );
int strlen      ( char s[] );
bool isPalind   ( char s[] );

// ===================================================
// ===================================================
int main ( void )
{

    char name[MAX];
    cout << "Enter your name: ";
    cin >> name;

    cout << "Hello " << name << endl;

    printASCII(name);

    int n = strlen(name);
    cout << name << " has " << n << " characters\n";

    return 0;
}

// ===================================================
// printASCII
// PARAMS:
// s - a c-style string
// RETURN:
// none, but prints table of character values
// ===================================================

void printASCII ( char s[] )
{
    int i = 0;
    do
    {
        cout << i << " "
             << s[i] << " "
             << (int)s[i] << endl;
    } while ( s[i++] );
}

// ===================================================
// strlen
// PARAMS:
// -s - a c-style string
// RETURN:
// an integer of the length of the C string
// ===================================================
int strlen ( char s[] )
{
    int i = 0;
    while ( s[i] != 0 )
        i++;
    return i;
}

bool isPalind ( char s[] )
{
    int i = 0;
    while ( s[i++] )
    {
        
    }
    return false
}
