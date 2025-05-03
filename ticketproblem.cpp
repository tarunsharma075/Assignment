#include<bits/stdc++.h>
using namespace std;
int TimeTickets(int arr[], int k, int n){
queue<int>ticket;
int time=0;
for(int i=0;i<n;i++){
ticket.push(i);
}	
while(!ticket.empty()){
int idfront= ticket.front();
ticket.pop();
if(arr[idfront]>0){
arr[idfront]--;
time++;
}
if(arr[idfront]>0){
ticket.push(idfront);
}
if (idfront == k && arr[idfront] == 0) {
                return time;
            }
}
return time;
}
int main() {
    cout << "Enter the size of the array" << endl;
    int n;
    cin >> n;

    int ticketArray[n];

    cout << "Now Enter the index of the person you want to find its time" << endl;
    int k;
    cin >> k;

    if (k >= n || k < 0) {
        cout << "Please enter a valid index (0 to " << n - 1 << ")" << endl;
        return 0;
    }

    cout << "Enter the values of the array" << endl;
    for (int i = 0; i < n; i++) {
        cin >> ticketArray[i];
    }

    cout << "Time taken for person at position " << k << " is: ";
    cout << TimeTickets(ticketArray, k, n) << endl;

    return 0;
}

