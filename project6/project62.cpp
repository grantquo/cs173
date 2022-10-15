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

string searchUp ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );
string searchDown ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );
string searchLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );
string searchRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );

string searchUpLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );
string searchUpRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );

string searchDownLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );
string searchDownRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );

bool breakerChecks ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );
void regChecks ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );

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
// breakerChecks
//
// PARAMS:
//
// RETURNS:
//
// =======================================
bool breakerChecks ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c ){
    bool breaker;
    cout << "@@@@@@@" << "Location: " << r << " , " << c << endl;
    cout << word << " initial check " << temp << endl;
    if (word == temp)
        return true;
    else
        return false;
}
// =======================================

// =======================================
void regChecks ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c ){
    cout << "@@@@@@@" << "Location: " << r << " , " << c << endl;
    cout << word << " initial check " << temp << endl;
    if (word == temp)
        printLocation(word, r, c);
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

    bool breaker;

    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "findWord called..." << " @ " << r << " , " << c << endl << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // cout << "You are searching for: " << word << "///" << endl;
    // breakerChecks(grid, word, temp, grid[r][c], target, r, c);

    cout << grid[r][c] << " @ " << r << " , " << c << " is getting compared to " << target << endl;
    if (grid[r][c] == target && word != temp){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        breaker = false;
        cout << "<<<<<<<<<<<<<<<<<<<<< Completed first letter!!" << endl;
        cout << "Handling directions..." << endl;
    }

    cout << "Temp is: " << temp << " ///////// " << "Target is: " << target << endl << endl;

    // surrounding search
    string tempComparator = "";

    // UP
    while (r>0 && breaker == false){
        tempComparator = temp;
        temp = searchUp(word, temp, grid[r-1][c], target, r+1, c);
        if (tempComparator == temp)
            break;
        else if (temp == word)
            breaker = true;
        else
            r = r-1;
    }

    // DOWN
    while (r<LENGTH-1 && breaker == false){
        tempComparator = temp;
        temp = searchDown(word, temp, grid[r+1][c], target, r+1, c);
        if (tempComparator == temp)
            break;
        else if (temp == word)
            breaker = true;
        else
            r = r+1;
    }

    // LEFT
    while (c>0 && breaker == false){
        tempComparator = temp;
        temp = searchLeft(word, temp, grid[r][c-1], target, r, c-1);
        if (tempComparator == temp)
            break;
        else if (temp == word)
            breaker = true;
        else
            c = c-1;
    }

    // RIGHT
    while (c<LENGTH-1 && breaker == false){
        tempComparator = temp;
        temp = searchRight(word, temp, grid[r][c+1], target, r, c+1);
        if (tempComparator == temp)
            break;
        else if (temp == word)
            breaker = true;
        else
            c = c+1;
    }

    // UP LEFT
    while (r>0 && c>0 && breaker == false){
        tempComparator = temp;
        temp = searchUpLeft(word, temp, grid[r-1][c-1], target, r-1, c-1);
        if (tempComparator == temp)
            break;
        else if (temp == word)
            breaker = true;
        else{
            r = r-1;
            c = c-1;
        }
    }

    // UP RIGHT
    while (r>0 && c<LENGTH-1 && breaker == false){
        tempComparator = temp;
        temp = searchUpRight(word, temp, grid[r-1][c+1], target, r-1, c+1);
        if (tempComparator == temp)
            break;
        else if (temp == word)
            breaker = true;
        else{
            r = r-1;
            c = c+1;
        }
    }

    // DOWN LEFT
    while (r<LENGTH-1 && c>0 && breaker == false){
        tempComparator = temp;
        temp = searchDownLeft(word, temp, grid[r+1][c-1], target, r+1, c-1);
        if (tempComparator == temp)
            break;
        else if (temp == word)
            breaker = true;
    }

    // DOWN RIGHT
    while (r<LENGTH-1 && c<LENGTH-1 && breaker == false){
        tempComparator = temp;
        temp = searchDownRight(word, temp, grid[r+1][c+1], target, r+1, c+1);
        if (tempComparator == temp)
            break;
        else if (temp == word)
            breaker = true;
        else{
            r = r+1;
            c = c+1;
        }

    }

    // move to next line

    if (c<LENGTH-1 && breaker == false){
        target = word[0];
        findWord(grid, word, temp, grid[r][c+1], target, r, c+1);}
    else if (r== 13 && c == 13 && breaker == false){
        cout << "Function didn't find the word." << endl;
        return;
    }
    else if (r>=0 && breaker == false){
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
string searchUp ( string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving up! " << endl;
    cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

    if (source == target){
        temp = temp + source;
    }
    return temp;

}

// =======================================
// searchDown
//
// PARAMS:
//
// RETURNS:
//
// =======================================
string searchDown ( string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving down! " << endl;
    cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

    if (source == target){
        temp = temp + source;
    }
    return temp;

}


// =======================================
// searchLeft
//
// PARAMS:
//
// RETURNS:
//
// =======================================
string searchLeft ( string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving left! " << endl;
    cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

    if (source == target){
        temp = temp + source;
    }
    return temp;

}

// =======================================
// searchRight
//
// PARAMS:
//
// RETURNS:
//
// =======================================
string searchRight ( string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving right! " << endl;
    cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

    if (source == target){
        temp = temp + source;
    }
    return temp;

}

// =======================================
// searchUpLeft
//
// PARAMS:
//
// RETURNS:
//
// =======================================
string searchUpLeft ( string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving upleft! " << endl;
    cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

    if (source == target){
        temp = temp + source;
    }
    return temp;

}


// =======================================
// searchUpRight
//
// PARAMS:
//
// RETURNS:
//
// =======================================
string searchUpRight ( string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving upright! " << endl;
    cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

    if (source == target){
        temp = temp + source;
    }
    return temp;

}


// =======================================
// searchDownLeft
//
// PARAMS:
//
// RETURNS:
//
// =======================================
string searchDownLeft ( string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving downleft! " << endl;
    cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

    if (source == target){
        temp = temp + source;
    }
    return temp;

}


// =======================================
// searchDownRight
//
// PARAMS:
//
// RETURNS:
//
// =======================================
string searchDownRight ( string word, string temp, char source, char target, int r, int c ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    // cout << "You are searching for: " << word << "///" << endl;
    cout << "~~~~~~~~~~~~~" << "Moving downright! " << endl;


    cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

    if (source == target){
        temp = temp + source;
    }
    return temp;

}
