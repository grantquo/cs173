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
//
// RETURNS:
//
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
// This function takes an existing list and copies it to
// another list.
// PARAMS:
//
// RETURNS:
//
//==========================================================
template <class T>
            List<T>::List ( const List<T> &mylist )
{
    // default constructor
    size = mylist.size;
    capacity = mylist.capacity;
    list = new T[capacity];
    // copy constructor
    for (int i=0; i<capacity; i++)
        list[i] = mylist.list[i];

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
            List<T>::~List ( void )
{
    delete [] list;
    capacity = 0;
    size = 0;
}

//==========================================================
// operator=newlist
// This gives functionality for the assignment operator "=",
// allowing for dynamics lists to be reassigned to other
// dynamic lists, while the deallocated data is deleted.
// PARAMS:
//
// RETURNS:
//
//==========================================================
template <class T>
List<T>     List<T>::operator= ( const List<T> &mylist )
{
    size = mylist.size;
    capacity = mylist.capacity;
    list = new T[capacity];
    // copy constructor
    for (int i=0; i<capacity; i++)
        list[i] = mylist.list[i];
    // List<T> list2 = List(mylist);
    // cout<<list2.to_string()<<endl;
    // // size = mylist.size;
    // // capacity = mylist.capacity;
    // size = list2.size;
    // capacity = list2.capacity;
    return *this;
}

//==========================================================
// to_string
// This function allows for lists to be outputted through
// strings using cout, diaplying all of their values.
// PARAMS:
//
// RETURNS:
//
//==========================================================
template <class T>
string      List<T>::to_string ( void ) const
{
    stringstream stream;    // int mylistCapacity = mylist.capacity;
    // int mylistSize = mylist.size;

    for ( int i = 0; i < size; i++ )
		stream << list[i] << " ";
	return stream.str();
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
void        List<T>::append ( const T &item )
{
    if (size == capacity)
    {
        // if list is full
        reallocate();
    }
    // if list isn't full
    list[size] = item;
    size = size + 1;

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
T &         List<T>::operator[] ( int index )
{
    return list[index];
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
void        List<T>::insert ( const T &item, int index )
{
    if (size == capacity)
    {
        // if list is full
        reallocate();
    }
    // if list isn't full

    temp = new T[capacity];
    T curItem;

    if (index > 0)          // if insertion isnt at beginning
    {
        for (int i=0; i<=index-1; i++)
        {
            temp[i] = list[i];
            // cout << " ======= item: " << curItem << " added to index: " << i << endl;
        }
        // cout << "NEW ITEM BEING ADDED !!!" << endl; //item at index being added
        temp[index] = item;
        T curItem;

        for (int i=index+1; i<size; i++)    //all items to right of index being added
        {
            temp[i] = list[i];
            // cout << " $$$$$$$ item: " << curItem << " being added to index: " << i << endl;
        }
    }

    else if (index == 0)        // if insertion is at the beginning
    {
        temp[0] = item;
        for (int i=1; i<size; i++)
        {
                temp[i] = list[i];
                // cout << " $$$$$$$ item: " << curItem << " being added to index: " << i << endl;
        }
    }


    delete [] list;

    // cout << "After " << item << " was added at " << index << " , this is list: " << endl;

    for (int i=0; i<capacity; i++)
    {
        list[i] = temp[i];
        // cout << "Item: " << list[i] << " Index: " << i << endl;
    }
    if (index == size){
            size += 1;
    }
    delete [] temp;
}

//==========================================================
// remove
// Remove allows for dynamic lists to have a value deleted
// from them at a specified index number. The total capacity
// of the list after a remove is unaffected.
// PARAMS:
//
// RETURNS:    size = size-1;

//
//==========================================================
template <class T>
void        List<T>::remove ( int index )
{

    cout << "New list after removal: " << endl;

    for (int ind = index+1; ind < size; ind++)
        list[ind] = list[ind+1];
    size = size-1;
}

//==========================================================
// operator+
// Gives dynamic lists the ability to be combined with other
// dynamic lists through operator "+". The second list getting
// added will be attached to the end of the first one.
// PARAMS:	list1.insert(50,1);

//
// RETURNS:
//
//==========================================================
template <class T>
List<T>     List<T>::operator+ ( const List<T> &mylist ) const
{
    List<T> newlist(mylist);
    // for (int i=0; i<mylist.size; i++)
    //     newlist.append(mylist.list[i]);

    return newlist;
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
int         List<T>::length ( void ) const
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
bool        List<T>::isEmpty ( void ) const
{
    return (size == 0);
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
void        List<T>::clear ( void )
{
    list = NULL;
    delete [] list;
    size = 0;
    list = new T[capacity];
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
// PRIVATE METHODS
//
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	//cout << "list2 = " << list2.to_string() << endl;

//==========================================================
// reallocate
// This function is called whenever a dynamic list is full
// and needs to make space for more items. It first creates
// a new dynamic list with double the amount of capacity,
// then copies every value from the first into the second.
// The old, smaller li    // for (int j=0; j<capacity; j++)
    // {
    //     item = list[j];
    //     cout << "Item: " << item << " at index: " << j << endl;
    // }st is then deleted for memory and
// capacity is adjusted for the new one.
// PARAMS:
//
// RETURNS:
//
//==========================================================
template <class T>
void        List<T>::reallocate ( void )
{
    // default constructor
    int newCapacity = capacity*2;
    temp = new T[newCapacity];
    T item;
    for (int i=0; i<size; i++)
    {
        if (list[i] != 0)
        {
            item = list[i];
            // cout << "in temp item: " << item << " in index: " << i << endl;
            temp[i] = item;
        }
    }
    // cout << "Temp Built!" << endl;

    delete [] list;
    capacity = newCapacity;
    list = new T[capacity];

    for (int i=0; i<size; i++)      // temp and list merge
        list[i] = temp[i];

    delete [] temp;
    cout << " @@@@ " << "Reallocated!" << " @@@@ " << endl;
    // cout << "THIS IS IN LIST: " << endl;

    // for (int j=0; j<capacity; j++)
    // {
    //     item = list[j];
    //     cout << "Item: " << item << " at index: " << j << endl;
    // }
}
