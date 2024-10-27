/*
Write a program to find sum of every row and every column in a two-dimensional array.
*/

#include <iostream>
using namespace std;

int main()
{

    int r = 0, c = 0;
    cout << "Enter the number of rows and columns for 2D-array" << endl;
    cin >> r >> c;
    int arr[r][c]; // Array created statically
    for (int i = 0; i < r; i++)
    {
        cout << "Enter the elements of the " << i + 1 << " row" << endl;
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Sum of each row" << endl;

    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < c; j++)
        {
            sum += arr[i][j];
        }
        cout << "Row " << i + 1 << ": " << sum << endl;
    }

    cout << "Sum of each column" << endl;

    for (int i = 0; i < c; i++)
    {
        int sum = 0;
        for (int j = 0; j < r; j++)
        {
            sum += arr[j][i];
        }
        cout << "Column " << i + 1 << ": " << sum << endl;
    }

    return 0;
}