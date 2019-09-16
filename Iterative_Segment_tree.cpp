#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int t[2*N+100];  // seg tree RMQ with single element modification
void build(){
    for(int i=n-1;i>0;i--)
        t[i]=min(t[i<<1],t[(i<<1)+1]);
}

// gives min element from [l,r) p.s. r exclusive
int query(int l,int r){
    int res=1000000;   // res= infinity
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(r&1)
            res=min(res,t[--r]);
        if(l&1)
            res=min(res,t[l++]);
    }
    return res;
}
void modify(int p, long new_val)  // update new_val at position p
    {
        p += n;
        t[p] = new_val;
        for (; p > 1; p/= 2)
        {
            t[p/2] = min(t[p] , t[p^1]);
        }
    }


int main()
{
    int q; cin>>n>>q;
    for (int i = 0; i < n; ++i) scanf("%d",&t[n+i]);
    build();
    for (int i = 0; i < q; ++i)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(l,r+1)<<endl;

    }
    return 0;
}
// i think, the same implementation will work for range sum, range max and 
//    all commutative properties. just a few changes
