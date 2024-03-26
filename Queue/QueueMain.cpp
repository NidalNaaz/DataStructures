#include <iostream>
#include "Queue.cpp"

using namespace std ;

int main ( )
{
    int max ;
    string choice ;

    cout << "Enter max size for queue: " << endl ; 
    cin >> max ;

    Queue< int > queue( max ) ;

    do
    {
	    int value ;

	    cout << "Enter the value to enqueue: " << endl ;
	    cin >> value ;

	    queue.enqueue( value ) ;

	    cout << "Would you like to continue? " << endl ;
	    cin >> choice ;

    } while ( choice == "yes" ) ;

    do
    {
	    cout << "Would you like to dequeue? " << endl ;
	    cin >> choice ;

	    queue.dequeue( ) ;

    } while ( choice == "yes" ) ;

    queue.rollBack( ) ;
    queue.status( ) ;    

    return 0 ; 
}
 


	