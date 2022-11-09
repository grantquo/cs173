//============================================
// Grant Gutterman
// 11-19-22
// List.cpp
// This is the class method implementation file
// for our linked list implementation.
//============================================

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
// destructor
// This is wrong fix later.
//============================================
template <class T>
            List<T>::~List ( void )
{
    // code here
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

    if ( head == NULL )         //special case of empty list
        head = qtr;
    else
    {
        Node *ptr;
        ptr = head;

        while ( ptr->next != NULL )
            ptr = ptr->next;
        ptr->next = qtr;
    }
}
/*
1. delcare qtr
2. allocate memory for qtr
3. put value in qtr
4. put qtr->next NULL
5. declare ptr
6. traverse ptr to last node
7. fix last node link
*/

// common problem: if you are doing something at the
// front of back of the linked list, those are special
// cases. if you dont treat them like so, you will get
// a segmentation fault / bad pointer dereference error
