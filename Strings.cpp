#include <iostream>
using namespace std ;

class Strings
{
	public :

        int Length ( char S1[] )
	{
		int i = -1 ; 
		while ( *( S1+ ++i ) != '\0' ) ;

                return i ;
	}


	int compare ( char S1[] , char S2[] )
	{
		int i = 0 ; 
		while ( S1[i] == S2[i] and S1[i] != '\0' and S2[i] != '\0' )
		{
			i++ ;
		}
                return ( S1[i] - S2[i] ) ;
	}

	string concat ( char S1[] , char S2[] )
	{
		int length1 = Length( S1 ) ;
		int length2 = Length( S2 ) ;

		char* S3 = new char[ length1 + length2 ] ;

		for ( int i = 0 ; i < ( length1 + 1 ) ; i++ )
		{
			S3[ i ] = S1[ i ] ;
		}

		for ( int i = 0 ; i < ( length2 + 1 ) ; i++ )
		{
			S3[ length1 ] = S2[ i ] ;
			length1++ ;
		}
	
		return S3 ;
	}

	string subString ( char S1[] , int start , int length )
	{
		char* T = new char[length] ;

		for ( int i = 0 ; i < length ; i++ )
		{
			T[ i ] = S1[ start + i ] ;
		}

		return T ;
	}

	int matchSubString ( char S1[] , char S2[] )
	{

		int pos = 0 ;

		while ( pos <= ( Length( S1 ) - Length( S2 ) ) )
		{
			int j  = 0 ;
			while ( ( S1[ pos + j ] == S2[ j ] ) and S2[ j ] != '\0' )
			{	
				j++ ; 
			}
			
			if ( S2[ j ] == '\0' )
			{		
				return pos ;
			}

			pos++ ;
		}
	
		return -1 ;
	}
};

int main ( ) 
{
	Strings s1 ;
	char str1[20] = { "Hello " } , str2[20] = { "Guys" } ;
	char b[20] = { "gh"}  ;


	int length = s1.Length ( str1 ) ;
	int compared = s1.compare ( str1 , str2 ) ;


	cout << "The length of the given string is: " << length << endl ;
	
	if ( compared > 0 )
	{
		cout << "The first string is greater." << endl ;
	}
	else if ( compared < 0 )
	{
		cout << "The second string is greater." << endl ;
	}
	else 
	{
		cout << "The first and second string is equal." << endl ;
	}

	//cout << s1.concat( str1 , str2 ) << endl ;
	//cout << s1.subString( str1 , 0 , 3 ) << endl ;
	cout << s1.matchSubString( str1 , b ) << endl ;

	return 0 ;

}
