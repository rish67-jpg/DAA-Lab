// Rishabh Ranjan 25/DA/054

#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int u, v, weight;
};
void bellmanFord(int V, int E, vector<Edge>& edges, int source) {
    const int INF = 1e9;
    vector<int> dist(V, INF);
    dist[source] = 0;
    for (int i = 1; i <= V -1; i++) {
        bool updated =false;
        for (auto edge : edges) {
            int u =edge.u;
            int v =edge.v;
            int w=edge.weight;

            if (dist[u]!=INF && dist[u]+ w <dist[v]) {
                dist[v]=dist[u] + w;
                updated =true;
            }
        }
        if (!updated)
            break;
    }
    for (auto edge : edges) {
        int u=edge.u;
        int v=edge.v;
        int w=edge.weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout<< "Negative-weight cycle detected!" << endl;
            return;
        }
    }
    cout << "Shortest distances from source vertex "
         << source << ":" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << "Vertex " << i << " : INF" << endl;
        else
            cout << "Vertex " << i << " : " << dist[i] << endl;
    }
}
int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<Edge> edges(E);
    cout << "Enter edges (source destination weight):" << endl;
    for (int i = 0; i < E; i++) {cin >> edges[i].u>> edges[i].v>> edges[i].weight;}
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    bellmanFord(V, E, edges, source);
    return 0;
}
