#include <bits/stdc++.h> 

using std :: cin;
using std :: cout;
using std :: vector;

typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;

struct SGT {
    int n; 
    struct nd {
        int l, r;
        ll s, tg; 
    }; 
    vector < nd > t; 
    inline void init(int N) {
        n = N, t.resize(4 * n + 1);
        for(int i = 0; i <= 4 * n; ++i) t[i].l = t[i].r = t[i].s = t[i].tg = 0; 
    }
    inline void pusdt(int p, ll v) {t[p].s += (ll)(t[p].r - t[p].l + 1) * v, t[p].tg += v; }
    inline void pusd(int p) {
        if(!t[p].tg) return ;
        pusdt(p << 1, t[p].tg), pusdt(p << 1 | 1, t[p].tg);
        t[p].tg = 0; 
    }
    inline void pus(int p) {
        t[p].s = t[p << 1].s + t[p << 1 | 1].s; 
    }
    inline void byd(int p, int l, int r, vector < int > &a) {
        t[p].l = l, t[p].r = r; 
        if(l == r) return t[p].s = a[l], void(); 
        int mid = l + r >> 1; 
        byd(p << 1, l, mid, a), byd(p << 1 | 1, mid + 1, r, a); 
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
        if(r > mid) S += Q(p << 1 | 1, l, r); return S;
    }
} ; 

int main() {
    
    return 0; 
}