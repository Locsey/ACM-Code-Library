#include <bits/stdc++.h>

using std :: cin;
using std :: cout;
using std :: vector; 

typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;

const int M = 3e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

inline int read() {
    int f = 1, s = 0; char ch = getchar(); 
    while(!isdigit(ch)) (ch == '-') && (f = -f), ch = getchar(); 
    while(isdigit(ch)) s = (s << 1) + (s << 3) + ch - 48, ch = getchar(); 
    return f * s; 
}

namespace Solver {
    int n, m, deg[M]; 
    vector < int > adj[M]; 
    int cnt, vis[M], op; 
    inline void dfs(int x) {
        vis[x] = 1, ++cnt; 
        for(int &y : adj[x]) if(!vis[y]) dfs(y); 
    }
    inline void Marionette_() {
        n = read(), m = read(); 
        for(int i = 1, x, y; i <= m; ++i) x = read(), y = read(), adj[x].push_back(y), adj[y].push_back(x), deg[x] ++, deg[y] ++; 
        op = 1; int nm = 0; 
        for(int i = 1; i <= n; ++i) if(!vis[i]) {
            cnt = 0, dfs(i);
            if(cnt == 1) op = -1; nm ++; 
        }
        if(~op) { int x = 0; 
            for(int i = 1; i <= n; ++i) if(deg[i] == n - 1) x = i; 
            for(int i = 1; i <= n; ++i) if(x != i) op &= deg[i] == 1;
            if(op) op = 0;
            else op = 1; 
        }
        if(op == -1) puts("Brain Melt");  
        else {
            if(nm > 1) op = 1; 
        if(op == 0) cout << 2 << '\n';
        if(op == 1) puts("Many"); 
        }
        
        for(int i = 1; i <= n; ++i) adj[i].clear(), deg[i] = vis[i] = 0; 
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