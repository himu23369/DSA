// Finding missing number in sorted array
/*
Question:
--------
Given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in list. One of the integers is missing in the list. Write an efficient code to find the missing integer.
*/

#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " elements in sorted manner" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    for (int j = 1; j < size - 1; j++)
    {
        if (arr[j - 1] != arr[j] - 1)
        {
            cout << "Element " << arr[j] - 1 << " is missing" << endl;
            break;
        }

        if (arr[j + 1] != arr[j] + 1)
        {
            cout << "Element " << arr[j] + 1 << " is missing" << endl;
            break;
        }
    }

    return 0;
}