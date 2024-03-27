#include < iostream >
#include < LinkedList.h >

using namespace std;

    template < class T >
	Node <T> :: Node (T data) : data(data), link(nullptr) {}   //re-visit


    template < class T >
	void Node <T> :: setData(T x) 
    {
        this->data = x;
    }

    template < class T >
	T Node <T> :: getData() 
    {
        return data;
    }

    template < class T >
	void Node <T> :: setLink(Node <T>* link) 
    {
        this->link = link ;
    }

    template < class T >
	Node <T>* Node <T> :: getLink( ) 
    {
        return link ;
    }


template < class T >
    LinkedList<T> :: LinkedList( ) : head(nullptr) {}

template < class T >
    void LinkedList<T> :: createList( ) 
    {            
        char choice ;

        do {

                T x ;

                cout << "Enter data: ";
                cin >> x;

                Node <T>* node = new Node <T>(x);

                if (head == nullptr)
		{
                    head = node ;
		}

                else 
		{
                	Node <T>* current = head;
                	while (current->getLink() != nullptr) {
                    	current = current->getLink();
                }
                
		     current->setLink(node);
            }

               cout << "Do you want to add more? (y/n): " ;
               cin >> choice ;

        } while (choice == 'y' || choice == 'Y') ;
    }

template < class T >
    LinkedList<T> ::  ~LinkedList() {
        Node <T>* current = head;
        while (current != nullptr) {
            Node <T>* temp = current;
            current = current->getLink();
            delete temp;
        }
      
       head = nullptr ;
    }


template < class T >
    void LinkedList<T> :: display( )
    {
        Node<T>* p = head ;
	while ( p != NULL )
	{
	    cout << p->getData() << endl  ;
	    p = p-> getLink( ) ;
 	}
    }


template < class T >
    void LinkedList<T> :: insertAtBeginning( T key )
    {
	Node<T>* node = new Node<T>(key) ;
	node->setLink(head) ;
	head = node ;
    }


template < class T >
    void LinkedList<T> :: insertAtEnd( T key )
    {
    	Node < T >* p = head ;
    	while ( p->getLink() != nullptr ) 
	{
            p = p->getLink( ) ;
    	}
		
	Node<T>* node = new Node<T> (key) ;
	node->setLink(nullptr) ;
	p->setLink(node) ;
    }

template < class T >
    void LinkedList<T> :: insertAfterKey( T key , T item ) 
    {
	Node <T>* p = head ;
	while ( p->getLink() != nullptr && p->getData() != key )
        {
	    p = p->getLink() ;
	}
	
	if ( p == nullptr ) 
	{
            cout << "Key not found in the list." << endl;
            return;
	}

	Node <T>* q = p->getLink( ) ;
	Node <T>* node = new Node<T> (item) ; 
	node->setLink(q) ; 
	p->setLink(node) ;  
    }


template < class T >
    void LinkedList :: insertBeforeKey(T key, T item)
    {
	if (head == nullptr) 
	{
            cout << "List is empty." << endl ;
            return ;
        }

    	if ( head->getData() == key ) 
	{
             insertAtBeginning(item) ;
             return ;
        }

	Node<T>* p = head->getLink( );
	Node<T>* q = p->getLink( );
	while (q->getData( ) !=  key)
	{
	     p = q;
	     q = q->getLink();
	}

	if ( q == NULL ) 
	{
            cout << "Key not found in the list." << endl ;
            return;
        }

   	Node<T>* node = new Node(item);
    	node->setLink(q);
   	p->setLink(node);
    }

template < class T >
    void LinkedList<T> :: deleteAtBeginning( )
    {
	if (head == nullptr) 
	{
            cout << "List is empty. Cannot delete from an empty list." << endl ;
            return;
    	}

	Node<T>* temp = head ;
	head = temp->getLink() ;
	delete temp ;
    }


template < class T >
    void LinkedList<T> :: deleteKey(T key ) 
    {
	Node<T>* p = head ;
	Node<T>* q = p->getLink() ;
	while(q->getData() != key )
	{
	    p = q ;
	    q = q->getLink() ;
	}

	p->setLink(q->getLink()) ;
	delete q ;
    }

template < class T >
    void LinkedList<T> :: deleteAtEnd( )  
    {
	Node<T>* p = head ;
	Node<T>* q = p->getLink() ;
	while(q->getLink() != nullptr )
	{
	    p = q ;
	    q = q->getLink() ;
	}

	p->setLink(nullptr) ;
	delete q ;
    }

template < class T >
void LinkedList :: concatLists(LinkedList list1)
    {
	if (head == nullptr)
	{
	    head = list1.head;
	    return;
	}

	Node<T>* current = head ;

	while(current->getLink() != NULL)
	{
	    current = current->getLink();
	}

	current->setLink(l1.head);
    }


template < class T >
Node* LinkedList :: search(T key)
{
	Node<T>* current = head ;
	while(current->getLink() != nullptr)	
	{
	     if(current->getData( ) == key )
	     {
		cout << "Target found : "<< current->getData( ) << endl ;
		return current ;
	     }
		current = current->getLink();
	}
	return nullptr;
}


template < class T >
void LinkedList :: reverseList( ) 
{
    Node<T>* previous = nullptr ;
    Node<T>* current = head ;
    Node<T>* next = nullptr ;
    
    while (current != nullptr) 
    {
        next = current->getLink( );
        current->setLink(previous);
        previous = current;
        current = next;
    }
    
    head = previous;
}


template < class T >
void LinkedList::reverseTraversal( ) 
{
    Node<T>* current = head;
    Node<T>* previous = nullptr;
    Node<T>* next = nullptr;

    while (current != nullptr) 
    {
        next = current->getLink( );  
        current->setLink(previous); 
        previous = current;
        current = next;
    }

    current = previous; 

    while (current != nullptr) 
    {
        cout << current->getData( ) <<endl;
        current = current->getLink( );
    }
}


template < class T >
Node* LinkedList::findMinimum(Node* start) const 
{
    if (start == NULL)
    {
        return NULL;
    }

    Node<T>* minNode = start ;
    Node<T>* current = start->getLink( );

    while (current != NULL) 
    {
        if (current->getData() < minNode->getData()) 
	{
            minNode = current;
        }
        current = current->getLink();
    }

    return minNode;
}


template < class T >
void LinkedList::sort( ) 
{
    if (head == NULL || head->getLink( ) == NULL) 
    {
        cout << "List is already sorted or empty. Nothing to sort." << endl ;
        return;
    }

    Node<T>* current = head;

    while (current != NULL) {
        Node<T>* minNode = findMinimum(current);

        int temp = current->getData();
        current->setData(minNode->getData());
        minNode->setData(temp);

        current = current->getLink();
    }
}

} ; 
