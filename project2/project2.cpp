// =====================
// Grant Gutterman
// 09-09-2022
// project2.cpp
// This project takes in lengths of time for how long two lights are on and off, and then
// outputs whether a delivery at a particular time will occur while both are on, one is off, 
// or both are off.
// =====================

#include <iostream>
#include <string>

using namespace std;

int main ( void )
{
	// Variable Initialization
	
	int t1_on;
	int t1_off;
	
	int t2_on;
	int t2_off;
	
	int t_ups;

	int light1;
	int light2;
	
	// User Input
	
	cout << "Enter t1_on: ";
	cin >> t1_on;
	cout << "Enter t1_off: ";
	cin >> t1_off;
	cout << "Enter t2_on: ";
	cin >> t2_on;
	cout << "Enter t2_off: ";
	cin >> t2_off;
	cout << "Enter t_ups: ";
	cin >> t_ups;
	
	// Light 1 Compare

	int loop = 0;
	int iterable = 0;
	do {

		iterable = iterable + t1_on;
		if ( iterable > t_ups ) {
			light1 = 1;
			loop = 1;
		}
		if ( iterable == t_ups ) {
			light1 = 0;
			loop = 1;
		}

		if  ( loop == 1 )
			break;

		iterable = iterable + t1_off;
		if ( iterable > t_ups ) {
			light1 = 0;
			loop = 1;
		}
		if ( iterable == t_ups ) {
			light1 = 1;
			loop = 1;
		}
	}
	while (loop = 0);

	// Light 2 Compare

	loop = 0;
	iterable = 0;
	do {

		iterable = iterable + t2_on;
		if ( iterable > t_ups ) {
			light2 = 1;
			loop = 1;
		}
		else if ( iterable == t_ups ) {
			light2 = 0;
			loop = 1;
		}

		if  ( loop == 1 )
			break;

		iterable = iterable + t2_off;
		if ( iterable > t_ups ) {
			light2 = 0;
			loop = 1;
		}
		else if ( iterable == t_ups ) {
			light2 = 1;
			loop = 1;
		}
	}
	while (loop = 0);

	// Get Result
	
	if ( light1 == 1 && light2 == 1 )
		cout << "BOTH" << endl;
	else if ( light1 == 1 && light2 == 0 )
		cout << "ONE" << endl;
	else if ( light1 == 0 && light2 == 1 )
		cout << "ONE" << endl;
	else if ( light1 == 0 && light2 == 0 )
		cout << "NONE" << endl;

	return 0;
}
