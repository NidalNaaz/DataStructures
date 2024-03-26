#include <iostream>

using namespace std ;

template < class T > 
Queue < T > :: Queue( int size )
{
    maxSize = size ;
    queue = new T[ maxSize ] ;
    rear = -1 ;
    front = 0 ;
}


template < class T > 
Queue < T > :: ~Queue( ) 
{
    delete[ ] queue ;
}

template < class T > 
bool Queue < T > :: isEmpty( ) 
{
    return front == 0 ;
}

template < class T > 
bool Queue < T > :: isFull( ) 
{
    return rear == maxSize ;
}

template < class T > 
void Queue < T > :: enqueue( T x )
{
    if ( !isFull )
    {
	rear++ ;
	queue[ rear ] = x ;
    }
    else 
    {
	cout << "Queue overflow! " << endl ;
    }
}


template < class T > 
void Queue < T > :: dequeue( ) ;
{
    if ( !isEmpty )
    {
	front++ ;
    }
    else 
    {
	cout << "Queue underflow! " << endl ;
    }
}

template < class T > 
T Queue < T > :: rollBack( ) ;
{
    if ( front > rear )
    {
	front = 0 ;
	rear = -1 ;
    }
}

template < class T > 
T Queue < T > :: peek( ) ;
{
    if ( !isEmpty )
    {
	return queue[ rear ] ;
    }
    else 
    {
	cout << "Queue empty! " << endl ;
	return -1 ;
    }
}

template < class T > 
double Queue < T > :: status( ) 
{
    return ( ( rear + 1 ) * 100 ) / maxSize ;
} 

