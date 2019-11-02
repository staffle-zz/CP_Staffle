#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
#ifdef LOCAL
#include "1.h"
#else
#define dbg(...) 
#endif
ll n,m,i,j,k,in,cnt = 0,l,r,u,v,x,y,tc = 1,mod = 1000000007  ;
const ll  mx = 100001 ;
vector<ll> a(mx);
vector < ll > adj[mx];    // stores the tree 
vector < ll > euler;      // tracks the eulerwalk 
vector < ll > depthArr;   // depth for each node corresponding 
                           // to eulerwalk 
vector<ll> xort(mx,0);
ll FAI[mx];     // stores first appearence index of every node 
ll level[mx];   // stores depth for all nodes in the tree 
ll ptr;         // pointer to euler walk 
ll dp[mx][18];  // sparse table 
ll logn[mx];    // stores log values 
ll p2[20];      // stores power of 2 
  
void buildSparseTable(ll n) 
{ 
    memset(dp,-1,sizeof(dp)); 
 
    for (ll i=1; i<n; i++) 
        dp[i-1][0] = (depthArr[i]>depthArr[i-1])?i-1:i; 

    for (ll l=1; l<15; l++) 
      for (ll i=0; i<n; i++) 
        if (dp[i][l-1]!=-1 and dp[i+p2[l-1]][l-1]!=-1) 
          dp[i][l] = 
            (depthArr[dp[i][l-1]]>depthArr[dp[i+p2[l-1]][l-1]])? 
             dp[i+p2[l-1]][l-1] : dp[i][l-1]; 
        else
             break; 
} 
  
ll query(ll l,ll r) 
{ 
    ll d = r-l; 
    ll dx = logn[d]; 
    if (l==r) return l; 
    if (depthArr[dp[l][dx]] > depthArr[dp[r-p2[dx]][dx]]) 
        return dp[r-p2[dx]][dx]; 
    else
        return dp[l][dx]; 
} 
  
void preprocess() 
{ 
    p2[0] = 1; 
    for (ll i=1; i<18; i++) 
        p2[i] = p2[i-1]*2; 
  
    ll val = 1,ptr=0; 
    for (ll i=1; i<mx; i++) 
    { 
        logn[i] = ptr-1; 
        if (val==i) 
        { 
            val*=2; 
            logn[i] = ptr; 
            ptr++; 
        } 
    } 
} 
void dfs(ll cur,ll prev,ll dep) 
{ 
    xort[cur] = a[cur]^xort[prev];
    if (FAI[cur]==-1) 
        FAI[cur] = ptr; 
  
    level[cur] = dep; 

    euler.push_back(cur); 
  
    ptr++; 
  
    for (auto x:adj[cur]) 
    { 
        if (x != prev) 
        { 
            dfs(x,cur,dep+1); 
  
            // pushing cur again in backtrack 
            // of euler walk 
            euler.push_back(cur); 
  
            // increment euler walk pointer 
            ptr++; 
        } 
    } 
} 
  
// Create Level depthArray corresponding 
// to the Euler walk Array 
void makeArr() 
{ 
    for (auto x : euler) 
        depthArr.push_back(level[x]); 
} 
  
ll LCA(ll u,ll v) 
{ 
    if (u==v) 
       return u; 
    if (FAI[u] > FAI[v]) 
       swap(u,v); 
    return euler[query(FAI[u], FAI[v])]; 
} 

void solve(){
    ll q;
    cin>>n>>q;
    for (ll i = 0; i < n; ++i)
    {
        cin>>a[i+1];
        adj[i+1].clear();
    }
    for (ll i = 0; i < n-1; ++i)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    preprocess();
    ptr = 0; 
    memset(FAI,-1,sizeof(FAI)); 
    dfs(1,0,0);
    makeArr();
    buildSparseTable(depthArr.size()); 
    for (ll i = 0; i < q; ++i)
    {
        ll u,v;
        cin>>u>>v;
        ll x = LCA(u,v);
        ll ans = 0;
        ans = xort[u]^xort[v]^a[x];
        cout << ans << endl;
    }
    euler.clear();
    depthArr.clear();

}
signed main(){                                          //F
    clock_t time = clock();                             //A
    ios_base::sync_with_stdio(0);                       //S
    cin.tie(0);                                         //T
    cout.tie(0);                                        //I
    cerr.tie(0);                                        //O
    if(1) cin>>tc;
    while(tc--)
        solve();
    dbg("Author - Amit dwivedi");
    return 0&fprintf(stderr, "Time ::%.3lf ms.\n",((clock() - time)*1000.0)/CLOCKS_PER_SEC);
}