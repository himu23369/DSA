#include<iostream>
using namespace std;

int minSteps(int n){
   if(n == 1){
     return 0;
   }
   
   int a = minSteps(n-1);
   
   int b = INT_MAX;
   int c = INT_MAX;

   if(n%2 == 0){
     b = minSteps(n/2);
   }

   if(n%3 == 0){
     c = minSteps(n/3);
   }

   return 1 + min(a,min(b,c));

}

int main(){

    int n;
    cout << "Enter n" << endl;
    cin >> n;
     
    cout << "Minimum steps to get reduced to " << n <<  " are " << minSteps(n) << endl; 
  
    return 0;
}