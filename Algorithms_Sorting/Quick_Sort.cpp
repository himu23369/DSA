// Quick Sort is based on divide and conquer technique
// Main thing is that array will be divided into further sub-arrays

#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int lb = start;   //lb is lower bound
    int ub = end;     //ub is upper bound

    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }

        while (arr[end] > pivot)
        {
            end--;
        }

        if (start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end;
}

void QuickSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    else if (start < end)
    {
        int key = partition(arr, start, end);
        QuickSort(arr, start, key - 1);
        QuickSort(arr, key + 1, end);
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

    cout << "Array before Quick Sort: " << endl;
    printArray(arr, n);
    QuickSort(arr, 0, n - 1);
    cout << "Array after Quick Sort:" << endl;
    printArray(arr, n);

    return 0;
}