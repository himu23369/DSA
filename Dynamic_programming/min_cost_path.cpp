#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// Brute force approach(Complexity will be something exponential like 3^n)
int findCost(int **input, int row, int column, int n, int m)
{
    // Base case
    if (row == n - 1 && column == m - 1)
    {
        return input[row][column];
    }

    if (row >= n || column >= m)
    {
        return INT_MAX;
    }

    // Recursive call
    int right = findCost(input, row, column + 1, n, m);
    int down = findCost(input, row + 1, column, n, m);
    int diagonal = findCost(input, row + 1, column + 1, n, m);

    // Small calculation
    return input[row][column] + fmin(right, fmin(down, diagonal));
}

int minCostPath(int **input, int n, int m)
{
    return findCost(input, 0, 0, n, m);
}

// Memoization
int findCost2(int **input, int **ans, int i, int j, int n, int m)
{
    // Base case
    if (i == n - 1 && j == m - 1)
    {
        ans[i][j] = input[i][j];
        return input[i][j];
    }

    if (i >= n || j >= m)
    {
        return INT_MAX;
    }

    if (ans[i][j] != -1)
    {
        return ans[i][j];
    }

    int right = findCost2(input,ans, i, j + 1, n, m);
    int down = findCost2(input,ans, i + 1, j, n, m);
    int diagonal = findCost2(input,ans, i + 1, j + 1, n, m);

    int a = input[i][j] + min(right, min(down, diagonal));

    return a;
}
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         int right = findCost(input, i, j + 1, n, m);
    //         int down = findCost(input, i + 1, j, n, m);
    //         int diagonal = findCost(input, i + 1, j + 1, n, m);
    //         ans[i][j] = input[i][j] + min(right, min(down, diagonal));
    //     }
    // }

int minCostPath2(int **input, int n, int m)
{
    int **ans = new int *[n];
    for (int i = 0; i < m; i++)
    {
        ans[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[i][j] = -1;
        }
    }

    return findCost2(input, ans, 0, 0, n, m);
}

//Using Dynamic Programming
// int minCostPath3(int **input, int n, int m){

// }

int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Brute force method: " << minCostPath(arr, n, m) << endl;
    cout << "Memoization: " << minCostPath2(arr, n, m) << endl;
    // cout << "Dynamic Programming: " << minCostPath3(arr, n, m) << endl;
}