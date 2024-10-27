#include <iostream>
#include<algorithm>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
}

int main()
{
    int n;
    cout << "Enter the number of activities to perform: " << endl;
    cin >> n;

    int start[n];
    cout << "Enter start time: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }

    int finish[n];
    cout << "Enter finish time: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> finish[i];
    }

    cout << "Start time array: ";
    printArr(start, n);
    cout << "Finish time array: ";
    printArr(finish, n);

    // Sorting finishing time array
    bubbleSort(finish, n);
    cout << "Finish time array: ";
    for (int i = 0; i < n; i++)
    {
        cout << finish[i] << " ";
    }
    
    cout << endl;
    int k = 0;
    cout << "Activities according to indexes are: " << 0 << " ";
    
    for(int i = 1; i < n; i++){
        if(start[i] >= finish[k]){
            cout << i << " ";
            k = i;
        }
    }

    return 0;
}