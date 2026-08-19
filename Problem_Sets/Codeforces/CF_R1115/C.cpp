#include<bits/stdc++.h>

using ll = long long; 
using ull = unsigned long long; 
using db = double; 

using std :: cin; 
using std :: cout; 

const int M = 1e6 + 5; 
const int INF = 0x3f3f3f3f; 
const int mod = 998244353; 

namespace Marionette_ {
    int n, m;
    struct tre {
        int l, r, sz; 
        ll s;
    } t[M << 2];
    int tmp[M], pq; 
    int wei[M];
    inline void push_up(int p) {
        t[p].sz = t[p << 1].sz + t[p << 1 | 1].sz;
        t[p].s = t[p << 1].s + t[p << 1 | 1].s; 
    }
    inline void build(int p, int l, int r) {
        t[p].l = l, t[p].r = r, t[p].sz = t[p].s = 0; 
        if(l == r) return ; int mid = l + r >> 1; 
        build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
        push_up(p); 
    } 
    inline void upd(int p, int k) {
        if(t[p].l == t[p].r) return t[p].sz ++, t[p].s += tmp[k], void();
        int mid = t[p].l + t[p].r >> 1; if(k <= mid) upd(p << 1, k); else upd(p << 1 | 1, k); 
        push_up(p); 
    }
    int res, sum; 
    inline void Q(int p) {
        if(t[p].l == t[p].r) {
            int w = tmp[t[p].l]; 
            int n = (res - 1) / w + 1; sum += n; return ; 
        }
        if(t[p << 1 | 1].s >= res) return Q(p << 1 | 1), void();
        res -= t[p << 1 | 1].s, sum += t[p << 1 | 1].sz, Q(p << 1); 
    }
    inline void mian() {
        cin >> n >> m;
        std :: vector < std :: vector < int > > a; a.resize(n);
        for(int i = 0; i < n; ++i) cin >> wei[i];
        pq = 0; 
        for(int i = 0; i < n; ++i) {
            for(int j = 0, x; j < m; ++j) cin >> x, a[i].push_back(x), tmp[++pq] = x; 
        }
        std :: sort(tmp + 1, tmp + pq + 1), pq = std :: unique(tmp + 1, tmp + pq + 1) - tmp - 1;
        build(1, 1, pq); ll S = 0; int an = m; 
        for(int i = n - 1; ~i; --i) {
            for(int j = 0; j < m; ++j) S += a[i][j], a[i][j] = std :: lower_bound(tmp + 1, tmp + pq + 1, a[i][j]) - tmp, upd(1, a[i][j]); 
            res = wei[i];
            if(S >= res) sum = 0, Q(1), an = std :: min(an, sum); 
        }
        cout << an << '\n'; 
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}