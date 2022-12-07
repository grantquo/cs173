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
void parenBalancer(stack<string> s)
// void errorReport(int type, int lineNum, int charNum);


using namespace std;

int main ( void )
{

    // read in file

    stack<char> s;
    parenBalancer(s);

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

void parenBalancer(stack<char> s)
{
    curChar = charReader();
    while (curChar != "O"){
        if (curChar == )
    }
}

// void errorReport(char paren1, char paren2, int type, int lineNum, int charNum)
// {
//     if (type == 1){
//         cout << "Type " << type << " Error: " << paren1 << " found at line: " <<
//         lineNum << " char: " << charNum << " does not match " << paren2 <<
//         " (found "
//     }
//     cout << "Type " << type << " Error: found at line: " <<
//     lineNum << " char: " <<
// }




struct curParenLoc
{
int lineNum;
int charNum;
}
