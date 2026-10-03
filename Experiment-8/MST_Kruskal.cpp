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

int kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());

    DisjointSet ds(V);
    int totalWeight = 0;
    int edgesCount = 0;

    for (const auto& edge : edges) {
        if (ds.find(edge.src) != ds.find(edge.dest)) {
            ds.unite(edge.src, edge.dest);
            totalWeight += edge.weight;
            edgesCount++;

            if (edgesCount == V - 1) break;
        }
    }

    return totalWeight;
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

    int minWeight = kruskalMST(V, edges);
    cout << "Weight of Minimum Spanning Tree: " << minWeight << endl;

    return 0;
}
