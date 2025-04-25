#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct Node{
	T data;
	Node*Next;
};
template<typename T>
class Queue{
private:
Node<T>*head;
Node<T>*rear;
public:
Queue(){
head=nullptr;
rear=nullptr;
}
void Push(T x){
Node<T>* newNode = new Node<T>;
newNode->data = x;
newNode->Next = nullptr;
if(head==nullptr){
head = newNode;
rear = newNode;
}else{
rear->Next = newNode;
rear = newNode;
}
}


void pop(){
if(head==nullptr){
	cout<<"There is nothing to pop";
	return ;
}else{
	Node<T>*temp=head;
	head=head->Next;
	temp->Next=nullptr;
	delete(temp);
	
	if(head==nullptr){
		rear=nullptr;
	}
}
}
  T front() {
        if (isEmpty()) {
           cout<<"The queue is empty"<<endl;
           return -1;
        }
        return head->data;
    }
bool isEmpty(){
	if(head==nullptr){
		return true;
	}else{
		return false;
	}
}
int size(){
	int count=0;
	if(isEmpty()){
		return -1;
	}else{
	
		Node<T>*temp=head;
		while(temp!=nullptr){
			count++;
			temp=temp->Next;
		}
	}
	return count;
}



};

int main() {
    Queue<int> q;

    q.Push(10);
    q.Push(20);
    q.Push(30);

    cout << "Front: " << q.front() << endl;
    q.pop();
    cout << "Front after pop: " << q.front() << endl;

    cout << "Queue size: " << q.size() << endl;

    return 0;
}


