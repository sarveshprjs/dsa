#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii; // {distance, vertex}

// Dijkstra's algorithm function
void dijkstra(int V, vector<vector<pii>>& adj, int src) {
    vector<int> dist(V, INT_MAX); // distance array
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Skip if we already found a shorter path
        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << "\n";
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pii>> adj(V); // adjacency list

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed graph
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(V, adj, src);

    return 0;
}
