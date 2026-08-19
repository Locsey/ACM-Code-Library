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
    ll n, a[M], can[M], vis[M];
    inline bool check(int x) {
        if(x < 1 || x > n || !can[x]) return 0; 
        return a[x] * 2 > a[x - 1] + a[x + 1]; 
    }
    inline void mian() {
        cin >> n; 
        for(int i = 1; i <= n; ++i) cin >> a[i];
        can[1] = can[n] = 0; 
        for(int i = 2; i < n; ++i) if((a[i - 1] + a[i + 1]) % 2 == 0) can[i] = 1; else can[i] = 0;
        std :: queue < int > q; 
        for(int l = 2, r; l < n; l = r) {
            r = l; while(r < n && can[r]) ++r; 
            if(l == r) {r++; continue ; }
            for(int i = l; i < r; ++i) if(check(i)) q.push(i), vis[i] = 1;
            while(!q.empty()) {
                int x = q.front(); q.pop(); vis[x] = 0; 
                if(check(x)) {
                    a[x] = a[x - 1] + a[x + 1] - a[x];
                    if(check(x - 1) && !vis[x - 1]) q.push(x - 1), vis[x - 1] = 1; 
                    if(check(x + 1) && !vis[x + 1]) q.push(x + 1), vis[x + 1] = 1; 
                }
            }
        }
        for(int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << '\n'; 
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}