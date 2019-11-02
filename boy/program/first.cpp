#include <bits/stdc++.h> 
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define mod 998244353 
#define mx 400005
#define mx2 19
#define inf 1e9
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
int h[mx];
// Harstit bhaiya's Solution for character Encoding 

int sub (int a, int b) {
    return (a >= b) ? (a - b) : (a - b + mod);
}
int fact[mx];
int power(ll x,ll y)
{
    
    ll res = 1;
    while(y)
    {
        if(y&1)
            res=res*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return res;
}
int invmod(int x)
{
    if(x<mx && h[x]!=0)
        return h[x];
    return power(x,mod-2);
}
int ncr(ll n,int r)
{
    if(n < 0)return 0;
    if(n < r)return 0;
    return 1LL*fact[n]*invmod(1LL*fact[r]*fact[n-r]%mod)%mod;
}
int main()
{
    fl(i,1,mx)
    {
        h[i] = invmod(i);
    }
    fact[0] = 1;
    fl(i,1,mx)
    {
        fact[i] = 1LL*fact[i-1]*i%mod;
    }
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        ll ans = 0;
        ll nc = 1;
        fl(i,0,m+1)
        {
            if(1LL*k+m-1-1LL*n*i < m-1)break;
            ll temp = 1LL*ncr(1LL*k+m-1-1LL*n*i,m-1)*nc%mod;
            nc = nc*(m-i)%mod*invmod(i+1)%mod;
            if(i&1)
            {
                ans = sub(ans,temp);
            }
            else 
                ans = add(ans,temp);
        }
        cout<<ans<<endl;
    }
    
}