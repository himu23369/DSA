#include<iostream>
using namespace std;
#include<vector>

int main(){
    // vector<int> *vp = new vector<int>(); //Dynamically creating 
    vector<int> v;  //Static
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout << "Size is: " << v.size() << endl;
    //push back isliye use krna pada kyunki usko dekhna padega ki size increase krna hai ya nhi
    v[1] = 100; //This should be avoided i.e.Don't use [] for inserting elements

    //For deleting elements from the last place
    v.pop_back();

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v.size() << endl;

    cout << v.at(2) << endl;
    cout << v.at(4) << endl;

    return 0;
}