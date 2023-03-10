//====================
// Grant Gutterman
// 09-14-2022
// arrays.cpp
// Random file practicing arrays.
//====================

#define SIZE 5
#include <iostream>
#include <iomanip>
using namespace std;

//function declarations
void printArray( float a[], int n );
float addValues(float a[], int n);

//====================
// main
//====================
int main ( void )
{
    float data[SIZE];

    // prompt to fill

    for (int i=0; i<SIZE; i++)
    {
        cout << "Enter value " << i+1 << ": ";
        cin >> data[i];
    }

    // output by index

    printArray(data, SIZE);
    float sum = addValues(data, SIZE);
    cout << "Sum of values is " << sum << endl;

    return 0;
}

//====================
// printArray
// PARAMETERS:
// - a : an array of floats
// - n : integer size of array
// RETURN:
// - void
//====================

void printArray ( float a[], int n )
{
    for (int i=0; i<n; i++){
        cout << "Value " << i+1 << " = " << fixed << setw(6)
        << setprecision(2) << a[i] << endl;
    }

}

//====================
// addValues
// PARAMETERS:
// - a[] : an array of floats
// - n : (int) size of array
// RETURN:
// Adds all values together.
//====================

float addValues(float a[], int n)
{
    float total = 0;
    for (int i=0; i<n; i++)
        total += a[i];
    return total;
}
