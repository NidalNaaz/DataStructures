#include <iostream>
using namespace   ;

template <typename T>
class Node {
    T data;
    Node* next;

public:
    Node(T);
    void setData(T);
    T getData();
    void setNext(Node<T>*);
    Node<T>* getNext();
};

template <typename T>
Node<T>::Node(T data) : data(data), next(nullptr) {}

template <typename T>
void Node<T>::setData(T x) {
    this->data = x;
}

template <typename T>
T Node<T>::getData() {
    return data;
}

template <typename T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}

template <typename T>
Node<T>* Node<T>::getNext() {
    return next;
}

template <typename T>
class Deque {
    Node<T>* front;
    Node<T>* rear;

public:
    Deque();
    ~Deque();
    bool isEmpty();
    void insertFront(T);
    void insertRear(T);
    void deleteFront();
    void deleteRear();
    void display();
};

template <typename T>
Deque<T>::Deque() : front(nullptr), rear(nullptr) {}

template <typename T>
Deque<T>::~Deque() {
    while (!isEmpty()) {
        deleteFront();
    }
}

template <typename T>
bool Deque<T>::isEmpty() {
    return front == nullptr;
}

template <typename T>
void Deque<T>::insertFront(T x) {
    Node<T>* newNode = new Node<T>(x);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        newNode->setNext(front);
        front = newNode;
    }
}

template <typename T>
void Deque<T>::insertRear(T x) {
    Node<T>* newNode = new Node<T>(x);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->setNext(newNode);
        rear = newNode;
    }
}

template <typename T>
void Deque<T>::deleteFront() {
    if (isEmpty()) {
        cout << "Deque underflow!" <<  ::endl;
        return;
    }
    Node<T>* temp = front;
    front = front->getNext();
    delete temp;
    if (front == nullptr) {
        rear = nullptr; 
    }
}

template <typename T>
void Deque<T>::deleteRear() {
    if (isEmpty()) {
        cout << "Deque underflow!" <<  ::endl;
        return;
    }
    Node<T>* temp = front;
    while (temp->getNext() != rear) {
        temp = temp->getNext();
    }
    delete rear;
    rear = temp;
    rear->setNext(nullptr);
    if (rear == nullptr) {
        front = nullptr; 
    }
}

template <typename T>
void Deque<T>::display() {
    if (isEmpty()) {
        cout << "Deque is empty." <<  ::endl;
        return;
    }
    Node<T>* temp = front;
    while (temp != nullptr) {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
     ::cout <<  ::endl;
}

int main() {
    Deque<int> myDeque;

    myDeque.insertFront(1);
    myDeque.insertFront(2);

    myDeque.insertRear(3);
    myDeque.insertRear(4);

    cout << "Deque after inserting elements: ";
    myDeque.display(); // Output: 2 1 3 4

    myDeque.deleteFront();
    myDeque.deleteRear();

    cout << "Deque after deleting front and rear elements: ";
    myDeque.display(); // Output: 1 3

    return 0;
}
