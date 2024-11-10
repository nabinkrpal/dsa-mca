#include <iostream>
using namespace std;

const int MAX = 10;

int adjMatrix[MAX][MAX] = {0};

void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void DFS(int start, int vertices) {
    bool visited[MAX] = {false};
    int stack[MAX];
    int top = -1;

    stack[++top] = start;

    cout << "DFS starting from vertex " << start << ": ";
    
    while (top >= 0) {
        int v = stack[top--];

        if (!visited[v]) {
            cout << v << " ";
            visited[v] = true;

            for (int i = vertices - 1; i >= 0; i--) {
                if (adjMatrix[v][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    cout << endl;
}

void BFS(int start, int vertices) {
    bool visited[MAX] = {false};
    int queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = true;

    cout << "BFS starting from vertex " << start << ": ";
    
    while (front < rear) {
        int v = queue[front++];
        cout << v << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[v][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
    cout << endl;
}
void displayadj(int arr[MAX][MAX],int size){
    for(int i=0; i<size ; i++){
        for(int j=0; j<size ; j++){
            cout<<arr[i][j]<<" ";        
        }
        cout<<endl;
    }
}

int main() {
    int vertices;
    cout << "Enter the number of vertices (max " << MAX << "): ";
    cin >> vertices;

    if (vertices > MAX) {
        cout << "Number of vertices exceeds the maximum allowed (" << MAX << ")." << endl;
        return 1;
    }

    for (int i = 0; i < vertices; i++) {
        int connectedNode;
        cout << "Enter the nodes connected to node " << i << " (enter -1 to stop): ";
        
        while (true) {
            cin >> connectedNode;
            if (connectedNode == -1) break;
            if (connectedNode >= 0 && connectedNode < vertices) {
                addEdge(i, connectedNode);
            } else {
                cout << "Invalid node. Enter a valid node between 0 and " << vertices - 1 << ": ";
            }
        }
    }
    cout<<"Adjacency Matrix: "<<endl;
    displayadj(adjMatrix,vertices);

    int startNode;
    cout << "Enter the starting vertex for traversal: ";
    cin >> startNode;

    DFS(startNode, vertices);
    BFS(startNode, vertices);


    return 0;
}
