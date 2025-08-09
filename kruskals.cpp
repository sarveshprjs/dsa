#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Function to find set of an element (with path compression)
int findSet(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = findSet(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to union two sets (by rank)
void unionSets(vector<Subset>& subsets, int x, int y) {
    int xroot = findSet(subsets, x);
    int yroot = findSet(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    }
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function for sorting edges by weight
bool compareEdge(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Kruskal's Algorithm
void KruskalMST(int V, vector<Edge>& edges) {
    vector<Edge> result;  // Store the MST edges
    int e = 0; // Count of edges in MST
    int i = 0; // Index for sorted edges

    // Sort edges in increasing order of weight
    sort(edges.begin(), edges.end(), compareEdge);

    // Create V subsets (one for each vertex)
    vector<Subset> subsets(V);
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Process edges until MST has V-1 edges
    while (e < V - 1 && i < edges.size()) {
        Edge next_edge = edges[i++];

        int x = findSet(subsets, next_edge.src);
        int y = findSet(subsets, next_edge.dest);

        // If including this edge doesn't form a cycle
        if (x != y) {
            result.push_back(next_edge);
            unionSets(subsets, x, y);
            e++;
        }
    }

    // Print the MST
    cout << "Edges in the Minimum Spanning Tree:\n";
    int totalWeight = 0;
    for (auto& edge : result) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << "\n";
        totalWeight += edge.weight;
    }
    cout << "Total weight of MST: " << totalWeight << "\n";
}

// Main function
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (src dest weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    KruskalMST(V, edges);

    return 0;
}
