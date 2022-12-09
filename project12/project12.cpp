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

struct Loc
{
    int lineNum;
    int charNum;
};

string lineReader( void );
void paremBalance(stack<char> s, stack<Loc> l, string curLine, int curLineNum);
bool comparator(char s1, char s2);
void clearStacks(stack<char> s, stack<Loc> l);
void errorReport(char openParem, char closedParem, int type, int lineNum, int charNum);



int main ( void )
{
    stack<char> s;
    stack<Loc> l;
    int curLineNum = 0;

    string curLine = lineReader();
    while (curLine != "")
    {
        paremBalance(s, l, curLine, curLineNum);
        curLineNum++; // +1 line index
        curLine = lineReader(); // go to next line
    }

    return 0;
}

string lineReader( void )
{
    string input;
    getline(cin, input);
    return input;
}

void paremBalance(stack<char> s, stack<Loc> l, string curLine, int curLineNum)
{
    for (int curCharNum = 0; curCharNum <= curLine.length(); curCharNum++) // loop through line
    {
        char curChar = curLine[curCharNum]; // obtain character from line string
        // if an open parem
        if (curChar == '(' || curChar == '[' || curChar == '{')
        {
            s.push(curChar);
            Loc curLoc;
            curLoc.lineNum = curLineNum;
            curLoc.charNum = curCharNum;
            l.push(curLoc);
        }

        // if a closed parem
        else if (curChar == ')' || curChar == ']' || curChar == '}')
        {
            if (s.empty() == false) // if stack isn't empty
            {
                // assign open parem
                // remove open parem from stack
                char stackTop = s.top();
                s.pop();

                // assign open parem locs
                // remove open parem locs from stack
                Loc topLoc = l.top();
                int openLineNum = topLoc.lineNum;
                int openCharNum = topLoc.charNum;
                l.pop();

                // if no match, ERROR 1 !!!!!!!!!!!
                if (comparator(stackTop, curChar) == false)
                {
                    errorReport(stackTop, curChar, 1, curLineNum, curCharNum);
                    // finishing output with error locs data
                    cout << " found at line " << openLineNum+1 << " char "
                    << openCharNum+1 << " ." << endl;
                }
            }

            else if (s.empty() == true)
            {
                // if stack is empty
                // report Type ERROR 3 !!!!!!!!!!!!!
                errorReport('O', curChar, 3, curLineNum, curCharNum);
            }

        }

    }
    clearStacks(s, l);
}

bool comparator(char open, char closed)
{
    if (open == '(' && closed == ')')
        return true;
    else if (open == '[' && closed == ']')
        return true;
    else if (open == '{' && closed == '}')
        return true;
    return false;
}

void clearStacks(stack<char> s, stack<Loc> l)
{
    while (s.empty() == false && l.empty() == false)
    {
        char topOpenParem = s.top();
        Loc topLoc = l.top();
        int topLineNum = topLoc.lineNum;
        int topCharNum = topLoc.charNum;
        errorReport(topOpenParem, 'O', 2, topLineNum, topCharNum);
        s.pop();
        l.pop();
    }
}
//
void errorReport(char openParem, char closedParem, int type, int lineNum, int charNum)
{
    if (type == 1)
    {
        cout << "Type I Error: " << closedParem << " found at line " << lineNum+1
        << " char " << charNum+1 << " does not match " << openParem;
    }

    else if (type == 2)
    {
        cout << "Type II Error: " << openParem << " found at line " << lineNum+1
        << " char " << charNum+1 << " with no matching close paren." << endl;
    }

    else
    {
        cout << "Type III Error: " << closedParem << " found at line " << lineNum+1
        << " char " << charNum+1 << " with no matching open paren." << endl;
    }
}
