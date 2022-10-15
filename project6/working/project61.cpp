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

int searchUp ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );
int searchDown ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );

int searchLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );
int searchRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c);

int searchUpLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );
int searchUpRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );

int searchDownLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );
int searchDownRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c );

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

    //cout << "Temp is: " << temp << " ///////// " << "Target is: " << target << endl << endl;

    // surrounding search

    if (r>0){
        searchUp(grid, word, temp, grid[r-1][c], target, r-1, c);
    }

    if (r<LENGTH-1){
        searchDown(grid, word, temp, grid[r+1][c], target, r+1, c);
    }

    if (c>0 ){
        searchLeft(grid, word, temp, grid[r][c-1], target, r, c-1);
    }
    if (c<LENGTH-1 ){
        searchRight(grid, word, temp, grid[r][c+1], target, r, c+1);
    }
    if (r>0 && c>0 ){
        searchUpLeft(grid, word, temp, grid[r-1][c-1], target, r-1, c-1);
    }
    if (r>0 && c<LENGTH-1 ){
        searchUpRight(grid, word, temp, grid[r-1][c+1], target, r-1, c+1);
    }
    if (r<LENGTH-1 && c>0 ){
        searchDownLeft(grid, word, temp, grid[r+1][c-1], target, r+1, c-1);
    }
    if (r<LENGTH-1 && c<LENGTH-1){
        searchDownRight(grid, word, temp, grid[r+1][c+1], target, r+1, c+1);
    }

    // move to next line

    temp = "";

    if (c<LENGTH-1){
        target = word[0];
        findWord(grid, word, temp, grid[r][c+1], target, r, c+1);}
    else if (r== 13 && c == 13 ){

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
int searchUp ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    //cout << "~~~~~~~~~~~~~" << "Moving up! " << endl;
    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

    if (r>0 && grid[r][c] == target && word != temp){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchUp(grid, word, temp, grid[r-1][c], target, r-1, c);
    }
    if(temp == word){
        x = r + word.length()-1;
        y = c;

        cout << word << " found at " << x << "," << y << " going up." <<  endl;
    }

    return x, y;

}

// =======================================
// searchDown
//
// PARAMS:
//
// RETURNS:
//
// =======================================
int searchDown ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    //cout << "~~~~~~~~~~~~~" << "Moving down! " << endl;
    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

    if (r<LENGTH-1 && grid[r][c] == target && word != temp){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchDown(grid, word, temp, grid[r+1][c], target, r+1, c);
        }
    if(temp == word){
        x = r - word.length()+1;
        y = c;

        cout << word << " found at " << x << "," << y << " going down." <<  endl;
    }
    return x, y;

}


// =======================================
// searchLeft
//
// PARAMS:
//
// RETURNS:
//
// =======================================
int searchLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    //cout << "~~~~~~~~~~~~~" << "Moving left! " << endl;
    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

    if (c>0 && grid[r][c] == target && word != temp){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchLeft(grid, word, temp, grid[r][c-1], target, r, c-1);
    }
    if(temp == word){
        x = r;
        y = c + word.length()-1;

        cout << word << " found at " << x << "," << y << " going left." <<  endl;
    }

    return x, y;

}

// =======================================
// searchRight
//
// PARAMS:
//
// RETURNS:
//
// =======================================
int searchRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    //cout << "~~~~~~~~~~~~~" << "Moving right! " << endl;
    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;
    if (c<LENGTH-1 && grid[r][c] == target && word != temp){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchRight(grid, word, temp, grid[r][c+1], target, r, c+1);
    }
    if(temp == word){
        x = r;
        y = c - word.length()+1;

        cout << word << " found at " << x << "," << y << " going right." <<  endl;
    }

    return x, y;

}

// =======================================
// searchUpLeft
//
// PARAMS:
//
// RETURNS:
//
// =======================================
int searchUpLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    //cout << "~~~~~~~~~~~~~" << "Moving upleft! " << endl;
    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

    if (r>0 && c>0 && grid[r][c] == target && word != temp){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchUpLeft(grid, word, temp, grid[r-1][c-1], target, r-1, c-1);
    }
    if(temp == word){
    	x = r - word.length()-1;
    	y = c - word.length()-1;

        cout << word << " found at " << x << "," << y << " going up left." <<  endl;
    }

    return x, y;

}


// =======================================
// searchUpRight
//
// PARAMS:
//
// RETURNS:
//
// =======================================
int searchUpRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    //cout << "~~~~~~~~~~~~~" << "Moving upright! " << endl;
    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

    if (r>0 && c<LENGTH-1 && grid[r][c] == target && word != temp){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchUpRight(grid, word, temp, grid[r-1][c+1], target, r-1, c+1);
    }
    if(temp == word){
        x = r + word.length()-1;
    	y = c - word.length()+1;

        cout << word << " found at " << x << "," << y << " going up right." <<  endl;
    }

    return x, y;
}


// =======================================
// searchDownLeft
//
// PARAMS:
//
// RETURNS:
//
// =======================================
void searchDownLeft ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    //cout << "~~~~~~~~~~~~~" << "Moving downleft! " << endl;
    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

    if (r<LENGTH-1 && c>0 && grid[r][c] == target && word != temp){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchDownLeft(grid, word, temp, grid[r+1][c-1], target, r+1, c-1);
    }
    if(temp == word){
    	x = r - word.length()+1;
    	y = c + word.length()-1;

    	cout << word << " found at " << x << "," << y << " going down left." <<  endl;
    }

    return x, y;
}


// =======================================
// searchDownRight
//
// PARAMS:
//
// RETURNS:
//
// =======================================
void searchDownRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c){
    assert(r>=0);
    assert(c>=0);
    assert(r<=LENGTH-1);
    assert(c<=LENGTH-1);
    int x, y;
    // cout << "You are searching for: " << word << "///" << endl;
    //cout << "~~~~~~~~~~~~~" << "Moving downright! " << endl;


    //cout << source << " @ " << r << " , " << c << " is getting compared to " << target << endl;

    if (r<LENGTH-1 && c<LENGTH-1 && grid[r][c] == target && word != temp){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchDownRight(grid, word, temp, grid[r+1][c+1], target, r+1, c+1);
    }
    if(temp == word){
        x = r - word.length()+1;
        y = c - word.length()+1;

        cout << word << " found at " << x << "," << y << " going down right." <<  endl;
    }
    return x, y;
}
