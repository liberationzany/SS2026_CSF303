#include <bits/stdc++.h>
using namespace std;
const long long INF = 9e15;

vector<vector<long long>> floydWarshall(int n, const vector<vector<long long>>& w) {
    vector<vector<long long>> dist = w;
    for(int i = 0; i < n; i++) dist[i][i] = min(dist[i][i], 0LL);
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            if(dist[i][k] == INF) continue;
            for(int j = 0; j < n; j++){
                if(dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

int main(){
    int n = 4;
    vector<vector<long long>> w(n, vector<long long>(n, INF));
    w[0][1] = 5; w[0][3] = 10;
    w[1][2] = 3;
    w[2][3] = 1;
    for(int i=0;i<n;i++) w[i][i]=0;

    auto d = floydWarshall(n, w);
    cout << "Floyd-Warshall result:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d[i][j] >= INF/2) cout<<"INF "; else cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout << "\nReflection: Floyd-Warshall is DP on k-intermediate nodes; runtime O(n^3); handles negative edge weights (not negative cycle).\n";
    return 0;
}
