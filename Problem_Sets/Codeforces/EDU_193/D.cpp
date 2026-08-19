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
    int n; 
    std :: vector < int > adj[M];
    int rt, sz[M]; 
    std :: vector < int > n1, n2;
    int dep[M]; 
    inline void dfs(int x, int fa) {
        sz[x] = 1; int op = 1; 
        for(int &y : adj[x]) if(y ^ fa) {
            dfs(y, x), sz[x] += sz[y]; 
            op &= (sz[y] <= n / 2); 
        }
        op &= ((n - sz[x]) <= n / 2);
        if(op) rt = x; 
    }
    int mxd[M], z, to; 
    inline void dfs2(int x, int fa) {
        dep[x] = dep[fa] + 1;
        for(int &y : adj[x]) if(y ^ fa) dfs2(y, x); 
        mxd[z] = std :: max(mxd[z], dep[x]); 
    }
    int cz[M], mk1[M], mk2[M]; 
    inline void dfs3(int x, int fa) { 
        cz[x] = 0; int v = 0; 
        if(dep[x] == mxd[to]) cz[x] = 1, v = 1; 
        for(int &y : adj[x]) if(y ^ fa) {
            dfs3(y, x);
            if(cz[x] && cz[y]) v = 1;
            cz[x] += cz[y]; 
        }
        if(v && (!mk1[dep[x]])) mk1[dep[x]] = 1, n1.push_back(dep[x]);  
    }
    inline void dfs4(int x, int fa) {
        cz[x] = 0; int v = 0;
        if(dep[x] == mxd[z]) cz[x] = 1, v = 1; 
        for(int &y : adj[x]) if(y ^ fa) {
            dfs4(y, x);
            if(cz[x] && cz[y]) v = 1; 
            cz[x] += cz[y]; 
        } 
        if(v && (!mk2[dep[x]])) mk2[dep[x]] = 1, n2.push_back(dep[x]); 
    }
    int ans[M]; 
    inline void clr() {
        for(int i = 1; i <= n; ++i) adj[i].clear(), mk1[i] = mk2[i] = ans[i] = mxd[i] = 0; 
        n1.clear(), n2.clear(); 
    }
    inline void mian() {
        cin >> n;
        for(int i = 1, x, y; i < n; ++i) cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x); rt = 0; 
        dfs(1, 0), dep[rt] = 0; 
        for(int &y : adj[rt]) z = y, mxd[z] = 0, dfs2(y, rt);
        to = 0; int w = adj[rt].size(); 
        std :: sort(adj[rt].begin(), adj[rt].end(), [&] (int x, int y) {return mxd[x] < mxd[y];});
        to = adj[rt][w - 1]; int Y = -1; 
        if(w > 1) Y = mxd[adj[rt][w - 2]], assert(Y != mxd[to]); 
        dfs3(to, rt); int cnt = 0; 
        for(int &y : adj[rt]) if(mxd[y] == Y) z = y, dfs4(y, rt), ++cnt;
        if(cnt > 1) n2.push_back(0); 
        for(int &x : n1) for(int &y : n2) ans[x + y] = 1; int num = 0; 
        if(n == 2) ans[1] = 1, ans[2] = 0; 
        for(int i = 1; i <= n; ++i) if(ans[i]) num ++;
        cout << num << ' ';
        for(int i = 1; i <= n; ++i) if(ans[i]) cout << i << ' ';
        puts(""); 
        clr(); 
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}