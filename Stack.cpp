#include <iostream>
#include <ostream>

using namespace std;

template < typename T > class Stack 
{
	private:
    	T* stack ;	
    	int top ;
    	int maxSize ;

	public :
	Stack( ) ;
	~Stack( ) ;
	bool isEmpty( ) ;
	bool isFull( ) ;
	void push( T ) ;
	void pop( ) ;
	int peek( ) ;
	int status( ) ;

	template < class U >
	friend ostream& operator << ( ostream& , stack<U> ) ;
} ;

template < class T >
{
	Stack < T > :: Stack( int ) 
    	{
	        maxSize = size ;
	        stack = new T[ maxSize ] ; 
		top = -1 ;
        }


     	Stack < T > :: ~Stack( ) 
	{
        	delete[	] stack ;
    	}


	template < class T >
	bool Stack( ) :: isEmpty( ) 
	{
        	return top == -1 ;
    	}


	template < class T >
	bool Stack( ) :: isFull( )
	{
        	return top == maxSize - 1;
    	} 
	

	template < class T >
	void Stack( ) :: push( T x ) 
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
	void Stack( ) :: pop( ) 
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
	int Stack( ) :: peek( ) 
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
	int Stack( ) :: status( ) 
	{
        	return ( ( top + 1 ) * 100) / maxSize ;
    	}
	
	template < class U >
	ostream& operator << ( ostream& os , Stack < U > St ) 
	{
		int i ;
		os << endl ; 
		
} ;

int main( ) 
{
    int max ;

    cout << "Enter max size for the stack: " << endl ;
    cin >> max ;

    Stack stack( max ) ;

    cout <<  stack.isFull( ) << endl ;
    cout <<  stack.isEmpty( ) << endl ;

    stack.push( 1 ) ;
    stack.push( 2 ) ;
    stack.push( 3 ) ;
    stack.push( 4 ) ;
    stack.push( 5 ) ;
    stack.push( 6 ) ; // Stack overflow!

    cout << "Status: " << stack.status( ) << "%" << endl ;

    cout <<  stack.isFull( ) << endl ;
    cout <<  stack.isEmpty( ) << endl ;

    stack.pop( ) ;
    stack.pop( ) ;
    stack.pop( ) ;
    stack.pop( ) ;
    stack.pop( ) ; 
    stack.pop( ) ; // Stack underflow!

    cout << "Status: " << stack.status( ) << "%" << endl ;

    cout <<  stack.isFull( ) << endl ;
    cout <<  stack.isEmpty( ) << endl ;

    return 0 ;
}

			

