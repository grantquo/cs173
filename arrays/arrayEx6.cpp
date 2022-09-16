//===============================================
// your name here
// September 2022
// arrayEx6.cpp
// You are given an array of integers and also a
// target value.  You want to determine if it is possible
// to hit the target by selecting some (or all) the
// values in the array to sum together.  
//===============================================

#include <iostream>
using namespace std;

// function declarations
int   hitTarget  ( int A[], int na, int target, int t[] );
void  printArray ( int a[], int n );

//===============================================
// main
//===============================================
int main ( void )
{
	int A[] = {2,3,5,8,9,11,15,50,100,175};
	int na = 10;
	int t[na];
	int nt;
	int target;

	target = 7;
	if ( (nt=hitTarget(A,na,target)) != -1 )
	{
		cout << target << " has been hit with ";
		printArray(t,nt);	
	}
	else
		cout << target << " cannot be hit\n";
			
	target = 16;
	if ( (nt=hitTarget(A,na,target)) != -1 )
	{
		cout << target << " has been hit with ";
		printArray(t,nt);	
	}
	else
		cout << target << " cannot be hit\n";
			
	target = 99;
	if ( (nt=hitTarget(A,na,target)) != -1 )
	{
		cout << target << " has been hit with ";
		printArray(t,nt);	
	}
	else
		cout << target << " cannot be hit\n";
			
	target = 0;
	if ( (nt=hitTarget(A,na,target)) != -1 )
	{
		cout << target << " has been hit with ";
		printArray(t,nt);	
	}
	else
		cout << target << " cannot be hit\n";
			
	return 0;
}

//===============================================
// hitTarget
// PARAMETERS:
// - array A : an array of integers
// - na      : number of values in A
// - target  : value to hit
// - array t : an array of na spots
// RETURN VALUE:
// This function attempts to use some subset of values
// from A to sum exactly to the target value. If this is
// possible, then we will fill these values in array t[]
// and return the number of items in t.
// If it is not possible to sum to the target,
// then we return -1
//===============================================
int   hitTarget  ( int A[], int na, int target, int t[] )
{

}
//===============================================
// printArray
//===============================================
// copy code from Exercise1

