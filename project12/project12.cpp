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

void parenBalance(stack<char> s)
{

    stack<Loc> l;
    int curLineNum = 0;
    string curLine = charReader(); // take first line


    while (curLine != "O" && curLine == "\n") // if line isn't empty
    {
        for (int curCharNum = 0; curCharNum <= curLine.length()) // loop through line
        {
            curChar = curLine[curCharNum]; // obtain character from line string

            if (curChar == "(" || curChar == "[" || curChar == "{") // if open
            {
                s.push(curChar);
                Loc curLoc;
                curLoc.lineNum = curLineNum;
                curLoc.charNum = curCharNum;
                l.push(curLoc);
            }
            elif (curChar == ")" || curChar == "]" || curChar = "}") // if not open
            {
                if (s.empty() == false) // if stack isn't empty
                {
                    char stackTop = s.top();
                    s.pop();

                }
                // if stack is empty
                // report Type Error 3

            }
            curCharNum++; // +1 char index
        }
        curLineNum++; // +1 line index
        curCharNum = 0; // reset char index
        curLine = charReader(); // go to next line
    }

    // end of string reached
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
