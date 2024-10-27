#include <iostream>
using namespace std;

int board[11][11];

bool isPossible(int n, int row, int column)
{
    // Look in the same column
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][column] == 1)
        {
            return false;
        }
    }
    // Look in Upper left diagonal
    for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    // Look in Upper Right diagonal
    for (int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

void nQueenHelper(int n, int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return;
    }

    // Place at all possible positions and move at smaller problem
    for (int j = 0; j < n; j++)
    {
        if (isPossible(n, row, j))
        {
            board[row][j] = 1;
            nQueenHelper(n, row + 1);
            board[row][j] = 0;
        }
    }
    return;
}

void placeNQueens(int n)
{
    // Initialising the matrix entries with 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    nQueenHelper(n,0);
}

int main()
{
    placeNQueens(4);

    return 0;
}