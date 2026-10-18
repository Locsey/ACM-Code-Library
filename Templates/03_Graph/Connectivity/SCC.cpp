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
typedef std::pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

const int M = 1e5 + 5;
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
    int n, m; int a[M]; 
    vi adj[M], adj2[M]; 
    int stk[M], in[M], bel[M], vis[M], dfn[M], low[M], sgn, scc, tp; 
    ll all[M], dp[M]; 
    inline void tarjan(int x) {
        vis[x] = 1, in[stk[++tp] = x] = 1, dfn[x] = low[x] = ++sgn; 
        for(int &y : adj[x]) {
            if(!vis[y]) tarjan(y), low[x] = std :: min(low[x], low[y]);
            else if(in[y]) low[x] = std :: min(low[x], dfn[y]); 
        }
        if(low[x] == dfn[x]) {
            ++scc; int y; 
            do {
                y = stk[tp --], in[y] = 0, bel[y] = scc, all[scc] += a[y]; 
            } while(y ^ x); 
        }
    }
    inline void Marionette_() {
        n = read(), m = read();
        for(int i = 1; i <= n; ++i) a[i] = read();
        for(int i = 1, x, y; i <= m; ++i) x = read(), y = read(), adj[x].pb(y);
        for(int i = 1; i <= n; ++i) if(!vis[i]) tarjan(i); 
        for(int x = 1; x <= n; ++x) for(int &y : adj[x]) if(bel[x] ^ bel[y]) adj2[bel[x]].pb(bel[y]); 
        for(int i = 1; i <= scc; ++i) {
            std :: sort(all(adj2[i])); 
            auto lst = std :: unique(all(adj2[i]));
            adj2[i].erase(lst, adj2[i].end()); 
        }
        for(int x = 1; x <= scc; ++x) for(int &y : adj2[x]) in[y] ++; 
        std :: queue < int > q; 
        for(int x = 1; x <= scc; ++x) if(!in[x]) q.push(x); 
        ll ans = 0; 
        while(!q.empty()) {
            int x = q.front(); q.pop(); dp[x] += all[x], ans = std :: max(ans, dp[x]); 
            for(int &y : adj2[x]) {
                dp[y] = std :: max(dp[y], dp[x]);
                if(!(--in[y])) q.push(y);
            }
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