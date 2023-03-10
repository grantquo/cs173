// =======================================
// Grant Gutterman
// 09-22-2022
// arrayproblem3.cpp
// This program takes an array input and checks if it is sorted from smallest
// to largest. It will return a boolean for whether it is or isn't sorted
// correctly.
// =======================================

#include <iostream>
#include <string>

using namespace std;

// function declarations
string isSorted(int arrayInput[], int size);

// main function
int main ( void )
{
    int sortedArray[5] = {1, 4, 6, 8, 9};
    int notSortArray[7] =  {1, 6, 4, 8, 2, 8, 9};
    int const array1Size = sizeof(sortedArray) / sizeof(int);
    int const array2Size = sizeof(notSortArray) / sizeof(int);

    for (int i=0; i<array1Size; i++)
        cout << sortedArray[i] << ", ";

    string result1 = isSorted(sortedArray, array1Size);
    cout << "\n" << result1 << endl;

    for (int i=0; i<array2Size; i++)
        cout << notSortArray[i] << ", ";

    string result2 = isSorted(notSortArray, array2Size);
    cout << "\n" << result2 << endl;

    return 0;
}


// isSorted
// Checks each element inside the array that is passed into its parameters for
// if the array is sorted from smallest to largest.
// PARAMS:
// - arrayInput[] - Reference call to the array we want to be checked for being
// sorted.
// - size - Seperate parameter for the specified size of the array we are
// passing into the function.
// RETURNS:
// A string "true" or "false" that will be sent to output to the user.
string isSorted(int arrayInput[], int size)
{
    for (int i=0; i < size-1; i++)
    {
        if (arrayInput[i] > arrayInput[i+1])
            return "false";
    }
    return "true";
}
