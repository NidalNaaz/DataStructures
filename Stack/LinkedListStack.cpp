#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    Node<T>* top; 
    int maxSize;
    int currentSize;

public:
    Stack(int maxSize) : top(nullptr), maxSize(maxSize), currentSize(0) {}

    ~Stack() {
       
        while (!isEmpty()) {
            pop();
        }
    }

    void push(T data) {
        if (isFull()) {
            cout << "Stack is full. Cannot push more elements." << endl;
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        newNode->next = top;
        top = newNode;
        currentSize++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        currentSize--;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    bool isFull() {
        return currentSize == maxSize;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return T();
        }
        return top->data;
    }
};

int main() {
    int maxSize;
    cout << "Enter the maximum size of the stack: ";
    cin >> maxSize;

    Stack<int> stack(maxSize);

    cout << "\nStack Operations Menu:" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Check if Empty" << endl;
    cout << "5. Check if Full" << endl;
    cout << "0. Exit" << endl;
    
    int choice;
    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            }
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Top element: " << stack.peek() << endl;
                break;
            case 4:
                if (stack.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 5:
                if (stack.isFull()) {
                    cout << "Stack is full." << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
