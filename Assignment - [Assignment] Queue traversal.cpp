#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Queue{
	private:
	int  front;
	int  rear;
//just for the assignment i took the size of array as 100	
	T arr[100];
	public:
Queue(){
front=0;
rear=0;	
}
void Push(T data){
	if(rear==99){
		cout<<"The queue is full";
		return ;
	}else{
		arr[rear]=data;
		rear++;
	}
}
void pop(){
	if(front==rear){
		cout<<"The queue is empty"<<endl;
		return;
	}else{
		front=-1;
		front++;
		if(front==rear){
			front=0;
			rear=0;
		}
		
	}
}
bool isEmpty(){
	if(front==rear){
		return true;
}else{
	return false;
}
}
T Front(){
	if(isEmpty()){
		return-1;
	}else{
	  return arr[front];
	}
}
int size(){
	
	return rear-front;
	}
	
void Traverse() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    for (int i = front; i < rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


};
int main() {
    Queue<int> q;
q.Push(10);
q.Push(20); 
q.Push(30);
q.Push(40);
q.Push(50); 
q.Traverse();
}





