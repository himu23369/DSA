// Selection sort

#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    int arr[n];

    cout << "Enter the array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array before Sorting: " << endl;
    printArray(arr, n);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int min = arr[i];
            if (arr[j] < min)
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }

        cout << "Array after " << i + 1 << " iteration: ";
        printArray(arr, n);
    }

    cout << "Array after Sorting: " << endl;
    printArray(arr, n);

    return 0;
}