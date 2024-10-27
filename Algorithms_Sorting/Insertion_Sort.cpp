// Insertion Sort - In this, array is divided into sorted list and unsorted list. Values from unsorted list are taken and placed at correct position in sorted list.

// Time Complexity -> O(n^2)
// Space Complexity -> O(1)

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

    // 1st method
    /*for (int i = 0; i < n - 1; i++)
    {
        int x = arr[i + 1];
        int y = 0;
        for (int j = i; j >= 0; j--)
        {
            if (x <= arr[j])
            {
                arr[j + 1] = arr[j];
                y++;
            }
        }
        arr[(i + 1) - y] = x;
    }*/

    // 2nd method
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    cout << "Array after Insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}