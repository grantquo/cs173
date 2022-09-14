// =======================
// Grant Gutterman
// 09-06-22
// vowels.cpp
// This program counts the number of vowels in the user's name.
// =======================

#include <iostream>
#include <string>
using namespace std;

int main ( void )
{
	string name;
	
	
	cout << "Enter your name: ";
	cin >> name;
	int total = 0;
	string vowels = "aeiouAEIOU";
	
	for ( int i = 0; i < name.length(); i++ )
	{
		if ( name[i] == 'a' || name[i] == 'A' || 
			 name[i] == 'e' || name[i] == 'E' || 
			 name[i] == 'i' || name[i] == 'I' ||
			 name[i] == 'o' || name[i] == 'O' ||
			 name[i] == 'u' || name[i] == 'U' )
			total++;
	}
	
	cout << "Your name: " << name << " has " << total
	<< " vowels." << endl;

	return 0;
}
