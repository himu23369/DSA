#include<iostream>
#include<queue>
using namespace std;

void kSortedArray(int input[],int n, int k){
   priority_queue<int> pq;

   //Complexity will be (k log(k)) as push function has complexity of log(k) and we are doing that for k elements.
   for(int i = 0; i < k; i++){
     pq.push(input[i]);
   }

   //Complexity will be (n - k)log(k)
   int j = 0;
   for(int i = k; i < n; i++){
     input[j] = pq.top();
     pq.pop();
     pq.push(input[i]);
     j++;
   }

   //Complexity will be k log(k)
   while(!pq.empty()){
     input[j] = pq.top();
     pq.pop();
     j++;
   }

   //So, overall Complexity will be k logk + (n-k)log(k) + k logk =  (n+k)log(k) = O(n) approximately
   //Best complexity obtained that can never be obtained using merge sort and heap sort which give complexity of O(n logn)
}

int main(){
   
   int input[] = {10,12,6,7,9};
   int k = 3;
   kSortedArray(input, 5 ,3);
   for(int i = 0; i < 5; i++){
     cout << input[i] << " ";
   }

   return 0;
}
