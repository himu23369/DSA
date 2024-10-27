// Merge Sort - Works on divide and conquer

//Time Complexity - O(nlogn)
//Space Complexity - O(n)

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

void merge(int arr[], int startIndex, int mid, int endIndex)
{
    int n1 = mid - startIndex + 1;
    int n2 = endIndex - mid;
    int i = 0, j = 0, k = startIndex;

    int arr1[n1];
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[startIndex + i];
    }

    int arr2[n2];
    for (int j = 0; j < n2; j++)
    {
        arr2[j] = arr[mid + 1 + j];
    }

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = arr1[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = arr2[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int startIndex, int endIndex)
{
    if (startIndex < endIndex)
    {
        int mid = (startIndex + endIndex) / 2;
        mergeSort(arr, startIndex, mid);
        mergeSort(arr, mid + 1, endIndex);
        merge(arr, startIndex, mid, endIndex);
    }
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

    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}