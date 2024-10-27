/*
Problem Statement : Given an array of positive numbers and a target sum. Find whether or not it's possible to find a subset in the array which adds to target sum.
let given array be 'arr', number of elements in array be 'n' and target sum be 'sum'
*/

#include<iostream>
using namespace std;

//Recursive approach
bool isSubsetSum(int arr[], int n, int sum) {
    if(sum > 0 && n == 0) 
       return false; 

    if(sum == 0) 
       return true;

    if(arr[n-1] > sum ) 
       return isSubsetSum(arr, n-1, sum); // this element can't be included
    
    bool ans = (isSubsetSum(arr, n-1, sum) || isSubsetSum(arr, n-1, sum - arr[n-1]));
   
    return ans; 
}

int main(){

    int arr[5] = {1,2,3,4,5};
    bool ans = isSubsetSum(arr, 5, 40);

    if(ans){
        cout << "Subset is possible" << endl;
    }
    else cout << "Not possible" << endl;

    return 0;
}