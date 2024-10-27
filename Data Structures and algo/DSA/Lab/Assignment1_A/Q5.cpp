/*
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.
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
    int totalElements = r*c;
    int count = 0;

    while(totalElements < count){
        
    }
    return 0;
}