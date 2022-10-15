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

void readGrid( char grid[LENGTH][LENGTH] );
void printGrid ( char grid[LENGTH][LENGTH] );

void findWord ( char grid[LENGTH][LENGTH], string word, char source, char target, int r, int c);

int searchUp ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );
int searchDown ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );

int searchLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );
int searchRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );

int searchUpLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );
int searchUpRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );

int searchDownLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );
int searchDownRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );

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
        findWord(grid, word, grid[0][0], word[0], 0, 0);

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
void readGrid( char grid[LENGTH][LENGTH] ){
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
//
// PARAMS:
//
// RETURNS:
//
// =======================================
void findWord ( char grid[LENGTH][LENGTH], string word, char source, char target, int r, int c){

    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    //cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    //cout << "findWord called..." << " @ " << r << " , " << c << endl << endl;
    //cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // cout << "You are searching for: " << word << "///" << endl;
    // breakerChecks(grid, word, temp, grid[r][c], target, r, c);

    //cout << grid[r][c] << " @ " << r << " , " << c << " is getting compared to " << target << endl;
    string temp = "";
    if (grid[r][c] == target){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];

    }

    int origin[2] = {r, c};
    int dirState;
    //cout << "Temp is: " << temp << " ///////// " << "Target is: " << target << endl << endl;

    // surrounding search
    if (temp != ""){
        if (r>0){
            dirState = searchUp(grid, word, temp, grid[r-1][c], target, r-1, c, origin);
        }
        if (r<LENGTH-1){
            dirState = searchDown(grid, word, temp, grid[r+1][c], target, r+1, c, origin);
        }
        if (c>0 ){
            dirState = searchLeft(grid, word, temp, grid[r][c-1], target, r, c-1, origin);
        }
        if (c<LENGTH-1 ){
            dirState = searchRight(grid, word, temp, grid[r][c+1], target, r, c+1, origin);
        }
        if (r>0 && c>0 ){
            dirState = searchUpLeft(grid, word, temp, grid[r-1][c-1], target, r-1, c-1, origin);
        }
        if (r>0 && c<LENGTH-1 ){
            dirState = searchUpRight(grid, word, temp, grid[r-1][c+1], target, r-1, c+1, origin);
        }
        if (r<LENGTH-1 && c>0 ){
            dirState = searchDownLeft(grid, word, temp, grid[r+1][c-1], target, r+1, c-1, origin);
        }
        if (r<LENGTH-1 && c<LENGTH-1){
            dirState = searchDownRight(grid, word, temp, grid[r+1][c+1], target, r+1, c+1, origin);
        }
    }
    // move to next line

    if (c<LENGTH-1){
        target = word[0];
        findWord(grid, word, grid[r][c+1], target, r, c+1);}
    else if (r== 13 && c == 13 ){
        cout << "The word " << word << " could not be found." << endl;
        return;
    }
    else if (r>=0){
        target = word[0];
        // cout << "Moving to nextline..." << endl;
        findWord(grid, word, grid[r+1][0], target, r+1, 0);
    }
    return;
}
// =======================================
// searchUp
//
// PARAMS:
//
// RETURNS:
//
// =======================================
int searchUp ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    // cout << "~~~~~~~~~~~~~" << "Up Function! " << endl;
    // cout << "TEMP = " << temp << " ///// WORD = " << word << endl;
    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;
    if(temp == word){
        x = r + word.length();
        y = c;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going up." <<  endl;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        return 0;
    }
    else if (r>0 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchUp(grid, word, temp, grid[r-1][c], target, r-1, c, origin);
    }
    return -1;
}
// =======================================
// searchDown
//
// PARAMS:
//
// RETURNS:
//
// =======================================
int searchDown ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    // cout << "~~~~~~~~~~~~~" << "Down Function! " << endl;
    // cout << "TEMP = " << temp << " ///// WORD = " << word << endl;
    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;
    if(temp == word){
        x = r - word.length();
        y = c;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going down." <<  endl;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        return 0;
    }
    else if (r<LENGTH-1 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchDown(grid, word, temp, grid[r+1][c], target, r+1, c, origin);
    }
    return -1;
}
// =======================================
// searchLeft
//
// PARAMS:
//
// RETURNS:
//
// =======================================
int searchLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    // cout << "~~~~~~~~~~~~~" << "Left Function! " << endl;
    // cout << "TEMP = " << temp << " ///// WORD = " << word << endl;

    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;
    if(temp == word){
        x = r;
        y = c + word.length();
        // cout << endl << "@@@@@@@@@@@@@@@@" << endl << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going left." <<  endl;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;

        return 0;
    }
    else if (c>0 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchLeft(grid, word, temp, grid[r][c-1], target, r, c-1, origin);
    }
    return -1;
}
// =======================================
// searchRight
//
// PARAMS:
//
// RETURNS:
//
// =======================================
int searchRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2]){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    // cout << "~~~~~~~~~~~~~" << "Right Function! " << endl;
    // cout << "TEMP = " << temp << " ///// WORD = " << word << endl;
    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;
    if(temp == word){
        x = r;
        y = c - word.length();
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going right." <<  endl;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;

        return 0;
    }
    else if (c<LENGTH-1 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchRight(grid, word, temp, grid[r][c+1], target, r, c+1, origin);
    }
    return -1;
}
// =======================================
// searchUpLeft
//
// PARAMS:
//
// RETURNS:
//
// =======================================
int searchUpLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2]){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    // cout << "~~~~~~~~~~~~~" << "Up Left Function! " << endl;
    // cout << "TEMP = " << temp << " ///// WORD = " << word << endl;
    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;
    if(temp == word){
        x = r - word.length();
        y = c - word.length();
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going up left." <<  endl;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;

        return 0;
    }
    else if (r>0 && c>0 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchUpLeft(grid, word, temp, grid[r-1][c-1], target, r-1, c-1, origin);
    }
    return -1;
}
// =======================================
// searchUpRight
//
// PARAMS:
//
// RETURNS:
//
// =======================================
int searchUpRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2]){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    // cout << "~~~~~~~~~~~~~" << "Up Right Function! " << endl;
    // cout << "TEMP = " << temp << " ///// WORD = " << word << endl;

    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;
    if(temp == word){
        x = r + word.length();
        y = c - word.length();
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going up right." <<  endl;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;

        return 0;
    }
    else if (r>0 && c<LENGTH-1 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchUpRight(grid, word, temp, grid[r-1][c+1], target, r-1, c+1, origin);
    }
    return -1;
}


// =======================================
// searchDownLeft
//
// PARAMS:
//
// RETURNS:
//
// =======================================
int searchDownLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2]){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    // cout << "~~~~~~~~~~~~~" << "Down Left Function! " << endl;
    // cout << "TEMP = " << temp << " ///// WORD = " << word << endl;
    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;
    if(temp == word){
        x = r - word.length();
        y = c + word.length();
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going down left." <<  endl;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;

        return 0;
    }
    else if (r<LENGTH-1 && c>0 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchDownLeft(grid, word, temp, grid[r+1][c-1], target, r+1, c-1, origin);
    }
    return -1;
}


// =======================================
// searchDownRight
//
// PARAMS:
//
// RETURNS:
//
// =======================================
int searchDownRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2]){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    // cout << "~~~~~~~~~~~~~" << "Down Right Function! " << endl;
    // cout << "TEMP = " << temp << " ///// WORD = " << word << endl;
    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;
    if(temp == word){
        x = r - word.length();
        y = c - word.length();
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going down right." <<  endl << endl ;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        return 0;
    }
    else if (r<LENGTH-1 && c<LENGTH-1 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchDownRight(grid, word, temp, grid[r+1][c+1], target, r+1, c+1, origin);
    }
    return -1;
}
