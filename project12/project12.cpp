//=============================================================
// Grant Gutterman, Cong Nguyen, & Di Wu
// 12-9-22
// project12.cpp
// Stack program that tracks parens and ensures they
// are balanced.
//=============================================================

// inclusions and function declarations

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 'Loc' datatype.
struct Loc
{
    int lineNum;
    int charNum;
};

string lineReader( void );
void parenBalance(stack<char> s, stack<Loc> l, string curLine, int curLineNum);
bool comparator(char s1, char s2);
void clearStacks(stack<char> s, stack<Loc> l);
void errorReport(char openParen, char closedParen, int type, int lineNum, int charNum);



//=============================================================
// main
// This is the main function of the program. It's purpose is to
// initialize a locator and char stack, while reading line by
// line the file. This sends the string lines to parenBalance to
// check for errors. It also keeps track of the line number index.
// PARAMS:
//      none
// RETURNS:
//      nothing
//=============================================================
int main ( void )
{
    stack<char> s;
    stack<Loc> l;
    int curLineNum = 0;

    string curLine = lineReader();
    while (curLine != "")
    {
        parenBalance(s, l, curLine, curLineNum);
        curLineNum++;
        curLine = lineReader();
    }

    return 0;
}

//=============================================================
// lineReader
// Simple function for using stdin to read a user-given file line
// by line.
// PARAMS:
//      none
// RETURNS:
//      A string of a full line from a text file.
//=============================================================
string lineReader( void )
{
    string input;
    getline(cin, input);
    return input;
}

//=============================================================
// parenBalance
// This function completes the main error tracking of the program.
// It loops through every character from a line in the file and
// checks for paren imbalances, calling the error reporting function
// when it finds one.
// PARAMS:
//      stack<char> s: A stack that hold open parens.
//      stack<Loc> l: This stack holds a struct that contains
//      character and line number information for each open parens.
//      string curLine: String of a line of text read from lineReader.
//      int curLineNum: Integer for index line number.
// RETURNS:
///     Nothing, but calls errorReport to output error information.
//=============================================================
void parenBalance(stack<char> s, stack<Loc> l, string curLine, int curLineNum)
{
    for (int curCharNum = 0; curCharNum <= curLine.length(); curCharNum++) // loop through line
    {
        char curChar = curLine[curCharNum];

        if (curChar == '(' || curChar == '[' || curChar == '{')
        {
            s.push(curChar);
            Loc curLoc;
            curLoc.lineNum = curLineNum;
            curLoc.charNum = curCharNum;
            l.push(curLoc);
        }

        else if (curChar == ')' || curChar == ']' || curChar == '}')
        {
            if (s.empty() == false)
            {
                char stackTop = s.top();
                s.pop();

                Loc topLoc = l.top();
                int openLineNum = topLoc.lineNum;
                int openCharNum = topLoc.charNum;
                l.pop();

                if (comparator(stackTop, curChar) == false)
                {
                    errorReport(stackTop, curChar, 1, curLineNum, curCharNum);
                    cout << " found at line " << openLineNum+1 << " char "
                    << openCharNum+1 << " ." << endl;
                }
            }
            else if (s.empty() == true)
                errorReport('O', curChar, 3, curLineNum, curCharNum);
        }
    }
    clearStacks(s, l);
}

//=============================================================
// comparator
// Simple comparing function that takes an open and closed parens
// and see if they are matching.
// PARAMS:
//      char open: An open paren in a char type.
//      char closed: A closed paren in a char type.
// RETURNS:
//      A Boolean true or false for if they are matching.
//=============================================================
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

//=============================================================
// clearStacks
// This function checks for any leftover data in the location
// and open paren stacks, and then send their information for
// error Type II reporting.
// PARAMS:
//      stack<char> s: A stack that hold open parens.
//      stack<Loc> l: This stack holds a struct that contains
//      character and line number information for each open parens.
// RETURNS:
//      Nothing, but calls errorReporting that outputs through
//      stdout.
//=============================================================
void clearStacks(stack<char> s, stack<Loc> l)
{
    while (s.empty() == false && l.empty() == false)
    {
        char topOpenParen = s.top();
        Loc topLoc = l.top();
        int topLineNum = topLoc.lineNum;
        int topCharNum = topLoc.charNum;
        errorReport(topOpenParen, 'O', 2, topLineNum, topCharNum);
        s.pop();
        l.pop();
    }
}

//=============================================================
// errorReport
// This function takes in information and uses them to report
// errors through stdout.
// PARAMS:
//      char openParen: An open paren.
//      char closedParen: A closed paren.
//      int type: An integer that denotes what type of error.
//      int lineNum: Index number for the line in the text file.
//      int charNum: Index number for the char in the text file.
// RETURNS:
//      Nothing is returned, but stdout outputs error information
//      and location.
//=============================================================
void errorReport(char openParen, char closedParen, int type, int lineNum, int charNum)
{
    if (type == 1)
    {
        cout << "Type I Error: " << closedParen << " found at line " << lineNum+1
        << " char " << charNum+1 << " does not match " << openParen;
    }
    else if (type == 2)
    {
        cout << "Type II Error: " << openParen << " found at line " << lineNum+1
        << " char " << charNum+1 << " with no matching close paren." << endl;
    }
    else
    {
        cout << "Type III Error: " << closedParen << " found at line " << lineNum+1
        << " char " << charNum+1 << " with no matching open paren." << endl;
    }
}
