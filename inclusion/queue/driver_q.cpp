//============================================
// Matt Kretchmar
// driver.cpp
// December 2022
// A simple driver test file for our Queue class
//============================================

#include <iostream>
using namespace std;
#include "Queue.h"

//============================================
// main
//============================================

int main ( void )
{
	Queue<int>	q1;
	cout << "q1 size = " << q1.size() << endl;
	cout << "q1 empty? " << q1.empty() << endl;
	
	for ( int i = 1; i <= 5; i++ )
		q1.enqueue(i);
		
	cout << "q1 size = " << q1.size() << endl;
	cout << "q1 empty? " << q1.empty() << endl;
	
	while ( !q1.empty() )
	{
		cout << "dequeue = " << q1.dequeue() << endl;
	}
	
	cout << "q1 size = " << q1.size() << endl;
	cout << "q1 empty? " << q1.empty() << endl;
	
	return 0;
}

