#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum)
{
    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true; // if sum == 0, then null subset is possible
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false; // if #elements == 0, but sum != 0, then ans is false
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j]; // this element can't be included
            }
            else
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]);
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (dp[i][j])
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }   

    return dp[n][sum];
}

int main()
{
    int arr[] = {2, 3, 5, 7, 10};
    int sum = 14;
    int n = 5;

    bool ans = isSubsetSum(arr, n, sum);
    cout << "subset with given sum is ";
    cout << (ans ? "possible" : "not possible") << '\n';
    return 0;
}

// #include <iostream>
// using namespace std;

// void solve(int a[], int n, int sum)
// {
//     int i, j;

//     int dp[n + 1][sum + 1];

//     for (j = 0; j <= sum; j++)
//         dp[0][j] = 0;

//     for (i = 0; i <= n; i++)
//         dp[i][0] = 1;

//     for (i = 1; i <= n; i++) // n = 5
//     {
//         for (j = 1; j <= sum; j++) // sum = 14
//         {
//             cout << "i: " << i << " & "
//                  << "j: " << j << endl;

//             if (j < a[i - 1])
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//             else
//             {
//                 dp[i][j] = (dp[i - 1][j]) || (dp[i - 1][j - a[i-1]]);
//             }
//         }
//     }

//     cout << "Hi" << endl;

//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= sum; j++)
//         {
//             cout << dp[i][j] << " ";
//         }
//         cout << endl;
//     }

//     if (dp[n][sum] == 1)
//         cout << "Possible" << endl;

//     else
//         cout << "Not Possible" << endl;
// }

// int main()
// {
//     int n = 5;
//     // cout << "Enter n" << endl;
//     // cin >> n;

//     int a[n];

//     cout << "Enter array elements: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     int sum = 14;
//     // cout << "Enter sum" << endl;
//     // cin >> sum;

//     solve(a, 5, 14);
// }