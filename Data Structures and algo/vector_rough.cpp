#include<iostream>
#include<vector>
using namespace std;

int main(){

    string pattern = "Bhavika";

    vector<string> v;
    v.push_back("Himanshu");
    v.push_back("Bhavika");
    v.push_back("Bansal");

    cout << v[0] << " ";
    // cout << pattern << endl;

    if(v[0] == pattern){
        cout << true;
    }
    else{
        cout << false << endl;
    }

    return 0;
}