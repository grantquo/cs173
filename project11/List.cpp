//============================================
// Grant Gutterman
// 11-18-22
// List.cpp
// This is the class method implementation file
// for our linked list implementation.
//============================================

#include <iomanip>
#include <string>

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
    Node *ptr = head;
    Node *qtr = mylist.head;

    // if mylist is empty
    if (qtr == NULL)
    {
        ptr = NULL;
        return;
    }
    while (qtr != NULL)
    {
        ptr->item = qtr->mylist.item;
        ptr = ptr->next;
        qtr = qtr->mylist.next;
    }
    return;
}

//============================================
// destructor
// This is wrong fix later.
//============================================
template <class T>
            List<T>::~List ( void )
{

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
    Node *ptr = head;
    Node *qtr;
    qtr = new Node;
    qtr->item = item;

    if (index == 0)
    {
        ptr->item = qtr->item;
        ptr->
    }
}

//============================================
// remove
//============================================
/*
template <class T>
void        List<T>::remove ( int index )
{

}
*/

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
/*
template <class T>
void        List<T>::clear ( void )
{
    Node *ptr = head;
    ptr = NULL;
}
*/
