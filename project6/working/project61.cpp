// =======================================
// Grant and Jack
// project6.cpp
// Takes a word puzzle and finds the words within the search, returning the
// coordinates of the first letter as the answer.
// =======================================

// inclusions

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// globals

const int LENGTH = 14;
bool foundState = false;

// function declarations

void readGrid       ( char grid[LENGTH][LENGTH] );
void printGrid      ( char grid[LENGTH][LENGTH] );

void findWord       ( char grid[LENGTH][LENGTH], string word, char target, int r, int c );

void searchUp        ( char grid[LENGTH][LENGTH], string word, string temp, char target, int r, int c, int origin[2] );
void searchDown      ( char grid[LENGTH][LENGTH], string word, string temp, char target, int r, int c, int origin[2] );

void searchLeft      ( char grid[LENGTH][LENGTH], string word, string temp, char target, int r, int c, int origin[2] );
void searchRight     ( char grid[LENGTH][LENGTH], string word, string temp, char target, int r, int c, int origin[2] );

void searchUpLeft    ( char grid[LENGTH][LENGTH], string word, string temp, char target, int r, int c, int origin[2] );
void searchUpRight   ( char grid[LENGTH][LENGTH], string word, string temp, char target, int r, int c, int origin[2] );

void searchDownLeft  ( char grid[LENGTH][LENGTH], string word, string temp, char target, int r, int c, int origin[2] );
void searchDownRight ( char grid[LENGTH][LENGTH], string word, string temp, char target, int r, int c, int origin[2] );

// =======================================
// main
//
// Conducts the program and calls the main search function. The main function
// takes a grid inputted by stdin and calls the read and print functions, then
// grabbs the number of words in the puzzle. It takes this number called
// numWords and iterates whatever is equal to it. Each loop calls the search
// function, and the search function handles the terminal outputs.
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
        findWord(grid, word, word[0], 0, 0);

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
void readGrid       ( char grid[LENGTH][LENGTH] ){
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
void printGrid      ( char grid[LENGTH][LENGTH] ){
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
// findWord is the main search function. This function takes in a starting
// pair of coordinates called by main, along with the first letter of the word
// it is searching for. If it finds the first letter (assigned to target), it
// will call directional functions to check the surrounding characters and find
// the rest of the word. If they don't find anything, the function moves through
// the puzzle repeating the process until it reaches the end, or finds the word.
// PARAMS:
//      grid[LENGTH][LENGTH] - word puzzle with its maximum length bounds
//      word - string parameter that holds the word we are searching for
//      target - single character meant to hold a character in word we are
//      searching for in the grid.
//      r - integer for the row coordinates
//      c - integer for the column coordinates
// RETURNS:
//      Nothing, but outputs a "not found" string for if a word isn't found in
//      the puzzle.
// =======================================
void findWord       ( char grid[LENGTH][LENGTH], string word, char target, int r, int c){

    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    string temp = "";

    if (grid[r][c] == target){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
    }

    int origin[2] = {r, c};
    foundState = false;

    // surrounding search
    if (temp != ""){

        if (r>0 && foundState == false){
            searchUp(grid, word, temp, target, r-1, c, origin);
        }

        if (r<LENGTH-1 && foundState == false){
            searchDown(grid, word, temp, target, r+1, c, origin);
        }

        if (c>0 && foundState == false){
            searchLeft(grid, word, temp, target, r, c-1, origin);
        }

        if (c<LENGTH-1 && foundState == false){
            searchRight(grid, word, temp, target, r, c+1, origin);
        }

        if (r>0 && c>0 && foundState == false){
            searchUpLeft(grid, word, temp, target, r-1, c-1, origin);
        }

        if (r>0 && c<LENGTH-1 && foundState == false){
            searchUpRight(grid, word, temp, target, r-1, c+1, origin);
        }

        if (r<LENGTH-1 && c>0 && foundState == false){
            searchDownLeft(grid, word, temp, target, r+1, c-1, origin);
        }
        if (r<LENGTH-1 && c<LENGTH-1 && foundState == false){
            searchDownRight(grid, word, temp, target, r+1, c+1, origin);
        }
    }
    // move to next line
    if (foundState == true)
        return;

    if (c<LENGTH-1){
        target = word[0];
        findWord(grid, word, target, r, c+1);}

    else if (r== 13 && c == 13){
        cout << "The word " << word << " could not be found." << endl;
        return;
    }

    else if (r>=0){
        target = word[0];
        findWord(grid, word, target, r+1, 0);
    }
    return;
}

// =======================================
// Recursive Directional Functions
//
// These functions are recursive functions that take a starting coordinate pair,
// (r,c) and move through the grid in their defined direction. As the functions
// find letters that are in the order of the word we are searching for, it adds
// the characters to a spare string that is constantly compared to word.
// If the two match, then the original coordinate pair the function was called
// with is outputted with the word, displaying an answer key to where the word
// is in the grid.
// If the search function finds any character in its path that doesn't match
// the letter target is set to, it stops everything through return.
//
// All of the functions are the same except for the direction they go in
// relation to the grid.

// PARAMS:
//      grid[LENGTH][LENGTH] - word puzzle with its maximum length bounds
//      word - string parameter that holds the word we are searching for
//      temp - string that tracks the progress of the characters found
//      target - single character meant to hold a character in word we are
//      searching for in the grid.
//      r - integer for the row coordinates
//      c - integer for the column coordinates
// RETURNS:
//      Nothing, but if the function finds the word through its searching
//      process, outputs the word, its coordinates of the first letter, and
//      the direction it is going from those coordinates.
// =======================================

// =======================================
// searchUp
// =======================================
void searchUp        ( char grid[LENGTH][LENGTH], string word, string temp,  char target, int r, int c, int origin[2] ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    if(temp == word){
        cout << word << " found at " << origin[0] << "," << origin[1] << " going up." <<  endl;
        foundState = true;
        return;
    }

    else if (r>0 && grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchUp(grid, word, temp, target, r-1, c, origin);
    }

    else if (grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going up." <<  endl;
        foundState = true;
        return;
    }
    return;
}

// =======================================
// searchDown
// =======================================
void searchDown      ( char grid[LENGTH][LENGTH], string word, string temp,  char target, int r, int c, int origin[2] ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    if(temp == word){
        cout << word << " found at " << origin[0] << "," << origin[1] << " going down." <<  endl;
        foundState = true;
        return;
    }

    else if (r<LENGTH-1 && grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchDown(grid, word, temp, target, r+1, c, origin);
    }

    else if (grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going down." <<  endl;
        foundState = true;
        return;
    }
    return;
}

// =======================================
// searchLeft
// =======================================
void searchLeft      ( char grid[LENGTH][LENGTH], string word, string temp,  char target, int r, int c, int origin[2] ){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    if(temp == word){
        cout << word << " found at " << origin[0] << "," << origin[1] << " going left." <<  endl;
        foundState = true;

        return;
    }

    else if (c>0 && grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchLeft(grid, word, temp, target, r, c-1, origin);
    }

    else if (grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going left." <<  endl;
        foundState = true;
        return;
    }
    return;
}

// =======================================
// searchRight
// =======================================
void searchRight     ( char grid[LENGTH][LENGTH], string word, string temp,  char target, int r, int c, int origin[2]){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    if(temp == word){
        cout << word << " found at " << origin[0] << "," << origin[1] << " going right." <<  endl;
        foundState = true;
        return;
    }

    else if (c<LENGTH-1 && grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchRight(grid, word, temp, target, r, c+1, origin);
    }

    else if (grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going right." <<  endl;
        foundState = true;
        return;
    }
    return;
}

// =======================================
// searchUpLeft
// =======================================
void searchUpLeft    ( char grid[LENGTH][LENGTH], string word, string temp,  char target, int r, int c, int origin[2]){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    if(temp == word){
        cout << word << " found at " << origin[0] << "," << origin[1] << " going up left." <<  endl;
        foundState = true;
        return;
    }

    else if (r>0 && c>0 && grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchUpLeft(grid, word, temp, target, r-1, c-1, origin);
    }

    else if (grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going up left." <<  endl;
        foundState = true;
        return;
    }
    return;
}

// =======================================
// searchUpRight
// =======================================
void searchUpRight   ( char grid[LENGTH][LENGTH], string word, string temp,  char target, int r, int c, int origin[2]){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    if(temp == word){
        cout << word << " found at " << origin[0] << "," << origin[1] << " going up right." <<  endl;
        foundState = true;
        return;
    }

    else if (r>0 && c<LENGTH-1 && grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchUpRight(grid, word, temp, target, r-1, c+1, origin);
    }

    else if (grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going up right." <<  endl;
        foundState = true;
        return;
    }
    return;
}

// =======================================
// searchDownLeft
// =======================================
void searchDownLeft  ( char grid[LENGTH][LENGTH], string word, string temp,  char target, int r, int c, int origin[2]){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);

    if(temp == word){
        cout << word << " found at " << origin[0] << "," << origin[1] << " going down left." <<  endl;
        foundState = true;
        return;
    }

    else if (r<LENGTH-1 && c>0 && grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchDownLeft(grid, word, temp, target, r+1, c-1, origin);
    }

    else if (grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going down left." <<  endl;
        foundState = true;
        return;
    }
    return;
}

// =======================================
// searchDownRight
// =======================================
void searchDownRight ( char grid[LENGTH][LENGTH], string word, string temp,  char target, int r, int c, int origin[2]){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    if(temp == word){
        cout << word << " found at " << origin[0] << "," << origin[1] << " going down right." <<  endl << endl ;
        foundState = true;
        return;
    }

    else if (r<LENGTH-1 && c<LENGTH-1 && grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchDownRight(grid, word, temp, target, r+1, c+1, origin);
    }

    else if (grid[r][c] == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going down right." <<  endl;
        foundState = true;
        return;
    }
    return;
}
