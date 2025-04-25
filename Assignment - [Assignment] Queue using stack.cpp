#include<iostream>
#include<stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    void Push(int x) {
        s1.push(x);
    }

    void Pop() {
        if (!s2.empty()) {
            s2.pop();
        } else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            if (!s2.empty()) {
                s2.pop();
            }
        }
    }

    int Top() {
        if (!s2.empty()) {
            return s2.top();
        } else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            if (!s2.empty()) {
                return s2.top();
            }
            // Agar yahan tak aa gaye, queue khali hai
            cout << "Queue is empty!" << endl;
            return -1; // Ya kuch error value
        }
    }

    bool Empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;
    q.Push(1);
    q.Push(2);
    q.Push(3);

    cout << q.Top() << endl; // 1
    q.Pop();

    cout << q.Top() << endl; // 2
    q.Pop();

    cout << q.Top() << endl; // 3
    q.Pop();

    cout << q.Empty() << endl; // 1 (true)

    return 0;
}

