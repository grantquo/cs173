//===============================================
// Matt Kretchmar
// December 2022
// sorting.cpp
// A program to explore and compare different sorting
// algorithms and their relative performance.
//===============================================

#include <iostream>
#include <ctime>
using namespace std;

#define MAX 1000000

//===============================================
// function declarations
//===============================================

void	createArray		( int *a, int size );
void	copyArray		( int *a, int *b, int size );
void	printArray		( int *a, int size );

void	selectionSort	( int *a, int size );
void	insertionSort	( int *a, int size );

void 	merge 			( int a[], int s1, int e1, int s2, int e2 );
void 	mergeSort 		( int a[], int low, int high );

//===============================================
// main
//===============================================

int main ( int argc, char *argv[] )
{
	// seed the PRNG with the clock
	srand(time(NULL));
	
	int n = 10;
	if ( argc > 1 )
		n = atoi(argv[1]);

	int *array1, *array2, *array3;

	array1 = new int[n];
	createArray(array1,n);
	
	array2 = new int[n];
	copyArray(array1,array2,n);

	// sort algorithm here on array2
	printArray(array2,n);

	return 0;
}

//===============================================
// printArray
//===============================================

void	printArray ( int *a, int size )
{
	for ( int i = 0; i < size; i++ )
		cout << a[i] << endl;
}

//===============================================
// createArray
//===============================================

void	createArray ( int *a, int size )
{
	for ( int i = 0; i < size; i++ )
		a[i] = rand() % MAX;
}

//===============================================
// copyArray
//===============================================

void 	copyArray ( int *a, int *b, int size )
{
	for ( int i = 0; i < size; i++ )
		b[i] = a[i];
}

//===============================================
//===============================================

//===============================================
//===============================================

//===============================================
//===============================================

//===============================================
//===============================================


//===============================================
//===============================================


//===============================================
//===============================================


//===============================================
//===============================================


//===============================================
//===============================================



