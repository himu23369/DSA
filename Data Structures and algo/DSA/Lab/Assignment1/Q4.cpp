#include <iostream>
using namespace std;

int main()
{

    int size;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " elements" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0, j = size - 1; i <= j, j >= i; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    cout << "Array is: " << endl;
    for(int k = 0; k < size; k++){
        cout << arr[k] << " ";
    }

    return 0;
}