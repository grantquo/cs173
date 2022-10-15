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
bool foundState = false;

// function declarations

void readGrid       ( char grid[LENGTH][LENGTH] );
void printGrid      ( char grid[LENGTH][LENGTH] );
//bool isFound        ( string word, int origin[2], string direction );
void findWord       ( char grid[LENGTH][LENGTH], string word, char source, char target, int r, int c );

void searchUp        ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );
void searchDown      ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );

void searchLeft      ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );
void searchRight     ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );

void searchUpLeft    ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );
void searchUpRight   ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );

void searchDownLeft  ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );
void searchDownRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] );

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

// bool isFound        ( string word, int origin[2], string direction, bool state ){
//     if (state == true){
//         cout << word << " found at " << origin[0] << "," << origin[1] << direction <<  endl;
//         return true;
//     }
//     return false;
//
// }
// =======================================
// findWord
//
// PARAMS:
//
// RETURNS:
//
// =======================================
void findWord       ( char grid[LENGTH][LENGTH], string word, char source, char target, int r, int c){

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
    foundState = false;
    //cout << "Temp is: " << temp << " ///////// " << "Target is: " << target << endl << endl;

    // surrounding search
    if (temp != ""){

        if (r>0 && foundState == false){
            searchUp(grid, word, temp, grid[r-1][c], target, r-1, c, origin);
        }

        if (r<LENGTH-1 && foundState == false){
            searchDown(grid, word, temp, grid[r+1][c], target, r+1, c, origin);
        }

        if (c>0 && foundState == false){
            searchLeft(grid, word, temp, grid[r][c-1], target, r, c-1, origin);
        }

        if (c<LENGTH-1 && foundState == false){
            searchRight(grid, word, temp, grid[r][c+1], target, r, c+1, origin);
        }

        if (r>0 && c>0 && foundState == false){
            searchUpLeft(grid, word, temp, grid[r-1][c-1], target, r-1, c-1, origin);
        }

        if (r>0 && c<LENGTH-1 && foundState == false){
            searchUpRight(grid, word, temp, grid[r-1][c+1], target, r-1, c+1, origin);
        }

        if (r<LENGTH-1 && c>0 && foundState == false){
            searchDownLeft(grid, word, temp, grid[r+1][c-1], target, r+1, c-1, origin);
        }
        if (r<LENGTH-1 && c<LENGTH-1 && foundState == false){
            searchDownRight(grid, word, temp, grid[r+1][c+1], target, r+1, c+1, origin);
        }
    }
    // move to next line
    if (foundState == true)
        return;

    if (c<LENGTH-1){
        target = word[0];
        findWord(grid, word, grid[r][c+1], target, r, c+1);}
    else if (r== 13 && c == 13){
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
void searchUp        ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] ){
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
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going up." <<  endl;
        foundState = true;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        return;
    }
    else if (r>0 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchUp(grid, word, temp, grid[r-1][c], target, r-1, c, origin);
    }
    else if (source == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going up." <<  endl;
        foundState = true;
        return;
    }
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
void searchDown      ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] ){
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
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going down." <<  endl;
        foundState = true;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        return;
    }
    else if (r<LENGTH-1 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchDown(grid, word, temp, grid[r+1][c], target, r+1, c, origin);
    }
    else if (source == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going down." <<  endl;
        foundState = true;
        return;
    }
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
void searchLeft      ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2] ){
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
        // cout << endl << "@@@@@@@@@@@@@@@@" << endl << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going left." <<  endl;
        foundState = true;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;

        return;
    }
    else if (c>0 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchLeft(grid, word, temp, grid[r][c-1], target, r, c-1, origin);
    }
    else if (source == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going left." <<  endl;
        foundState = true;
        return;
    }
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
void searchRight     ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2]){
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
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going right." <<  endl;
        foundState = true;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        return;
    }
    else if (c<LENGTH-1 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchRight(grid, word, temp, grid[r][c+1], target, r, c+1, origin);
    }
    else if (source == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going right." <<  endl;
        foundState = true;
        return;
    }
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
void searchUpLeft    ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2]){
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
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going up left." <<  endl;
        foundState = true;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        return;
    }
    else if (r>0 && c>0 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchUpLeft(grid, word, temp, grid[r-1][c-1], target, r-1, c-1, origin);
    }
    else if (source == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going up left." <<  endl;
        foundState = true;
        return;
    }
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
void searchUpRight   ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2]){
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
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going up right." <<  endl;
        foundState = true;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        return;
    }
    else if (r>0 && c<LENGTH-1 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchUpRight(grid, word, temp, grid[r-1][c+1], target, r-1, c+1, origin);
    }
    else if (source == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going up right." <<  endl;
        foundState = true;
        return;
    }
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
void searchDownLeft  ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2]){
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
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going down left." <<  endl;
        foundState = true;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        return;
    }
    else if (r<LENGTH-1 && c>0 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchDownLeft(grid, word, temp, grid[r+1][c-1], target, r+1, c-1, origin);
    }
    else if (source == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going down left." <<  endl;
        foundState = true;
        return;
    }
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
void searchDownRight ( char grid[LENGTH][LENGTH], string word, string temp, char source, char target, int r, int c, int origin[2]){
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
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        cout << word << " found at " << origin[0] << "," << origin[1] << " going down right." <<  endl << endl ;
        foundState = true;
        // cout << endl << endl << "@@@@@@@@@@@@@@@@" << endl;
        return;
    }
    else if (r<LENGTH-1 && c<LENGTH-1 && source == target && temp != word){
        temp = temp + grid[r][c];
        int tempLen = temp.length();
        target = word[tempLen];
        searchDownRight(grid, word, temp, grid[r+1][c+1], target, r+1, c+1, origin);
    }
    else if (source == target && temp != word){
        temp = temp + grid[r][c];
        cout << word << " found at " << origin[0] << "," << origin[1] << " going down right." <<  endl;
        foundState = true;
        return;
    }
    return;
}
