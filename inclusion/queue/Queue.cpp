//===============================================
// Matt Kretchmar
// December 2022
// Queue.cpp
// Implements a Queue ADT using a List ADT via inclusion
//===============================================

//===============================================
// default constructor
//===============================================
template <class T>
			Queue<T>::Queue		( void )
{
	// call to list default constructor implicit
}

//===============================================
// copy constructor
//===============================================
template <class T>
			Queue<T>::Queue		( const Queue<T> &q ) : list(q.list)
{
	// call to list copy constructor explicit above
}

//===============================================
// destructor
//===============================================
template <class T>
			Queue<T>::~Queue		( void ) 
{
	// call to list copy destructor implicit
}

//===============================================
// assignment operator
//===============================================
template <class T>
Queue<T>		Queue<T>::operator=	( const Queue<T> &q ) 
{
	list = q.list;
	return *this;
}

//===============================================
// enqueue
//===============================================
template <class T>
void	Queue<T>::enqueue	( const T & item ) 
{
	// insert at front is more efficient than 
	// insert at back for linked list List
	list.append(item);
}

//===============================================
// dequeue
//===============================================
template <class T>
T		Queue<T>::dequeue	( void ) 
{
	if ( list.isEmpty() )
	{
		cout << "Cannot dequeue from empty Queue\n";
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
T		Queue<T>::peek		( void ) 
{
	if ( list.isEmpty() )
	{
		cout << "Cannot peek at empty Queue\n";
		exit(1);
	}
	return list[0];
}

//===============================================
// empty
//===============================================
template <class T>
bool	Queue<T>::empty		( void ) 
{
	return list.isEmpty();
}

//===============================================
// size
//===============================================
template <class T>
int		Queue<T>::size		( void ) 
{
	return list.length();
}

//===============================================
// clear
//===============================================
template <class T>
void	Queue<T>::clear		( void ) 
{
	list.clear();
}




