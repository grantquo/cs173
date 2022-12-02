//===============================================
// Matt Kretchmar
// December 2022
// Stack.cpp
// Implements a Stack ADT using a List ADT via inclusion
//===============================================

//===============================================
// default constructor
//===============================================
template <class T>
			Stack<T>::Stack		( void )
{
	// call to list default constructor implicit
}

//===============================================
// copy constructor
//===============================================
template <class T>
			Stack<T>::Stack		( const Stack<T> &s ) : list(s.list)
{
	// call to list copy constructor explicit above
}

//===============================================
// destructor
//===============================================
template <class T>
			Stack<T>::~Stack		( void ) 
{
	// call to list copy destructor implicit
}

//===============================================
// assignment operator
//===============================================
template <class T>
Stack<T>		Stack<T>::operator=	( const Stack<T> &s ) 
{
	list = s.list;
	return *this;
}

//===============================================
// push
//===============================================
template <class T>
void	Stack<T>::push		( const T & item ) 
{
	// insert at front is more efficient than 
	// insert at back for linked list List
	list.insert(item,0);
}

//===============================================
// pop
//===============================================
template <class T>
T		Stack<T>::pop		( void ) 
{
	if ( list.isEmpty() )
	{
		cout << "Cannot pop from empty stack\n";
		exit(1);
	}
	T ret = list[0];
	list.remove(0);
	return ret;
}

//===============================================
// peek
//===============================================
template <class T>
T		Stack<T>::peek		( void ) 
{
	if ( list.isEmpty() )
	{
		cout << "Cannot peek at empty stack\n";
		exit(1);
	}
	return list[0];
}

//===============================================
// empty
//===============================================
template <class T>
bool	Stack<T>::empty		( void ) 
{
	return list.isEmpty();
}

//===============================================
// size
//===============================================
template <class T>
int		Stack<T>::size		( void ) 
{
	return list.length();
}

//===============================================
// clear
//===============================================
template <class T>
void	Stack<T>::clear		( void ) 
{
	list.clear();
}




