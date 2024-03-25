#include <iostream>

using namespace std;

template < typename T > class Stack 
{
	private:
    	T* stack ;	
    	int top ;
    	int maxSize ;

	public :
	Stack( int ) ;
	~Stack( ) ;
	bool isEmpty( ) ;
	bool isFull( ) ;
	void push( T ) ;
	void pop( ) ;
	int peek( ) ;
	int status( ) ;
} ;
