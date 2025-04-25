#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    void Push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    void Pop() {
        if (!q1.empty()) {
            q1.pop();
        } else {
            cout << "Stack is empty!" << endl;
        }
    }

    int Top() {
        if (!q1.empty()) {
            return q1.front();
        } else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return q1.empty();
    }
};
int main() {
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << "Top: " << s.Top() << endl;
    s.Pop();

    cout << "Top after pop: " << s.Top() << endl;

    return 0;
}

