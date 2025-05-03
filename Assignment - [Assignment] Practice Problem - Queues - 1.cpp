#include<bits/stdc++.h>
#include<queue>
using namespace std;

void DeckOfCards(int n){
vector <int> arr(n);
queue<int>q1;

for(int i=0;i<n;i++){
cin>>arr[i];
}

for(int i=0;i<n;i++){
	q1.push(arr[i]);
}
while(q1.size()>1){
int temp=q1.front();
q1.pop();
q1.pop();
q1.push(temp);
}
cout<<"The final element is "<<" "<<q1.front();
}

int main() {
    int n;
    cout << "Enter number of cards: ";
    cin >> n;

    cout << "Enter card values: ";
    DeckOfCards(n);

    return 0;
}
