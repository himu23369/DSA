#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
  /* unordered_map<int, int> u;
   int arr[] = {1, 2, 3};

   for (int i = 0; i < 3; i++)
   {
     cout << u[arr[i]] << " ";
  }*/
  
  unordered_map<string, int> ourMap;

  // Insert
  // 1st way
  pair<string, int> p("abc", 1);
  ourMap.insert(p);
  // 2nd way
  ourMap["def"] = 2;

  // Find or access
  // 1st way
  cout << ourMap["abc"] << endl;
  // 2nd way
  cout << ourMap.at("abc") << endl;

  // When we write this, our program will crash
  cout << ourMap.at("ghi") << endl;

  // Using this, our program will find the key and if not found will return the default value i.e. zero
  cout << "Size: " << ourMap.size() << endl;
  cout << ourMap["ghi"] << endl;
  cout << "Size: " << ourMap.size() << endl;

  // To check the presence
  if (ourMap.count("ghi") > 0)
  {
    cout << "ghi is present" << endl;
  }

  // erase
  ourMap.erase("ghi");

  return 0;
}