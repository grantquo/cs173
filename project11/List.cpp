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
// the class local linked list.
// PARAMS:
//      none
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

    this->~List();

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
// Appends a new item onto the end of the list
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
//====================================================
template <class T>
void        List<T>::remove ( int index )
{
    Node *ptr = head;
    Node *trailPtr = NULL;
    int curInd = 0;
    while (ptr->next != NULL)
    {
        if (curInd == index){
            trailPtr->next = ptr->next;
        }
        trailPtr = ptr;
        ptr = ptr->next;
        curInd++;
    }
}

//====================================================
// operator+
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
//====================================================
template <class T>
bool        List<T>::isEmpty ( void ) const
{
    Node *ptr = head;
    return (ptr == NULL);
}

//====================================================
// clear
//====================================================
template <class T>
void        List<T>::clear ( void )
{
    this->~List();
}
