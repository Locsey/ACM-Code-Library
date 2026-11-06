#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp std :: make_pair
#define vp std :: vector < std :: pair < int, int > > 

const int mod = 998244353; 
const int M = 2e5 + 5; 

using ll = long long; 

inline int qpow(int a, int b, int p) {
    int s = 1; 
    for(int bas = a; b; b >>= 1, bas = (ll)bas * bas % p)
        if(b & 1) s = (ll)s * bas % p;
    return s; 
}

int out[M], outm[M], O[M]; 
vp adj[M];  
int n, m, T; 
std :: string str;  
ll dis[M]; 
int dp[M], cn[M]; 
inline void topo(int S) {
    memset(dis, 0x3f, sizeof(dis)), dis[S] = 0; 
    std :: queue < int > q; q.push(S); 
    while(!q.empty()) {
        int x = q.front(); q.pop(); 
        for(auto &it : adj[x]) {
            int y = it.fi, z = it.se; 
            dis[y] = std :: min(dis[y], dis[x] + z); 
            if(!(--O[y])) q.push(y); 
         }
    }
}
inline int add(int x, int y) {x += y; return (x >= mod) ? (x - mod) : x;}
int main() {
    std :: cin >> n >> m >> T; 
    std :: cin >> str, str = " " + str; 
    for(int i = 1; i <= m; ++i) {
        int u, v, w; 
        std :: cin >> u >> v >> w; 
        adj[v].pb(mp(u, w)), out[u] ++; 
    }
    for(int i = 1; i <= n; ++i) O[i] = out[i]; 
    topo(T); 
    for(int i = 1; i <= n; ++i) O[i] = out[i]; 
    std :: queue < int > q; q.push(T), cn[T] = 1; 
    while(!q.empty()) {
        int x = q.front(); q.pop();
        if(str[x] == '1') dp[x] = (ll)dp[x] * qpow(cn[x], mod - 2, mod) % mod;
        else dp[x] = (ll)dp[x] * qpow(out[x], mod - 2, mod) % mod; 
        for(auto &it : adj[x]) {
            int y = it.fi, z = it.se; 
            O[y] --;
            if(dis[y] == dis[x] + z) cn[y] = add(cn[y], cn[x]); 
            if(str[y] == '1') {
                if(dis[y] == dis[x] + z) dp[y] = add(dp[y], (ll)cn[x] * add(dp[x], z) % mod); 
            }
            else dp[y] = add(dp[y], add(dp[x], z)); 
            if(!O[y]) q.push(y); 
        }
    }
    for(int i = 1; i <= n; ++i) std :: cout << dp[i] << ' ' ;
}