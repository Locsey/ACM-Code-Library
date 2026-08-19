#include<bits/stdc++.h>

using ll = long long; 
using ull = unsigned long long; 
using db = double; 

using std :: cin; 
using std :: cout; 

const int M = 1e5 + 5; 
const int INF = 0x3f3f3f3f; 
const int mod = 998244353; 

namespace Marionette_ {
    int n, m, x, y;
    int a[M], b[M], vis[M]; 
    inline void clr() {
        for(int i = 1; i <= n + m; ++i) vis[i] = 0; 
    }
    inline void mian() {
        cin >> n >> m >> x >> y; ll an = 0; clr(); 
        for(int i = 1; i <= x; ++i) cin >> a[i], vis[a[i]] |= 1; 
        for(int i = 1; i <= y; ++i) cin >> b[i], vis[b[i]] |= 2; 
        ll s1 = 0, s2 = 0;
        for(int i = 1; i <= std :: min(x, n); ++i) s1 += a[x - i + 1];
        for(int i = 1; i <= std :: min(y, m); ++i) s2 += b[y - i + 1];
        an = std :: max(s1, s2);
        int r1 = n - 1, r2 = m, mst = 0; s1 = 0; 
        for(int i = n + m; i && (r1 + r2 > mst); --i) if(vis[i]) {
            if(vis[i] == 1) {
                if(r1) r1 --, s1 += i; 
            }
            else if(vis[i] == 2) {
                if(r2) r2 --, s1 += i;
            }
            else {
                s1 += i, mst ++; 
            }
        }
        an = std :: max(an, s1); 
        r1 = n, r2 = m - 1, mst = 0; s2 = 0; 
        for(int i = n + m; i && (r1 + r2 > mst); --i) if(vis[i]) {
            if(vis[i] == 1) {
                if(r1) r1 --, s2 += i; 
            }
            else if(vis[i] == 2) {
                if(r2) r2 --, s2 += i;
            }
            else {
                s2 += i, mst ++; 
            }
        }
        an = std :: max(an, s2); 
        cout << an << '\n'; 
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}