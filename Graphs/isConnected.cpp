#include <iostream>
using namespace std;

void isConnected(bool **edges, int n, int sv, bool *visited){
   visited[sv] = true;
   cout << "true for: " << sv << endl;
 
   for(int i = 0; i < n; i++){
      if(i == sv){
        continue;
      }
      if(!visited[i] && edges[sv][i] == 1){
         isConnected(edges, n, i, visited);
      } 
   }    
}

int main() {
  int n, e;
  cout << "Enter n and e" << endl;
  cin >> n >> e;

  bool **edges = new bool *[n];
  for (int i = 0; i < n; i++) {
    edges[i] = new bool[n];
    for (int j = 0; j < n; j++) {
      edges[i][j] = false;
    }
  }

  for (int i = 0; i < e; i++) {
    int start, end;
    cout << "Enter " << i+1 << " edge" << endl;
    cin >> start >> end;
    edges[start][end] = true;
    edges[end][start] = true;
  }

  bool *visited = new bool[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }

  isConnected(edges, n, 0, visited);
  
  cout << "Visited Array: ";
  for(int i = 0; i < n; i++){
     cout << visited[i] << " ";
  }
  cout << endl;
  
  int i;
  for(i = 0; i < n; i++){
      if(visited[i] == false){
        cout << "false";
        break;
      }
  }
  
  if(i == n){
    cout << "true";
  }

  return 0;
}