#include <bits/stdc++.h>
using namespace std;      using ll=long long int;
clock_t time_p=clock();ll seed;mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline ll rnd(ll l=0,ll r=INT_MAX){return uniform_int_distribution<ll>(l,r)(rng);}
#define fr(i,a,b) for(auto i=a,inc = sign(b-a); i!=b ; i+=inc)
#define c(x) cout<<to_string(x)<<endl
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:",O_O(__VA_ARGS__)
void O_O() { cerr << endl; }
void K_O(){time_p=clock()-time_p;cerr<<"Time Taken : "<<(double)(time_p*1000)/CLOCKS_PER_SEC<<" ms."<<"\n";exit(0);}
string to_string(string s) {return  s;}
string to_string(const char* s) {return to_string((string) s);}
string to_string(bool b) {return (b ? "true" : "false");}
template <typename T, typename... Tail>void O_O(T H, Tail... X) {cerr << " " << to_string(H);O_O(X...);} 
template <typename T, typename B>string to_string(pair<T, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename T>string to_string(T v) {bool first = true;string res = "{";for(const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}  
template<typename T> inline int sign(const T&a) {if(a<0)return -1;if(a>0)return 1;return 0;}
template<typename T,typename S>inline bool amin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool amax(T&a,const S&b){return a<b?a=b,1:0;}
const ll inf = (ll)(1e18),mod = (ll)(1e9+7), MX= 100001; 

main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); // int test=1; cin>>test; while(test--)
  
    

  K_O();
}
