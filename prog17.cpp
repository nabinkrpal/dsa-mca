#include<iostream>
using namespace std;
const int MAX = 10;
const int INF = 9999; 
int parent[MAX];

struct Edge {
  int u, v, weight;
};

int adjMatrix[MAX][MAX], dist[MAX], visited[MAX];
int V, E;  

void displayadj(int arr[MAX][MAX],int size){
    for(int i=0; i<size ; i++){
        for(int j=0; j<size ; j++){
            cout<<arr[i][j]<<" ";        
        }
        cout<<endl;
    }
}


int find(int i) {
  if (parent[i] == i) {
    return i;
  }
  parent[i] = find(parent[i]);
  return parent[i];
}

void unionSets(int u, int v) {
  int root_u = find(u);
  int root_v = find(v);

  if (root_u != root_v) {
    parent[root_v] = root_u;
  }
}

int minDistance() {
  int min = INF, min_index = -1;
  for (int v = 0; v < V; v++) {
    if (visited[v] == 0 && dist[v] <= min) { 
      min = dist[v];
      min_index = v;
    }
  }
  return min_index;
}

void dijkstra(int start) {
  for (int i = 0; i < V; i++) {
    dist[i] = INF; 
    visited[i] = 0;
  }
  dist[start] = 0;

  for (int count = 0; count < V - 1; count++) {
    int u = minDistance();
    visited[u] = 1; 
    for (int v = 0; v < V; v++) {
      if (adjMatrix[u][v] && visited[v] == 0 && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v]) {
        dist[v] = dist[u] + adjMatrix[u][v];
      }
    }
  }

  cout << "Dijkstra's Shortest Path Algorithm:" << endl;
  for (int i = 0; i < V; i++) {
    cout << "Distance from " << start << " to " << i << " is: " << (dist[i] == INF ? -1 : dist[i]) << endl;
  }
}

void kruskal(Edge edgeList[], int edges) {
  for (int i = 0; i < V; i++) {
    parent[i] = i; 
  }

  for (int i = 0; i < edges - 1; i++) {
    for (int j = i + 1; j < edges; j++) {
      if (edgeList[i].weight > edgeList[j].weight) {
        swap(edgeList[i], edgeList[j]);
      }
    }
  }

  cout << "\nKruskal's Minimum Spanning Tree:" << endl;
  int mst_weight = 0;
  for (int i = 0; i < edges; i++) {
    int u = edgeList[i].u;
    int v = edgeList[i].v;
    if (find(u) != find(v)) {
      cout << u << " -- " << v << " == " << edgeList[i].weight << endl;
      unionSets(u, v); 
      mst_weight += edgeList[i].weight;
    }
  }
  cout << "Weight of MST: " << mst_weight << endl;
}

int main() {
  cout << "Enter the number of vertices: ";
  cin >> V;

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      adjMatrix[i][j] = 0;
    }
  }

  cout << "Enter the number of edges: ";
  cin >> E;
  Edge edgeList[E];

  for (int i = 0; i < E; i++) {
    int u, v, weight;
    cout << "Enter edge (u v weight): ";
    cin >> u >> v >> weight;
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
    edgeList[i].u = u;
    edgeList[i].v = v;
    edgeList[i].weight = weight;
  }

  displayadj(adjMatrix,V);
  int start;
  cout << "Enter the source vertex for Dijkstra's algorithm: ";
  cin >> start;
  dijkstra(start);
  kruskal(edgeList, E);

  return 0;
}