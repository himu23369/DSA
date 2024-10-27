#include <iostream>
using namespace std;

void printSolution(int **solution, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void mazeHelp(int maze[][20], int n, int **solution, int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        solution[x][y] = 1;
        printSolution(solution, n);
        return;
    }

    if (x >= n || x < 0 || y >= n || y < 0 || maze[x][y] ==  0 || solution[x][y] == 1)
    {
        return;
    }

    solution[x][y] = 1;
    mazeHelp(maze, n, solution, x - 1, y); // up
    mazeHelp(maze, n, solution, x + 1, y); // down
    mazeHelp(maze, n, solution, x, y - 1); // left
    mazeHelp(maze, n, solution, x, y + 1); // right
    solution[x][y] = 0;
}

void ratInAMaze(int maze[20][20], int n)
{
    int **solution = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solution[i] = new int[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            solution[i][j] = 0;
        }
    }

    mazeHelp(maze, n, solution, 0, 0);
}

int main()
{
    int n;
    cout << "Enter n" << endl;
    cin >> n;

    int maze[20][20];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           cin >> maze[i][j];
        }
    }   
    ratInAMaze(maze,n);
    return 0;
}
