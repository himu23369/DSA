// Bubble Sort

//Time Complexity -> O(n^2)
//Space Complexity -> O(1)

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in array" << endl;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element at " << i << endl;
        cin >> arr[i];
    }

    cout << "ARRAY is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n; i++){
       for(int j = 0; j < n - i - 1; j++){
          if(arr[j] > arr[j+1]){
             int temp = arr[j];
             arr[j] = arr[j+1];
             arr[j+1] = temp;
          }
       } 
    }

    cout << "The SORTED ARRAY is:" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}