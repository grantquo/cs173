//==========================================================
// Grant Gutterman
// 11-8-22
// List.cpp
// This file contains the class implementation for the dynamic
// list array class.
//==========================================================

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
    cout << size << endl;
    cout << capacity << endl;
    // copy constructor
    for (int ind = 0; ind < capacity; ind++)
    {
        T value = mylist[ind];
        list[ind] == value;
    }

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
List<T>     List<T>::operator= ( const List<T> &mylist )
{
    delete [] list;
    list = mylist;
    return *list;
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
    stringstream stream;
    for ( int i = 1; i <= size; i++ )
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
    list[size+1] = item;
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

    cout << "This is in list so far: " << endl;
    for (int ind=0; ind < capacity; ind++)
        cout << list[ind] << endl;

    if (index > 0)          // if insertion isnt at beginning
    {
        for (int i=0; i<=index-1; i++)
        {
            curItem = list[i];
            temp[i] = curItem;
            cout << " ======= item: " << curItem << " added to index: " << i << endl;
        }
        cout << "NEW ITEM BEING ADDED !!!" << endl; //item at index being added
        temp[index] = item;
        T curItem;

        for (int i=index+1; i<size; i++)    //all items to right of index being added
        {
            curItem = list[i];
            temp[i] = curItem;
            cout << " $$$$$$$ item: " << curItem << " being added to index: " << i << endl;
        }
    }



    else if (index == 0)        // if insertion is at the beginning
    {
        temp[0] = item;
        for (int i=1; i<size; i++)
        {
                curItem = list[i];
                temp[i] = curItem;
                cout << "+++++++ item: " << curItem << " being added to index: " << i << endl;
        }
    }

    cout << "this is temp: " << endl;
    for (int qwery = 0; qwery<capacity; qwery++)
        cout << temp[qwery] << endl;

    delete [] list;
    list = temp;
    size = size + 1;
    delete [] temp;
    temp = NULL;
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
void        List<T>::remove ( int index )
{
    for (int ind = index; ind < size; ind++)
    {
        list[ind] = list[ind+1];
    }
    size = size - 1;
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
/*
template <class T>
List<T>     List<T>::operator+ ( const List<T> &mylist ) const
{
    // idfk
}
*/
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
            // cout << "item: " << item << " in index: " << i << endl;
            temp[i] = item;
        }
    }

    // for (int i=0; i<newCapacity; i++)
        // cout << "in temp: " << temp[i] << " in index: " << i << endl;

    delete [] list;
    list = NULL;
    capacity = newCapacity;
    list=temp;
    delete [] temp;
    temp = NULL;
    cout << " @@@@ " << "Reallocation Completed!" << " @@@@ " << endl;
    for (int j=0; j<capacity; j++)
    {
        item = list[j];
        cout << "in list item: " << item << " at index: " << j << endl;
    }

}
