// 1. Breadth First Search (BFS)

#include <iostream>
using namespace std;

class Graph {
 private:
  int vertices;
  int adjMatrix[20][20];

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

  void BFS(int start) {
    bool visited[20] = {false};
    int queue[20];
    int front = 0;
    int rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    cout << "BFS Traversal starting from vertex " << start << ": ";

    while (front < rear) {
      int current = queue[front++];
      cout << current << " ";

      for (int i = 0; i < vertices; i++) {
        if (adjMatrix[current][i] == 1 && !visited[i]) {
          visited[i] = true;
          queue[rear++] = i;
        }
      }
    }

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

  cout << "\nEnter starting vertex for BFS: ";
  cin >> start;

  g.BFS(start);

  return 0;
}