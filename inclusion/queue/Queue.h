//===============================================
// Matt Kretchmar
// December 2022
// Queue.h
// Implements a Queue ADT using a List ADT via inclusion
//===============================================

#ifndef QUEUE
#define QUEUE

#include "List.h"

template <class T>
class Queue
{
protected:
	List<T>     list;
public:
				Queue		( void );
				Queue		( const Queue<T> &s );
			   ~Queue		( void );
	Queue<T>	operator=	( const Queue<T> &s );
	void		enqueue		( const T &item );
	T			dequeue		( void );
	bool		empty		( void );
	int			size		( void );
	T			peek		( void );
	void		clear		( void );
};

#include "Queue.cpp"
#endif 

