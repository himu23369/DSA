// DFS

#include <iostream>
using namespace std;

/*
void print(int **edges, int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        cout << i << ": ";
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1)
            {
                count++;
                if (count == 1)
                {
                    cout << j;
                }
                else
                {
                    cout << "," << j;
                }
            }
        }
        cout << endl;
    }
}
*/

void printGraph(int **edges, int n, int sv, bool *visited)
{
    cout << sv << " ";
    visited[sv] = 1;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            printGraph(edges, n, i, visited);
        }
    }
}
// Isme basically ham depth tk jaa rhe hain pehle and phir vapis aa ke search, kind of DFS

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printGraph(edges, n, i, visited);
        }
    }
    delete[] visited;
}

int main()
{
    int n; // n is number of vertices from 0 to n-1
    int e; // e is number of edges

    cout << "Enter the number of vertices n" << endl;
    cin >> n;
    cout << "Enter the number of edges e" << endl;
    cin >> e;

    // Initialising whole matrix with zero
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    // Ask the edge
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cout << "Enter the first and second vertice" << endl;
        cin >> f;
        cin >> s;

        if (f >= n || s >= n)
        {
            cout << "Invalid entry" << endl;
        }

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // Print the matrix
    cout << "Adjacency matrix is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }

    cout << "DFS: " << endl;
    DFS(edges, n);

    /*
         bool *visited = new bool[n];
            for (int i = 0; i < n; i++)
            {
                visited[i] = 0;
            }

         cout << "Graph: " << endl;
            printGraph(edges, n, 0, visited);


        // Delete dynamically allocated memory
        delete[] visited;
    */

    return 0;
}