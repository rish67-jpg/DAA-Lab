#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

struct Edge {
    int u, v, w;
};

void primMST(int V, const vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> key(V, 1e9);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty()) {
        pii current = pq.top();
        int u = current.second;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;
    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << key[i] << endl;
        totalWeight += key[i];
    }
    cout << "Total MST Weight: " << totalWeight << endl;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    primMST(V, adj);

    return 0;
}
