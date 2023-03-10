//=====================================================
// Grant Gutterman
// 11-15-22
// stack.cpp
// Basic STL Stack Build
//=====================================================

#include <iostream>
#include <stack>
using namespace std;

int main ( void ){

    stack<char> s;
    s.push('A');
    s.push('B');
    s.push('C');

    cout << "stack size = " << s.size() << endl;

    while ( !s.empty() )
    {
        cout << "popped item: " << s.top() << endl;
        s.pop();
    }


    return 0;
}
