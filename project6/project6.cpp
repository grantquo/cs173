// =======================================
// Grant and Jack
// project6.cpp
// Project Description
// =======================================


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// function declarations
const int LENGTH = 14;

void readGrid( char grid[LENGTH][LENGTH] );
void printGrid ( char grid[LENGTH][LENGTH] );
void findWord ( char grid[LENGTH][LENGTH], char word, string temp, char source, char target, int r, int c );
//bool isConnected( char grid[LENGTH][LENGTH], char source, char target, int r, int c);
void printLocation (char target, int r, int c);

// =======================================
// main
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
        string temp = "";
        findWord(grid, word, temp, grid[0][0], word[0], 0, 0);
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
// =======================================
// findWord
// =======================================
void findWord ( char grid[LENGTH][LENGTH], char word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<LENGTH);
    assert(c<LENGTH);

    int x =

    if (word == temp)
        return printLocation(word, r, c);
    // string temp = "";
    if (source == target)
        temp += source;
        word[x+1] = target;

    if (r>0)
        // check up
        findWord(grid, word, temp, source, target, r-1, c)
    if (r<LENGTH-1)
        // check down
        findWord(grid, word, temp, source, target, r+1, c)
    if (c>0)
        // check left
        findWord(grid, word, temp, source, target, r, c-1)
    if (c<LENGTH-1)
        // check right
        findWord(grid, word, temp, source, target, r, c+1)
    if (r>0 && c>0)
        // check up/left
        findWord(grid, word, temp, source, target, r-1, c-1)
    if (r>0 && c<LENGTH-1)
        // check up/right
        findWord(grid, word, temp, source, target, r-1, c+1)
    if (r<LENGTH-1 && c>0)
        // check down/left
        findWord(grid, word, temp, source, target, r+1, c-1)
    if (r<LENGTH-1 && c<LENGTH-1)
        // check down/right
        findWord(grid, word, temp, source, target, r+1, c+1)

    return printLocation(target, -1. -1);
}
// =======================================
// printLocation
// =======================================
void printLocation( char target, int r, int c ){
    /*
    if r & c < 0:
        cout << "The word "<< target <<" was not found in the puzzle." << endl;
    */
    // cout << target " found at " << r << "," << c << endl;
    return;
}
