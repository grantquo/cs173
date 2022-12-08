//=====================================================
// Simple character reader.
//=====================================================

#include <iostream>
#include <string>

using namespace std;

int main ( void )
{
    string inputStr;
    getline(cin, inputStr);
    cout << inputStr << endl;
    getline(cin, inputStr);
    if (inputStr == "")
    {
        cout << "Passed Condition!" << endl;
        cout << inputStr << endl;
    }
    return 0;
}
