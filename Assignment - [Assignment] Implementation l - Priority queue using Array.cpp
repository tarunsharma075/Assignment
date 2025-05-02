#include<bits/stdc++.h>
using namespace std;

struct Node{
int Data;
int Priority;
Node*Next;
};

class PriorityQueue{
private:
Node*queue[4];
public:
PriorityQueue(){
for(int i=0;i<4;i++){
	queue[i]=nullptr;
}
}

void Push(int data, int p){
if(p<0||p>3){
	cout<<"Invalid Positions"<<endl;
	return;
}
Node* NewNode= new Node();
NewNode->Data=data;
NewNode->Next=nullptr;
NewNode->Priority=p;

if(queue[p]==nullptr){
queue[p]=NewNode;
}else{
Node*temp=queue[p];
while(temp->Next!=nullptr){
	temp=temp->Next;
}
temp->Next= NewNode;
}	
}

void Pop(){
for(int i=3;i>=0;i--){
if(queue[i]!=nullptr){
Node* temp= queue[i];
queue[i]=queue[i]->Next;
  cout << "Popped: " << temp->Data << " (Priority " << i << ")" << endl;
  delete temp;
  return;
}
}
cout<<"The queue is empty";
}

void Front(){
for(int i=3;i>=0;i--){
if(queue[i]!=nullptr){
cout<<queue[i]->Data<<" ";
}
return;
}
cout<<"The queue is empty"<<endl;	
}

    void Display() {
        for (int i = 3; i >= 0; i--) {
            cout << "Priority " << i << ": ";
            Node* temp = queue[i];
            while (temp != nullptr) {
                cout << temp->Data << " -> ";
                temp = temp->Next;
            }
            cout << "NULL" << endl;
        }
    }

};

int main() {
    PriorityQueue pq;

    pq.Push(10, 1); // Medium
    pq.Push(20, 3); // Urgent
    pq.Push(30, 0); // Low
    pq.Push(40, 2); // High

    pq.Display();

    pq.Front();

    pq.Pop();
    pq.Front();

    pq.Display();

    return 0;
}

