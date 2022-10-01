dna// ===========================================
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
int main ( int argc, char *argv[] ){

    if (argc == 1){
        ifstream inputfile;
        inputfile.open(argv[0]);
    }
    for (int i=0;i<searchNum;i++)x
        int indexNum = strandSearch(dna, segment);
        cout << "The index of " << segment << " is " << indexNum << "." << endl;
    // char segment[] = {'T','C','C','G','A','for (int segIndex=0; segIndex<segLen; segIndex++\0'};
    // indexNum = strandSearch(dna, segment);
    // cout << "The index of " << segment << " is " << indexNum << "." << endl;
    inputfile.close();
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
            dnaSlice[segIndex] = maindna[workingIndex];
            cout << dnaSlice << endl;
        }
        int condOutput = strcmp(segment1, dnaSlice);
        cout << condOutput << endl;
        cout << dnaSlice << " compared to " << segment1 << endl;
        if (condOutput == 0)
            return dnaIndex;
        else
            dnaIndex = dnaIndex+1;

    }
    return -1;
}
