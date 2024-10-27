// Insertion Sort - In this, array is divided into sorted list and unsorted list

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in array" << endl;
    cin >> n;
    int arr[n];
 
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

//Printing the array
    cout << "Array before Insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    if (n == 1)
    {
        cout << "The array is Sorted" << endl;
        cout << "SORTED ARRAY: " << arr[0];
    }

    int key;
    for (int i = 1; i <= n - 1; i++)
    {
        key = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > key)
            {
                arr[i] = arr[j];
                arr[j] = key;
            }

            cout << "Array after " << i << " iteration: ";

            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}