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
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
    x = x % p;  // Update x if it is more than or 
                // equal to p 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
// This function is called for all k trials. It returns 
// false if n is composite and returns false if n is 
// probably prime. 
// d is an odd number such that  d*2<sup>r</sup> = n-1 
// for some r >= 1 
bool miillerTest(ll d, ll n) 
{ 
    // Pick a random number in [2..n-2] 
    // Corner cases make sure that n > 4 
    ll a = 2 + rand() % (n - 4); 
  
    // Compute a^d % n 
    ll x = power(a, d, n); 
  
    if (x == 1  || x == n-1) 
       return true; 
  
    // Keep squaring x while one of the following doesn't 
    // happen 
    // (i)   d does not reach n-1 
    // (ii)  (x^2) % n is not 1 
    // (iii) (x^2) % n is not n-1 
    while (d != n-1) 
    { 
        x = (x * x) % n; 
        d *= 2; 
  
        if (x == 1)      return false; 
        if (x == n-1)    return true; 
    } 
  
    // Return composite 
    return false; 
} 

bool isPrime(ll n, ll k = 20) 
{ 
    if (n <= 1 || n == 4)  return false; 
    if (n <= 3) return true; 

    ll d = n - 1; 
    while (d % 2 == 0) 
        d /= 2; 

    for (ll i = 0; i < k; i++) 
         if (!miillerTest(d, n)) 
              return false; 
  
    return true; 
}
void solve(){
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    cnt = 0;
    ll fp = -1;
    bool ok = 0;
    for (int i = 0; i < n/2; ++i)
    {
        if(isPrime(a[i])){
            if(!ok) fp = a[i], ok = 1;
            cnt++;
        }
    }
    ll fp_ = -1;
    ok = 0;
    for (int i = n; i >=n/2 ; --i)
    {
        if(isPrime(a[i])){
            if(!ok) fp_ = a[i], ok = 1;
            cnt--;
        }
    }
    if(cnt==0 and fp > fp_)
        cout << "PERFECT" << endl;
    else
        cout << "IMPERFECT" << endl;


}
signed main(){                                          //F
    clock_t time = clock();                             //A
    ios_base::sync_with_stdio(0);                       //S
    cin.tie(0);                                         //T
    cout.tie(0);                                        //I
    cerr.tie(0);                                        //O
    if(0) cin>>tc;
    while(tc--)
        solve();
    dbg("Author - Amit dwivedi");
    return 0&fprintf(stderr, "Time ::%.3lf ms.\n",((clock() - time)*1000.0)/CLOCKS_PER_SEC);
}