#include<iostream>
#include<ostream>


template < class T >
class Array 
{
    private:
    int LB , UB ;
    T A[ 100 ]  ;

    public:
  
    Array( ) ;

    Array( int , int , T[ ] ) ;


    void insertAtBeginning( T ) ;
    void insertAtEnd( T ) ;
    void insertAtIndex( T , int ) ;

    void deleteAtBeginning( ) ;
    void deleteAtEnd( ) ;
    void deleteAtIndex( int ) ;

    int linearSearch( T ) ;
    int binarySearch( T ) ;

    void selectionSort( ) ;
    void BubbleSort( ) ;
    void insertionSort( ) ;
    void quickSort ( int , int ) ;

    void swap ( int , int ) ; 
    int partition ( int , int ) ;
    
    void rotateClockwise ( int ) ;
    void rotateAntiClockwise ( int ) ; 
    void distictElements ( ) ;
    void frequecyElements ( ) ;


    template < class U >
    friend ostream& operator<< ( ostream& , const Array<U>& ) ;
} ;
