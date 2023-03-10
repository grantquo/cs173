//============================================
// Matt Kretchmar
// October 2022
// dumb example of repetitive classes
//============================================
#include <iostream>
using namespace std;
//============================================
// RingCounter as integer
//============================================
class RingCounterInt 
{
public:
			RingCounterInt	( int min, int max )
			{ smallest = min; largest = max; current = smallest; }
	int		read			( void )
			{ return current; }
	void	increment		( void )
			{ current = (current==largest) ? smallest:current+1; }
	void	decrement		( void )
			{ current = (current==smallest) ? largest:current-1; }
	void	reset			( void )
			{ current = smallest; }
private:
	int		current;
	int		smallest;
	int		largest;
};

//============================================
// RingCounter as char
//============================================
class RingCounterChar
{
public:
			RingCounterChar	( char min, char max )
			{ smallest = min; largest = max; current = smallest; }
	char	read			( void )
			{ return current; }
	void	increment		( void )
			{ current = (current==largest) ? smallest:current+1; }
	void	decrement		( void )
			{ current = (current==smallest) ? largest:current-1; }
	void	reset			( void )
			{ current = smallest; }
private:
	char	current;
	char	smallest;
	char	largest;
};

//============================================
int main ( void )
{
	RingCounterInt	r1(1,4);
	RingCounterChar	c1('a','d');
	
	for ( int i = 0; i < 6; i++ )
	{
		cout << "r1 = " << r1.read() << endl;
		r1.increment();
	}
	for ( int i = 0; i < 6; i++ )
	{
		cout << "c1 = " << c1.read() << endl;
		c1.increment();
	}

	return 0;
}

