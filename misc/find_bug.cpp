//=============================================
// Matt Kretchmar
// November 2022
// find_bug.cpp
// This program has a bug we need to find with the
// debugger.  
//=============================================

#include <iostream>
using namespace std;

int main ( void )
{
	int *array;
	array = new int[10];
	for ( int i = 0; i < 10; i++ )
		if ( i % 2 )
			array[i] = (i+1)*10;
		else
			array[i] = 0;
		
	// ptr points to array[2]
	int *ptr = array+2;
	
	// change array[2] to 5
	*ptr = 5;
	
	// move to array[4]
	ptr += 2;
	
	// if value at array[4] != 0, add 100 to it
	if ( ptr )
		*ptr += 100;
		
	for ( int i = 0; i < 10; i++ )
		cout << "array[" << i << "] = " << array[i] << endl;

	delete []array;
	
	return 0;
}
