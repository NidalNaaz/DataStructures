#include<iostream>
#include<ostream>
using namespace std;

template <class T>
class Node{
		T data;
		Node<T>* link;
	public:
		Node(T);
		void setData(T);
		void setLink(Node<T>*);
		T getData();
		Node<T>* getLink();
};

template<class T>		
class LinkedList{
		Node<T>* head;
	public:
		LinkedList();
		void createLinkedList();
		void display();
		void insertAtBeg(T);
		void insertAtEnd(T);
		void insertBeforeKey(T,T);
		void insertAfterKey(T,T);
		void DeleteAtBeg();
		void DeleteAtEnd();
		void DeleteAtKey(T);
		void concat(LinkedList<T>&);
		void Reverse();
		void Search(T);
		void ReverseTraverse();
		void ReverseTraverse(Node<T>*);
		void Sort();
};	
