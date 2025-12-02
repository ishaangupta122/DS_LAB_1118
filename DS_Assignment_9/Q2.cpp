// 2. Depth First Search (DFS)

#include <iostream>
using namespace std;

class Graph {
 private:
  int vertices;
  int adjMatrix[20][20];

  void DFSUtil(int vertex, bool visited[]) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 0; i < vertices; i++) {
      if (adjMatrix[vertex][i] == 1 && !visited[i]) {
        DFSUtil(i, visited);
      }
    }
  }

 public:
  Graph(int v) {
    vertices = v;

    for (int i = 0; i < vertices; i++) {
      for (int j = 0; j < vertices; j++) {
        adjMatrix[i][j] = 0;
      }
    }
  }

  void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
  }

  void DFS(int start) {
    bool visited[20] = {false};

    cout << "DFS Traversal starting from vertex " << start << ": ";
    DFSUtil(start, visited);
    cout << "\n";
  }

  void display() {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < vertices; i++) {
      for (int j = 0; j < vertices; j++) {
        cout << adjMatrix[i][j] << " ";
      }
      cout << "\n";
    }
  }
};

int main() {
  int vertices, edges, u, v, start;

  cout << "Enter number of vertices: ";
  cin >> vertices;

  Graph g(vertices);

  cout << "Enter number of edges: ";
  cin >> edges;

  cout << "Enter edges (u v):\n";
  for (int i = 0; i < edges; i++) {
    cin >> u >> v;
    g.addEdge(u, v);
  }

  g.display();

  cout << "\nEnter starting vertex for DFS: ";
  cin >> start;

  g.DFS(start);

  return 0;
}