struct segtree {
    #define lc cur + cur + 1
    #define rc cur + cur + 2
    #define mid (s + e) / 2
 
    struct node {
        ll val = 0; // 0 for sum query
        ll lazy = 0;
    };
 
    ll n;
    vector<node> seg;
 
    node unite(const node& a, const node& b) {
        node res;
        res.val = a.val + b.val;
        return res;
    }
 
    inline void push(ll cur, ll s, ll e) {
        if (seg[cur].lazy == 0) return;
        if (s != e) {
            seg[lc].lazy += seg[cur].lazy;
            seg[rc].lazy += seg[cur].lazy;
        }
        seg[cur].val += (e - s + 1) * seg[cur].lazy;
        // seg[cur].val += seg[cur].lazy;
        seg[cur].lazy = 0;
    }
 
    void pull(ll cur) {
        seg[cur] = unite(seg[lc], seg[rc]);
    }
 
    void build(ll cur, ll s, ll e) {
        if (s == e) {
            seg[cur].val = 0;
            return;
        }
        build(lc, s, mid); build(rc, mid+1, e);
        pull(cur);
    }
 
    template <class M>
    void build(ll cur, ll s, ll e, const vector<M>& v) {
        if (s == e) {
            seg[cur].val = v[s];
            return;
        }
        build(lc, s, mid, v); build(rc, mid+1, e, v);
        pull(cur);
    }
 
    template <class M>
    void update(ll cur, ll s, ll e, ll l, ll r, const M& v) {
        push(cur, s, e);
        if (s > r || e < l) return;
        if (l <= s && e <= r) {
            seg[cur].lazy += v;
            push(cur, s, e);
            return;
        }
        update(lc, s, mid, l, r, v);
        update(rc, mid+1, e, l, r, v);
        pull(cur);
    }
 
    node query(ll cur, ll s, ll e, ll l, ll r) {
        push(cur, s, e);
        if (s > r || e < l) return node();
        if (l <= s && e <= r) return seg[cur];
        return unite(query(lc, s, mid, l, r), query(rc, mid+1, e, l, r));
    }
 
    #undef lc
    #undef rc
    #undef mid
 
    segtree(ll _n) : n(_n) {
        assert(n > 0);
        seg.resize(4 * n);
        build(0, 0, n-1);
    }
 
    template <class M>
    segtree(const vector<M>& v) {
        n = v.size();
        assert(n > 0);
        seg.resize(4 * n);
        build(0, 0, n-1, v);
    }
 
    template <class M>
    void update(ll idx, const M& val) {
        if (idx < 0 || idx > n-1) return;
        update(0, 0, n-1, idx, idx, val);
    }
 
    template <class M>
    void update(ll l, ll r, const M& val) {
        if (l < 0 || l > n-1 || r < 0 || r > n-1 || r < l) return;
        update(0, 0, n-1, l, r, val);
    }
 
    node query(ll l, ll r) {
        if (l < 0 || l > n-1 || r < 0 || r > n-1 || r < l) return node();
        return query(0, 0, n-1, l, r);
    }
};
// check initial value in struct node
