// ===========================================
// Grant Gutterman
// 09-22-2022
// arrayproblem5.cpp
// This program takes three arrays and combines them into one array. This one
// array will be sorted completely from smallest to largest.
// ===========================================

#include <iostream>
using namespace std;

// function statements

int merge(int array1[], int array2[], int array3[], int size1, int size2, int size3);

int main ( void )
{

    // initializing arrays and sizes

    int array1[3] = {1, 3, 8};
    int array2[4] = {5, 6, 7, 10};
    int const array1size = sizeof(array1) / sizeof(int);
    int const array2size = sizeof(array2) / sizeof(int);
    int const array3size = array1size + array2size;

    // fill in empty integer values for 3rd array

    int array3[array3size] = {};
    for (int i=0; i<array3size;i++)
        array3[i] = 0;

    // output working arrays

    cout << "Array 1: " << endl;
    for (int i=0; i<array1size; i++)
        cout << array1[i] << ", " << endl;

    cout << "Array 2: " << endl;
    for (int i=0; i<array2size; i++)
        cout << array2[i] << ", " << endl;

    merge(array1, array2, array3, array1size, array2size, array3size);

    return 0;
}

// merge
// This function takes 2 arrays with data and combines them into a third array.
// The third array is sorted from smallest to largest with both of the 2 arrays'
// data.
// PARAMS:
// - array1[] & array2[] - Two arrays with integer data. These will be the two
// arrays that will be combined.
// - array3[] - An empty array with just 0s that will be overwritten with other
// integer values.
// - size1 & size2 & size3 - Array sizes need to be stated since in parameter
// lists, array declarations do not include sizes. The compiler needs the size
// explicitly stated in a different parameter in order to import it into the
// function.
// RETURNS:
// Nothing is returned back to main(). Rather, the 3rd array with the combined
// and sorted data is outputted to the user.

int merge(int array1[], int array2[], int array3[], int size1, int size2, int size3)
{
    int i, needsSort;
    for (i = 0; i < size1; i++)
        array3[i] = array1[i];
    for (i = 0; i < size2; i++)
        array3[i+size1] = array2[i];
    for (int i1 = 0; i1 < size3; i1++)
    {
        for (int i2 = i1+1; i2 < size3; i2++)
            if (array3[i1] > array3[i2]){
                needsSort = array3[i1];
                array3[i1] = array3[i2];
                array3[i2] = needsSort;
            }
    }
    cout << "Array 3: " << endl;
    for (int i=0; i<size3; i++)
        cout << array3[i] << ", " << endl;
    return 0;
}
