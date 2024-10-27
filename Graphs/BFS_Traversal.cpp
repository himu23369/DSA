// BFS is Breadth First Search

#include <iostream>
#include <queue>
using namespace std;

/*
void BFS_traversal(int **edges, int n, int sv, bool *visited) {
  queue<int> q;
  q.push(sv);
  visited[sv] = 1;

  while (q.size() != 0) {
    sv = q.front();
    for (int i = 0; i < n; i++) {
      if (i == sv) {
        continue;
      }
      if (edges[sv][i] == 1) {
        if (visited[i]) {
          continue;
        }
        q.push(i);
        visited[i] = 1;
      }
    }
    cout << q.front() << " ";
    q.pop();
  }
}
*/

// In case tree is connected(For disconnected, this will not work)
void BFS_traversal(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << " ";
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
            {
                continue;
            }
            if (edges[currentVertex][i] == true && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;  
            }
        }
    }   
}

// For disconnected graph
void BFS(int **edges, int n)
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
            BFS_traversal(edges, n, i, visited);
        }
    }

    delete[] visited;
}

int main()
{
    int n; // n is number of vertices from 0 to n-1
    int e; // e is number of edges

    cin >> n;
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
        cin >> f;
        cin >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    /*
        if (e != 0)
        {
            BFS_traversal(edges, n, 0);
        }
        else if (e == 0)
        {
            for (int i = 0; i < n; i++)
            {
                cout << i << " ";
            }
        }
    */

    cout << "BFS: " << endl;
    BFS(edges, n);

    // Deleting the dynamically created array
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}