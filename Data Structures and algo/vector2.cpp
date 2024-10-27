#include <iostream>
#include <vector>
using namespace std;

int main()
{
//Code showing that capacity is getting doubled if size becomes full    
/*
   vector<int> v;
   cout << "CAP." << "  " << "SIZE" << endl;
   for(int i = 0; i <= 10; i++){
       cout << v.capacity() << "     " << v.size() << endl;
       v.push_back(i);
   }
*/

   vector<int> v;
   v.push_back(3);
   v.push_back(4);
   v.push_back(6);
   for(int i = 0; i < v.size(); i++){
     cout << v[i] << " ";
   }


    return 0;
}