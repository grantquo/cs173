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
// These two functions create a list based off either a blank
// or list name input.
// PARAMS:
//
// RETURNS:
//
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
// This function clears all data from the list pointer and
// size/capacity integers associated with it.
// PARAMS:
//
// RETURNS:
//
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
// This gives functionality for the assignment operator "=",
// allowing for dynamics lists to be reassigned to other
// dynamic lists, while the deallocated data is deleted.
// PARAMS:
//
// RETURNS:
//
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
// This gives the dynamics lists the ability for "append", an
// operation where an item is added to the end of the list.
// PARAMS:
//
// RETURNS:
//
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
// This lets dynamic lists take specific value calls, where
// by calling an index number, the dynamic list returns the
// value at that index.
// PARAMS:
//
// RETURNS:
//
//==========================================================
template <class T>
T &         List<class T>::operator[] ( int index )
{
    return *list[index];
}

//==========================================================
// insert
// This adds an item at a specific index of a dynamic list.
// After an insert, every prev value on the specified index
// and above are moved up an index level, allowing room for
// the item.
// PARAMS:
//
// RETURNS:
//
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
// Remove allows for dynamic lists to have a value deleted
// from them at a specified index number. The total capacity
// of the list after a remove is unaffected.
// PARAMS:
//
// RETURNS:
//
//==========================================================
template <class T>
void        List<class T>::remove ( int index )
{
    delete [] list;
    size = size - 1;
}

//==========================================================
// operator+
// Gives dynamic lists the ability to be combined with other
// dynamic lists through operator "+". The second list getting
// added will be attached to the end of the first one.
// PARAMS:
//
// RETURNS:
//
//==========================================================
template <class T>
List<T>     List<class T>::operator+ ( const List<T> &mylist ) const
{
    // idfk
}

//==========================================================
// length
// Simple function that returns the number of values stored
// in the dynamic list.
// PARAMS:
//
// RETURNS:
//
//==========================================================
template <class T>
int         List<class T>::length ( void ) const
{
    return size;
}

//==========================================================
// isEmpty
// Boolean function that returns either true or false for if
// the dynamic list is empty.
// PARAMS:
//
// RETURNS:
//
//==========================================================
template <class T>
bool        List<class T>::isEmpty ( void ) const
{
    return (capacity != size);
}

//==========================================================
// clear
// Clear deletes all of the values of a list, while retaining
// the dynamic list's capacity.
// PARAMS:
//
// RETURNS:
//
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
// This function is called whenever a dynamic list is full
// and needs to make space for more items. It first creates
// a new dynamic list with double the amount of capacity,
// then copies every value from the first into the second.
// The old, smaller list is then deleted for memory and
// capacity is adjusted for the new one.
// PARAMS:
//
// RETURNS:
//
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
