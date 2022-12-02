//===============================================
// Matt Kretchmar
// December 2022
// Stack.h
// Implements a Stack ADT using a List ADT via inclusion
//===============================================

#ifndef STACK
#define STACK

#include "List.h"

template <class T>
class Stack
{
private:
	List<T>     list;
public:
				Stack		( void );
				Stack		( const Stack<T> &s );
			   ~Stack		( void );
	Stack<T>	operator=	( const Stack<T> &s );
	void		push		( const T &item );
	T			pop			( void );
	bool		empty		( void );
	int			size		( void );
	T			peek		( void );
	void		clear		( void );
};

#include "Stack.cpp"
#endif 

