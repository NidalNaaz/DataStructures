template <class T>
class TwoWayStack {
private:
    T *stack;
    int maxSize;
    int top1;
    int top2;
public:
    TwoWayStack(int size) {
        maxSize = size;
        stack = new T[maxSize];
        top1 = -1;
        top2 = maxSize;
    }

    ~TwoWayStack() {
        delete[] stack;
    }

    bool isEmpty(int stackNumber) {
        if (stackNumber == 1)
            return top1 == -1;
        else
            return top2 == maxSize;
    }

    bool isFull() {
        return top1 == top2 - 1;
    }

    void push(int stackNumber, T x) {
        if (!isFull()) {
            if (stackNumber == 1)
                stack[++top1] = x;
            else
                stack[--top2] = x;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    void pop(int stackNumber) {
        if (isEmpty(stackNumber)) {
            cout << "Stack underflow!" << endl;
        } else {
            if (stackNumber == 1)
                top1--;
            else
                top2++;
        }
    }

    T peek(int stackNumber) {
        if (isEmpty(stackNumber)) {
            cout << "Stack is empty!" << endl;
            return -1;
        } else {
            if (stackNumber == 1)
                return stack[top1];
            else
                return stack[top2];
        }
    }
};
