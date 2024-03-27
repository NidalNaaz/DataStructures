#include <iostream>

template <typename T>
class Node {
    T data;
    Node* link;

public:
    Node(T);
    void setData(T);
    T getData();
    void setLink(Node<T>*);
    Node<T>* getLink();
};

template <typename T>
Node<T>::Node(T data) : data(data), link(nullptr) {}

template <typename T>
void Node<T>::setData(T x) {
    this->data = x;
}

template <typename T>
T Node<T>::getData() {
    return data;
}

template <typename T>
void Node<T>::setLink(Node<T>* link) {
    this->link = link;
}

template <typename T>
Node<T>* Node<T>::getLink() {
    return link;
}

template <typename T>
class Queue {
    Node<T>* front;
    Node<T>* rear;

public:
    Queue();
    ~Queue();
    bool isEmpty();
    void enqueue(T);
    void dequeue();
    T peek();
};

template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr) {}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
bool Queue<T>::isEmpty() {
    return front == nullptr;
}

template <typename T>
void Queue<T>::enqueue(T x) {
    Node<T>* newNode = new Node<T>(x);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->setLink(newNode);
        rear = newNode;
    }
}

template <typename T>
void Queue<T>::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue underflow!" << std::endl;
        return;
    }
    Node<T>* temp = front;
    front = front->getLink();
    delete temp;
}

template <typename T>
T Queue<T>::peek() {
    if (isEmpty()) {
        std::cout << "Queue empty!" << std::endl;
        return T(); // Return default value for T
    }
    return front->getData();
}

int main() {
    Queue<int> myQueue;
    int choice, item;

    do {
        cout << "\n---------------------";
        cout << "\nQueue Menu";
        cout << "\n---------------------";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Check if Queue is Empty";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> item;
                myQueue.enqueue(item);
                cout << item << " enqueued into the queue." << endl;
                break;
            case 2:
                if (!myQueue.isEmpty()) {
                    item = myQueue.peek();
                    myQueue.dequeue();
                    cout << item << " dequeued from the queue." << endl;
                } else {
                    cout << "Queue is empty. Cannot dequeue." << endl;
                }
                break;
            case 3:
                if (!myQueue.isEmpty()) {
                    item = myQueue.peek();
                    cout << "Front element of the queue: " << item << endl;
                } else {
                    cout << "Queue is empty. No elements to peek." << endl;
                }
                break;
            case 4:
                if (myQueue.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 5);

    return 0;
}

