#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cout << "Enter number of nodes" << endl;  
    cin >> n;

    cout << "Enter number of edges" << endl;
    cin >> m;
  
  /*
    //Creating a adjacency matrix
    int adj[n+1][m+1]; 
    for(int i = 0; i < m; i++){
        int f,s;
        cin >> f >> s;
        adj[f][s] = 1;
        adj[s][f] = 1;
    }
    //Disadvantage of this is space which is of order n^2
  */
 
    /*
    Space Complexity: O(2E) for undirected graph, O(E) for directed graph
    We will be using Adjacency List to solve space issue
    */

   vector<int> adj[n+1]; //(n+1) for 1-indexed and n for 0-indexed
   for(int i = 0; i < m; i++){
      int u,v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   
    return 0;
}

