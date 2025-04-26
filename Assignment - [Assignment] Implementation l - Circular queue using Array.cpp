#include<iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue() {
        size = 100;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    void push(int data) {
        if ((front == 0 && rear == size-1) || (rear == (front - 1 + size) % size)) {
            cout << "The queue is full" << endl;
            return;
        }
        else if (front == -1) {
            front = rear = 0;
            arr[rear] = data;
        }
        else if (rear == size-1 && front != 0) {
            rear = 0;
            arr[rear] = data;
        }
        else {
            rear++;
            arr[rear] = data;
        }
    }

    void pop() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        else if (front == rear) {
            front = rear = -1;
        }
        else if (front == size-1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    bool isEmpty() {
        return (front == -1);
    }

    int getSize() {
        if (front == -1) {
            return 0;
        }
        else if (rear >= front) {
            return rear - front + 1;
        }
        else {
            return (size - front + rear + 1);
        }
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        else {
            return arr[front];
        }
    }
};

int main() {
    CircularQueue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Front element: " << q.getFront() << endl;
    cout << "Size: " << q.getSize() << endl;

    q.pop();
    cout << "After one pop:" << endl;
    cout << "Front element: " << q.getFront() << endl;
    cout << "Size: " << q.getSize() << endl;

    while (!q.isEmpty()) {
        cout << "Popped front: " << q.getFront() << endl;
        q.pop();
    }

    q.pop(); // Empty pop

    return 0;
}

