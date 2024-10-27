//LCS is Least Common Subsequence

#include <iostream>
using namespace std;

// Brute force
int lcs(string s, string t)
{
    // Base case
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }

    // Recursive call
    if (s[0] == t[0])
    {
        return 1 + lcs(s.substr(1), t.substr(1));
    }
    else
    {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        // int c = lcs(s.substr(1), t.substr(1)); //This can be ignored will be taken care of internally

        return max(a, b);
    }
}
// Time complexity exponential 2^n

// Memoization
int lcs_mem_helper(string s, string t, int **output)
{
    int m = s.size();
    int n = t.size();

    // Base case
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (output[m][n] != -1)
    {
        return output[m][n];
    }

    int ans;
    // Recursive call
    if (s[0] == t[0])
    {
        ans = 1 + lcs_mem_helper(s.substr(1), t.substr(1), output);
    }
    else
    {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        int c = lcs(s.substr(1), t.substr(1));
        ans = max(a, max(b, c));
    }
    output[m][n] = ans;
    return ans;
}

int lcs_mem(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }
    return lcs_mem_helper(s, t, output);
}

// DP(use iterations)
// First step is to create an output array
// Then fill first row and column with 0 value
// So, ham pure matrix ko row by row fill krdenge from L to R

int lcs_dp(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i < n; i++)
    {
        output[i] = new int[n + 1];
    }

    // Fill 1st row
    for (int i = 0; i <= n; i++)
    {
        output[0][i] = 0;
    }
    // Fill 1st column
    for (int i = 0; i <= m; i++)
    {
        output[i][0] = 0;
    }
    // Fill remaining
    for (int i = 1; i <= m; i++)
    { //note that i means length of s and j length of t 
        for (int j = 1; j <= n; j++)
        {
            // check if char matches
            if (s[m - i] == t[n - j])
            {
                output[i][j] = 1 + output[i - 1][j - 1];
            }
            else
            {
                int a = output[i-1][j];
                int b = output[i][j-1];
                output[i][j] = max(a,b);
            }
        }
    }
    return output[m][n];
}

int main()
{

    string s1, s2;
    cout << "Enter two strings" << endl;
    cout << "s1: ";
    cin >> s1;
    cout << "s2: ";
    cin >> s2;
    cout << "Answer with Brute Force: " << lcs(s1, s2) << endl;
    cout << "Answer with Memoziation: " << lcs_mem(s1, s2) << endl;
    cout << "Answer with DP: " << lcs_dp(s1, s2) << endl;

    return 0;
}