//========================================================
// Matt Kretchmar
// December 2022
// inherit.cpp
// An example illustrating inheritance 
// 
// We have a regular counter that increments by 1 as
// a base class.  We then build a specialized counters 
// that increment by 2 or by 10.  
//========================================================
#include <iostream>
using namespace std;

//========================================================
// Base class is simple counter
//========================================================
class Counter
{
protected:
	int value;
public:
			Counter 	( void ) { value = 0; }
	void 	increment 	( void ) { value += 1; }
	void 	reset     	( void ) { value = 0; }
	int		getValue 	( void ) { return value; }
	friend ostream & operator<< ( ostream &os, Counter &c )
	{ os << c.value;  return os; }
};
//========================================================
// Counter2 is derived from Counter
//========================================================
class Counter2 : public Counter
{
public:
	void	increment	( void ) { value += 2; }
};
//========================================================
// Counter10 is also derived from Counter
//========================================================
class Counter10 : public Counter
{
public:
	void	increment	( void ) { value += 10; }
};
//========================================================
// main has three different counters
//========================================================
int main ( void )
{
	Counter c1;
	
	cout << "c1 = " << c1 << endl;
	for ( int i = 0; i < 3; i++ )  c1.increment();
	cout << "c1 = " << c1 << endl;
	
	Counter2 c2;
	
	cout << "c2 = " << c2 << endl;
	for ( int i = 0; i < 3; i++ )  c2.increment();
	cout << "c2 = " << c2 << endl;

	Counter10 *c3;
	c3 = new Counter10;
	
	cout << "c3 = " << *c3 << endl;
	for ( int i = 0; i < 3; i++ )  c3->increment();
	cout << "c3 = " << *c3 << endl;
	delete c3;

	return 0;
}
