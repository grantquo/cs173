//=========================================
// Matt Kretchmar
// October 2022
// practice with pointers
//=========================================

#include <iostream>
using namespace std;

int		p	( int *a, int n );
void    printArray ( int a[], int n );

int main ( void )
{
	int array1[] = {5,1,9,3,11,4,0,6,7};
	int array2[] = {12,10,8,7,6,3,2,1,0};
	int array3[] = {0,1,2,3,6,7,8,10,12};
	int array4[] = {6,1,6,1,6,1,6,1,6};
	
	printArray(array1,9);
	printArray(array2,9);
	printArray(array3,9);
	printArray(array4,9);
	cout << endl;
	
	int index1 = p(array1,9);
	int index2 = p(array2,9);
	int index3 = p(array3,9);
	int index4 = p(array4,9);
	
	cout << "array1 " << index1 << endl;
	printArray(array1,9);
	cout << "array2 " << index2 << endl;
	printArray(array2,9);
	cout << "array3 " << index3 << endl;
	printArray(array3,9);
	cout << "array4 " << index4 << endl;
	printArray(array4,9);
	
	return 0;
}
	
//=========================================
void printArray ( int a[], int n )
{
	for ( int i = 0; i < n; i++ )
		cout << a[i] << " ";
	cout << endl;
}
//=========================================
int		p	( int *a, int n )
{
	int	*ptr = a;
	int *qtr = a + n - 1;
	int v = *qtr--;
	int t;
	
	while ( ptr < qtr )
	{
		while ( *ptr < v )
			ptr++;
		while ( qtr >= a && *qtr >= v)
			qtr--;
		if ( ptr < qtr )
		{
			t = *ptr;
			*ptr = *qtr;
			*qtr = t;
		}
	}
	t = *(a+n-1);
	*(a+n-1) = *ptr;
	*ptr = t;
	return ptr-a;
}
	
	
