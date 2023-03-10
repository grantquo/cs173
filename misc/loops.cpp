// =====================
// Grant Gutterman
// 09-07-22
// loops.cpp
// Series of loop exercises for practice.
// =====================

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main( void )
{
	
	
	// Number 1
	
	/*
	for (int i =0; i <= 10; i++)
	{
		cout << i << endl;
	}
	*/
	
	// Number 2
	
	/*
	for (int i = 50; i >= 2;i=i-2)
	{
		cout << i << endl;
	}
	*/
	
	// Number 3
	
	
	/*
	int number;
	while (number > 10)	
	{
		cout << "Enter a number between 1 and 10: " << endl;
		cin >> number;
	}
	*/
	
	// Number 4
	
	int num;
	cout << "Enter a number to find its factors: " << endl;
	cin >> num;
	 
	
	while (num > 2)
	{
		cout << num/2 << endl;
	} 
	cout << 1 << endl;
	return 0;
};

