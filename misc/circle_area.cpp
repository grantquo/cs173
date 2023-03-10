// ===========
// Grant Gutterman
// 09-02-2022
// circle_area.cpp
// Computer the area of two circles.
// ===========

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//const float PI = 3.141529;

int main( void )
{
	float radius1, radius2;
	float area1, area2;
	float percent_diff;
	
	// prompt user for and read in radii
	
	cout << "Enter radius1: ";
	cin >> radius1;
	
	cout << "Enter radius2: ";
	cin >> radius2;
	
	// compute the area
	
	area1 = M_PI * radius1 * radius1;
	area2 = M_PI * pow(radius2, 2.0);
	
	// compute the difference
	
	float diff = abs(area1-area2);
	percent_diff = diff / area1 * 100.0;
	
	if ( area1 > area2 )
		cout << "Circle 2 is " << percent_diff << "% smaller.\n";
	else
		cout << "Circle 2 is " << percent_diff << "% bigger.\n";
	
	return 0;

}
