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

string lineReader( void );
void parenBalance(stack<string> s);
bool comparator(string s1, string s2);
void clearStacks(stack<string> s, stack<string> l);
// void errorReport(int type, int lineNum, int charNum);

struct Loc
{
    int lineNum;
    int charNum;
};

int main ( void )
{

    // read in file

    stack<string> s;
    parenBalancer(s);

    return 0;
}

string lineReader( void )
{
    string input = "0";
    if (cin.eof() == false)
        getline(cin, input);
    return input;
}

void parenBalance(stack<string> s)
{

    stack<Loc> l;
    int curLineNum = 0;
    string curLine = lineReader(); // take first line


    while (curLine != "O" && curLine == "\n") // if line isn't empty
    {
        for (int curCharNum = 0; curCharNum <= curLine.length()) // loop through line
        {
            string curChar = curLine[curCharNum]; // obtain character from line string

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

                    // assign open param
                    // remove open param from stack
                    string stackTop = s.top();
                    s.pop();

                    // assign open param locs
                    // remove open param locs from stack
                    Loc topLoc = l.top();
                    int openLineNum = topLoc.lineNum;
                    int openCharNum = topLoc.charNum;
                    l.pop();

                    // if no match, ERROR 1 !!!!!!!!!!!
                    if (comparator(stackTop, curChar) == false)
                    {
                        errorReport(stackTop, curChar, 1, curLineNum, curCharNum);
                        // finishing output with error locs data
                    }
                }
                // if stack is empty
                // report Type ERROR 3 !!!!!!!!!!!!!
                errorReport("", curChar, 3, curLineNum, curCharNum);
            }
            curCharNum++; // +1 char index
        }

        // report Type ERROR 2 !!!!!
        clearStacks(s, l);

        curLineNum++; // +1 line index
        curCharNum = 0; // reset char index
        curLine = lineReader(); // go to next line
    }

    // end of string reached
}

bool comparator(string open, string closed)
{
    if (open == "(" && closed == ")")
        return true;
    elif (open == "[" && closed == "]")
        return true;
    elif (open == "{" && closed == "}")
        return true;
    return false;
}

void clearStacks(stack<string> s, stack<string> l)
{
    while (s.empty() != false && l.empty() != false)
    {
        string topOpenParam = s.top();
        Loc topLoc = l.top();
        int topLineNum = topLoc.lineNum;
        int topCharNum = topLoc.charNum;
        errorReport(topOpenParam, "", 2, topLineNum, topCharNum);
        s.pop();
        l.pop();
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
