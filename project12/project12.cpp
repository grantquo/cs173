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

char charReader( void );
void errorReport(int type, int lineNum, int charNum);


using namespace std;

int main ( void )
{

    // read in file

    stack<string> s;
    char curParen;
    bool errorStatus = false;
    curParen = charReader();
    while (curParen != 'O' && errorStatus = false)
    {
        curParen = charReader();
        s.push(curParen)
    }

    return 0;
}

// function definitions

char charReader( void )
{
    char input = 'O';
    if (cin.eof() == false)
        cin >> input;
    return input;
}

void errorReport(int type, int lineNum, int charNum)
{
    return;
}



/*
struct var
{
int lineNum;
int charNum;
}



*/
