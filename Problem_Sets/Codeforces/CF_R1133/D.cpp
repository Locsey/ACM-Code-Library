#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::queue;
using std::sort;
using std::swap;
using std::pair;
using std::iota;
using std::gcd;
using std::abs;
using std::min;
using std::max;
using std::greater;
using std::priority_queue;

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
struct FM {
    vector<ull> ks;
    vector<int> vs;
    size_t msk;
    int sh;
    inline void init(int m) {
        size_t cap = 1;
        while (cap < 4ULL * m) cap <<= 1;
        ks.assign(cap, 0);
        vs.resize(cap);
        msk = cap - 1;
        sh = 64 - __builtin_ctzll(cap);
    }
    inline size_t pos(ull k) const {
        return (k * 11400714819323198485ull) >> sh;
    }
    inline void ins(ull k, int v) {
        size_t p = pos(k);
        while (ks[p]) p = (p + 1) & msk;
        ks[p] = k;
        vs[p] = v;
    }
    inline int get(ull k) const {
        size_t p = pos(k);
        while (ks[p] && ks[p] != k) p = (p + 1) & msk;
        return ks[p] ? vs[p] : -1;
    }
};
inline void Marionette_() {
    int n = read(), m = read();
    int w = read(), x = read(), y = read(), z = read();
    --w; --x; --y; --z;
    vi eu(m), ev(m), deg(n);
    for (int i = 0; i < m; ++i) {
        eu[i] = read();
        ev[i] = read();
        --eu[i];
        --ev[i];
        ++deg[eu[i]];
        ++deg[ev[i]];
    }
    vi off(n + 1);
    for (int i = 0; i < n; ++i) off[i + 1] = off[i] + deg[i];
    vi cur = off;
    vi to(2 * m), adj(2 * m);
    FM mp;
    mp.init(m);
    for (int i = 0; i < m; ++i) {
        int u = eu[i], v = ev[i];
        int a = 2 * i;
        int b = a ^ 1;
        to[a] = v;
        to[b] = u;
        adj[cur[u]++] = a;
        adj[cur[v]++] = b;
        mp.ins(1ULL * u * n + v + 1, a);
        mp.ins(1ULL * v * n + u + 1, b);
    }
    auto bfs = [&](int s) {
        vi d(n, -1);
        vi q(n);
        int l = 0, r = 0;
        d[s] = 0;
        q[r++] = s;
        while (l < r) {
            int u = q[l++];
            for (int p = off[u]; p < off[u + 1]; ++p) {
                int v = to[adj[p]];
                if (d[v] == -1) {
                    d[v] = d[u] + 1;
                    q[r++] = v;
                }
            }
        }
        return d;
    };
    vi dx = bfs(x);
    vi dz = bfs(z);
    const int BIG = 1e9;
    vi dist(2 * m, BIG);
    vi best(n, BIG);
    vector<unsigned char> sch(m, 0);
    priority_queue<ull, vector<ull>, greater<ull>> pq;
    auto relax = [&](int st, int nd) {
        if (nd < dist[st]) {
            dist[st] = nd;
            pq.push((ull(nd) << 32) | (unsigned int)st);
        }
    };
    for (int p = off[w]; p < off[w + 1]; ++p) {
        int a = adj[p];
        int b = to[a];
        relax(a ^ 1, dx[b] + 1);
    }
    while (!pq.empty()) {
        ull code = pq.top();
        pq.pop();
        int d = int(code >> 32);
        int type = int((code >> 31) & 1);
        int id = int(code & 0x7fffffffULL);
        if (type == 1) {
            int e = id;
            int u = eu[e];
            int v = ev[e];
            int uv = e << 1;
            int vu = uv | 1;
            bool use_uv = (dist[uv] == best[u]);
            bool use_vu = (dist[vu] == best[v]);
            if (!use_uv && !use_vu) continue;
            if (deg[u] <= deg[v]) {
                for (int p = off[u]; p < off[u + 1]; ++p) {
                    int auw = adj[p];
                    int ww = to[auw];
                    int avw = mp.get(1ULL * v * n + ww + 1);
                    if (avw < 0) continue;
                    if (use_uv) relax(auw ^ 1, dist[uv] + 2);
                    if (use_vu) relax(avw ^ 1, dist[vu] + 2);
                }
            } else {
                for (int p = off[v]; p < off[v + 1]; ++p) {
                    int avw = adj[p];
                    int ww = to[avw];
                    int auw = mp.get(1ULL * u * n + ww + 1);
                    if (auw < 0) continue;
                    if (use_uv) relax(auw ^ 1, dist[uv] + 2);
                    if (use_vu) relax(avw ^ 1, dist[vu] + 2);
                }
            }
            continue;
        }
        int st = id;
        if (d != dist[st]) continue;
        int e = st >> 1;
        int u = to[st ^ 1];
        if (best[u] == BIG) {
            best[u] = d;
            for (int p = off[u]; p < off[u + 1]; ++p) {
                relax(adj[p] ^ 1, d + 3);
            }
        }
        relax(st ^ 1, d + 1);
        if (d == best[u] && !sch[e]) {
            sch[e] = 1;
            pq.push((ull(d + 1) << 32) | (1ULL << 31) | (unsigned)e);
        }
    }
    int ans = BIG;
    if (w == y) ans = dx[z];
    for (int p = off[y]; p < off[y + 1]; ++p) {
        int a = adj[p];
        int b = to[a];
        ans = min(ans, dist[a] + dz[b]);
    }
    cout << ans << '\n';
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