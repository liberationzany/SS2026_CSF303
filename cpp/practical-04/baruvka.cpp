#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 9e15;

struct DSU { vector<int> p; DSU(int n): p(n,-1){}; int find(int a){ return p[a]<0 ? a : p[a]=find(p[a]); } bool unite(int a,int b){ a=find(a); b=find(b); if(a==b) return false; if(p[a]>p[b]) swap(a,b); p[a]+=p[b]; p[b]=a; return true; }};

ll baruvka(int n, const vector<tuple<int,int,ll>>& edges, vector<pair<int,int>>& chosen){
    DSU dsu(n);
    int comp=n;
    ll sum=0;
    while(comp>1){
        vector<int> cheapest(n,-1);
        for(int i=0;i<edges.size();i++){
            auto [u,v,w] = edges[i];
            int ru=dsu.find(u), rv=dsu.find(v);
            if(ru==rv) continue;
            if(cheapest[ru]==-1 || get<2>(edges[cheapest[ru]]) > w) cheapest[ru]=i;
            if(cheapest[rv]==-1 || get<2>(edges[cheapest[rv]]) > w) cheapest[rv]=i;
        }
        bool progress=false;
        for(int i=0;i<n;i++){
            if(cheapest[i]==-1) continue;
            auto [u,v,w] = edges[cheapest[i]];
            if(dsu.unite(u,v)){
                sum+=w;
                chosen.push_back({u,v});
                comp--;
                progress=true;
            }
        }
        if(!progress) break;
    }
    return sum;
}

int main(){
    int n=4;
    vector<tuple<int,int,ll>> edges={
        {0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}
    };
    vector<pair<int,int>> chosen;
    ll cost = baruvka(n, edges, chosen);
    cout<<"Baruvka MST cost: "<<cost<<"\n";
    cout<<"Edges:\n";
    for(auto &e: chosen) cout<<e.first<<" - "<<e.second<<"\n";
    cout<<"\nReflection: Baruvka repeatedly picks cheapest outgoing edge per component and merges; excellent support for parallelism; complexity O(E log V).\n";
    return 0;
}
