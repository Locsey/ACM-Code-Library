#include <bits/stdc++.h>

using std :: cin;
using std :: cout;

typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;

const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

inline int read() {
    int f = 1, s = 0; char ch = getchar(); 
    while(!isdigit(ch)) (ch == '-') && (f = -f), ch = getchar(); 
    while(isdigit(ch)) s = (s << 1) + (s << 3) + ch - 48, ch = getchar(); 
    return f * s; 
}

namespace Solver {
    int n, m, q; 
    struct E {
        int u, v, w;
        inline bool operator < (const E &rhs) const {
            return w < rhs.w; 
        }
    } edg[M];
    int f[M], cnt, pq; 
    inline int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
    int cost[M]; ll pref[M], ans[M]; 
    inline ll Q(int x) {
        int l = 1, r = pq, an = 0;
        while(l <= r) {
            int mid = l + r >> 1;
            if((ll)x * (mid + cnt - 1) <= cost[mid]) an = mid, l = mid + 1;
            else r = mid - 1; 
        } 
        return pref[an] - (ll)an * (2 * cnt + an - 1) * x / 2; 
    }
    inline void Marionette_() {
        n = read(), m = read(), q = read(); ll w = 0; 
        for(int i = 1; i <= m; ++i) edg[i].u = read(), edg[i].v = read(), edg[i].w = read(), w += edg[i].w; 
        std :: sort(edg + 1, edg + m + 1); 
        std :: iota(f + 1, f + n + 1, 1); cnt = 0, pq = 0; 
        for(int i = 1; i <= m; ++i) {
            int u = edg[i].u, v = edg[i].v;
            if(find(u) != find(v)) f[find(u)] = find(v), w -= edg[i].w, cost[++pq] = edg[i].w; 
        }
        std :: sort(cost + 1, cost + pq + 1, [&](int x, int y) {return x > y;}); 
        for(int i = 1; i <= pq; ++i) pref[i] = pref[i - 1] + cost[i]; 
        for(int i = 1; i <= n; ++i) cnt += find(i) == i; 
        for(int i = 1; i <= q; ++i) {
            int x = read(); 
            ll an = w - (ll)(cnt - 1) * cnt * x / 2 + Q(x);
            ans[i] = an; 
        }
        for(int i = 1; i <= q; ++i) cout << ans[i] << ' ';
        puts(""); 
    }
    inline void mian() {
        int t = 1; 
        t = read();
        while(t --) Marionette_(); 
    }
}

int main() {
    Solver :: mian(); 
    return 0; 
}