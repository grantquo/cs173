//==========================================================
// Grant Gutterman
// 09-23-2022
// project4.cpp
// Description
//==========================================================

#include <iostream>
#include <string>
using namespace std;

string convert(int year);

int main ( void )
{

    int year;
    while (year != 0)
    {
        cout << "Enter a year from 1 to 2022 (0 to quit): ";
        cin >> year;
        if (year < 0 || year > 2022)
        {
            cout << "Error! Year out of range. Try again." << endl;
            continue;
        }
        /*
        string output = convert(year);
        cout << year << " = " << output << endl;
        */
    }

    return 0;
}

string convert(int year){

    return 0;
}
