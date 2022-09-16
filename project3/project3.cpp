// ============================================
// Grant Gutterman
// 09-16-2022
// project3.cpp
// Ceaser Cypher program that decrypts by taking a cipher text and key, and then
// returns a decrypted message.
// ============================================

// INCLUSIONS
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

// FUNCTION DECLARATIONS
int integerize(char encryptChar);
int shift(int value, int key);
char characterize(int decryptVal);

// ============================================
// main
// ============================================
int main ( int argc, char *argv[] )
{

    // FILE INPUTS

    int key;
    if ( argc > 1 )
        key = atoi(argv[1]);
    else
        key = 3;

    string message, temp;
    string decryptStr;
    char activeChar;
    while ( getline(cin,temp) ){
        message = message+temp;
    }

    for (int i=0; i<message.length(); i++)
    {

        if ( isspace(message[i]) == 0 ){
            activeChar = message[i];
            int encryptVal = integerize(message[i]);
            int decryptVal = shift(encryptVal, key);
            char decryptChar = characterize(decryptVal);
            decryptStr = decryptStr + decryptChar;
        }
        else if ( isspace(message[i]) != 0 )
            decryptStr = decryptStr + message[i];
        else if ( message[i] == '\n' )
            decryptStr = decryptStr + " ";
    }
        cout << decryptStr;
    return 0;
}

//=========================================================
// integerize
// Takes an encrpyted character and then takes its ASCII value from it, then
// subtracts 97 from it to be put in the 0-25 value range.
// PARAMS:
// - encryptChar: an encrypted character
// RETURNS:
// - encryptVal: the encrypted character's value in terms of 0-25
//=========================================================
int integerize(char encryptChar){
    int encryptVal = int(encryptChar)-97;
    return encryptVal;
}
//=========================================================
// shift
// Takes the encrypted value and subtracts the key number from it, decrypting
// the value and then putting it back in terms of ASCII values (+97)
// PARAMS:
// - value: encrypted value for the character (not yet decrypted)
// - key: the "key" for the encryption that moves the values over for decryption
// RETURNS:
// - value+97: the decrypted value, now back in terms of ASCII
//=========================================================
int shift(int value, int key){
    value = value-key;
    if (value > 25)
        value = value%26;
    else if (value < 0)
        value = value+26;
    return value+97;
}
//=========================================================
// characterize
// Takes the decrypted value and converts it back to ASCII. Essentially does
// the reverse of integerize.
// PARAMS:
// - decryptVal: decrypted value for the character
// RETURNS:
// - decryptChar: decrypted character that will be placed in the output string
//=========================================================
char characterize(int decryptVal){
    char decryptChar = decryptVal;
    return decryptChar;
}
