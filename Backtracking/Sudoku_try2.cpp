#include <iostream>
using namespace std;

bool isPossible(int board[][9], int row, int column, int k)
{
    int flag = 1;
    // Checking in the row
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == k)
        {
            return false;
        }
    }
    cout << "Flag: " << flag << endl;

    // Checking in the column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][column] == k)
        {
            return false;
        }
    }
    cout << "Flag: " << flag << endl;

    // 9 0 0 0 2 0 7 5 0
    // 6 0 0 0 5 0 0 4 0
    // 0 2 0 4 0 0 0 1 0
    // 2 0 8 0 0 0 0 0 0
    // 0 7 0 5 0 9 0 6 0
    // 0 0 0 0 0 0 4 0 1
    // 0 1 0 0 0 5 0 8 0
    // 0 9 0 0 7 0 0 0 4
    // 0 8 2 0 4 0 0 0 6

    // Checking the box
    int rowFactor = row - (row % 3);
    int columnFactor = column - (column % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i + rowFactor][j + columnFactor] == k)
            {
                return false;
            }
        }
    }
    cout << "Flag: " << flag << endl;

    // In case no result from above three cases
    return true;
}

bool findEmptyLocation(int board[][9], int &row, int &column)
{
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == 0){
                row = i;
                column = j;
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int board[][9])
{
    int row, column;
    if(!findEmptyLocation(board,row,column)){
       return true;
    }

    for (int k = 1; k < 10; k++)
    {
        bool possible = isPossible(board, row, column, k);
        if (possible)
        {
            board[row][column] = k;

            if (solveSudoku(board))
            {
                return true;
            }
            board[row][column] = 0;
        }
    }
    return false;
}

int main()
{
    int board[9][9];
    cout << "Enter board" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    if (solveSudoku(board))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}