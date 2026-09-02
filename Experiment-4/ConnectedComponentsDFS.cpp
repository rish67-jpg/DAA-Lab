// Rishabh Ranjan 25/DA/054

#include <iostream>

using namespace std;

void DFS(int u, int V, int adj[][100], bool visited[]) {
    visited[u] = true;
    cout << u << " ";

    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            DFS(v, V, adj, visited);
        }
    }
}

void findConnectedComponents(int V, int adj[][100]) {
    bool visited[100] = {false};
    int componentCount = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            componentCount++;
            cout << "Component " << componentCount << ": ";
            DFS(i, V, adj, visited);
            cout << endl;
        }
    }
}

int main() {
    int V = 5;
    int adj[100][100] = {0};

    // Edge 0 - 1
    adj[0][1] = 1;
    adj[1][0] = 1;

    // Edge 1 - 2
    adj[1][2] = 1;
    adj[2][1] = 1;

    // Edge 3 - 4
    adj[3][4] = 1;
    adj[4][3] = 1;

    cout << "Connected Components:" << endl;
    findConnectedComponents(V, adj);

    return 0;
}
