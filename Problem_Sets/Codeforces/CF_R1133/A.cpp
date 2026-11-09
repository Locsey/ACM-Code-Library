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
inline void Marionette_() {
    int n = read();
    vi a(n);
    for (int &x : a) x = read();
    vi d(n - 1);
    int D = 0;
    for (int i = 0; i < n - 1; i++) {
        d[i] = abs(a[i] - a[i + 1]);
        D = max(D, d[i]);
    }
    auto ck = [&](int x) -> bool {
        vi b;
        for (int i = 0; i < n - 1; i++) {
            if (d[i] > x) {
                b.push_back(i);
                if (b.size() > 2) return false;
            }
        }
        if (b.empty()) return true;
        if (b.size() == 2) {
            int p = b[0];
            int q = b[1];
            for (int i = p + 1; i < q; i++) {
                if (d[i] > x / 2) return false;
            }
            if (abs(a[p] - 2 * a[q]) > x) return false;
            if (abs(2 * a[p + 1] - a[q + 1]) > x) return false;
            return true;
        }
        int p = b[0];
        for (int r = p + 1; r < n; r++) {
            bool ok1 = (abs(a[p] - 2 * a[r]) <= x);
            bool ok2 = (r == n - 1 || abs(2 * a[p + 1] - a[r + 1]) <= x);
            if (ok1 && ok2) return true;
            if (r < n - 1 && d[r] > x / 2) break;
        }
        for (int l = p; l >= 0; l--) {
            bool ok1 = (l == 0 || abs(a[l - 1] - 2 * a[p]) <= x);
            bool ok2 = (abs(2 * a[l] - a[p + 1]) <= x);
            if (ok1 && ok2) return true;
            if (l > 0 && d[l - 1] > x / 2) break;
        }
        return false;
    };
    int lo = -1, hi = D;
    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
        if (ck(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
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