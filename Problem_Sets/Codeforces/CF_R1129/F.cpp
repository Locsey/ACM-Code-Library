#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::vector;
using std::sort;
using std::min;
using std::max;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
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
inline void mian() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> sz(n + 1);
        sz[1] = n;
        auto query = [&](int x, const vector<int>& p) -> ll {
            cout << "? " << x;
            for (int i = 1; i <= n; ++i) cout << ' ' << p[i];
            cout << '\n'; 
            cout.flush();
            ll res;
            cin >> res;
            if (res == -1) exit(0);
            return res;
        };
        for (int u = 2; u <= n; ++u) {
            vector<int> p(n + 1, 0);
            p[1] = n - 1;
            p[u] = n;
            int cur = 1;
            for (int v = 1; v <= n; ++v) {
                if (v == 1 || v == u) continue;
                p[v] = cur++;
            }
            ll res = query(1, p);
            sz[u] = int(res - 1LL * n * (n - 1));
        }
        vector<std::pair<int, int>> edges;
        for (int x = 2; x <= n; ++x) {
            vector<int> p(n + 1, 0);
            p[x] = 1;
            vector<int> ord;
            for (int v = 1; v <= n; ++v) {
                if (v != x) ord.push_back(v);
            }
            sort(ord.begin(), ord.end(), [&](int a, int b) {
                if (sz[a] != sz[b]) return sz[a] < sz[b];
                return a < b;
            });
            int cur = n;
            for (int v : ord) p[v] = cur--;
            ll res = query(x, p);
            int t = sz[x];
            ll base = 1;
            for (int i = 1; i <= n; ++i) {
                if (i != x && sz[i] <= t) base += p[i];
            }
            ll target = res - base;
            vector<ll> cnt(n + 2, 0), sum(n + 2, 0);
            for (int i = 1; i <= n; ++i) {
                if (sz[i] > t) {
                    ++cnt[p[i]];
                    sum[p[i]] += p[i];
                }
            }
            vector<ll> prefCnt(n + 2, 0);
            vector<ll> sufSum(n + 3, 0);
            for (int k = 1; k <= n; ++k) {
                prefCnt[k] = prefCnt[k - 1] + cnt[k];
            }
            for (int k = n; k >= 1; --k) {
                sufSum[k] = sufSum[k + 1] + sum[k];
            }
            int parent = -1;
            for (int v = 1; v <= n; ++v) {
                if (sz[v] <= t) continue;
                int pv = p[v];
                ll g = 1LL * pv * prefCnt[pv] + sufSum[pv + 1];
                if (g == target) {
                    parent = v;
                    break;
                }
            }
            if (parent == -1) exit(0);
            edges.push_back({parent, x});
        }
        cout << "!" << '\n';
        for (auto [u, v] : edges) {
            cout << u << ' ' << v << '\n';
        }
        cout.flush();
    }
}
}

int main() {
#ifdef LOCAL_DEBUG
#endif
    Solver::mian();
    return 0;
}