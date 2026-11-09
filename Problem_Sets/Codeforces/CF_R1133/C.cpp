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
using std::upper_bound;
using std::sqrtl;

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
    ll l = readll();
    vll a(n);
    ll sum = 0;
    for (auto &x : a) {
        x = readll();
        sum += x;
    }
    sort(a.begin(), a.end(), greater<ll>());
    ll mx = a[0];
    if (l == 1) {
        cout << sum - mx << '\n';
        return;
    }
    vll b(a.begin() + 1, a.end());
    sort(b.begin(), b.end());
    int m = n - 1;
    vll pref(m + 1, 0);
    for (int i = 0; i < m; i++) pref[i + 1] = pref[i] + b[i];
    auto calc = [&](ll y) -> ll {
        int p = upper_bound(b.begin(), b.end(), y) - b.begin();
        return pref[p] + 1LL * (m - p) * y;
    };
    ll L = l - 1;
    ll s = sqrtl((long double)L);
    while ((s + 1) * (s + 1) <= L) ++s;
    while (s * s > L) --s;
    ll best = 0;
    ll x0 = min(mx, s);
    best = max(best, x0 + calc(x0));
    if (mx <= s) {
        cout << 0 << '\n';
        return;
    }
    ll x = s + 1;
    while (x <= mx) {
        ll y = L / x;
        if (y == 0) {
            best = max(best, mx);
            break;
        }
        ll r = min(mx, L / y);
        best = max(best, r + calc(y));
        x = r + 1;
    }
    cout << sum - best << '\n';
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