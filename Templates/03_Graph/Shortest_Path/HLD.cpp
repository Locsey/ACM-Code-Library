#include <bits/stdc++.h>
#include <cassert>

#define LOCAL_DEBUG

using std :: cin;
using std :: cout;

typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;

const int M = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

inline int read() {
    int f = 1, s = 0; char ch = getchar(); 
    while(!isdigit(ch)) (ch == '-') && (f = -f), ch = getchar(); 
    while(isdigit(ch)) s = (s << 1) + (s << 3) + ch - 48, ch = getchar(); 
    return f * s; 
}

namespace HLD {
    int n, m, r, P, sgn; 
    std :: vector < int > adj[M];
    int a[M]; 
    int son[M], sz[M], dfn[M], fp[M], d[M], top[M], prt[M]; 
    struct SGT {
        int l, r;
        ll s, tg; 
    } t[M << 2];    
    inline void dfs1(int x, int fa, int dep) {
        d[x] = dep, prt[x] = fa, sz[x] = 1;
        for(int &y : adj[x]) if(y ^ fa) {
            dfs1(y, x, dep + 1), sz[x] += sz[y]; 
            if(sz[y] > sz[son[x]]) son[x] = y; 
        }
    }
    inline void dfs2(int x, int tp) {
        dfn[x] = ++sgn, fp[sgn] = x, top[x] = tp; if(son[x]) dfs2(son[x], tp);
        for(int &y : adj[x]) if((y ^ prt[x]) && (y ^ son[x])) dfs2(y, y); 
    }
    inline void pusdt(int p, ll v) {t[p].s += (ll)(t[p].r - t[p].l + 1) * v % P, t[p].tg += v, t[p].s %= P, t[p].tg %= P; }
    inline void pusd(int p) {
        if(!t[p].tg) return ;
        pusdt(p << 1, t[p].tg), pusdt(p << 1 | 1, t[p].tg);
        t[p].tg = 0; 
    }
    inline void pus(int p) {
        t[p].s = t[p << 1].s + t[p << 1 | 1].s;
        t[p].s %= P; 
    }
    inline void byd(int p, int l, int r) {
        t[p].l = l, t[p].r = r; 
        if(l == r) return t[p].s = a[fp[l]], void(); 
        int mid = l + r >> 1; 
        byd(p << 1, l, mid), byd(p << 1 | 1, mid + 1, r); 
        pus(p); 
    }
    inline void upd(int p, int l, int r, ll v) {
        if(l <= t[p].l && t[p].r <= r) return pusdt(p, v), void();
        int mid = t[p].l + t[p].r >> 1; pusd(p);
        if(l <= mid) upd(p << 1, l, r, v); 
        if(r > mid) upd(p << 1 | 1, l, r, v); pus(p); 
    }
    inline ll Q(int p, int l, int r) {
        if(l <= t[p].l && t[p].r <= r) return t[p].s; 
        int mid = t[p].l + t[p].r >> 1; pusd(p); ll S = 0; 
        if(l <= mid) S += Q(p << 1, l, r);
        if(r > mid) S += Q(p << 1 | 1, l, r); return S % P;
    }
    inline void add_path(int x, int y, int z) {
        z %= P; 
        while(top[x] ^ top[y]) {
            if(d[top[x]] < d[top[y]]) std :: swap(x, y); 
            upd(1, dfn[top[x]], dfn[x], z);
            x = prt[top[x]]; 
        }
        if(d[x] > d[y]) std :: swap(x, y); 
        upd(1, dfn[x], dfn[y], z); 
    }
    inline ll query_path(int x, int y) {
        ll ans = 0;
        while(top[x] ^ top[y]) {
            if(d[top[x]] < d[top[y]]) std :: swap(x, y); 
            ans += Q(1, dfn[top[x]], dfn[x]);
            x = prt[top[x]], ans %= P; 
        }
        if(d[x] > d[y]) std :: swap(x, y);
        ans += Q(1, dfn[x], dfn[y]); 
        return ans % P; 
    }
    inline void add_subtre(int x, int z) {
        z %= P;
        upd(1, dfn[x], dfn[x] + sz[x] - 1, z); 
    }
    inline ll query_sub(int x) {
        return Q(1, dfn[x], dfn[x] + sz[x] - 1); 
    }
    void mian() {
        n = read(), m = read(), r = read(), P = read();
        for(int i = 1; i <= n; ++i) a[i] = read() % P;
        for(int i = 1, x, y; i < n; ++i) x = read(), y = read(), adj[x].push_back(y), adj[y].push_back(x);
        dfs1(r, 0, 0), dfs2(r, r); 
        byd(1, 1, n); 
        while(m --) {
            int op = read(), x = read(), y, z; 
            if(op == 1) y = read(), z = read(), add_path(x, y, z);
            if(op == 2) y = read(), printf("%lld\n", query_path(x, y));
            if(op == 3) z = read(), add_subtre(x, z);
            if(op == 4) printf("%lld\n", query_sub(x)); 
        }
    }
}; 

#ifdef LOCAL_DEBUG

namespace Solver {
    
    inline void Marionette_() {
        HLD :: mian(); 
    }
    inline void mian() {
        int t = 1; 
        // t = read();
        while(t --) Marionette_(); 
    }
}

int main() {
    Solver :: mian(); 
    return 0; 
}

#endif 