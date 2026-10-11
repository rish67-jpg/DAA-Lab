#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 5

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i] &&
                (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        if (u == -1 || dist[u] == INT_MAX)
            break;

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nVertex\tShortest Distance from Source\n";

    for (int i = 0; i < V; i++) {
        cout << i << "\t";

        if (dist[i] == INT_MAX)
            cout << "Unreachable";
        else
            cout << dist[i];

        cout << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 9, 4},
        {5, 2, 9, 0, 2},
        {0, 0, 4, 2, 0}
    };

    int source;

    cout << "Enter the source vertex (0-4): ";
    cin >> source;

    if (source < 0 || source >= V) {
        cout << "Invalid source vertex!" << endl;
        return 1;
    }

    dijkstra(graph, source);

    return 0;
}
