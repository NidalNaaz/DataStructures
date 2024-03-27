#include <iostream>

using namespace std;

int main() {
    LinkedList<int> LLobj;
    char choice;
    int data, position;

    cout << "Menu:\n";
    cout << "a. Insert at Beginning\n";
    cout << "b. Insert at End\n";
    cout << "c. Insert at a specified Position\n";
    cout << "d. Delete from Beginning\n";
    cout << "e. Delete from End\n";
    cout << "f. Delete from a specified Position\n";
    cout << "g. Display\n";
    cout << "h. Exit\n";
    
  do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                cout << "Enter data to insert at beginning: ";
                cin >> data;
                LLobj.insertAtBeginning(LLobj.getHead(), data);
                break;
          
            case 'b':
                cout << "Enter data to insert at end: ";
                cin >> data;
                LLobj.insertAtEnd(LLobj.getHead(), data);
                break;
          
            case 'c':
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> position;
                LLobj.insertAtPosition(LLobj.getHead(), data, position);
                break;
          
            case 'd':
                LLobj.deleteAtBeginning(LLobj.getHead());
                break;
          
            case 'e':
                LLobj.deleteAtEnd(LLobj.getHead());
                break;
          
            case 'f':
                cout << "Enter position to delete from: ";
                cin >> position;
                LLobj.deleteAtPosition(LLobj.getHead(), position);
                break;
          
            case 'g':
                cout << "Linked List: ";
                LLobj.display(LLobj.getHead());
                cout << endl;
                break;
          
            case 'h':
                cout << "Exiting program.\n";
                break;
          
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 'h');

    return 0;
}
