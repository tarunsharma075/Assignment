#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* Next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    Node* CreateNode() {
        Node* newNode = new Node;
        newNode->Next = NULL;
        return newNode;
    }

    void InsertAtEnd(int value) {
        Node* NewNode = CreateNode();
        NewNode->data = value;

        if (head == NULL) {
            NewNode->Next = NewNode;
            head = NewNode;
        } else {
            Node* temp = head;
            while (temp->Next != head) {
                temp = temp->Next;
            }
            temp->Next = NewNode;
            NewNode->Next = head;
        }
    }

    void InsertAtBegning(int value) {
        Node* NewNode = CreateNode();
        NewNode->data = value;

        if (head == NULL) {
            NewNode->Next = NewNode;
            head = NewNode;
            return;
        }

        Node* temp = head;
        while (temp->Next != head) {
            temp = temp->Next;
        }
        NewNode->Next = head;
        temp->Next = NewNode;
        head = NewNode;
    }

    void traverse() {
        if (head == NULL) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->Next;
        } while (temp != head);
        cout << endl;
    }

    void findTheMiddle() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        int count = 1;
        Node* temp = head;
        while (temp->Next != head) {
            count++;
            temp = temp->Next;
        }
        int mid = count / 2;
        temp = head;
        for (int i = 0; i < mid; i++) {
            temp = temp->Next;
        }
        cout << "The middle node is " << temp->data << endl;
    }

    void insertAtIndex(int index, int value) {
        if (index < 0) {
            cout << "Invalid Index" << endl;
            return;
        }

        if (head == NULL) {
            if (index == 0) {
                Node* NewNode = CreateNode();
                NewNode->data = value;
                NewNode->Next = NewNode;
                head = NewNode;
            } else {
                cout << "Invalid Index" << endl;
            }
            return;
        }

        if (index == 0) {
            InsertAtBegning(value);
            return;
        }

        int current = 0;
        Node* temp = head;
        while (current < index - 1 && temp->Next != head) {
            temp = temp->Next;
            current++;
        }

        if (current == index - 1) {
            Node* NewNode = CreateNode();
            NewNode->data = value;
            NewNode->Next = temp->Next;
            temp->Next = NewNode;
        } else {
            cout << "Index out of bounds" << endl;
        }
    }

    void deleteFromEnd() {
        if (head == NULL) return;
        if (head->Next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->Next->Next != head) {
            temp = temp->Next;
        }
        delete temp->Next;
        temp->Next = head;
    }

    void deleteFromBeginning() {
        if (head == NULL) return;
        if (head->Next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->Next != head) {
            temp = temp->Next;
        }
        Node* toDelete = head;
        temp->Next = head->Next;
        head = head->Next;
        delete toDelete;
    }

    void deleteFromIndex(int index) {
        if (head == NULL) return;
        if (index == 0) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        int currentIndex = 0;
        while (currentIndex < index - 1 && temp->Next != head) {
            temp = temp->Next;
            currentIndex++;
        }
        if (currentIndex == index - 1 && temp->Next != head) {
            Node* toDelete = temp->Next;
            temp->Next = toDelete->Next;
            delete toDelete;
        } else {
            cout << "The Index is invalid" << endl;
        }
    }

    void reverse() {
        if (head == NULL || head->Next == head) return;

        Node* prev = NULL;
        Node* current = head;
        Node* Next = NULL;
        Node* last = head;

        while (last->Next != head) {
            last = last->Next;
        }

        do {
            Next = current->Next;
            current->Next = prev;
            prev = current;
            current = Next;
        } while (current != head);

        head->Next = prev;
        head = prev;
        last->Next = head; // maintain circular link
    }
};

int main() {
    LinkedList list;
    list.InsertAtEnd(10);
    list.InsertAtEnd(20);
    list.InsertAtEnd(30);
    list.InsertAtBegning(5);
    list.insertAtIndex(2, 15);

    cout << "List after insertions: ";
    list.traverse();

    list.findTheMiddle();

    list.deleteFromBeginning();
    cout << "After deleting from beginning: ";
    list.traverse();

    list.deleteFromEnd();
    cout << "After deleting from end: ";
    list.traverse();

    list.deleteFromIndex(1);
    cout << "After deleting from index 1: ";
    list.traverse();

    list.reverse();
    cout << "After reversing: ";
    list.traverse();

    return 0;
}

