// =======================================
// Grant and Jack
// project6.cpp
// Project Description
// =======================================


#include <iostream>
#include <fstream>
#define SIZE 14

using namespace std;

// function declarations
const int length = 14;

void printGrid ( char grid[length][length] );
int main(  int argc, char* argv[]  ){

    ifstream file;
    file.open(argv[1]);
    char maingrid[14][14];
    for (int row = 0; row < SIZE; row++){
        getline(maingrid, file);
    }
    cout << maingrid[14][14] << endl;


    return 0;
}


void printGrid ( char grid[length][length]){
    return;
}
