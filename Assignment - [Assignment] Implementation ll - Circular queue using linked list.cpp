#include<bits/stdc++.h>
using namespace std;

struct Node{
int data;
Node*Next;
};

class CircularQueue{
	
private:	
Node*head;
Node*front;
Node* rear;

public:
CircularQueue(){
head=nullptr;
front=nullptr;
rear=nullptr;

}

void Push(int value){
	
Node*temp=new Node();
temp->data=value;	
if(head==nullptr){
temp->Next=temp;
head=temp;
front = rear = head;
return ;

}


temp->data=value;
rear->Next=temp;
temp->Next=front;
rear=temp;

}

void pop(){

if(head==nullptr){
cout<<"There is noqthing to pop"<<endl;
return;
}

if(head->Next==head){
head->Next=nullptr;
delete(head);
head=nullptr;
front = rear = nullptr;
}else{
Node*temp=head;
head=head->Next;
rear->Next=head;
front=head;
temp->Next=nullptr;
delete(temp);
}

}

int GetFront(){
if(IsEmpty()){
return 0;
}else{
return front->data;
}	

}

bool IsEmpty(){
if(head==nullptr){
return true;
}else{
return false;
}
	
}

int Size(){
int count=0;	
if(IsEmpty()){
	return 0;
}
Node* temp = head;
do {
count++;
temp = temp->Next;
} while (temp != head);
return count;
}

void Display() {
if (IsEmpty()) {
cout << "Queue is empty" << endl;
return;
}
Node* temp = head;
cout << "Circular Queue elements: ";
do {
cout << temp->data << " ";
temp = temp->Next;
} while (temp != head);
cout << endl;
}

};


int main() {
CircularQueue q;

q.Push(10);
q.Push(20);
q.Push(30);
q.Push(40);

q.Display(); 

cout << "Front Element: " << q.GetFront() << endl; 
cout << "Size: " << q.Size() << endl;              

q.pop();
q.Display();
cout << "Front Element after pop: " << q.GetFront() << endl; 
cout << "Size after pop: " << q.Size() << endl;              

return 0;
}
