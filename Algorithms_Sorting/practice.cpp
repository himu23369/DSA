#include <iostream>
#include <stack>
#include <string>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int i = 0, j = 0, k = start;

    int arr1[n1];
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[start + i];
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
            i++;
            k++;
        }
        else if (arr1[i] > arr2[j])
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    else
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
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

bool isBalanced(string expression)
{
    int flag;
    stack<char> helper;

    if (expression[0] == ')')
    {
        return false;
    }

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '(')
        {
            helper.push(expression[i]);
        }
        else
        {
            char element = helper.top();
            if (element == '(')
            {
                flag = 1;
            }
            else
            {
                return false;
            }
            helper.pop();
        }
    }
    if (helper.size() != 0)
    {
        return false;
    }
    return true;
}