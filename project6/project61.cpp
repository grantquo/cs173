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
string printLocation ( string word, int r, int c );

void findWord ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );

void searchUp ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker );
void searchDown ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker );
void searchLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker );
void searchRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker );

void searchUpLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker );
void searchUpRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker );

void searchDownLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker );
void searchDownRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker );

bool initialChecks ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );

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
// initialChecks
//
// PARAMS:
//
// RETURNS:
//
// =======================================
bool initialChecks ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c ){
    bool breaker;
    cout << "@@@@@@@" << "Location: " << r << " , " << c << endl;
    cout << word << " initial check " << temp << endl;
    if (word == temp)
        return breaker=true;
    else
        return breaker=false;
}
// =======================================
// printLocation
//
// PARAMS:
//
// REUTRNS:
//
// =======================================
string printLocation( string word, int r, int c ){
    cout << " !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    cout << word << " found at " << r << "," << c << "!" << endl;
    cout << " !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    return "found";
}



// =======================================
// findWord
//
// PARAMS:
//
// RETURNS:
//
// =======================================
void findWord ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c ){

    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "findWord called..." << " @ " << r << " , " << c << endl << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // cout << "You are searching for: " << word << "///" << endl;
    // initialChecks(grid, word, temp, grid[r][c], target, r, c);

    cout << grid[r][c] << " @ " << r << " , " << c << " is getting compared to " << target << endl;
    if (grid[r][c] == target && word != temp){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
    }

    cout << "Temp is: " << temp << " ///////// " << "Target is: " << target << endl << endl;

    // surrounding search

    bool breaker = false;

    if (r>0 && breaker == false){
        searchUp(grid, word, temp, grid[r-1][c], target, r-1, c, breaker);

    }
    if (r<LENGTH-1 && breaker == false){
        searchDown(grid, word, temp, grid[r+1][c], target, r+1, c, breaker);

    }
    if (c>0 && breaker == false){
        searchLeft(grid, word, temp, grid[r][c-1], target, r, c-1, breaker);

    }
    if (c<LENGTH-1 && breaker == false){
        searchRight(grid, word, temp, grid[r][c+1], target, r, c+1, breaker);

    }
    if (r>0 && c>0 && breaker == false){
        searchUpLeft(grid, word, temp, grid[r-1][c-1], target, r-1, c-1, breaker);

    }
    if (r>0 && c<LENGTH-1 && breaker == false){
        searchUpRight(grid, word, temp, grid[r-1][c+1], target, r-1, c+1, breaker);

    }
    if (r<LENGTH-1 && c>0 && breaker == false){
        searchDownLeft(grid, word, temp, grid[r+1][c-1], target, r+1, c-1, breaker);

    }
    if (r<LENGTH-1 && c<LENGTH-1 && breaker == false){
        searchDownRight(grid, word, temp, grid[r+1][c+1], target, r+1, c+1, breaker);

    }
    // move to next line

    temp = "";

    if (c<LENGTH-1){
        target = word[0];
        findWord(grid, word, temp, grid[r][c+1], target, r, c+1);}
    else if (r== 13 && c == 13){
        cout << "Function didn't find the word." << endl;
        return;
    }
    else if (r>=0){
        target = word[0];
        // cout << "Moving to nextline..." << endl;
        findWord(grid, word, temp, grid[r+1][0], target, r+1, 0);
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
void searchUp ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving up! " << endl;

    breaker = initialChecks(grid, word, temp, grid[r][c], target, r, c);

    if (breaker == false){
        cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

        if (r>0 && grid[r][c] == target && word != temp){
            temp = temp + grid[r][c];
            int tempLen = temp.length();
            target = word[tempLen];
            searchUp(grid, word, temp, grid[r-1][c], target, r-1, c, breaker);
        }
    }
    else
        return;
}

// =======================================
// searchDown
//
// PARAMS:
//
// RETURNS:
//
// =======================================
void searchDown ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving down! " << endl;

    breaker = initialChecks(grid, word, temp, grid[r][c], target, r, c);

    if (breaker == false){
        cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

        if (r<LENGTH-1 && grid[r][c] == target && word != temp){
            temp = temp + grid[r][c];
            int tempLen = temp.length();
            target = word[tempLen];
            searchDown(grid, word, temp, grid[r+1][c], target, r+1, c, breaker);
        }
    }
    else
        return;
}


// =======================================
// searchLeft
//
// PARAMS:
//
// RETURNS:
//
// =======================================
void searchLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving left! " << endl;

    breaker = initialChecks(grid, word, temp, grid[r][c], target, r, c);

    if (breaker == false){
        cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

        if (c>0 && grid[r][c] == target && word != temp){
            temp = temp + grid[r][c];
            int tempLen = temp.length();
            target = word[tempLen];
            searchLeft(grid, word, temp, grid[r][c-1], target, r, c-1, breaker);
        }
    }
    else
        return;
}

// =======================================
// searchRight
//
// PARAMS:
//
// RETURNS:
//
// =======================================
void searchRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving right! " << endl;

    breaker = initialChecks(grid, word, temp, grid[r][c], target, r, c);

    if (breaker == false){
        cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

        if (c<LENGTH-1 && grid[r][c] == target && word != temp){
            temp = temp + grid[r][c];
            int tempLen = temp.length();
            target = word[tempLen];
            searchRight(grid, word, temp, grid[r][c+1], target, r, c+1, breaker);
        }
    }
    else
        return;
}

// =======================================
// searchUpLeft
//
// PARAMS:
//
// RETURNS:
//
// =======================================
void searchUpLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving upleft! " << endl;

    breaker = initialChecks(grid, word, temp, grid[r][c], target, r, c);

    if (breaker == false){
        cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

        if (r>0 && c>0 && grid[r][c] == target && word != temp){
            temp = temp + grid[r][c];
            int tempLen = temp.length();
            target = word[tempLen];
            searchUpLeft(grid, word, temp, grid[r-1][c-1], target, r-1, c-1, breaker);
        }
    }
    else
        return;
}


// =======================================
// searchUpRight
//
// PARAMS:
//
// RETURNS:
//
// =======================================
void searchUpRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving upright! " << endl;

    breaker = initialChecks(grid, word, temp, grid[r][c], target, r, c);

    if (breaker == false){
        cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

        if (r>0 && c<LENGTH-1 && grid[r][c] == target && word != temp){
            temp = temp + grid[r][c];
            int tempLen = temp.length();
            target = word[tempLen];
            searchUpRight(grid, word, temp, grid[r-1][c+1], target, r-1, c+1, breaker);
        }
    }
    else
        return;
}


// =======================================
// searchDownLeft
//
// PARAMS:
//
// RETURNS:
//
// =======================================
void searchDownLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving downleft! " << endl;

    breaker = initialChecks(grid, word, temp, grid[r][c], target, r, c);

    if (breaker == false){
        cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

        if (r<LENGTH-1 && c>0 && grid[r][c] == target && word != temp){
            temp = temp + grid[r][c];
            int tempLen = temp.length();
            target = word[tempLen];
            searchDownLeft(grid, word, temp, grid[r+1][c-1], target, r+1, c-1, breaker);
        }
    }
    else
        return;
}


// =======================================
// searchDownRight
//
// PARAMS:
//
// RETURNS:
//
// =======================================
void searchDownRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, bool breaker ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving downright! " << endl;

    breaker = initialChecks(grid, word, temp, grid[r][c], target, r, c);

    if (breaker == false){
        cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

        if (r<LENGTH-1 && c<LENGTH-1 && grid[r][c] == target && word != temp){
            temp = temp + grid[r][c];
            int tempLen = temp.length();
            target = word[tempLen];
            searchDownRight(grid, word, temp, grid[r+1][c+1], target, r+1, c+1, breaker);
        }
    }
    else
        return;
}
