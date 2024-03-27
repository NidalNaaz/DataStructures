#include <iostream>

using namespace std;

template <class T>
class Deque {
private:
    T* queue;
    int maxSize;
    int front;
    int rear;
public:
    Deque(int size) {
        maxSize = size;
        queue = new T[maxSize];
        front = -1;
        rear = -1;
    }

    ~Deque() {
        delete[] queue;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((front == 0 && rear == maxSize - 1) || front == rear + 1);
    }

    void insertFront(T x) {
        if (isFull()) {
            cout << "Deque overflow!" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = maxSize - 1;
        } else {
            front--;
        }
        queue[front] = x;
    }

    void insertRear(T x) {
        if (isFull()) {
            cout << "Deque overflow!" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (rear == maxSize - 1) {
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = x;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque underflow!" << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == maxSize - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque underflow!" << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = maxSize - 1;
        } else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % maxSize;
        }
        cout << queue[rear] << endl;
    }
};

int main() {
    Deque<int> dq(5);

    dq.insertFront(1);
    dq.display(); // Output: 1

    dq.insertRear(2);
    dq.display(); // Output: 1 2

    dq.insertFront(3);
    dq.display(); // Output: 3 1 2

    dq.deleteFront();
    dq.display(); // Output: 1 2

    dq.deleteRear();
    dq.display(); // Output: 1

    return 0;
}
