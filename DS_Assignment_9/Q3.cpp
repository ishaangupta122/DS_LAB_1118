// 3. Minimum Spanning Tree (Kruskal and Prim)

#include <iostream>
using namespace std;

struct Edge {
  int src, dest, weight;
};

class Graph {
 private:
  int vertices;
  Edge edges[100];
  int edgeCount;
  int adjMatrix[20][20];

  int findParent(int parent[], int i) {
    if (parent[i] == i) {
      return i;
    }
    return findParent(parent, parent[i]);
  }

  void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);

    if (rank[xroot] < rank[yroot]) {
      parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
      parent[yroot] = xroot;
    } else {
      parent[yroot] = xroot;
      rank[xroot]++;
    }
  }

  int minKey(int key[], bool mstSet[]) {
    int min = 99999;
    int minIndex = -1;

    for (int v = 0; v < vertices; v++) {
      if (!mstSet[v] && key[v] < min) {
        min = key[v];
        minIndex = v;
      }
    }

    return minIndex;
  }

 public:
  Graph(int v) {
    vertices = v;
    edgeCount = 0;

    for (int i = 0; i < vertices; i++) {
      for (int j = 0; j < vertices; j++) {
        adjMatrix[i][j] = 0;
      }
    }
  }

  void addEdge(int u, int v, int w) {
    edges[edgeCount].src = u;
    edges[edgeCount].dest = v;
    edges[edgeCount].weight = w;
    edgeCount++;

    adjMatrix[u][v] = w;
    adjMatrix[v][u] = w;
  }

  void kruskalMST() {
    // Sort edges by weight
    for (int i = 0; i < edgeCount - 1; i++) {
      for (int j = 0; j < edgeCount - i - 1; j++) {
        if (edges[j].weight > edges[j + 1].weight) {
          Edge temp = edges[j];
          edges[j] = edges[j + 1];
          edges[j + 1] = temp;
        }
      }
    }

    int parent[20];
    int rank[20] = {0};

    for (int i = 0; i < vertices; i++) {
      parent[i] = i;
    }

    cout << "\n=== Kruskal's MST ===\n";
    cout << "Edge \tWeight\n";

    int mstWeight = 0;
    int edgesAdded = 0;

    for (int i = 0; i < edgeCount && edgesAdded < vertices - 1; i++) {
      int x = findParent(parent, edges[i].src);
      int y = findParent(parent, edges[i].dest);

      if (x != y) {
        cout << edges[i].src << " - " << edges[i].dest << "\t" << edges[i].weight << "\n";
        mstWeight += edges[i].weight;
        unionSets(parent, rank, x, y);
        edgesAdded++;
      }
    }

    cout << "Total weight: " << mstWeight << "\n";
  }

  void primMST() {
    int parent[20];
    int key[20];
    bool mstSet[20];

    for (int i = 0; i < vertices; i++) {
      key[i] = 99999;
      mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
      int u = minKey(key, mstSet);
      mstSet[u] = true;

      for (int v = 0; v < vertices; v++) {
        if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v]) {
          parent[v] = u;
          key[v] = adjMatrix[u][v];
        }
      }
    }

    cout << "\n=== Prim's MST ===\n";
    cout << "Edge \tWeight\n";

    int mstWeight = 0;
    for (int i = 1; i < vertices; i++) {
      cout << parent[i] << " - " << i << "\t" << adjMatrix[i][parent[i]] << "\n";
      mstWeight += adjMatrix[i][parent[i]];
    }

    cout << "Total weight: " << mstWeight << "\n";
  }
};

int main() {
  int vertices, edges, u, v, w;

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

  g.kruskalMST();
  g.primMST();

  return 0;
}