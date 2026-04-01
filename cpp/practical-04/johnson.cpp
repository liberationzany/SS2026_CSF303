#include <bits/stdc++.h>
using namespace std;
const long long INF = 9e15;

vector<vector<long long>> johnson(int n, const vector<vector<pair<int,long long>>>& adj) {
    vector<long long> h(n, INF);
    for(int i=0;i<n;i++) h[i]=0;
    // Bellman-Ford style
    for(int i=0;i<n;i++){
        bool changed=false;
        for(int u=0;u<n;u++){
            if(h[u]==INF) continue;
            for(auto &e: adj[u]){
                int v=e.first; long long w=e.second;
                if(h[v] > h[u]+w){ h[v]=h[u]+w; changed=true; }
            }
        }
        if(!changed) break;
        if(i==n-1 && changed) throw runtime_error("Negative cycle");
    }

    vector<vector<pair<int,long long>>> adj2(n);
    for(int u=0;u<n;u++){
        for(auto &e: adj[u]){
            int v=e.first; long long w=e.second;
            long long w2 = w + h[u] - h[v];
            adj2[u].push_back({v,w2});
        }
    }

    auto dijkstra=[&](int src){
        vector<long long> d(n, INF);
        d[src]=0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto [du,u]=pq.top(); pq.pop();
            if(du != d[u]) continue;
            for(auto &e: adj2[u]){
                int v=e.first; long long w=e.second;
                if(d[v] > du + w){ d[v] = du + w; pq.push({d[v], v}); }
            }
        }
        vector<long long> res(n, INF);
        for(int i=0;i<n;i++) if(d[i]<INF) res[i]=d[i] + h[i] - h[src];
        return res;
    };

    vector<vector<long long>> all(n, vector<long long>(n, INF));
    for(int i=0;i<n;i++) all[i]=dijkstra(i);
    return all;
}

int main(){
    int n = 4;
    vector<vector<pair<int,long long>>> adj(n);
    adj[0].push_back({1,5}); adj[0].push_back({2,4});
    adj[1].push_back({2,-3}); adj[2].push_back({3,2});
    adj[3].push_back({1,1});

    try {
        auto d = johnson(n,adj);
        cout<<"Johnson result:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][j]>=INF/2) cout<<"INF "; else cout<<d[i][j]<<" ";
            }
            cout<<"\n";
        }
    } catch(exception &e){
        cout<<"Error: "<<e.what()<<"\n";
    }

    cout << "\nReflection: Johnson converts weights to non-negative using potentials then runs Dijkstra from each vertex; efficient for sparse graphs.\n";
    return 0;
}
