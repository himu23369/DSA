#include<iostream>
#include<map>
using namespace std;

int main(){
    //map stores all the values in sorted order
    map<int, string> m;
    m[1] = "One";
    m[2] = "Two"; 
    
    cout << "Value at key2 is: " << m[2] << endl;

    //Iterating in the map
    for(auto it:m){
        cout << it.first << " " << it.second << endl;
    }   

    return 0;
}