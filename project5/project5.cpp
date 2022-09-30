// ===========================================
// Grant Gutterman
// 09-30-22
// project5.cpp
// Long ass project description
// ===========================================

// packages
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int MAX = 100;

int strandSearch(char maindna, char segment1);

int main ( void ){

    // inputs
    char dna[MAX] = {'A','G','T','C','C','G','A','T','C','C','G','A','\0'};
    cin >> dna;
    int searchNum;
    int indexNum;
    // for (int i=0;i<searchNum;i++)
    //     char segment[MAX];
    //     cin >> segment;
    //     indexNum = strandSearch(char dna, char segment);
    //     cout << "The index of " << segment << " is " << indexNum << "." << endl;
    char segment[MAX] = {'G','A','T','C','C','\0'};
    indexNum = strandSearch(dna, segment);


    return 0;
}

int strandSearch(char maindna, char segment1){
    int dnaLen = strlen(dna);
    int segLen = strlen(segment);
    int dnaIndex = 0;
    while (dnaIndex<dnaLen-segLen){
        cout << dnaIndex << endl;
        char dnaSlice[segLen+1];
        for (int segIndex=0; segIndex<segLen; segIndex++){
            int workingIndex = dnaIndex+segIndex;
            dnaSlice[segIndex] = dna[workingIndex];
            cout << dnaSlice << endl;
        int condOutput = strcmp(segment, dnaSlice);
        if (condOutput == 0)
            return dnaIndex;
        else
            dnaIndex++;
        }
    }
    return 0;
}
