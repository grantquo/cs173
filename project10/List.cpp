//==========================================================
// Grant Gutterman
// 11-8-22
// List.cpp
// This file contains the class implementation for the dynamic
// list array class.
//==========================================================

#include <iomanip>
#include <string>

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
// PUBLIC METHODS
//
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//==========================================================
// List initialize
// This functions creates an initializes new list.
// PARAMS:
//      void / nothing
// RETURNS:
//      Nothing, but builds a list within the class with 0
//      elements, and the default capacity.
//==========================================================
template <class T>
            List<T>::List ( void )
{
    list = new T[DEFAULT_LIST_CAPACITY];
    capacity = DEFAULT_LIST_CAPACITY;
    size = 0;
}

//==========================================================
// List copy
// This function takes an existing list in the parameter
// and copies its data into the class, overwriting any
// previous data.
// PARAMS:
//      const List<T> &mylist : A dynamic list with data type
//      T.
// RETURNS:
//      Nothing, but builds a list within the class with data
//      from the list parameter.
//==========================================================
template <class T>
            List<T>::List ( const List<T> &mylist )
{
    size = mylist.size;
    capacity = mylist.capacity;
    list = new T[capacity];
    for (int i=0; i<capacity; i++)
        list[i] = mylist.list[i];
}

//==========================================================
// destructor
// This function clears all data from the list pointer and
// size/capacity integers associated with it.
// PARAMS:
//      void / nothing
// RETURNS:
//      Nothing, but clears all previous data and memory
//      out of the class.
//==========================================================
template <class T>
            List<T>::~List ( void )
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
//      const List<T> &mylist : A dynamic list with data type
//      T.
// RETURNS:
//      A dynamic list that has been reassigned to everything
//      in &mylist.
//==========================================================
template <class T>
List<T>     List<T>::operator= ( const List<T> &mylist )
{
    delete [] list;
    capacity = 0;
    size = 0;

    size = mylist.size;
    capacity = mylist.capacity;
    list = new T[capacity];

    for (int i=0; i<capacity; i++)
        list[i] = mylist.list[i];
    return *this;
}

//==========================================================
// to_string
// This function allows for lists to be outputted through
// strings using cout, diaplying all of their values.
// PARAMS:
//      void / nothing
// RETURNS:
//      A string that processes and outputs every value in
//      the dynamic list (not including empty spaces).
//==========================================================
template <class T>
string      List<T>::to_string ( void ) const
{
    stringstream stream;

    for ( int i = 0; i < size; i++ )
		stream << list[i] << " ";
	return stream.str();
}

//==========================================================
// append
// This gives the dynamics lists the ability for "append", an
// operation where an item is added to the end of the list.
// PARAMS:
//      const T &item : An object with data type T
// RETURNS:
//      Nothing, but stores the object at the end of the list.
//==========================================================
template <class T>
void        List<T>::append ( const T &item )
{
    if (size == capacity)
        reallocate();

    list[size] = item;
    size = size + 1;
}

//==========================================================
// operator[]
// This lets dynamic lists take specific value calls, where
// by calling an index number, the dynamic list returns the
// value at that index.
// PARAMS:
//      int index : An integer within range of the list's
//      indexes.
// RETURNS:
//      An object of the list's data type T that is stored
//      in the specified index.
//==========================================================
template <class T>
T &         List<T>::operator[] ( int index )
{
    if (index < 0 || index > size)
    cout << "Runtime Error: Illegal Indices" << endl;
    return list[index];
}

//==========================================================
// insert
// This adds an item at a specific index of a dynamic list.
// After an insert, every value to the right of the specified
// index are moved up an index level (to the right), allowing
// room for the item to be stored.
// PARAMS:
//      const T &item : An object with data type T
//      int index : An integer within range of the list's
//      indexes.
// RETURNS:
//      Nothing, but stores the specified item in the list
//      at the specified index.
//==========================================================
template <class T>
void        List<T>::insert ( const T &item, int index )
{
    if (size == capacity)
        reallocate();

    for (int i = size; i>=index; i--)
        list[i+1] = list[i];

    list[index] = item;
    size = size + 1;
}

//==========================================================
// remove
// Remove allows for dynamic lists to have a value deleted
// from them at a specified index number. The total capacity
// of the list after a remove is unaffected.
// PARAMS:
//      int index : An integer within range of the list's
//      indexes.
// RETURNS:
//      Nothing, but removes a value stored in the specified
//      index.
//==========================================================
template <class T>
void        List<T>::remove ( int index )
{
    for (int ind = index; ind < size-1; ind++)
        list[ind] = list[ind+1];
    size = size - 1;

}

//==========================================================
// operator+
// Gives dynamic lists the ability to be combined with other
// dynamic lists through operator "+". The second list getting
// added will be attached to the end of the first one.
// PARAMS:	list1.insert(50,1);
//      const List<T> &mylist : A dynamic list with data type
//      T.
// RETURNS:
//      Returns a new list that has list1 and list2 combined
//      in order.
//==========================================================
template <class T>
List<T>     List<T>::operator+ ( const List<T> &mylist ) const
{
    List<T> newlist(mylist);
    for (int i=0; i<size; i++)
        newlist.insert(list[i], i);

    return newlist;
}

//==========================================================
// length
// Simple function that returns the number of values stored
// in the dynamic list.
// PARAMS:
//      void / nothing
// RETURNS:
//      An integer that represents the number of values in
//      the dynamic list.
//==========================================================
template <class T>
int         List<T>::length ( void ) const
{
    return size;
}

//==========================================================
// isEmpty
// Boolean function that returns either true or false for if
// the dynamic list is empty.
// PARAMS:
//      void / nothing
// RETURNS:
//      A boolean true/false for whether or not the dynamic
//      list is empty.
//==========================================================
template <class T>
bool        List<T>::isEmpty ( void ) const
{
    return (size == 0);
}

//==========================================================
// clear
// Clear deletes all of the values of a list, while retaining
// the dynamic list's capacity.
// PARAMS:
//      void / nothing
// RETURNS:
//      Nothing, but clears all values out of the dynamic list.
//==========================================================
template <class T>
void        List<T>::clear ( void )
{
    size = 0;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
// PRIVATE METHODS
//
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//==========================================================
// reallocate
// This function is called whenever a dynamic list needs more
// spaces/capacity to store a value. The function creates a
// temporary list with double the capacity of the last, and
// stores the first list's values in based on their order.
// After, the previous list is deleted for memory and merged
// with the temporary list.
// PARAMS:
//      void / nothing
// RETURNS:
//      Nothing, but makes the class's list have double the
//      amount of capacity for storage.
//==========================================================
template <class T>
void        List<T>::reallocate ( void )
{
    T	*temp;
    int newCapacity = capacity*2;
    temp = new T[newCapacity];
    for (int i=0; i<size; i++)
    {
        temp[i] = list[i];
    }

    delete [] list;
    capacity = newCapacity;
    list = temp;
}
