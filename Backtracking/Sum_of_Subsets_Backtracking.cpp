#include <bits/stdc++.h>
using namespace std;

void subset_sum(vector<int> &A, vector<int> &subset, int sum, int index, int &count)
{
    // cout << "Sum: " << sum << " Index: " << index << " Subset: ";
    // for (int i = 0; i < subset.size(); i++)
    // {
    //     cout << subset[i] << " ";
    // }
    // cout << endl;

    if (sum == 0)
    {
        // We have found a valid subset that sums up to the target sum
        count++;
        cout << count << ": ";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << " ";
        }
        cout << endl;
        return;
    }

    if (sum < 0 || index >= A.size())
    {
        // The current subset is invalid, backtrack
        return;
    }

    // Add the current element to the subset and explore the next element
    subset.push_back(A[index]);
    subset_sum(A, subset, sum - A[index], index + 1, count);

    // Remove the current element from the subset and explore the next element
    subset.pop_back();
    subset_sum(A, subset, sum, index + 1, count);
}

int main()
{
    int n, sum;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> A(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << "Enter the target sum: ";
    cin >> sum;

    vector<int> subset;
    int count = 0;
    subset_sum(A, subset, sum, 0, count);

    if (count == 0)
    {
        cout << "No subset found that sums up to " << sum << endl;
    }

    return 0;
}
