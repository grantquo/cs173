//============================================
// Grant Gutterman
// 11-18-22
// List.cpp
// This is the class method implementation file
// for our linked list implementation.
//============================================

#include <iomanip>
#include <string>

/*

To do:

1. copy constructor debugging
2. remove needs to be finished in built
3. insert cases - beginning, middle, end of list
4. operator+ built

*/

//============================================
// default constructor
// creates an empty list
//============================================
template <class T>
            List<T>::List ( void )
{
    head = NULL;
}

//============================================
// copy constructor
//============================================
template <class T>
            List<T>::List ( const List<T> &mylist )
{
    Node *mylistPtr;
    Node *ptr;

    if (mylist.head == NULL)
    {
        head = NULL;
        return;
    }

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

//============================================
// destructor
//============================================
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

//============================================
// operator=
//============================================
/*
template <class T>
List<T>     List<T>::operator= ( const List<T> &mylist )
{

}
*/
//============================================
// to_string
//============================================
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

//============================================
// append
// Appends a new item onto the end of the list
//============================================
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

//============================================
// operator[]
//============================================
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

//============================================
// insert
//============================================
template <class T>
void        List<T>::insert ( const T &item, int index )
{
    // need a case for beginning, middle, and end insertions
    // Node *ptr = head;
    // Node *qtr;
    // qtr = new Node;
    // qtr->item = item;
    //
    // if (index == 0)
    // {
    //     ptr->item = qtr->item;
    //     ptr->
    // }
    Node *frontPtr = head;
    Node *trailPtr = NULL;
    Node *newNodePtr;
    int curInd = 0;

    newNodePtr = new Node;
    newNodePtr->item = item;
    newNodePtr->next = NULL;

    if (head==NULL)
    {
        head = newNodePtr;
        return;
    }
    else
    {
        while (frontPtr != NULL)
        {
            if (curInd == index)
            {
                if (trailPtr == NULL)
                {
                    head = newNodePtr;
                    newNodePtr->next = frontPtr;
                    frontPtr = frontPtr->next;
                    return;
                }
                trailPtr->next = newNodePtr;
                newNodePtr->next = frontPtr;
                frontPtr = frontPtr->next;
                return;
            }
            trailPtr = frontPtr;
            frontPtr = frontPtr->next;
            curInd++;
        }
        if (frontPtr == NULL && curInd == index)
        {
            frontPtr = newNodePtr;
            trailPtr->next = newNodePtr;
            return;
        }

    }
    cout << "!!! INVALID INDEX FOR INSERTION !!!" << endl;
    return;
}

//============================================
// remove
//============================================
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

//============================================
// operator+
//============================================
/*
template <class T>
List<T>     List<T>::operator+ ( const List<T> &mylist ) const
{
    Node *ptr = head;
    Node *qtr = mylist.head;

    while (ptr->next != NULL) // get to the end of list 1
        ptr = ptr->next;

    while (qtr->next != NULL)
    {
        ptr = ptr->next;
        ptr->item = qtr->item;
        qtr = qtr->next;
    }
    ptr->item = qtr->item;
    ptr->next = NULL;

    return; //need to figure out return setup

}
*/

//============================================
// length
//============================================
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

//============================================
// isEmpty
//============================================
template <class T>
bool        List<T>::isEmpty ( void ) const
{
    Node *ptr = head;
    return (ptr == NULL);
}

//============================================
// clear
//============================================
template <class T>
void        List<T>::clear ( void )
{
    Node *ptr = head; // PROBABLY DOESNT WORK YET !!!
    ptr = NULL;
}
