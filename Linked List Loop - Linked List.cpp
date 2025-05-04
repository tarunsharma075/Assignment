#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* Next;
};

void CheckLoop(Node* head) {

    Node* slow= head;
	Node* fast= head;
	while(fast != nullptr && fast->Next != nullptr){
		slow=slow->Next;
		fast=fast->Next->Next;
			if(slow==fast){
			cout<<"There is a loop"<<endl;
			return ;
		}
	
	}
	
  cout<<"There is no loop"<<endl;
}

int main() {
    Node* head;
    
// the code where the loop exists 
// please uncomment  the loop you want to check

//    Node* first = new Node();
//    Node* second = new Node();
//    Node* third = new Node();
//    Node* fourth = new Node();
//    Node* fifth = new Node();
//
//    first->data = 10;
//    first->Next = second;
//
//    second->data = 20;
//    second->Next = third;
//
//    third->data = 30;
//    third->Next = fourth;
//
//    fourth->data = 40;
//    fourth->Next = fifth;
//
//    fifth->data = 50;
//    fifth->Next = third; 


//the code where loop dosent exist


    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();

    first->data = 10;
    first->Next = second;

    second->data = 20;
    second->Next = third;

    third->data = 30;
    third->Next = fourth;

    fourth->data = 40;
    fourth->Next = fifth;

    fifth->data = 50;
    fifth->Next = nullptr; 

    head = first;

    CheckLoop(head);
}

