//============================================
// Matt Kretchmar
// driver.cpp
// December 2022
// A simple driver test file for our Stack class
//============================================

#include <iostream>
using namespace std;
#include "Stack.h"

//============================================
// main
//============================================

int main ( void )
{
	Stack<int>	s1;
	cout << "s1 size = " << s1.size() << endl;
	cout << "s1 empty? " << s1.empty() << endl;
	
	for ( int i = 1; i <= 5; i++ )
		s1.push(i);
		
	cout << "s1 size = " << s1.size() << endl;
	cout << "s1 empty? " << s1.empty() << endl;
	
	while ( !s1.empty() )
	{
		cout << "pop = " << s1.pop() << endl;
	}
	
	cout << "s1 size = " << s1.size() << endl;
	cout << "s1 empty? " << s1.empty() << endl;
	
	return 0;
}

