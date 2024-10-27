//Removing duplicate elements from an array
//I will store corresponding to a key that a particular value has occured

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> removeDuplicates(int*a , int size){
   vector<int> output;
   unordered_map<int , bool> seen;

   for(int i = 0; i < size; i++){
    if(seen.count(a[i]) > 0){
        continue;
    }
    seen[a[i]] = true; //This is n times O(1) -> O(n)
    output.push_back(a[i]);
   }
   return output;
}

int main(){
    int a[] = {1,2,2,3,3,4,4,5};
    vector<int> output = removeDuplicates(a, 8);
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }


    return 0;
}
