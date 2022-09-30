// ===========================================
// Grant Gutterman
// 09-30-22
// project5.cpp
// Takes a test file of DNA and searches for DNA segments, returning its index
// location within the main DNA.
// ===========================================

// packages
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX = 100;

int strandSearch(char maindna[MAX], char segment1[MAX]);

// ===========================================
// main function
// ===========================================
int main ( void ){

    // inputs
    char dna[] = {'A','G','T','C','C','G','A','T','C','C','G','A','\0'};
    int searchNum;
    int indexNum;
    // for (int i=0;i<searchNum;i++)
    //     char segment[MAX];
    //     cin >> segment;
    //     indexNum = strandSearch(char dna, char segment);
    //     cout << "The index of " << segment << " is " << indexNum << "." << endl;
    char segment[] = {'G','A','T','C','C','\0'};
    indexNum = strandSearch(dna, segment);
    cout << "The index of " << segment << " is " << indexNum << "." << endl;

    return 0;
}
// ===========================================
// strandSearch
// Completes the main searching within the program. This function takes the
// main function and loops through each index value. In each iteration, it will
// create a new DNA slice meant to hold a portion of the main DNA the size of
// the segment. The slice and segment keep getting compared as the slice changes
// through values of the DNA until a match is found.
// PARAMS:
// maindna[MAX] - the main DNA data inputted
// segment1[MAX] - the segment of DNA
// RETURNS:
// Either an integer for the index of the found segment, or a -1 for no result.
// ===========================================
int strandSearch(char maindna[MAX], char segment1[MAX]){
    int dnaLen = strlen(maindna);
    int segLen = strlen(segment1);
    int dnaIndex = 0;
    while (dnaIndex<dnaLen-segLen){
        char dnaSlice[segLen+1];
        for (int segIndex=0; segIndex<segLen; segIndex++){
            int workingIndex = dnaIndex+segIndex;
            dnaSlice[workingIndex] = maindna[workingIndex];
        int condOutput = strcmp(segment1, dnaSlice);
        if (condOutput == 0)
            return dnaIndex;
        else
            dnaIndex++;
        }
    }
    return -1;
}
