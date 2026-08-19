#include<bits/stdc++.h>

using ll = long long; 
using ull = unsigned long long; 
using db = double; 

using std :: cin; 
using std :: cout; 

const int M = 2e5 + 5; 
const int INF = 0x3f3f3f3f; 
const int mod = 998244353; 

namespace Marionette_ {
    int n; ll a[M]; 
    struct nd {
        int p; ll v; 
        inline bool operator < (const nd &x) const {
            return v < x.v; 
        }
    } b[M];
    int c[M], d[M]; ll e[M]; 
    inline void mian() {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i], b[i] = {i, a[i]}; 
        std :: sort(b + 1, b + n + 1); int pq = 0; 
        for(int l = 1, r; l <= n; l = r) {
            r = l;
            while(r <= n && b[l].v == b[r].v) ++r; ++pq;
            c[pq] = l, d[pq] = r - 1; 
        }
        ll S = 0, lst = 0; 
        if(b[c[1]].v != 0) return puts("-1"), void(); 
        for(int i = 2; i <= pq; ++i) {
            ll w = b[c[i]].v - S; int nm = d[i - 1] - c[i - 1] + 1; 
            if(w < 0) return puts("-1"), void(); 
            if(w % nm) return puts("-1"), void(); 
            S = b[c[i]].v;
            if((w / nm) <= lst) return puts("-1"), void(); lst = w / nm; 
            for(int j = c[i - 1]; j <= d[i - 1]; ++j) e[b[j].p] = lst; 
        }
        for(int i = c[pq]; i <= d[pq]; ++i) e[b[i].p] = lst + 1;
        for(int i = 1; i <= n; ++i) cout << e[i] << ' '; 
        puts(""); 
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}