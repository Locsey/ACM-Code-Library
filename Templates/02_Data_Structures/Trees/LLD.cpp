#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::vector;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define mem(a, b) memset(a, b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef unsigned int ui; 
typedef std::pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

const int M = 5e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const ll INFLL = 1e18;
const db eps = 1e-8;

// ---------- Debug Overloads (C++98) ----------
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) os << (i ? ", " : "") << v[i];
    return os << "]";
}
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "{";
    typename std::set<T>::const_iterator it = s.begin();
    while (it != s.end()) {
        os << *it;
        ++it;
        if (it != s.end()) os << ", ";
    }
    return os << "}";
}

// ---------- Debug Macros ----------
#ifdef LOCAL_DEBUG
#define debug(x) std::cerr << #x << " = " << x << '\n'
#define debug2(x, y) std::cerr << #x << " = " << x << ", " << #y << " = " << y << '\n'
#define debug3(x, y, z) std::cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << '\n'
#define debug_arr(arr, n) { std::cerr << #arr << " = ["; \
    for (int _i = 0; _i < (n); ++_i) std::cerr << (arr)[_i] << (_i == (n) - 1 ? "" : ", "); \
    std::cerr << "]\n"; }
#define debug_mat(mat, n, m) { std::cerr << #mat << ":\n"; \
    for (int _i = 0; _i < (n); ++_i) { \
        std::cerr << "  ["; \
        for (int _j = 0; _j < (m); ++_j) std::cerr << (mat)[_i][_j] << (_j == (m) - 1 ? "" : ", "); \
        std::cerr << "]\n"; \
    } }
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug_arr(arr, n)
#define debug_mat(mat, n, m)
#endif

// ---------- Fast IO ----------
inline int read() {
    int f = 1, s = 0; 
    char ch = getchar();
    while (!isdigit(ch)) { 
        if (ch == '-') f = -f; 
        ch = getchar(); 
    }
    while (isdigit(ch)) { 
        s = (s << 1) + (s << 3) + (ch ^ 48); 
        ch = getchar(); 
    }
    return f * s;
}

// ---------- Fast Power ----------
inline ll qpow(ll a, ll b, ll p) {
    ll s = 1;
    for (ll bas = a; b; b >>= 1, bas = bas * bas % p)
        if (b & 1) s = s * bas % p;
    return s;
}

namespace Solver {
    int n, q; ui s; 
    int dep[M], son[M], mxd[M], top[M], prt[M]; 
    int f[M][20], lg[M]; 
    vi adj[M], up[M], dn[M]; 
    inline void dfs(int x, int fa) {
        dep[x] = dep[prt[x] = fa] + 1, f[x][0] = fa;
        for(int i = 1; i < 20 && f[x][i - 1]; ++i) f[x][i] = f[f[x][i - 1]][i - 1]; 
        for(int &y : adj[x]) {
             dfs(y, x); 
             if(mxd[y] + 1 > mxd[x]) mxd[x] = mxd[y] + 1, son[x] = y; 
        }
    }
    inline void dfs2(int x, int tp) {
        top[x] = tp;
        if(x == tp) {
            int u = x, ct = 0; 
            while(u) dn[x].pb(u), u = son[u]; 
            for(u = x; u && (ct <= mxd[x]); u = prt[u], ++ct) up[x].pb(u); 
        }
        if(son[x]) dfs2(son[x], tp); 
        for(int &y : adj[x]) if(y ^ son[x]) dfs2(y, y); 
    }
    inline int get_kth(int x, int k) {
        if(!k) return x; 
        int pos = lg[k]; x = f[x][pos]; k -= 1 << pos;
        int u = top[x]; k -= dep[x] - dep[u];
        if(k >= 0) return up[u][k];
        return dn[u][-k]; 
    }
    inline ui get(ui x) {
        x ^= x << 13;
        x ^= x >> 17; 
        x ^= x << 5; 
        return s = x; 
    }
    inline void Marionette_() {
        n = read(), q = read(), s = read(), lg[0] = -1; 
        for(int i = 1; i <= n; ++i) lg[i] = lg[i >> 1] + 1; int rt = 0; 
        for(int i = 1, x; i <= n; ++i) {
            x = read(); 
            if(!x) rt = i;
            else adj[x].pb(i); 
        }
        dep[rt] = 1, dfs(rt, 0), dfs2(rt, rt); int lst = 0; 
        ll ans = 0; 
        for(int i = 1; i <= q; ++i) {
            int x = (get(s) ^ lst) % n + 1, k = (get(s) ^ lst) % dep[x];
            ans ^= (ll)i * (lst = get_kth(x, k)); 
        }
        cout << ans; 
    }
    inline void mian() {
        int t = 1;
        // t = read();
        while (t--) Marionette_();
    }
}

int main() {
    #ifdef LOCAL_DEBUG
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solver::mian();
    return 0;
}