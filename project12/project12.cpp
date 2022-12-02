//=====================================================
// Grant Gutterman
// 12-9-22
// project12.cpp
// Stack program that tracks parens and ensures they
// are balanced.
//=====================================================

// inclusions and function declarations

#include <iostream>
#include <string>
#include <stack>

string charReader( void );
void errorReport(int type, int lineNum, int charNum);

using namespace std;

int main ( void )
{

    // read in file

    stack<string> s;



    return 0;
}

// function definitions

void errorReport(int type, int lineNum, int charNum)
{
    return;
}

string charReader( void )
{
    string character;

    while (cin.get(character) != " ")
        cin.get(character);

    return character;
}
