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
bool loopDirection       ( char grid[LENGTH][LENGTH], string word, int r, int c );


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
    if (grid[r][c] == target)
        return true;
    else if (grid[r][c] != target)
        return false;
    return false;
}
// =======================================
// boundsCheck
//
// PARAMS:
//
// RETURNS:
//
// =======================================
int boundsCheck         ( char grid[LENGTH][LENGTH], int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    if (c<LENGTH-1)
        return 0;
    else if (c==LENGTH-1 && r<LENGTH-1)
        return 1;
    else if (r==13 && c==13 )
    {
        return 2;
    }
    else
    {
        cout << "No Bound Conditionals Passed!" << endl;
        return 3;
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
void recursor           ( char grid[LENGTH][LENGTH], string word, int r, int c ){

    // assertions

    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    cout << "Recursive call completed." << endl;
    // first letter find
    bool isFound;
    int boundState = -1;
    cout << "Beginning first letter call." << endl;
    cout << word[0] << " being compared to " << grid[r][c] << endl;
    isFound = mainSearch(grid, word[0], r, c);
    cout << "First letter check result: " << isFound << endl;
    if (isFound == false)
    {
        boundState = boundsCheck(grid, r, c);
        cout << "Checking bounds." << endl;
        if (boundState == 0)
            recursor(grid, word, r, c+1);
        else if (boundState == 1)
            recursor(grid, word, r+1, 0);
        else if (boundState == 2)
            return;
        else if (boundState == 3)
            return;
    }
    else if (isFound == true)
        cout << "Found " << word[0] << " as first letter." << endl;
        isFound = loopDirection(grid, word, r, c);

    // final check / output
    boundState = -1;
    if (isFound == true)
    {
        // found word
        printLocation(word, r, c);
        return;
    }
    else
    {
        // move on (when first letter = word[0])
        cout << "Could not find word in area." << endl;
        cout << "Checking bounds." << endl;
        int boundState = boundsCheck(grid, r, c);
        if (boundState == 0)
            recursor(grid, word, r, c+1);
        else if (boundState == 1)
            recursor(grid, word, r+1, 0);
        else if (boundState == 2)
            return;
        else if (boundState == 3)
            return;
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
bool loopDirection       ( char grid[LENGTH][LENGTH], string word, int r, int c ){

    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    int originR = r;
    int originC = c;
    // directionals
    // might need r and c to be restated
    // up
    bool isFound;
    string temp = "";
    temp = temp + word[0];
    int targetInd = 1;
    bool breakState = true;
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
            return true;
        }
        else
            breakState = false;
    }
    r = originR;
    c = originC;
    // down
    temp = "";
    temp = temp + word[0];
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
            return true;
        }
        else
            breakState = false;
    }
    r = originR;
    c = originC;
    // left
    temp = "";
    temp = temp + word[0];
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
            return true;
        }
        else
            breakState = false;
    }
    r = originR;
    c = originC;
    // right
    temp = "";
    temp = temp + word[0];
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
            return true;
        }
        else
            breakState = false;
    }
    r = originR;
    c = originC;
    // upleft
    temp = "";
    temp = temp + word[0];
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
            return true;
        }
        else
            breakState = false;
    }
    r = originR;
    c = originC;
    // upright
    temp = "";
    temp = temp + word[0];
    targetInd = 1;
    breakState = true;
    while (r>0 && c<LENGTH-1 && breakState != false)
    {
        isFound = mainSearch(grid, word[targetInd], r-1, c+1);
        if (isFound == true)
        {
            temp = temp + word[targetInd];
            r = r-1;
            c = c+1;
        }
        else if (isFound == true && temp == word)
        {
            return true;
        }
        else
            breakState = false;
    }
    r = originR;
    c = originC;
    // downleft
    temp = "";
    temp = temp + word[0];
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
            return true;
        }
        else
            breakState = false;
    }
    r = originR;
    c = originC;
    // downright
    temp = "";
    temp = temp + word[0];
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
            return true;
        }
        else
            breakState = false;
    }
    return false;

}
