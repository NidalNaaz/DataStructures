#include"LinkedList.h"

template<class T>	
Node<T>::Node(T data){
	this->data=data;
	this->link=NULL;
}

template<class T>
T Node<T>:: getData(){
	return data;
}

template<class T>
Node<T>* Node<T>:: getLink(){
	return link;
}

template<class T>
void Node<T>::setLink(Node<T>* link){
	this->link=link;
}

template<class T>
void Node<T>::setData(T data){
	this->data=data;
}


template<class T>
LinkedList<T>::LinkedList(){
	/*head->setData(NULL);
	head->setLink(NULL);*/
	head=NULL;
}

template<class T>
void LinkedList<T>::createLinkedList(){
	T x;
	char option;
	Node<T>* current;
	current=head;
	do{
		cout<<"Enter the data:";
		cin>>x;
		Node<T>* node=new Node<T>(x);
		if(head==NULL){
			head=node;
			current=head;
		}
		else{
			current->setLink(node);
			current=node;
		}
		cout<<"Do you want to enter numbers(y/n):";
		cin>>option;
	}while(option=='y');
}

template<class T>
void LinkedList<T>::display(){
	Node<T>* p=head;
	while (p!=NULL){
		cout<<p->getData()<<" ";
		/*cout<<p->getData();*/
		p=p->getLink();
	}
	cout<<endl;
}

template<class T>
void LinkedList<T>::insertAtBeg(T key){
	Node<T>* node1=new Node<T>(key);
	node1->setLink(head);
	head=node1;
}

template<class T>
void LinkedList<T>::insertAtEnd(T key){
	Node<T>* p=head;
	while (p->getLink() !=NULL){
		p=p->getLink();
	}
	Node<T>* node2=new Node<T>(key);
	p->setLink(node2);
	
}

template<class T>
void LinkedList<T>::insertBeforeKey(T key,T item){
	Node<T>* p=head;
	Node<T>* q=p->getLink();
	while (q!=NULL && q->getData()!=key){		
		p=q;
		q=q->getLink();
	}
	if (q==NULL) {
        cout<<"Key not found in the list"<<endl;
    }
	Node<T>* node3=new Node<T>(item);
	node3->setLink(q);
	p->setLink(node3);
}
	

template<class T>
void LinkedList<T>::insertAfterKey(T key,T item){
	Node<T>* p=head;
	while (p!=NULL && p->getData()!=key){
		p=p->getLink();
	}
	Node<T>* node4=new Node<T>(item);
	node4->setLink(p->getLink());
	p->setLink(node4);
	
}

template<class T>
void LinkedList<T>::DeleteAtBeg(){
	Node<T>* temp=head;
	head=head->getLink();
	delete temp;	
}

template<class T>
void LinkedList<T>::DeleteAtEnd(){
	Node<T>* p= head;
	Node<T>* q=p->getLink();
	while(q->getLink()!=NULL){
		p=q;
		q=q->getLink();
	}
	p->setLink(NULL);
	delete q;
}

template<class T>
void LinkedList<T>::DeleteAtKey(T key){
	Node<T>* p=head;
	Node<T>* q=p->getLink();
	while(q!=NULL && q->getData()!=key){
		p=q;
		q=q->getLink();
	}
	p->setLink(q->getLink());
	delete q;
}

template<class T>
void LinkedList<T>::concat(LinkedList<T>& L){
	Node<T>* end=head;
	while(end->getLink()!=NULL){
		end=end->getLink();		
	}
	end->setLink(L.head);	
}

template<class T>
void LinkedList<T>::Search(T key){
	Node<T>* p=head;
	int count=0;
	while(p!=NULL){
		if(p->getData()==key){
			count++;
		}
		p=p->getLink();
	}
	if(count==0){
		cout<<"Element not Found "<<endl;
	}
	else{
		cout<<"Element "<<key<<" Found "<<count<<" times"<<endl;	
	}
}

template<class T>
void LinkedList<T>::Reverse(){
	Node<T>* q=head;
	Node<T>* p=NULL;
	Node<T>* r=NULL;
	while(q!=NULL){
		r=q->getLink();
		q->setLink(p);
		p=q;
		q=r;		
	}
	head=p;	
}

template<class T>
void LinkedList<T>::ReverseTraverse(Node<T>* n){
	if (n==NULL){
		return;
	}
	ReverseTraverse(n->getLink());
	cout<<n->getData()<<" ";
}
template<class T>
void LinkedList<T>::ReverseTraverse(){
	ReverseTraverse(head);
	cout<<endl;
}
	
template<class T>
void LinkedList<T>::Sort(){
	Node<T>* p=head;
	while(p!=NULL){
		Node<T>* q=p->getLink();
		while(q!=NULL){
			if(p->getData()>q->getData()){
				T temp_data=p->getData();
				p->setData(q->getData());
				q->setData(temp_data);
			}	
			q=q->getLink();
		}
		p=p->getLink();
	}
}
