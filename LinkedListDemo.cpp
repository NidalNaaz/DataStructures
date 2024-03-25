#include"LinkedList.cpp"
int main(){	
	LinkedList<int> LLobj;
	LLobj.createLinkedList();
	LLobj.display();
  
  cout<<"Inserted 6 at Beginning"<<endl;
	LLobj.insertAtBeg(6);
	LLobj.display();
  
	cout<<"Inserted 2 at End:"<<endl;
	LLobj.insertAtEnd(2);
	LLobj.display();
	
	cout<<"Inserted 1 after 3:"<<endl;
	LLobj.insertAfterKey(3,1);
	LLobj.display();
  
	cout<<"Deleted from beginning:"<<endl;
	LLobj.DelAtBeg();
	LLobj.display();
  
	cout<<"Deleted from End:"<<endl;
	LLobj.DelAtEnd();
	LLobj.display();
  
	cout<<"Deleting the key 3:"<<endl;
	LLobj.DelAfterKey(3);
	LLobj.display();

	cout<<"Reversing Linked List"<<endl;
	LLobj.Reverse();
  LLobj.display();
  
	cout<<"Searching for element 3"<<endl;
	LLobj.Search(3);
  
	cout<<"Sorting Linked List"<<endl;
	LLobj.Sort();
	LLobj.display();
  
	cout<<"Reverse Traversal"<<endl;
	LLobj.ReverseTraverse();
	
	
	cout<<"Enter the character List for concatenation"<<endl;
	LinkedList<char> LLobj1;
	LLobj1.createLLobj();
  
	cout<<"First String:";
	LLobj1.display();
  
	LinkedList<char> LLobj2;
	LLobj2.createLLobj();
  
	cout<<"Second String:";
	LLobj2.display();
  
	cout<<"Concatenated String:";
	LLobj1.concat(LLobj2);
	LLobj1.display();
	
	return 0;	
}
