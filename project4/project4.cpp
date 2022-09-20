//==========================================================
// Grant Gutterman
// 09-23-2022
// project4.cpp
// Description
//==========================================================

#include <iostream>
#include <string>
using namespace std;

int convert(int year);

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

        int output = convert(year);
        cout << year << " = " << output << endl;

    }

    return 0;
}

int convert(int year){
    int ones, tens, hundreds, thousands;
    ones = (year)%10;
    tens = (year-ones)%100;
    hundreds = (year-tens-ones)%1000;
    thousands = (year-hundreds-tens-ones)%10000;
    // cout << ones << ", " << tens << ", " << hundreds << ", " << thousands << endl;
    

}
