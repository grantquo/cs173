// ============================================
// Grant Gutterman
// 09-16-2022
// project3.cpp
// Ceaser Cypher program that decrypts by taking a cipher text and returns a
// decrypted message.
// ============================================

#define SIZE 25
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;

// function declarations
int integerize(char character);

char convert();

// ============================================
// main
// ============================================
int main ( int argc, char *argv[] )
{

    char alpha[SIZE] = {('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'
    , 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z')};

    int values[SIZE] = {(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
    17, 18, 19, 20, 21, 22, 23, 24, 25)};

    // FILE INPUTS

    int key;
    if ( argc > 1 )
        key = atoi(argv[1]);
    else
        key = 3;

    string message, temp;

    while ( getline(cin,temp) )
        message = message+temp;


    /*
    for (int i=0; i<message.length(); i++)
    {
        if ( isspace(message[i]) == 0 ){
            cout << message[i];
        }
    }
    */

    return 0;
}


int integerize(char character){

    return 0;
}

char convert(){

    return 0;
}
