// =======================================
// Grant and Jack
// project6.cpp
// Project Description
// =======================================

#include <iostream>
#include <iomanip>
#include <cassert>
#include <fstream>
#include <string>

using namespace std;

const int LENGTH = 14;

// function declarations

void readGrid( char grid[LENGTH][LENGTH] );
void printGrid ( char grid[LENGTH][LENGTH] );
void printLocation ( string word, int r, int c );

void findWord ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );

void searchUp ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );
void searchDown ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );
void searchLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );
void searchRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );

void searchUpLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );
void searchUpRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );

void searchDownLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );
void searchDownRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );

void initialChecks ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );

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
        string word;
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
// initialChecks
// =======================================
void initialChecks ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c ){
    if (word == temp)
        return printLocation(word, r, c);
}
// =======================================
// printLocation
// =======================================
void printLocation( string word, int r, int c ){
    cout << word << " found at " << r << "," << c << endl;
    return;
}



// =======================================
// findWord
// =======================================
void findWord ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c ){

    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    initialChecks(grid, word, temp, source, target, r, c);
    if (source == target && word != temp){
        temp += source;
        int tempLen = temp.length()+1;
        target = word[tempLen];
    }

    // surrounding search

    if (r>0){
        searchUp(grid, word, temp, source, target, r-1, c);
        temp = "";
        target = word[0];

    }
    if (r<LENGTH-1){
        searchDown(grid, word, temp, source, target, r+1, c);
        temp = "";
        target = word[0];
    }
    if (c>0){
        searchLeft(grid, word, temp, source, target, r, c-1);
        temp = "";
        target = word[0];
    }
    if (c<LENGTH-1){
        searchRight(grid, word, temp, source, target, r, c+1);
        temp = "";
        target = word[0];
    }
    if (r>0 && c>0){
        searchUpLeft(grid, word, temp, source, target, r-1, c-1);
        temp = "";
        target = word[0];
    }
    if (r>0 && c<LENGTH-1){
        searchUpRight(grid, word, temp, source, target, r-1, c+1);
        temp = "";
        target = word[0];
    }
    if (r<LENGTH-1 && c>0){
        searchDownLeft(grid, word, temp, source, target, r+1, c-1);
        temp = "";
        target = word[0];
    }
    if (r<LENGTH-1 && c<LENGTH-1){
        searchDownRight(grid, word, temp, source, target, r+1, c+1);
        temp = "";
        target = word[0];
    }

    // move to next line

    temp = "";

    if (c<LENGTH-1)
        findWord(grid, word, temp, grid[r][c+1], target, r, c+1);
    else if (r== 13 && c == 13){
        cout << "Function didn't find the word." << endl;
        return;
    }
    else{
        cout << "Moving to nextline..." << endl;
        findWord(grid, word, temp, grid[r+1][0], target, r+1, 0);
    }

    return;
}

// =======================================
// searchUp
// =======================================
void searchUp ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    initialChecks(grid, word, temp, source, target, r, c);

    if (r>=0 && source == target && word != temp){
        temp += source;
        int tempLen = temp.length()+1;
        target = word[tempLen];
        searchUp(grid, word, temp, source, target, r-1, c);
    }

    return;
}

// =======================================
// searchDown
// =======================================
void searchDown ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    initialChecks(grid, word, temp, source, target, r, c);

    if (r<LENGTH-1 && source == target && word != temp){
        temp += source;
        int tempLen = temp.length()+1;
        target = word[tempLen];
        searchDown(grid, word, temp, source, target, r+1, c);
    }

    return;
}

// =======================================
// searchLeft
// =======================================
void searchLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    initialChecks(grid, word, temp, source, target, r, c);

    if (c>0 && source == target && word != temp){
        temp += source;
        int tempLen = temp.length()+1;
        target = word[tempLen];
        searchLeft(grid, word, temp, source, target, r, c-1);
    }

    return;
}

// =======================================
// searchRight
// =======================================
void searchRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    initialChecks(grid, word, temp, source, target, r, c);

    if (c<LENGTH-1 && source == target && word != temp){
        temp += source;
        int tempLen = temp.length()+1;
        target = word[tempLen];
        searchRight(grid, word, temp, source, target, r, c+1);
    }
    return;
}

// =======================================
// searchUpLeft
// =======================================
void searchUpLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    initialChecks(grid, word, temp, source, target, r, c);

    if (r>0 && c>0 && source == target && word != temp){
        temp += source;
        int tempLen = temp.length()+1;
        target = word[tempLen];
        searchUpLeft(grid, word, temp, source, target, r-1, c-1);
    }

    return;
}

// =======================================
// searchUpRight
// =======================================
void searchUpRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    initialChecks(grid, word, temp, source, target, r, c);

    if (r>0 && c<LENGTH-1 && source == target && word != temp){
        temp += source;
        int tempLen = temp.length()+1;
        target = word[tempLen];assert(c<LENGTH-1);
        searchUpRight(grid, word, temp, source, target, r-1, c+1);
    }
    return;
}

// =======================================
// searchDownLeft
// =======================================
void searchDownLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    initialChecks(grid, word, temp, source, target, r, c);

    if (r<LENGTH-1 && c>0 && source == target && word != temp){
        temp += source;
        int tempLen = temp.length()+1;
        target = word[tempLen];
        searchDownLeft(grid, word, temp, source, target, r+1, c-1);
    }

    return;
}

// =======================================
// searchDownRight
// =======================================
void searchDownRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    initialChecks(grid, word, temp, source, target, r, c);

    if (r<LENGTH-1 && c<LENGTH-1 && source == target && word != temp){
        temp += source;
        int tempLen = temp.length()+1;
        target = word[tempLen];
        searchDownRight(grid, word, temp, source, target, r+1, c+1);
    }

    return;
}
