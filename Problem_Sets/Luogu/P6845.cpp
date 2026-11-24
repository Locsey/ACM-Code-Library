#include <bits/stdc++.h>
#include <cassert>

#define int long long

inline int read() {
	int f = 1, s = 0; char ch = getchar();
	while(!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar();
	while(isdigit(ch)) s = s * 10 + (ch - 48) , ch = getchar();
	return f * s;
}

namespace TopTree {
    #define pb push_back 
    #define fi first
    #define se second 
    #define pii std :: pair < int, int > 
    #define vii vector < pii > 
    #define it vii :: iterator 
    using std :: vector; 
    using std :: max; 
    using std :: min; 
    using ll = long long;
    const int M = 2e5 + 5;
    const int INF = 0x3f3f3f3f; 
    int n, m, D, cnt; 
    int sz[M], son[M], prt[M], fto[M]; 
    bool typ[M]; 
    vector < int > adj[M]; 
    int up[M], dn[M], an[M], mxd[M][2], f[M], c[M][2], len[M]; 
    int Cnt, head[M], to[M], nxt[M], W[M], Id[M]; 
    inline void add(int x, int y,int id) {
        ++Cnt, to[Cnt] = y, Id[Cnt] = id, nxt[Cnt] = head[x], head[x] = Cnt; 
    }
    inline void upd(int x) {
        int w = W[x]; 
        x = fto[x], an[x] = mxd[x][0] = mxd[x][1] = len[x] = w; 
    }
    inline void dfs(int x, int fa) {
        sz[x] = 1, prt[x] = fa; 
        for(int i = head[x]; i; i = nxt[i]) {
            int y = to[i]; if(y == fa) continue ; adj[x].pb(y); 
            fto[Id[i]] = y, upd(Id[i]), up[y] = x, dn[y] = y, dfs(y, x), sz[x] += sz[y]; 
            if(sz[y] >= sz[son[x]]) son[x] = y; 
        }
    }
    inline void rake(int x) {
        const int lc = c[x][0], rc = c[x][1]; 
        up[x] = up[lc], dn[x] = dn[rc], len[x] = len[rc]; 
        mxd[x][0] = max(mxd[lc][0], mxd[rc][0]);
        mxd[x][1] = max(mxd[rc][1], len[rc] + mxd[lc][0]); 
        an[x] = max(max(an[lc], an[rc]), mxd[lc][0] + mxd[rc][0]); 
    }
    inline void compress(int x) {
        const int lc = c[x][0], rc = c[x][1]; 
        up[x] = up[lc], dn[x] = dn[rc]; len[x] = len[lc] + len[rc]; 
        mxd[x][0] = max(mxd[lc][0], len[lc] + mxd[rc][0]);
        mxd[x][1] = max(mxd[rc][1], len[rc] + mxd[lc][1]); 
        an[x] = max(max(an[lc], an[rc]), mxd[lc][1] + mxd[rc][0]); 
    }
    inline void push_up(int x) {
        if(!typ[x]) rake(x); 
        else compress(x); 
    }
    inline int merge(int x, int y, bool op) {
        int nd = ++cnt; c[nd][0] = x, c[nd][1] = y, f[x] = f[y] = nd, typ[nd] = op; 
        return push_up(nd), nd; 
    }
    inline int byd(it l, it r, bool op) {
        if(l + 1 == r) return l -> fi; 
        int S = 0; for(it x = l; x != r; ++x) S += x -> se; 
        for(it x = l; x != r; ++x) {
            S -= (x -> se) * 2; 
            if(S <= 0 || (x == r - 2)) return merge(byd(l, x + 1, op), byd(x + 1, r, op), op); 
        }
    }
    inline int dfs2(int x) {
        vii vec1; 
        if(x > 1) vec1.pb(pii(x, 1)); 
        for(; son[x]; x = son[x]) {
            vii vec2; 
            for(int &y : adj[x]) if(y != prt[x] && y != son[x]) vec2.pb(pii(dfs2(y), sz[y])); 
            vec2.pb(pii(son[x], 1)); 
            vec1.pb(pii(byd(vec2.begin(), vec2.end(), 0), sz[x] - sz[son[x]])); 
        }
        return byd(vec1.begin(), vec1.end(), 1); 
    }
    inline void mian() {
        n = read(), m = read(), D = read(); 
        for(int i = 1, x, y, z; i < n; ++i) {
            x = read(), y = read(), z = read();
            add(x, y, i), add(y, x, i), W[i] = z;  
        }
        dfs(1, 0), cnt = n; int rt = dfs2(1); 
        for(int i = n + 1; i <= cnt; ++i) std :: cout << typ[i] << ' ' << up[i] << ' ' << dn[i] << '\n'; 
        int lst = 0; 
        while(m --) {
            int x = read(), y = read(); 
            x += lst, y += lst, x %= (n - 1), y %= D, ++x; 
            W[x] = y; 
            upd(x), x = fto[x]; while(x = f[x]) push_up(x); 
            printf("%lld\n", lst = an[rt]);  
        }
    }
}

signed main() {
    TopTree :: mian(); 
    return 0; 
}