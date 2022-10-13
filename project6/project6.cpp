// =======================================
// Grant and Jack
// project6.cpp
// Project Description
// =======================================


#include <iostream>
#include <fstream>

using namespace std;

// function declarations
const int LENGTH = 14;

void readGrid( char grid[LENGTH][LENGTH] );
void printGrid ( char grid[LENGTH][LENGTH] );
void findWord ( char grid[LENGTH][LENGTH], char source, char target, int r, int c );
//bool isConnected( char grid[LENGTH][LENGTH], char source, char target, int r, int c);

// =======================================

// =======================================
int main(  void  ){

// initial puzzle read & print
    char grid[LENGTH][LENGTH];
    readGrid(grid);
    printGrid(grid);

// number of words inputs
    int numWords;
    cin >> numWords;
    cout << numWords << endl;


// word search loop
    for (int i=0; i<numWords; i++){
// getting individual word for searching
        char word[100];
        cin >> word;
        cout << word << endl;
// searching
        findWord(grid, grid[0][0], word[1]);
    }

    return 0;
}
// =======================================
// readGrid
// =======================================
void readGrid( char grid[LENGTH][LENGTH] ){
    for (int i=0; i < LENGTH; i++)
        for (int j=0; j < LENGTH; j++)
            cin >> grid[i][j];
    return;
}
// =======================================
// printGrid
// =======================================
void printGrid ( char grid[LENGTH][LENGTH] ){
    for (int i=0; i < LENGTH; i++){
        for (int j=0; j < LENGTH; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

void findWord ( char grid[LENGTH][LENGTH], char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<LENGTH);
    assert(c<LENGTH);



    return;
}
