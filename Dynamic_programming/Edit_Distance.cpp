#include <iostream>
#include <cstring>
using namespace std;

int editDistance(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    int **output = new int *[m + 1];

    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }

    // fill the 1st row
    for (int i = 0; i <= n; i++)
    {
        output[0][i] = i;
    }

    // fill the 1st column
    for (int i = 0; i <= m; i++)
    {
        output[i][0] = i;
    }

    // fill the rest
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[m-i] == s2[n-j])
            {
                output[i][j] = output[i - 1][j - 1];
            }
            else
            {
                int x = output[i - 1][j];
                int y = output[i][j - 1];
                int z = output[i - 1][j - 1];
                output[i][j] = 1 + min(x, min(y, z));
            }
        }
    }

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return output[m - 1][n - 1];
}

using namespace std;

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << endl;
}