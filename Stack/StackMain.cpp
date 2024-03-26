#include <iostream>
#include "Stack.cpp"

using namespace std ;

int main ( )
{
    int max ;
    string choice ;

    cout << "Enter max size for stack: " << endl ; 
    cin >> max ;

    Queue< int > stack( max ) ;

    do
    {
	    int value ;
    
	    cout << "Enter the value to stack: " << endl ;
	    cin >> value ;
    
	    stack.push( value ) ;
    
	    cout << "Would you like to continue? " << endl ;
	    cin >> choice ;

    } while ( choice == "yes" ) ;

    do
    {
	    cout << "Would you like to pop? " << endl ;
	    cin >> choice ;

	    stack.pop( ) ;

    } while ( choice == "yes" ) ;

    stack.status( ) ;

    return 0 ; 
}
 