//========================================================
// Matt Kretchmar
// allSorts.cpp
// December 2022
// A program that sorts in multiple ways.

//========================================================
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define MAX 1000000

//===============================================
// function declarations
//===============================================

void	createArray		( int *a, int size );
void	copyArray		( int *a, int *b, int size );
void	printArray		( int *a, int size );
bool	isSorted		( int *a, int size );

void	selectionSort	( int *a, int size );
void	insertionSort	( int *a, int size );
void	bubbleSort		( int *a, int size );

void 	merge 			( int a[], int s1, int e1, int s2, int e2 );
void 	mergeSort 		( int a[], int low, int high );

int		partition		( int *a, int low, int high );
void 	quickSort 		( int *a, int low, int high );

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

	cout << "Selection Sort\n";
	copyArray(array1,array2,n);
	auto start = high_resolution_clock::now();
	selectionSort(array2,n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	//printArray(array2,n);
	cout << "Is Sorted? " << isSorted(array2,n) << endl;
	cout << "Time: " << duration.count() << endl << endl;

	cout << "Insertion Sort\n";
	copyArray(array1,array2,n);
	start = high_resolution_clock::now();
	insertionSort(array2,n);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	//printArray(array2,n);
	cout << "Is Sorted? " << isSorted(array2,n) << endl;
	cout << "Time: " << duration.count() << endl << endl;

	cout << "Bubble Sort\n";
	copyArray(array1,array2,n);
	start = high_resolution_clock::now();
	bubbleSort(array2,n);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	//printArray(array2,n);
	cout << "Is Sorted? " << isSorted(array2,n) << endl;
	cout << "Time: " << duration.count() << endl << endl;

	cout << "Merge Sort\n";
	copyArray(array1,array2,n);
	start = high_resolution_clock::now();
	mergeSort(array2,0,n-1);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	//printArray(array2,n);
	cout << "Is Sorted? " << isSorted(array2,n) << endl;
	cout << "Time: " << duration.count() << endl << endl;

	cout << "Quick Sort\n";
	copyArray(array1,array2,n);
	start = high_resolution_clock::now();
	quickSort(array2,0,n-1);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	//printArray(array2,n);
	cout << "Is Sorted? " << isSorted(array2,n) << endl;
	cout << "Time: " << duration.count() << endl << endl;

	return 0;
}

//===============================================
// isSorted
// PARAMETERS:
// array a
// int size as the length of the array
// RETURN VALUE:
// true if the array is in sorted ascending order
// false if not.   Arrays with size 0 or 1 are
// considered to be in sorted order.
//===============================================
bool	isSorted ( int *a, int size )
{
	for ( int i = 0; i < size-1; i++ )
		if ( a[i] > a[i+1] )
			return false;
	return true;
}
//===============================================
// printArray
// PARAMETERS:
// array a
// int size as the length of the array
// RETURN VALUE:
// none, but array printed to screen, one element per line
//===============================================

void	printArray ( int *a, int size )
{
	for ( int i = 0; i < size; i++ )
		cout << a[i] << endl;
}

//===============================================
// createArray
// PARAMETERS:
// array a
// int size as the length of the array
// RETURN VALUE:
// none, but array is filled in with random values
// between 0 and MAX-1
//===============================================

void	createArray ( int *a, int size )
{
	for ( int i = 0; i < size; i++ )
		a[i] = rand() % MAX;
}

//===============================================
// copyArray
// PARAMETERS:
// array a
// array b
// int size as the length of the array
// RETURN VALUE:
// none, but the values of a are copied into b
//===============================================

void 	copyArray ( int *a, int *b, int size )
{
	for ( int i = 0; i < size; i++ )
		b[i] = a[i];
}

//===============================================
// selection sort
// PARAMETERS:
// array a
// int size as the length of the array
// RETURN VALUE:
// none, but the values in the array are placed
// in sorted ascending order
//===============================================
void	selectionSort	( int *a, int size )
{
	for ( int i = 0; i < size-1; i++ )
	{
		int min = i;
		for ( int j = i+1; j < size; j++ )
		{
			if ( a[j] < a[min] )
				min = j;
		}
		// swap a[i] with a[min]
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}

//===============================================
// insertion sort
// PARAMETERS:
// array a
// int size as the length of the array
// RETURN VALUE:
// none, but the values in the array are placed
// in sorted ascending order
// insert the next item from the unsorted part into
// the sorted part.
// -- outer loop controls boundary between sorted
// and unsorted parts
// -- inner loop moves the next value left until
// it finds the correct location to insert.
//===============================================

void	insertionSort	( int *a, int size )
{
	for ( int i = 1; i < size; i++ )
	{
		int j = i;
		while ( j > 0 && a[j-1] > a[j] )
		{
			int temp = a[j];
			a[j] = a[j-1];
			a[j-1] = temp;
			j--;
		}
	}
}

//===============================================
// bubbleSort
// PARAMETERS:
// array a
// int size as the length of the array
// RETURN VALUE:
// none, but the values in the array are placed
// in sorted ascending order
//===============================================

void	bubbleSort	( int *a, int size )
{
	for (int i = size-1; i > 0; i-- )
	{
		for ( int j = 0; j < i; j++ )
		{
			if ( a[j] > a[j+1] )
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

//===============================================
// merge
// PARAMETERS:
// array a
// int s1, e1
// int s2, e2
// These indices frame two parts of the array
// a[s1 .. e1] and a[s2 .. e2].  Note that these are
// consecutive segments so that s2 = e1+1
// RETURN VALUE:
// none, but the values in the array are placed
// in sorted ascending order from indices low to high
//===============================================
void 	merge	( int a[], int s1, int e1,
                           int s2, int e2 )
{
	int n = e2 - s1 + 1;
	int temp[n];

	int i = s1;
	int j = s2;
	int k = 0;
	// pick next smallest from first or second part
	while ( i <= e1 && j <= e2 )
	{
		if ( a[i] < a[j] )
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	// get remainder of first part
	while ( i <= e1 )
	{
		temp[k++] = a[i++];
	}

	// get remainder of second part
	while ( j <= e2 )
	{
		temp[k++] = a[j++];
	}

	// copy back into original array
	i = s1;
	for ( int k = 0; k < n; k++ )
		a[i++] = temp[k];
}

//===============================================
// mergeSort
// PARAMETERS:
// array a
// int low
// int high
// These form the part of the array to be sorted
// from a[low .. high]
// RETURN VALUE:
// none, but the values in the array are placed
// in sorted ascending order from indices low to high
//===============================================

void mergeSort ( int a[], int low, int high )
{
	if ( low < high )
	{
		int mid = (low+high) / 2;
		mergeSort(a,low,mid);
		mergeSort(a,mid+1,high);
		merge(a,low,mid,mid+1,high);
	}
}

//===============================================
//partition
// you write the comment block
//===============================================
int partition ( int a[], int low, int high )
{
	int pivot = a[high];
	int i = low-1;
	for ( int j = low; j < high; j++ )
	{
		if ( a[j] <= pivot )
		{
			i++;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	i++;
	a[high] = a[i];
	a[i] = pivot;
	return i;
}

//===============================================
// quickSort
// array a
// int low
// int high
// These form the part of the array to be sorted
// from a[low .. high]
// RETURN VALUE:
// none, but the values in the array are placed
// in sorted ascending order from indices low to high
//===============================================
void quickSort ( int *a, int low, int high )
{
	if ( low < high )
	{
		int mid = partition(a,low,high);
		quickSort(a,low,mid-1);
		quickSort(a,mid+1,high);
	}
}
