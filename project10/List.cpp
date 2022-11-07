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
    T *list[DEFAULT_LIST_CAPACITY] = {};
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
    delete *list;
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

}

//==========================================================
// append
// add shit at end of list
//==========================================================
template <class T>
void        List<class T>::append ( const T &item )
{
    if (isEmpty(*list) == true)
    {
        // if list is full
        reallocate();
    }
    // if list isn't full


}

//==========================================================
// operator[]
// index access
//==========================================================
template <class T>
T &         List<class T>::operator[] ( int index )
{

}

//==========================================================
// insert
// new value at specific pos
//==========================================================
template <class T>
void        List<class T>::insert ( const T &item, int index )
{
    if (isEmpty(*list) == true)
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
    delete *list[index];
    size = size - 1;
    // possibly wrong ^
}

//==========================================================
// operator+
// adds two lists together
//==========================================================
template <class T>
List<T>     List<class T>::operator+ ( const List<T> &mylist ) const
{

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
    return (capacity == size);
}

//==========================================================
// clear
// removes all items from list
//==========================================================
template <class T>
void        List<class T>::clear ( void )
{

}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
// PUBLIC METHODS
//
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//==========================================================
// reallocate
// private method fo reallocating lists if full
//==========================================================
void        List<class T>::reallocate ( void )
{

}
