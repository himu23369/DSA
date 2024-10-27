#include <iostream>
using namespace std;

// 2D arrays

int main()
{
    int m, n;
    cin >> m >> n;
    // m is no. of rows and n is no. of columns

    int **p = new int *[m];
    for (int i = 0; i < m; i++)
    {
        p[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }

    // Now we have to clear memory from heap also
    for (int j = 0; j < m; j++)
    {
        delete[] p[j];
    }
    delete[] p;

    return 0;
}
