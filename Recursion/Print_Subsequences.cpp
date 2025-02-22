// Subsequence -> A contigous/non-contigous sequence which follows the order

#include <iostream>
#include<vector>
using namespace std;

// Recursive function to print all possible subsequences for given array
void printSubsequences(int arr[], int index, vector<int> &subarr, int n)
{
    if (index == n)
    {
        for (auto it : subarr)
        {
            cout << it << " ";
        }
        if (subarr.size() == 0)
            cout << "{}";

        cout << endl;
        return;
    }
    else
    {
        // pick the current index into the subsequence.
        subarr.push_back(arr[index]);

        printSubsequences(arr, index + 1, subarr, n);

        subarr.pop_back();

        // not picking the element into the subsequence.
        printSubsequences(arr, index + 1, subarr, n);
    }
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vec;

    printSubsequences(arr, 0, vec, n);

    return 0;
}

