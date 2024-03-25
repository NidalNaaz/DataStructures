
#include <iostream>
#include <Stack.cpp>

int main( ) 
{
    int max ;

    cout << "Enter max size for the stack: " << endl ;
    cin >> max ;

    Stack< int > stack( max ) ;

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

			

