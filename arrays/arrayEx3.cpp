//===============================================
// your name here
// September 2022
// arrayEx3.cpp
// In this program we write a function to determine
// if an array is in sorted order (ascending) or not.
//===============================================

#include <iostream>
using namespace std;

// function declarations
bool isSorted ( int a[], int n );

//===============================================
// main
//===============================================
int main ( void )
{
	int array1[] = {1,1,2,3,5,8,13,21,34,55};
	int size = 10;
	int array2[] = {1,1,2,3,5,8,13,21,55,34};
	int array3[0];
	
	if ( isSorted(array1,size) )
		cout << "Array1 is sorted\n";
	else
		cout << "Array1 is not sorted\n";

	if ( isSorted(array2,size) )
		cout << "Array2 is sorted\n";
	else
		cout << "Array2 is not sorted\n";
	
	if ( isSorted(array3,0) )
		cout << "Array3 is sorted\n";
	else
		cout << "Array3 is not sorted\n";
	
	return 0;
}

//===============================================
// isSorted
// This function determines if the array of integers
// is in sorted ascending order or not. 
// PARAMETERS:
// - a  : an array of integers
// - n  : number of elements in array
// RETURN VALUE:  
// True if the array is in sorted ascending order,
// False otherwise.  Consecutive values in the array
// are permitted to be equal and still consider the array
// to be sorted. 
//===============================================

bool isSorted (int a[], int n )
{
	// you write the code in here

}

