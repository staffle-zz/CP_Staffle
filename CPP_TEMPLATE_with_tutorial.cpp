#include <bits/stdc++.h>        
using namespace std;
using ll=long long int;
#ifdef DBG
      #include "debug.h" 
      /*   
      save this file in your working folder and you are good to go
      for debugging -->use dbg(var1,var2,...) and db(iterable_name, from , to)  {see solution function} 
      https://github.com/amit-nits/justforsharing/blob/master/debug.h
      */
#else
      #define dbg(...)
      #define db(...)
#endif
// Global variable declaration mostly because it is faster and more easy to be used in every func.
ll n,m,p,q,k,u,v,cnt = 0,ans = -1,mod=1e9+7,mx=1e5+1;
int T = 1; //If problem.has_test_cases:T = 0;else T = 1.

vector<ll> a(mx,-1);
vector<unsigned long long int> two_power(61,1);
void solution(){//Real solution lies in this function
      iota(a.begin(), a.end(),1);
      n = 10 + (rand())%10;
      dbg(n,cnt,mod,mx);// printing multiple variable at a time in extremly useful. works for almoast any data type
      db(a,0,n-1); // to print a[l] to a[r] quite handy sometimes(works for 2D and higher dimention iterables too).
}
void preprocess(){ // called once in whole execution before test cases starts. 
      //(for prime seive ,power storing , sparse table etc.)
      if(!T)cin>>T;
      for (int i = 1; i < 61; ++i)
      {
            two_power[i] = 1ll << i;
      }
      dbg(two_power);
}
int main(){ 
      // Next 4 lines are for Fast I/O/Debug (sufficiently Fast most of the time.)
      ios_base::sync_with_stdio(0); 
      cout.tie(0);
      cin.tie(0);
      cerr.tie(0);
      preprocess();
      while(T--) 
            solution();
      return 0;
}
