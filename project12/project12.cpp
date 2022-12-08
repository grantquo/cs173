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
using namespace std;

string charReader( void );
// void parenBalance(stack<string> s)
// void errorReport(int type, int lineNum, int charNum);

struct Loc
{
    int lineNum;
    int charNum;
};

int main ( void )
{

    // read in file

    stack<char> s;
    parenBalancer(s);

    return 0;
}

string charReader( void )
{
    string input = "0";
    if (cin.eof() == false)
        getline(cin, input);
    return input;
}


// function definitions


// void parenBalance(stack<char> s)
// {
//
//     stack<Loc> l;
//     int line = 0;
//     int char = 0;
//     char curChar = charReader();
//     while (curChar != "O"){
//         if (curChar == "(" || curChar == "[" || curChar == "{") // if open
//         {
//             s.push(curChar);
//             Loc curLoc;
//             curLoc.lineNum =
//
//         }
//         elif (curChar != "\n") // if not open
//         {
//             if (s.empty() == false) // if stack isn't empty
//             {
//                 char stackTop = s.top();
//                 s.pop();
//
//             }
//             // if stack is empty
//             // report Type Error 3
//
//         }
//         else
//         {
//
//         }
//         curChar = charReader(); // cycle next charReader
//     }
//
//     // end of string reached
// }

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
