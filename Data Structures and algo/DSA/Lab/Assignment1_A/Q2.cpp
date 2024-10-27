// Transpose of a matrix

#include <iostream>
using namespace std;

int main()
{
    int r, c;
    cout << "Enter the value of r and c" << endl;
    cin >> r >> c;
    int a[r][c];

    cout << "Enter the elements of the matrix" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Enter the elements of the " << i << " row and " << j << " column" << endl;
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(i < j){
               int temp = a[i][j];
               a[i][j] = a[j][i];
               a[j][i] = temp; 
            }
        }
    }

    cout << "Transpose of the Matrix" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}