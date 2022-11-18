//====================================================
// Grant Gutterman
// 11-18-22
// List.cpp
// This is the class method implementation file
// for our linked list implementation.
//====================================================

#include <iomanip>
#include <string>

//====================================================
// default constructor
// Main constructor that initializes a linked list
// without arguments.
// PARAMS:
//      none
// RETURNS:
//      Has no returns. Initializes the class with a
//      blank linked list.
//====================================================
template <class T>
            List<T>::List ( void )
{
    head = NULL;
}

//====================================================
// copy constructor
// Copy constructor that takes everything from a linked
// list in its argument and makes a copy of it within
// the class local linked list. If mylist is empty,
// the class's list will be a blank state.
// PARAMS:
//      mylist - Linked list of type T.
// RETURNS:
//      Has no returns. Makes the list given in the
//      function argument identical to the class linked
//      list.
//====================================================
template <class T>
            List<T>::List ( const List<T> &mylist )
{
    Node *mylistPtr;
    Node *ptr;

    if (mylist.head == NULL) // if mylist is empty
    {
        head = NULL;
        return;
    }

    // this->~List();

    mylistPtr = mylist.head;
    head = new Node;
    head->item = mylistPtr->item;

    ptr = head;
    mylistPtr = mylistPtr->next;

    while (mylistPtr != NULL)
    {
        ptr->next = new Node;
        ptr = ptr->next;
        ptr->item = mylistPtr->item;
        mylistPtr = mylistPtr->next;
    }
    ptr->next = NULL;
}

//====================================================
// destructor
// Destructor class implementation that wipes the class's
// memory and resets the linked list to a blank state.
// PARAMS:
//      none
// RETURNS:
//      Has no returns. Deletes all Nodes stored in
//      memory and sets the linked list head to NULL.
//====================================================
template <class T>
            List<T>::~List ( void )
{
    Node *tempPtr;
    Node *ptr = head;
    while (ptr != NULL)
    {
        tempPtr = ptr;
        ptr = ptr->next;
        delete tempPtr;
    }
    head = NULL;
}

//====================================================
// operator=
// This function overloads operator= and sets the class
// linked list equal to the argument's list. The destructor
// is called to ensure that the memory is cleared before
// reassignment.
// PARAMS:
//      mylist - Linked list of type T.
// RETURNS:
//      Returns the class local linked list reassigned
//      to the parameter list.
//====================================================
template <class T>
List<T>     List<T>::operator= ( const List<T> &mylist )
{
    Node *qtr = mylist.head;
    Node *ptr = head;

    this->~List();

    Node *trailPtr = NULL;
    if (qtr != NULL)    // if mylist is not empty
    {
        Node *firstNode = new Node;
        head = firstNode;
        firstNode->item = qtr->item;
        trailPtr = firstNode;
        qtr = qtr->next;

        while (qtr != NULL)
        {
            Node *newNodePtr = new Node;
            newNodePtr->item = qtr->item;
            trailPtr->next = newNodePtr;
            trailPtr = newNodePtr;
            qtr = qtr->next;
        }
    }

    return *this;
}

//====================================================
// to_string
// Function for turning a linked list into a string
// that can be outputted.
// PARAMS:
//      none
// RETURNS:
//      Returns a string of a iostream output, formatted
//      for outputting each value within a linked list.
//====================================================
template <class T>
string      List<T>::to_string ( void ) const
{
    stringstream stream;
    Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->next != NULL)
            stream << ptr->item << " ";
        else
            stream << ptr->item;
        ptr = ptr->next;
    }
    return stream.str();
}

//====================================================
// append
// Appends a new item onto the end of the linked list.
// PARAMS:
//      item = An object of type T.
// RETURNS:
//      Has no returns. The class local linked list
//      will have item attached to the end.
//====================================================
template <class T>
void        List<T>::append ( const T &item )
{
    Node *qtr;
    qtr = new Node;
    qtr->item = item;
    qtr->next = NULL;

    if (head == NULL)         //special case of empty list
        head = qtr;
    else
    {
        Node *ptr;
        ptr = head;

        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = qtr;
    }
}

//====================================================
// operator[]
// Operator "[]" overloading function that gives linked
// lists the ability to call a value by its index number.
// PARAMS:
//      int index: An integer index number from 0-length.
// RETURNS:
//      An object of type T that is in the linked list
//      at the specified index number.
//====================================================
template <class T>
T &         List<T>::operator[] ( int index )
{
    Node *ptr = head;
    int curInd = 0;
    while (ptr->next != NULL)
    {
        if (curInd == index)
            return ptr->item;
        else
        {
            ptr = ptr->next;
            curInd++;
        }
    }
    return temp; // NEEDS ERROR CASE !!!!
}

//====================================================
// insert
// Insertion function that inserts an item at a specific
// index number. All values to the right of the index
// number are shifted to make room for the new item.
// PARAMS:
//      int index: An integer index number from 0-length.
//      item = An object of type T.
// RETURNS:
//      Has no returns. Only adds an object to be stored
//      in the list.
//====================================================
template <class T>
void        List<T>::insert ( const T &item, int index )
{
    Node *frontPtr = head;
    Node *trailPtr = NULL;
    Node *newNodePtr;
    int curInd = 0;

    newNodePtr = new Node;
    newNodePtr->item = item;
    newNodePtr->next = NULL;

    if (head==NULL)     // empty list case
    {
        head = newNodePtr;
        return;
    }
    while (frontPtr != NULL)
    {
        if (curInd == index)
        {
            if (trailPtr == NULL)   // beginning of list case
            {
                head = newNodePtr;
                newNodePtr->next = frontPtr;
                frontPtr = frontPtr->next;
                return;
            }

            trailPtr->next = newNodePtr;    // index != 0 case
            newNodePtr->next = frontPtr;
            frontPtr = frontPtr->next;
            return;
        }
        trailPtr = frontPtr;
        frontPtr = frontPtr->next;
        curInd++;
    }

    if (frontPtr == NULL && curInd == index) // end of list case
    {
        frontPtr = newNodePtr;
        trailPtr->next = newNodePtr;
        return;
    }
    cout << "!!! INVALID INDEX FOR INSERTION !!!" << endl;
    return;
}

//====================================================
// remove
// Removal function that takes a specific index and
// deletes the item from it.
// PARAMS:
//      int index: An integer index number from 0-length.
// RETURNS:
//      Has no returns. Removes an object from the list.
//====================================================
template <class T>
void        List<T>::remove ( int index )
{
    Node *ptr = head;
    Node *trailPtr = NULL;
    int curInd = 0;
    while (ptr->next != NULL && curInd != index)
    {
        trailPtr = ptr;
        ptr = ptr->next;
        curInd++;
    }
    if (ptr != NULL)
    {
        if (ptr == head)
            head = ptr->next;
        else
            trailPtr->next = ptr->next;
        if (ptr->next == NULL)
            ptr->next = trailPtr;
        delete ptr;
    }
    cout << "!!! INVALID INDEX: OUTSIDE OF BOUNDS !!!" << endl;
    return;
}
//====================================================
// operator+
// Operator "+" overloading function that concatenates
// a list given in its parameter to the end of the class
// list.
// PARAMS:
//      mylist - Linked list of type T.
// RETURNS:
//      A new list that has parameter list attached
//      to the end of the class local list.
//====================================================
template <class T>
List<T>     List<T>::operator+ ( const List<T> &mylist ) const
{
    List<T> newlist(mylist);
    Node *ptr = head;
    int curInd = 0;
    while (ptr != NULL)
    {
        newlist.insert(ptr->item, curInd);
        ptr = ptr->next;
        curInd++;
    }
    return newlist;
}

//====================================================
// length
// Length function that calculates the linked list's
// number of items.
// PARAMS:
//      none
// RETURNS:
//      An integer that represents the number of items
//      stored.
//====================================================
template <class T>
int         List<T>::length ( void ) const
{
    Node *ptr= head;
    int total = 0;
    while (ptr != NULL)
    {
        total++;
        ptr = ptr->next;
    }
    return total;
}

//====================================================
// isEmpty
// Simple boolean function returning a true or false
// for whether the linked list is empty.
// PARAMS:
//      none
// RETURNS:
//      A true or false for if the list has no objects.
//====================================================
template <class T>
bool        List<T>::isEmpty ( void ) const
{
    Node *ptr = head;
    return (ptr == NULL);
}

//====================================================
// clear
// Clear function that wipes all objects from the list,
// leaving the list empty.
// PARAMS:
//      none
// RETURNS:
//      Has no return, but calls the destructor to clear
//      items from the list.
//====================================================
template <class T>
void        List<T>::clear ( void )
{
    this->~List();
}
