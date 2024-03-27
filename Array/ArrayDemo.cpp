#include <iostream>
#include "Array.h"

using namespace std;

int main() {
    Array<int> myArray;
    int choice;
    int element, position;

    cout << "\nMenu:\n";
    cout << "1. Insert an element at the beginning\n";
    cout << "2. Insert an element at the end\n";
    cout << "3. Insert an element at a specific index\n";
    cout << "4. Delete an element from the beginning\n";
    cout << "5. Delete an element from the end\n";
    cout << "6. Delete an element from a specific index\n";
    cout << "7. Linear Search\n";
    cout << "8. Binary Search\n";
    cout << "9. Selection Sort\n";
    cout << "10. Bubble Sort\n";
    cout << "11. Insertion Sort\n";
    cout << "12. Quick Sort\n";
    cout << "13. Rotate Clockwise\n";
    cout << "14. Rotate Anti-Clockwise\n";
    cout << "15. Print Array\n";
    cout << "0. Exit\n";
    
    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter element to insert at beginning: ";
                cin >> element;
                myArray.insertAtBeginning(element);
                break;
            case 2:
                cout << "Enter element to insert at end: ";
                cin >> element;
                myArray.insertAtEnd(element);
                break;
            case 3:
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter position to insert at: ";
                cin >> position;
                myArray.insertAtIndex(element, position);
                break;
            case 4:
                myArray.deleteAtBeginning();
                break;
            case 5:
                myArray.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                myArray.deleteAtIndex(position);
                break;
            case 7:
                cout << "Enter element to search: ";
                cin >> element;
                cout << "Index position: " << myArray.linearSearch(element) << endl;
                break;
            case 8:
                cout << "Enter element to search: ";
                cin >> element;
                cout << "Index position: " << myArray.binarySearch(element) << endl;
                break;
            case 9:
                myArray.selectionSort();
                cout << "Array sorted using Selection Sort.\n";
                break;
            case 10:
                myArray.bubbleSort();
                cout << "Array sorted using Bubble Sort.\n";
                break;
            case 11:
                myArray.insertionSort();
                cout << "Array sorted using Insertion Sort.\n";
                break;
            case 12:
                myArray.quickSort(1, myArray.getUpperBound());
                cout << "Array sorted using Quick Sort.\n";
                break;
            case 13:
                cout << "Enter positions to rotate clockwise: ";
                cin >> position;
                myArray.rotateClockwise(position);
                break;
            case 14:
                cout << "Enter positions to rotate anti-clockwise: ";
                cin >> position;
                myArray.rotateAntiClockwise(position);
                break;
            case 15:
                cout << "Array: " << myArray << endl;
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while(choice != 0);

    return 0;
}
