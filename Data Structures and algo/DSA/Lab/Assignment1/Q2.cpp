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

    int newSize = 1;
    int index = 1;
    int i = 0, j = 0;
    for (int k = 0; k < size; k++)
    {
        if (arr[j] == arr[j + 1])
        {
            j++;
        }
        else if (arr[j] != arr[j + 1])
        {
            arr[index] = arr[j + 1];
            j++;
            i = j;
            index++;
            newSize++;
        }
    }

    cout << "Array is: ";
    for (int i = 0; i < newSize - 1; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}