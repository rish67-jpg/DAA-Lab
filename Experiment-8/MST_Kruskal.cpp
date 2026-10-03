#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
    
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j])
                swap(root_i, root_j);
            parent[root_j] = root_i;
            if (rank[root_i] == rank[root_j])
                rank[root_i]++;
        }
    }
};

void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());

    DisjointSet ds(V);
    vector<Edge> result;
    int totalWeight = 0;

    for (const auto& edge : edges) {
        if (ds.find(edge.src) != ds.find(edge.dest)) {
            ds.unite(edge.src, edge.dest);
            result.push_back(edge);
            totalWeight += edge.weight;

            if (result.size() == V - 1) break;
        }
    }

    cout << "Edge \tWeight" << endl;
    for (const auto& edge : result) {
        cout << edge.src << " - " << edge.dest << " \t" << edge.weight << endl;
    }
    cout << "Total MST Weight: " << totalWeight << endl;
}

int main() {
    int V = 5;
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7}
    };

    kruskalMST(V, edges);

    return 0;
}
