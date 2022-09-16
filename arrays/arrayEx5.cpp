//===============================================
// your name here
// September 2022
// arrayEx5.cpp
// This program performs the merge operation of 
// mergesort.  
//===============================================

#include <iostream>
using namespace std;

// function declarations
void merge 		( int A[], int na, int B[], int nb, int C[] );
void printArray ( int a[], int n );

//===============================================
// main
//===============================================
int main ( void )
{
	int A[] = {2,3,5,7,11,13,17,19};
	int na = 8;
	int B[] = {1,1,2,3,5,8,13,21,34,55};
	int nb = 10;
	int nc = na+nb;
	int C[nc];
	
	merge(A,na,B,nb,C);
	
	cout << "Array A: ";
	printArray(A,na);
	cout << "Array B: ";
	printArray(B,nb);
	cout << "Array C: ";
	printArray(C,nc);
			
	return 0;
}

//===============================================
// Merge
// you write the comments and the definition
//===============================================

//===============================================
// printArray
//===============================================
// copy code from Exercise1

