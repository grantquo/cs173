//==============================================================
//Zheng and Grant
//September 2022
//project4.cpp
//translate decimal values into Roman numerals
//==============================================================

#include <iostream>
#include <string>
using namespace std;
//==============================================================
//convert
//This function convert the decimal number to Roman numerals
// PARAMETERS:
// - year  : a decimal integer between 1 and 2022
// RETURN :  
// - result : the translsted Roman numeral of year
//==============================================================

string convert (int year)
{
	string roman_numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int decimal_values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string result = "";

        for (int i = 0; i < 13; ++i)
        {
            	while(year - decimal_values[i] >= 0)
            	{
                	result += roman_numerals[i];
                	year -= decimal_values[i];
            	}
        }
	return result;
}

//==================
//main function
//===================

int main ( void )
{
	
	int year;
	
	while (year != 0)
	{
		cout << "Enter year 1 to 2022 (0 to quit): " << endl;
		cin  >> year;
		if ( year < 0 || year > 2022)
		{
			cout << "Invalid Entry. Try again." << endl;
			continue;
		}
		else if ( year == 0)
		{
			return 0;
		}
		cout << year << "=" << convert(year) << endl;
	}
	
	return 0;
	
}
