#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int primMST(int V, const vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> inMST(V, false);
    
    pq.push({0, 0});
    int totalWeight = 0;

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        totalWeight += weight;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (!inMST[v]) {
                pq.push({w, v});
            }
        }
    }

    return totalWeight;
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

    int minWeight = primMST(V, adj);
    cout << "Weight of Minimum Spanning Tree: " << minWeight << endl;

    return 0;
}
