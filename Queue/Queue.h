#include <iostream>

using namesapce std ;

template < class T > class Queue
{
    private :
	T* queue ;
	int rear ;
	int front ;
	int maxSize ;

    public :
	Queue( int ) ;
	~Queue( ) ;
	bool isEmpty( ) ;
	bool isFull( ) ;
	void enqueue( T ) ;
	void dequeue( ) ;
	T peek( ) ;  
	double status( ) ;
} ;