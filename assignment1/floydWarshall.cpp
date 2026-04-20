#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

void floydWarshall(vector<vector<long long>>& dist, int V) {
    // Initialize diagonal to 0 (already done if input ensures it)
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < V; ++j) {
                if (dist[k][j] == INF) continue;
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Detect negative cycle: if any dist[i][i] < 0
    bool hasNegCycle = false;
    for (int i = 0; i < V; ++i) {
        if (dist[i][i] < 0) {
            hasNegCycle = true;
            break;
        }
    }

    if (hasNegCycle) {
        cout << "Graph contains a negative cycle.\n";
    } else {
        cout << "All-pairs shortest distance matrix:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<long long>> dist(V, vector<long long>(V, INF));
    for (int i = 0; i < V; ++i) dist[i][i] = 0;

    for (int i = 0; i < E; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w); // handle multiple edges
    }

    floydWarshall(dist, V);
    return 0;
}