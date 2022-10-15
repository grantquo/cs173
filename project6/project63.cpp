// =======================================
// Grant and Jack
// project6.cpp
// Takes a word puzzle and finds the words within the search, returning the
// coordinates of the first letter as the answer.
// =======================================

#include <iostream>
#include <iomanip>
#include <cassert>
#include <fstream>
#include <string>

using namespace std;

const int LENGTH = 14;

// function declarations

void readGrid           ( char grid[LENGTH][LENGTH] );
void printGrid          ( char grid[LENGTH][LENGTH] );
string printLocation    ( string word, int r, int c );
bool mainSearch         ( char grid[LENGTH][LENGTH], char target, int r, int c );
int boundsCheck         ( char grid[LENGTH][LENGTH], int r, int c );
void recursor           ( char grid[LENGTH][LENGTH], string word, int r, int c );
int loopDirection       ( char grid[LENGTH][LENGTH], string word, string temp, int r, int c );


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
    for (int i=0; i<numWords; i++)
    {
// getting individual word for searching
        string word;
        cin >> word;
        cout << word << endl;
// searching
        recursor(grid, word, 0, 0);
    }
    return 0;
}

// =======================================
// readGrid
// Uses cin by inputting the loop line by line by LENGTH number of times.
// PARAMS:
//      grid[LENGTH][LENGTH] - word puzzle with its maximum length bounds
// RETURNS:
//      nothing, but uses stdin to read in the grid
// =======================================
void readGrid           ( char grid[LENGTH][LENGTH] ){
    for (int i=0; i < LENGTH; i++)
        for (int j=0; j < LENGTH; j++)
            cin >> grid[i][j];
    return;
}
// =======================================
// printGrid
// Loops through each line of the puzzle outputting it in a grid organization.
// PARAMS:
//      grid[LENGTH][LENGTH] - word puzzle with its maximum length bounds
// RETURNS:
//      nothing, but uses stdout to output the grid
// =======================================
void printGrid          ( char grid[LENGTH][LENGTH] ){
    for (int i=0; i < LENGTH; i++)
    {
        for (int j=0; j < LENGTH; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
// =======================================
// printLocation
//
// PARAMS:
//
// REUTRNS:
//
// =======================================
string printLocation    ( string word, int r, int c ){
    cout << word << " found at " << r << "," << c << "!" << endl;
    return "found";
}
// =======================================
// mainSearch
//
// PARAMS:
//
// RETURNS:
//
// =======================================
bool mainSearch         ( char grid[LENGTH][LENGTH], char target, int r, int c ){
    char source = grid[r][c];
    if (source == target)
    {
        return true;
    }
    else (source== target)
    {
        return false;
    }
}
// =======================================

// =======================================
int boundsCheck         ( char grid[LENGTH][LENGTH], int r, int c ){
    if (c<LENGTH-1)
        return 0;
    else if (c==LENGTH-1 && r<LENGTH-1)
        return 1;
    else
    {
        cout << "Bound Conditionals did not work!" << endl;
        return 2;
    }
}
// =======================================
// recursor
//
// PARAMS:
//
// RETURNS:
//
// =======================================
void recursor           ( char grid[LENGTH][LENGTH], word, r, c ){

    // assertions

    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    // first letter find
    bool isFound;
    isFound = mainSearch(grid, word[0], r, c);
    if (isFound == false)
    {
        int boundState = boundsCheck(grid, r, c);

        if (boundState == 0)
            recursor(grid, word, r, c+1);
        if (boundState == 1)
            recursor(grid, word, r+1, 0);
    }

    // final check / output

    if (temp == word && breakState == true)
    {
        // found word
        printLocation(word, r, c);
        return;
    }

    else
    {
        // move on (when first letter = word[0])
        int boundState = boundsCheck(grid, r, c);

        if (boundState == 0)
            recursor(grid, word, r, c+1);
        if (boundState == 1)
            recursor(grid, word, r+1, 0);
    }

    return;
}

// =======================================
// loopDirection
//
// PARAMS:
//
// RETURNS:
//
// =======================================
int loopDirection       ( char grid[LENGTH][LENGTH], string word, string temp, int r, int c ){
    // directionals
    // might need r and c to be restated
    // up
    temp = word[0];
    targetInd = 1;
    breakState = true;
    while (r>0 && breakState != false)
    {
        isFound = mainSearch(grid, word[targetInd], r-1, c);
        if (isFound == true)
        {
            temp = temp+word[targetInd];
            r = r-1;
        }
        else if (isFound == true && temp == word)
        {
            return 1;
        }
        else
            breakState = false;
    }
    // down
    temp = word[0];
    targetInd = 1;
    breakState = true;
    while (r<LENGTH-1 && breakState != false)
    {
        isFound = mainSearch(grid, word[targetInd], r+1, c);
        if (isFound == true)
        {
            temp = temp + word[targetInd];
            r = r+1;
        }
        else if (isFound == true && temp == word)
        {
            return 1;
        }
        else
            breakState = false;
    }
    // left
    temp = word[0];
    targetInd = 1;
    breakState = true;
    while (c>0 && breakState != false)
    {
        isFound = mainSearch(grid, word[targetInd], r, c-1);
        if (isFound == true)
        {
            temp = temp + word[targetInd];
            c = c-1;
        }
        else if (isFound == true && temp == word)
        {
            return 1;
        }
        else
            breakState = false;
    }
    // right
    temp = word[0];
    targetInd = 1;
    breakState = true;
    while (r<LENGTH-1 && breakState != false)
    {
        isFound = mainSearch(grid, word[targetInd], r, c+1);
        if (isFound == true)
        {
            temp = temp + word[targetInd];
            c = c+1;
        }
        else if (isFound == true && temp == word)
        {
            return 1;
        }
        else
            breakState = false;
    }
    // upleft
    temp = word[0];
    targetInd = 1;
    breakState = true;
    while (r>0 && c>0 && breakState != false)
    {
        isFound = mainSearch(grid, word[targetInd], r-1, c-1);
        if (isFound == true)
        {
            temp = temp + word[targetInd];
            r = r-1;
            c = c-1;
        }
        else if (isFound == true && temp == word)
        {
            return 1;
        }
        else
            breakState = false;
    }
    // upright
    temp = word[0];
    targetInd = 1;
    breakState = true;
    while (r>0 && c<LENGTH-1 && breakState != false)
    {
        isFound = mainSearch(grid, word[targetInd], r-1, c+1);
        if (isFound == true)
        {
            temp = temp + word[targetInd];
            r = r-1;
            c = c+1
        }
        else if (isFound == true && temp == word)
        {
            return 1;
        }
        else
            breakState = false;
    }
    // downleft
    temp = word[0];
    targetInd = 1;
    breakState = true;
    while (r<LENGTH-1 && c>0 && breakState != false)
    {
        isFound = mainSearch(grid, word[targetInd], r+1, c-1);
        if (isFound == true)
        {
            temp = temp + word[targetInd];
            r = r+1;
            c = c-1;
        }
        else if (isFound == true && temp == word)
        {
            return 1;
        }
        else
            breakState = false;
    }

    // downright
    temp = word[0];
    targetInd = 1;
    breakState = true;
    while (r<LENGTH-1 && c<LENGTH-1 && breakState != false)
    {
        isFound = mainSearch(grid, word[targetInd], r+1, c+1);
        if (isFound == true)
        {
            temp = temp + word[targetInd];
            r = r+1;
            c = c+1;
        }
        else if (isFound == true && temp == word)
        {
            return 1;
        }
        else
            breakState = false;
    }

}
