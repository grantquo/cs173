//========================================================
// Matt Kretchmar
// December 2022
// inclusion.cpp
// An example illustrating inclusion
//
// We have a first class which is a simple counter that
// increments by 1 and is able to reset.  
//
// We have a Bouncer class which keeps track of who gets
// into a night club.  We want the Bouncer to keep the
// gender representation in the night club about equal.
// So we use counters in the Bouncer class to keep track
// of how many males and females are currently in the club.
// We use this information to decide whether or not to 
// admit the next guest.  
//========================================================
#include <iostream>
using namespace std;

//========================================================
// Counter class
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
	friend ostream & operator<< ( ostream &os, const Counter &c )
	{ os << c.value;  return os; }
};
//========================================================
// Bouncer class
//========================================================
class Bouncer
{
private:
	Counter		males;
	Counter		females;
	const int MAX_DIFF = 2;
public:
			Bouncer		( void ) { }
	bool	allowMale	( void ) 
	{
		if ( males.getValue() - females.getValue() < MAX_DIFF )
		{
			males.increment();
			return true;
		}
		return false;
	}
	bool	allowFemale	( void ) 
	{
		if ( females.getValue() - males.getValue() < MAX_DIFF )
		{
			females.increment();
			return true;
		}
		return false;
	}
	int		getValue	( void )
	{ return males.getValue() + females.getValue(); }
	void	reset		( void )
	{ males.reset(); females.reset(); }
	friend ostream & operator<< ( ostream &os, const Bouncer &b )
	{
		os << "f:" << b.females << ",m:" << b.males;
		return os;
	}
};
//========================================================
// main program to use in the night club
//========================================================
int main ( void )
{
	// random number seed
	srand(time(NULL));
	
	Bouncer b;
	while (1)
	{
		cout << "bouncer " << b << endl;
		// use the rand function to randomly pick whether
		// a male or female arrives next to the club.  
		if ( rand() % 2 ) 
		{
			printf("Male arrives\n");
			if ( !b.allowMale() )
				break;
		}
		else
		{
			printf("Female arrives\n");
			if ( !b.allowFemale() )
				break;
		}
	}
	
	printf("Number entered: %d\n",b.getValue() );
	return 0;
}
