#include<bits/stdc++.h>
using namespace std;

int Sandwiches(int n){

queue<int>Students;
stack<int>Sandwiches;
for(int i=0;i<n;i++){
int number= rand()%2;
Students.push(number);
}
for(int i=0;i<n;i++){
	int number= rand()%2;
	Sandwiches.push(number);
}
int count = 0;
while(!Sandwiches.empty() && count < Students.size()){
if(Students.front()==Sandwiches.top()){
Students.pop();
Sandwiches.pop();
count=0;
}else{
	int temp=Students.front();
	Students.pop();
	Students.push(temp);
	count++;
}	
}
return Students.size();
}
int main() {
	srand(time(0));
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int result = Sandwiches(n);
    cout << "Number of students who couldn't eat: " << result << endl;

   
    return 0;
}



