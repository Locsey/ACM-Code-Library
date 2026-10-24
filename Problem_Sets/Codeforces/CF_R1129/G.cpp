#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::vector;
using std::sort;
using std::swap;
using std::pair;
using std::iota;
using std::min;
using std::max;

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
inline ll readll() {
    ll f = 1, s = 0;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (isdigit(ch)) {
        s = s * 10 + (ch ^ 48);
        ch = getchar();
    }
    return f * s;
}
inline ll qpow(ll a, ll b, ll p) {
    ll s = 1;
    for (ll bas = a; b; b >>= 1, bas = bas * bas % p)
        if (b & 1) s = s * bas % p;
    return s;
}

namespace Solver {
static const ll MOD = 998244353;
inline ll norm(ll x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}
struct DSU {
    vector<int> fa, sz;
    vector<ll> lazy;
    DSU(int n) {
        fa.resize(n + 1);
        sz.assign(n + 1, 1);
        lazy.assign(n + 1, 0);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (fa[x] == x) return x;
        int f = fa[x];
        fa[x] = find(f);
        lazy[x] = (lazy[x] + lazy[f]) % MOD;
        return fa[x];
    }
    void add(int x, ll val) {
        x = find(x);
        lazy[x] = (lazy[x] + val) % MOD;
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        lazy[y] = norm(lazy[y] - lazy[x]);
    }
    ll get(int x) {
        find(x);
        return lazy[x];
    }
};
inline void Marionette_() {
    int n = read();
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> a(n + 1);
    ll total = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = readll();
        total = (total + a[i]) % MOD;
    }
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) p[i] = read();
    vector<int> par(n + 1, 0), order;
    order.reserve(n);
    order.push_back(1);
    for (int i = 0; i < (int)order.size(); ++i) {
        int u = order[i];
        for (int v : g[u]) {
            if (v == par[u]) continue;
            par[v] = u;
            order.push_back(v);
        }
    }
    vector<ll> sub = a;
    for (int i = n - 1; i >= 1; --i) {
        int u = order[i];
        sub[par[u]] = (sub[par[u]] + sub[u]) % MOD;
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return p[x] > p[y];
    });
    DSU dsu(n);
    vector<bool> active(n + 1, false);
    vector<ll> ans(n + 1, 0);
    for (int u : ord) {
        ans[u] = total;
        vector<pair<int, ll>> updates;
        for (int v : g[u]) {
            if (!active[v]) continue;
            ll side;
            if (par[v] == u) side = sub[v];
            else side = norm(total - sub[u]);
            ll contribution = norm(total - side);
            updates.push_back({v, contribution});
        }
        for (auto [v, val] : updates) dsu.add(v, val);
        active[u] = true;
        for (int v : g[u]) if (active[v]) dsu.unite(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        ans[i] = (ans[i] + dsu.get(i)) % MOD;
        cout << ans[i] << (i == n ? '\n' : ' ');
    }
}
inline void mian() {
    int t = read();
    while (t--) Marionette_();
}
}

int main() {
#ifdef LOCAL_DEBUG
#endif
    Solver::mian();
    return 0;
}