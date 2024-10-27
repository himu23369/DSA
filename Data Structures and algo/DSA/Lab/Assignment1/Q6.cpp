/*
BUBBLE SORT(Sinking Sort) --> Time Complexity(n^2)
*/

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

    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted Array is: " << endl;
    for (int k = 0; k < size; k++)
    {
        cout << arr[k] << " ";
    }

    return 0;
}
