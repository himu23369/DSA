// Not a comparison sort
// In this, sorting done according to keys
// Count elements having distinct key values
// Will not work with negative and floating point values
// Time complexity -> O(n)

#include <iostream>
using namespace std;

int main()
{
    int n, max = -1;
    cout << "Enter the number of elements in array" << endl;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element at " << i << endl;
        cin >> arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
        cout << "Current max element is:" << max << endl;
    }
    cout << "Max value is: " << max << endl;

    cout << "ARRAY is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int k = max + 1;
    cout << "Value of k is: " << k << endl;
    int count[k] = {0};

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    cout << "Count ARRAY is:" << endl;
    for (int i = 0; i < k; i++)
    {
        cout << count[i] << " ";
    }
    cout << endl;

    for (int i = 1; i < k; i++)
    {
        count[i] += count[i - 1];
    }

    cout << "Updated Count ARRAY is:" << endl;
    for (int i = 0; i < k; i++)
    {
        cout << count[i] << " ";
    }
    cout << endl;

    int b[n] = {0};
    for (int i = n-1; i >= 0; i--)
    {
        count[arr[i]]--;
        int key = count[arr[i]];
        b[key] = arr[i];
    }
     
    cout << "Sorted ARRAY is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}