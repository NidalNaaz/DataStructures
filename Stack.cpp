#include <iostream>
#include <Stack.h>

	template < class T >
	Stack < T > :: Stack( int size ) 
    	{
	        maxSize = size ;
	        stack = new T[ maxSize ] ; 
		top = -1 ;
        }

	template < class T >
     	Stack < T > :: ~Stack( ) 
	{
        	delete[	] stack ;
    	}


	template < class T >
	bool Stack< T > :: isEmpty( ) 
	{
        	return top == -1 ;
    	}


	template < class T >
	bool Stack< T > :: isFull( )
	{
        	return top == maxSize - 1;
    	} 
	

	template < class T >
	void Stack< T > :: push( T x ) 
	{
        	if ( !isFull( ) ) 
		{
            		top++ ;
            		stack[ top ] = x ;
        	} 
		else 
		{
            		cout << "Stack overflow! " << endl ;
        	}
    	}


	template < class T >
	void Stack< T > :: pop( ) 
	{
         	if ( !isEmpty( ) ) 
		{
            		top-- ;
        	} 
		else 
		{
            	cout << "Stack underflow! " << endl ;
        	}
    	}


	template < class T >
	int Stack< T > :: peek( ) 
	{
        	if ( !isEmpty( ) ) 
		{
            		return stack[ top ] ;
        	} 
		else 
		{
            		cout << "Stack is empty! " << endl ;
            		return -1 ;
        	}
   	}


	template < class T >
	int Stack< T > :: status( ) 
	{
        	return ( ( top + 1 ) * 100) / maxSize ;
    	}

