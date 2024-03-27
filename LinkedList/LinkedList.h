#include <iostream>

template < typename T > class Node
{
	T data ;
	Node* link ;

	public :
	Node (T) ;
	
	void setData(T) ;    
   	T getData() ;
  
	void setLink(Node <T>*) ;
	Node<T>* getLink( ) ;

} ;	


template < typename T > class LinkedList
{
	Node <T>* head ;

	public :

	LinkedList() ;
	void createlist() ;
	~LinkedList() ;
	
	void traverse( ) ;
	void display( ) ;

	void insertAtBeginning(T) ;
	void insertBeforeKey(T,T) ;
	void insertAfterKey(T,T) ;
	void insertAtEnd(T) ;

	void deleteAtBeginning( ) ;
	void deleteKey(T) ;
	void deleteAtEnd( ) ;

	void concatLists(LinkedList);
	Node<T>* search(T);
	void reverseList( );
	void reverseTraversal( );
	void sort( );
	Node<T>* findMinimum(Node<T>*) const;
} ;
