//============================================
//Grant Gutterman
//09-21-2022
//badarrays.cpp
//This file demonstrates arrays that are BADDDD!!!!!!!!!
//============================================

#include <iostream>
#include <string>

using namespace std;

int main ( void )
{
    int A[4];

    for ( int i=0; i<4; i++ )
        A[i] = i+1;

    A[4]=100;
    cout << A[0] << endl;
    cout << A[4] << endl;

    /* This array boundary doesn't cause any problems, but long term it will
    affect the program. When you write data outside of the bounds, variables
    you have stated will be overwritten after compiling. This is hard to find
    and can only be found through the terminal post-compiling. You need to do
    strict boundary checking to fix this.
    */
    return 0;
}
