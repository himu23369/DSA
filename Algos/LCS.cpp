// Dynamic Programming can be applied in this because of optimal sub-structure and overlapping subproblems
// Memoization Approach(Top Down approach)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs_Recursive(string s1, string s2, int m, int n)
{

    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (s1[m - 1] == s2[n - 1])
    {
        return 1 + lcs_Recursive(s1, s2, m - 1, n - 1);
    }
    else
    {
        return max(lcs_Recursive(s1, s2, m, n - 1), lcs_Recursive(s1, s2, m - 1, n));
    }
}

int lcs_memoization(string s1, string s2, int m, int n, vector<vector<int>> &v)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (v[m][n] != -1)
    {
        return v[m][n];
    }

    if (s1[m - 1] == s2[n - 1])
    {
        v[m][n] = 1 + lcs_memoization(s1, s2, m - 1, n - 1, v);
    }

    else
    {
        v[m][n] = max(lcs_memoization(s1, s2, m, n - 1, v), lcs_memoization(s1, s2, m - 1, n, v));
    }

    return v[m][n];
}

int lcs_DP(string s1, string s2, int m, int n, vector<vector<int>> &v)
{
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                v[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                v[i][j] = 1 + v[i - 1][j - 1];
            }
            else
            {
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
            }
        }
    }
    return v[m][n];
}

void print_Matrix(vector<vector<int>> &v, int m, int n)
{
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Enter 2 strings" << endl;

    string s1, s2;
    cin >> s1 >> s2;

    int m = s1.length();
    int n = s2.length();
    cout << m << endl;

    cout << "With Recursive method: " << lcs_Recursive(s1, s2, m, n) << endl;

    vector<vector<int>> v1(m + 1, vector<int>(n + 1, -1));
    cout << "With Memoization approach: " << lcs_memoization(s1, s2, m, n, v1) << endl;
    cout << "Matrix is: " << endl;
    print_Matrix(v1, m, n);

    vector<vector<int>> v2(m + 1, vector<int>(n + 1, -1));
    cout << "With Dynamic Programming: " << lcs_DP(s1, s2, m, n, v2) << endl;
    cout << "Matrix is: " << endl;
    print_Matrix(v2, m, n);

    return 0;
}

