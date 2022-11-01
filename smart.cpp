//============================================
// Matt Kretchmar
// October 2022
// smart example of using templates to avoid
// repetitive classes
//============================================
#include <iostream>
using namespace std;
//============================================
// RingCounter as integer
//============================================
template <class T> 
class RingCounter 
{
public:
			RingCounter		( T min, T max )
			{ smallest = min; largest = max; current = smallest; }
	T		read			( void )
			{ return current; }
	void	increment		( void );
	void	decrement		( void )
			{ current = (current==smallest) ? largest:current-1; }
	void	reset			( void )
			{ current = smallest; }
	RingCounter<T> operator= ( const RingCounter<T> &r );
private:
	T		current;
	T		smallest;
	T		largest;
};

template <class T>
void		RingCounter<T>::increment ( void )
{
	if ( current == largest )
		current = smallest;
	else
		current++;
}

template <class T>
RingCounter<T>	RingCounter<T>::operator= ( const RingCounter<T> &r )
{
	current = r.current;
	smallest = r.smallest;
	largest = r.largest;
	return *this;
}

//============================================
int main ( void )
{
	RingCounter<int>   r1(1,4);;
	RingCounter<char>  c1('a','d');
	
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

	RingCounter<char> c2('r','t');
	for ( int i = 0; i < 6; i++ )
	{
		cout << "c2 = " << c2.read() << endl;
		c2.increment();
	}
	
	c2 = c1;
	for ( int i = 0; i < 6; i++ )
	{
		cout << "c2 = " << c2.read() << endl;
		c2.increment();
	}
	

	return 0;
}

