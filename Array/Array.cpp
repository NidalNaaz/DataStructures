#include "Array.h"


template < class T >
Array< T > :: Array( ) 
{
    LB = 1 ;
    UB = 0 ;
}


template < class T >
Array < T > :: Array( int lowerBound , int upperBound , T x[ ] ) 
{
    LB = lowerBound ;
    UB = upperBound ;

    for ( int i = LB ; i <= UB ; i++ ) 
    {
        A[ i ] = x [ i - LB ];
    }
}




template < class T >
void Array < T > :: insertAtBeginning( T key ) 
{
    UB = UB + 1 ;
    int k = UB - 1 ;
    
    while ( k >= LB )
    {
        A[ k + 1 ] = A[ k ] ;
        k-- ;
    }
    A[ LB ] = key ;
}


template < class T >
void Array < T > :: insertAtEnd( T key ) 
{
    UB = UB + 1 ;
    A[ UB ] = key ;
}


template < class T >
void Array < T > :: insertAtIndex( T key , int position ) 
{
    UB = UB + 1 ;
    int k = UB - 1 ;
    
    while ( k >= position )
    {
        A[ k + 1 ] = A[ k ] ;
        k-- ;
    }
    A[ LB ] = key ;
}


template < class T >
void Array < T > :: deleteAtBeginning( )
{
    LB = LB + 1 ;
	
}


template<class T>
void Array < T > :: deleteAtEnd( )
{
    UB = UB - 1 ;
	
}


template < class T >
void Array < T > :: deleteAtIndex( int position ) 
{
 
    if ( LB <= position and UB >= position )
    {
	 k = position + 1 ;

	 while ( k <= UB )
         {
             A[ k - 1 ] = A[ k ] ;
	     k++ ;	
	 }

         UB-- ;
    }

    else
    {
         cout << "Out Of Bound. " << endl ;
    }
	

}


template < class T >
int Array < T > :: linearSearch( T key )
{
    int index = -1 ;
    int i = LB ;

    while ( i <= UB )
    {
        if ( A[ i ] == key )
        {
            index = i ;
            break ;
        }

        i++ ;
    }
    return index ;
}


template < class T >
int Array < T > :: binarySearch( T key )
{
    int left = LB ;
    int right = UB ;
    int middle = ( ( left + right ) / 2 ) ;

    while ( left <= right )
    {
	int middle = ( ( left + right ) / 2 ) ;
        
        if ( A[ middle ] > key )
        {
           right = middle - 1 ;
        }

        else if ( A[ middle ] < key )
        {
            left = middle + 1 ;
        }

        else 
	{
	    return mid ;
        }

    return -1 ; 
    }
}

template < class T >
void Array < T > :: selectionSort( )
{
    for ( int i = LB ; i < UB ; i++ )
    {
	int min = i ;

	for ( int j = i + 1 ; j <= UB ; j++ )
	{
	    if ( A[ j ] < A[ min ] )
	    {
	        min = j ;
            }
	}
		

        if ( min != i )
	{
	    swap( i , min ) ;
	}

    }
}


template < class T >
void Array < T > :: bubbleSort( )
{
    for ( int i = LB ; i < UB ; i++ )
    {
	for ( int j = LB ; j < ( UB + LB - i ) ; j++ )
	{
	    if (A[j]>A[j+1])
	    {
		swap(j,j+1);
	    }
	}
    }
}


template < class T >
void Array < T > :: insertionSort( )
{
    int i ;
    i = LB + 1 ;

    while ( i <= UB )
    {
	T key = A[ i ] ;
	int j ;
	j = i - 1 ;
		
	while ( j >= LB and A[ j ] > key )
	{
	    A[ j + 1 ] = A[ j ] ;
	    j = j - 1 ;
	}
	
	A[ j + 1 ] = key ;
	i = i + 1 ;
    }
}


template < class T >
int Array < T > :: partition( int LB , int UB )
{
    int j = LB - 1 ;
    T pivot = A[ UB ] ;
    int i = LB ;
	
    while ( i <= UB - 1 )
    {
	if ( A[ i ] < pivot )
	{
	    j = j + 1 ;
	    swap ( i , j ) ;
	} 
	
 	i += 1 ;	
    }

    swap( j + 1 , UB ) ;
    return j + 1 ; 
}




template < class T >
void Array < T > :: quickSort( int LB , int UB )
{
    if ( LB < UB )
    {
	int p = partition( LB , UB ) ;
	quickSort( LB , p - 1 ) ;
	quickSort( p + 1 , UB ) ;	
    }
}


template < class T >
void Array < T > :: swap( int p , int q )
{
	T t = A[ p ] ;
	A[ p ] = A[q ] ;
	A[ q ] = t ;
}


template < class T >
void Array < T > :: rotateClockwise ( int pos )
{
    cout << "Rotated clockwise: " << endl ;
    for ( int i = 0 ; i < pos ; i++ )
    {
	T temp = A[ UB ] ;
	for ( int j = UB ; j > 0 ; j-- )
	{
	    A[ j ] = A[ j - 1 ] ;
	} 
        
	A[ LB ] = temp ;
    }
}


template < class T >
void Array < T > :: rotateAntiClockwise ( int pos )
{
    cout << "Rotated Anti - clockwise: " << endl ;
    for ( int i = LB ; i <= pos ; i++ )
    { 
	T temp = A[ LB ] ;
	for ( int j = LB ; j <= UB ; j++ )
	{ 
	    A[ j ] = A[ j + 1 ] ;
	}
	
       	A[ UB ] = temp ;
    }
}


template < class T >
void Array < T > :: distinctElements( )
{
    for ( int i = 0 ; i < UB ; i++ )
    {
	int count = 0 ;
	for ( int j = 0 ; j < UB ; j++ )
	{
	     if ( A[ i ] == A[ j ] )
	     {
		 count += 1 ;
	      }
	}
	
	if ( count == 1 )
	{
	   cout << A[ i ] << " " ;	
	}		
     }
}


template < class T >
void Array < T > :: frequency( )
{
    int i;
    int count = 1 ;

    quickSort ( LB , UB ) ;
    cout << "Element " << "	" << " Frequency " << endl ;
    for ( i = LB ; i <= UB ; i++ )
    {
  	if ( A[ i ] == A[ i + 1 ] )
        {
	   count += 1 ;	
	}	
	
        else
	{
	    cout << A[ i ] <<"		" << count << endl ;
            count=1;
	}
    }
}



template < class U >
ostream& operator<< ( ostream& os , const Array<U>& M ) 
{
    os << endl ;
    for ( int i = M.LB ; i <= M.UB ; i++ ) 
    {
        os << M.A[i] << " " ;
    }
    os << endl ;
    return os ;
}

