#include<bits/stdc++.h>
using namespace std;
class Stack{
private:
queue<int>q;
public:
void Push(int x){
q.push(x);
for(int i=0;i<q.size()-1;i++){
	q.push(q.front());
	q.pop();
}

}
void pop(){
q.pop();
}
int top(){
return q.front();
}
};

int main() {
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << "Top: " << s.top() << endl;
    s.pop();

    cout << "Top after pop: " << s.top() << endl;

    return 0;
}
