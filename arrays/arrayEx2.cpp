//===============================================
// your name here
// September 2022
// arrayEx2.cpp
// In this program we write a function to count
// the number of odd integers in an array.
//===============================================

#include <iostream>
using namespace std;

// function declarations
int countOdd ( int a[], int n );

//===============================================
//===============================================
int main ( void )
{
	int array[] = {1,1,2,3,5,8,13,21,34,55};
	int size = 10;
	
	int oddNum = countOdd(array,size);
	cout << "Array has " << oddNum << " odd integers\n";
	
	return 0;
}

//===============================================
// countOdd
// This function counts the number of odd integers
// in an array.
// PARAMETERS:
// - a  : an array of integers
// - n  : number of elements in array
// RETURN VALUE:  
// The number of odd values in the array of integers
//===============================================

int countOdd ( int a[], int n )
{
	// you write the code in here

}

