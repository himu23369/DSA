/*
BINARY SEARCH ALGORITHM -> Time Complexity - O(log n)
*/
#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the sorted array" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " elements in a sorted manner" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int searchElement;
    cout << "Enter the element to be searched" << endl;
    cin >> searchElement;

    int start = 0, flag = 0;
    int end = size - 1;
    int mid = -1;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] == searchElement)
        {
            cout << "Element is present at index " << mid << endl;
            flag = 1;
            break;
        }

        else if (arr[mid] > searchElement)
        {
            end = mid - 1;
        }

        else if (arr[mid] < searchElement)
        {
            start = mid + 1;
        }
    }

    if (flag == 0)
    {
      cout << "Element not found" << endl;
    }

    return 0;
}