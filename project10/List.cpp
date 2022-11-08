//==========================================================
// Grant Gutterman
// 11-8-22
// List.cpp
// This file contains the class implementation for the dynamic
// list array class.
//==========================================================

#include "List.h"
#include <iomanip>
#include <string>

/*
>>>>> Things left to do:

- TESTING TESTING TESTING TESTING

- Build the adding two lists together function

- Build list from mylist function

- Docstrings

>>>>> Possible problems:

- If statement pointers need to either have/dont have * in them

- To build the list, you either need/dont need * in the init statement

- Delete statements might need/dont need *

- Assignments might need/dont need * in their statements

- Reallocate is actually trash even when it makes sense

- You don't need to return the pointer as * but instead just "list"

*/
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
// PUBLIC METHODS
//
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//==========================================================
// List initialize
// create list
//==========================================================
template <class T>
            List<class T>::List ( void )
{
    *list = new T[DEFAULT_LIST_CAPACITY];
    capacity = DEFAULT_LIST_CAPACITY;
    size = 0;
}


template <class T>
            List<class T>::List ( const List<T> &mylist )
{

}

//==========================================================
// destructor
//==========================================================
template <class T>
            List<class T>::~List ( void )
{
    delete [] list;
    capacity = 0;
    size = 0;
}

//==========================================================
// operator=
// assignment op
//==========================================================
template <class T>
List<T>     List<class T>::operator= ( const List<T> &mylist )
{
    delete [] list;
    *list = mylist;
    return *list;
}

//==========================================================
// append
// add shit at end of list
//==========================================================
template <class T>
void        List<class T>::append ( const T &item )
{
    if (size == capacity)
    {
        // if list is full
        reallocate();
    }
    // if list isn't full
    size += 1;
    *list[size] = item;
}

//==========================================================
// operator[]
// index access
//==========================================================
template <class T>
T &         List<class T>::operator[] ( int index )
{
    return *list[index];
}

//==========================================================
// insert
// new value at specific pos
//==========================================================
template <class T>
void        List<class T>::insert ( const T &item, int index )
{
    if (size == capacity)
    {
        // if list is full
        reallocate();
    }
    // if list isn't full

}

//==========================================================
// remove
// delete value
//==========================================================
template <class T>
void        List<class T>::remove ( int index )
{
    delete [] list;
    size = size - 1;
}

//==========================================================
// operator+
// adds two lists together
//==========================================================
template <class T>
List<T>     List<class T>::operator+ ( const List<T> &mylist ) const
{
    // idfk
}

//==========================================================
// length
// gets length of list
//==========================================================
template <class T>
int         List<class T>::length ( void ) const
{
    return size;
}

//==========================================================
// isEmpty
// boolean of empty check
//==========================================================
template <class T>
bool        List<class T>::isEmpty ( void ) const
{
    return (capacity != size);
}

//==========================================================
// clear
// removes all items from list
//==========================================================
template <class T>
void        List<class T>::clear ( void )
{
    delete [] list;
    size = 0;
    *list = new T[capacity];
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
// PRIVATE METHODS
//
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//==========================================================
// reallocate
// private method for reallocating lists if full
//==========================================================
void        List<class T>::reallocate ( void )
{
    // default constructor
    int newCapacity *= 2;
    T temp[newCapacity] = {};
    // copy constructor
    for (int ind = 0; ind < capacity; ind++)
        *list[ind] = temp[ind];
    // destructor
    delete [] list;
    *list = temp;
    // assignment
    capacity = newCapacity;

}
