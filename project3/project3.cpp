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
int integerize();

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

    int key;
    if ( argc > 1 )
        key = atoi(argv[1]);
    else
        key = 3;
    string text;    
    cin >> text;
    cout << text << endl;
    cout << key << endl;













    return 0;
}


int integerize(){

    return 0;
}

char convert(){

    return 0;
}
