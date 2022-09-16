//===============================================
// your name here
// September 2022
// arrayEx4.cpp
// This program contains a function to determine
// if one array dominates another array.
// Array A is said to dominate array B if there is
// no A[i] < B[i] for the same index i.  If array
// A is longer than array B, then each entry in B
// must be dominated by the corresponding entry in A.
// If array B is longer, then B is not dominated by A.
//===============================================

#include <iostream>
using namespace std;

// function declarations
bool dominates ( int a[], int na, int b[], int nb );

//===============================================
// main
//===============================================
int main ( void )
{
	int A[] = {1, 10, 6, 5, 8, 100};
	int na = 6;
	int B[] = {-50, 10, 6, 2};
	int nb = 4;
	int C[] = {0, 0, 0, 0, 0, 0, 0};
	int nc = 7;
	
	if ( dominates(A,na,B,nb) )
		cout << "A dominates B\n";
	else
		cout << "A does not dominate B\n";
		
	if ( dominates(A,na,A,na) )
		cout << "A dominates A\n";
	else
		cout << "A does not dominate A\n";
		
	if ( dominates(B,nb,A,na) )
		cout << "B dominates A\n";
	else
		cout << "B does not dominate A\n";
		
	if ( dominates(A,na,C,nc) )
		cout << "A dominates C\n";
	else
		cout << "A does not dominate C\n";
		
	
	return 0;
}

//===============================================
// you write function comment and function
// definition
//===============================================


