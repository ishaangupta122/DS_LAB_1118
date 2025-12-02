// 4. Dijkstra's Shortest Path Algorithm

#include <iostream>
using namespace std;

class Graph {
 private:
  int vertices;
  int adjMatrix[20][20];

  int minDistance(int dist[], bool visited[]) {
    int min = 99999;
    int minIndex = -1;

    for (int v = 0; v < vertices; v++) {
      if (!visited[v] && dist[v] < min) {
        min = dist[v];
        minIndex = v;
      }
    }

    return minIndex;
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

  void addEdge(int u, int v, int w) {
    adjMatrix[u][v] = w;
    adjMatrix[v][u] = w;
  }

  void dijkstra(int src) {
    int dist[20];
    bool visited[20];
    int parent[20];

    for (int i = 0; i < vertices; i++) {
      dist[i] = 99999;
      visited[i] = false;
      parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
      int u = minDistance(dist, visited);
      visited[u] = true;

      for (int v = 0; v < vertices; v++) {
        if (!visited[v] && adjMatrix[u][v] && dist[u] != 99999 &&
            dist[u] + adjMatrix[u][v] < dist[v]) {
          dist[v] = dist[u] + adjMatrix[u][v];
          parent[v] = u;
        }
      }
    }

    cout << "\n=== Dijkstra's Shortest Path from vertex " << src << " ===\n";
    cout << "Vertex\tDistance\tPath\n";

    for (int i = 0; i < vertices; i++) {
      cout << i << "\t" << dist[i] << "\t\t";

      // Print path
      int path[20];
      int pathIndex = 0;
      int current = i;

      while (current != -1) {
        path[pathIndex++] = current;
        current = parent[current];
      }

      for (int j = pathIndex - 1; j >= 0; j--) {
        cout << path[j];
        if (j > 0) {
          cout << " -> ";
        }
      }

      cout << "\n";
    }
  }
};

int main() {
  int vertices, edges, u, v, w, src;

  cout << "Enter number of vertices: ";
  cin >> vertices;

  Graph g(vertices);

  cout << "Enter number of edges: ";
  cin >> edges;

  cout << "Enter edges (u v weight):\n";
  for (int i = 0; i < edges; i++) {
    cin >> u >> v >> w;
    g.addEdge(u, v, w);
  }

  cout << "\nEnter source vertex: ";
  cin >> src;

  g.dijkstra(src);

  return 0;
}