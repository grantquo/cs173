// =======================================
// Grant and Jack
// project6.cpp
// Project Description
// =======================================


#include <iostream>
#include <fstream>


using namespace std;

// function declarations
const int length = 14;

void readGrid( char grid[length][length] );
void printGrid ( char grid[length][length] );
int main(  void  ){

    char grid[length][length];
    readGrid(grid);
    printGrid(grid);

    return 0;
}

void readGrid( char grid[length][length] ){
    for (int i=0; i < length; i++)
        for (int j=0; j < length; j++)
            cin >> grid[i][j];
    return;
}

void printGrid ( char grid[length][length] ){
    for (int i=0; i < length; i++){
        for (int j=0; j < length; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
