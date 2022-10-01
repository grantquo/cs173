// ===========================================
// Grant Gutterman
// 09-30-22
// project5.cpp
// Takes a test file of donor DNA and searches for DNA segments/strands,
// returning its index location within the donor. If a search comes back with no
// index results, the program checks for the segment in the donor DNA in
// reverse order.
// ===========================================

// inclusions and function declarations
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX = 100;

int strandSearch(char maindna[MAX], char segment[MAX]);
int reverseSearch(char maindna[MAX], char segment[MAX]);

// ===========================================
// main function
// This function directs the entirety of the program. It first initializes
// the main donor dna C style string, along with getting the number of segments
// searches. The function then loops an algorithm of determining one segment's
// index. Once it determines its index (or if there isn't one), it will begin
// another iteration of a different segment.
// ===========================================
int main ( int argc, char* argv[] ){

    // file open and variable initialization
    char dna[MAX];
    int searchNum;

    ifstream casefile;
    casefile.open(argv[1]);
    casefile >> dna >> searchNum;

    // main loop for calling the searches
    for (int i=0;i<searchNum;i++){
        char segment[MAX];
        casefile >> segment;
        int indexNum;
        indexNum = strandSearch(dna, segment);
        if (indexNum < 0){
            indexNum = reverseSearch(dna, segment);
            if (indexNum < 0){
                cout << "There is no instance of "
                << segment << " in the donor DNA." << endl;}
            else{
                cout << "The index of " << segment << " is " << indexNum
                << " of the donor index reversed." << endl;}
        }
        else
            cout << "The index of " << segment << " is " << indexNum << "." << endl;
    }

    casefile.close();

    return 0;
}

// ===========================================
// strandSearch
// Completes the main searching within the program. This function takes the
// main function and loops through each index value. In each iteration, it will
// create a new DNA slice meant to hold a portion of the main DNA the size of
// the segment. The slice and segment get compared as the slice changes
// through values of the DNA until a match is found.
// PARAMS:
// maindna[MAX] - the main DNA data inputted
// segment[MAX] - the segment/strand of DNA we want to search for
// RETURNS:
// Either an integer for the index of the found segment, or a -1 for no result.
// ===========================================
int strandSearch(char maindna[MAX], char segment[MAX]){
    int dnaLen = strlen(maindna);
    int segLen = strlen(segment);
    int dnaIndex = 0;
    while (dnaIndex<dnaLen-segLen){
        char dnaSlice[segLen+1] = {};
        int segIndex = 0;
        // donor DNA slice building loop
        while (segIndex<segLen){
            int workingIndex = dnaIndex+segIndex;
            dnaSlice[segIndex] = maindna[workingIndex];
            segIndex ++;
        }
        // comparison
        int condOutput = strcmp(segment, dnaSlice);
        if (condOutput == 0)
            return dnaIndex;
        else
            dnaIndex = dnaIndex+1;
    }
    return -1;
}

// ===========================================
// reverseSearch
// This function is meant to be called if an initial strand/segment search isn't
// found. It takes the main donor dna strand data and reverses it. After it is
// reversed with a while loop, it will send it back to the strandSearch function
// for a second search of the segment/strand.
// PARAMS:
// maindna[MAX] - the main DNA data inputted
// segment[MAX] - the segment/strand of DNA we want to search for
// RETURNS:
// Calls the strandSearch function to perform a search with the newly created
// 'reversedna' C style string.
// ===========================================
int reverseSearch(char maindna[MAX], char segment[MAX]){
    char reversedna[MAX];
    strcpy(reversedna, maindna);
    int dnaLen = strlen(maindna);
    int startIndex = 0;
    int endIndex = dnaLen-1;
    char temp;
    // reversed donor DNA building loop
    while (startIndex<endIndex){
        temp = reversedna[startIndex];
        reversedna[startIndex] = reversedna[endIndex];
        reversedna[endIndex] = temp;
        startIndex = startIndex+1;
        endIndex = endIndex-1;
    }
    return strandSearch(reversedna, segment);
}
