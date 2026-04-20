#include <iostream>
#include <vector>
#include <limits>

using namespace std;
struct Edge {
    int u, v;
    long long w;
};

void bellmanFord(int V, int E, int src, const vector<Edge>& edges) {
    const long long INF = numeric_limits<long long>::max();
    vector<long long> dist(V, INF);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        bool updated = false;
        for (const auto& e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }
        if (!updated) break; // Early exit if no relaxation
    }

    // Check for negative weight cycle
    bool hasNegCycle = false;
    for (const auto& e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            hasNegCycle = true;
            break;
        }
    }

    if (hasNegCycle) {
        cout << "Graph contains a negative weight cycle reachable from source.\n";
    } else {
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << " : ";
            if (dist[i] == INF)
                cout << "INF\n";
            else
                cout << dist[i] << "\n";
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    int src;
    cin >> src;
    bellmanFord(V, E, src, edges);
    return 0;
}