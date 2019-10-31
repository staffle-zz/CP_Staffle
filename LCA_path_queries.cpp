#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
#ifndef ONLINE_JUDGE
#include "1.h"
#else
#define dbg(...) 
#endif
#define ll long long

vector<int> adj[100005];
int dep[100005];
int par[100005][20];
int a[100005];
int dis[100005];

void dfs(int cv,int p,int d){
    dep[cv] = d;
    par[cv][0] = p;
    dis[cv] = dis[p]^a[cv];
    for(int i=0;i<adj[cv].size(); i++){
        if(adj[cv][i] != p){
            dfs(adj[cv][i],cv,d+1);
        }
    }
}

int lca(int u,int v){
    if(dep[u] > dep[v]){
        swap(u,v);
    }
   	for(int i=19; i>=0; i--){
        if(dep[u]+(1<<i) <= dep[v]){
            v = par[v][i];
        }
    }
    if(u == v){
        return u;
    }
    for(int i=19; i>=0; i--){
        if(par[u][i] == par[v][i]){
            continue;
        }
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}
void prep(int n){
	par[1][0] = 1;
     for (int j = 1; j <=19; ++j){
         for (int i = 1; i <=n; ++i){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }

}

void solve(){
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <=n; ++i)
    {
        cin >> a[i];
        adj[i].clear();
    }
    for (int i = 1; i <=n-1; ++i){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dis[0] = 0;
    dfs(1,0,0);
    prep(n);
    while(q--){
        int u,v;
        cin >> u >> v;
        int val = dis[u]^dis[v];
        val ^= a[lca(u,v)];
        cout << val << endl;
    }   
}
int tc = 1;
signed main(){                                          //F
    clock_t time = clock();                             //A
    ios_base::sync_with_stdio(0);                       //S
    cin.tie(0);                                         //T
    cout.tie(0);                                        //I
    cerr.tie(0);                                        //O
    if(1) cin>>tc; while(tc--) solve();
    return 0&fprintf(stderr, "Time ::%.3lf ms.\n",((clock() - time)*1000.0)/CLOCKS_PER_SEC);
}