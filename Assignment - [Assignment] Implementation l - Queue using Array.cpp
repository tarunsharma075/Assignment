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
	


};
int main() {
    Queue<int> q;

    // Pushing elements
    q.Push(10);
    q.Push(20);
    q.Push(30);

    // Display front element
    cout << "Front element: " << q.Front() << endl;

    // Size of the queue
    cout << "Size of queue: " << q.size() << endl;

    // Pop one element
    q.pop();

    // Display front again
    cout << "Front element after pop: " << q.Front() << endl;

    // Check if empty
    if (q.isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    // Pop all
    q.pop();
    q.pop();

    // Try to pop from empty
    q.pop();

    return 0;
}





