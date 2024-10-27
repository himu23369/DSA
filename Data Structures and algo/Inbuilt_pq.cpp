#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq;
    //Inbuilt min priority queue
    /* 
      priority_queue<int, vector<int>, greater<int>> p;
    */

    pq.push(11);
    pq.push(102);
    pq.push(143); 
    pq.push(214);
    pq.push(125);
    pq.push(162);

    cout << pq.size() << endl;
    cout << pq.top() << endl;

    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }
}