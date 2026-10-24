#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::vector;
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
static constexpr ll MOD = 998244353LL;
static constexpr ll INV2 = (MOD + 1) / 2;
static constexpr int P = 8192;
static constexpr int LOG = 60;
ll prefW[P];
ll prefMin[LOG + 1][P];
ll Acoef[LOG + 1];
ll Cval[P];
ll Dval[LOG + 1];
inline ll mulmod(ll a, ll b) {
    return (a % MOD) * (b % MOD) % MOD;
}
inline ll triMod(ll x) {
    return mulmod(mulmod(x, x + 1), INV2);
}
inline ll countOnes(ll x, int bit) {
    ll n = x + 1;
    ll len = 1LL << (bit + 1);
    ll half = 1LL << bit;
    return (n / len) * half + max(0LL, n % len - half);
}
inline ll h0(ll p) {
    ll ans = 32768LL * p;
    for (int i = 0; i <= LOG && (1LL << i) <= p; ++i) {
        if ((p >> i) & 1LL) ans += i + 14;
    }
    return ans;
}
inline ll lowVal(ll q) {
    ll ans = 4LL * q;
    for (int i = 0; i < 13; ++i) {
        if ((q >> i) & 1LL) ans += i + 1;
    }
    return ans;
}
inline void init() {
    for (int t = 0; t <= LOG; ++t) {
        Dval[t] = 32768LL + 14 - 13LL * t - 1LL * t * (t - 1) / 2;
    }
    for (int q = 0; q < P; ++q) {
        ll v = lowVal(q);
        if (q <= P - 16) {
            int a = (q + 15) / 16 * 16;
            Cval[q] = min(v, lowVal(a));
        } else {
            Cval[q] = v;
        }
    }
    prefW[0] = 0;
    for (int q = 1; q < P; ++q) {
        ll w = 2LL * (__builtin_ctz((unsigned)q) + 1);
        prefW[q] = (prefW[q - 1] + w) % MOD;
    }
    for (int t = 0; t <= LOG; ++t) {
        prefMin[t][0] = 0;
        for (int q = 1; q < P; ++q) {
            ll w = 2LL * (__builtin_ctz((unsigned)q) + 1);
            ll val = min(Cval[q], Dval[t]);
            prefMin[t][q] = (prefMin[t][q - 1] + mulmod(w, val)) % MOD;
        }
        Acoef[t] = prefMin[t][P - 1];
    }
}
inline ll sumH0Prefix(ll x) {
    if (x < 0) return 0;
    ll ans = mulmod(32768, triMod(x));
    for (int i = 0; i <= LOG && (1LL << i) <= x; ++i) {
        ans = (ans + mulmod(i + 14, countOnes(x, i))) % MOD;
    }
    return ans;
}
inline ll sumH0MultiplesPrefix(ll x, int t) {
    if (x <= 0 || t > LOG) return 0;
    ll pw = 1LL << t;
    ll y = x / pw;
    if (y == 0) return 0;
    ll coeff = (32768LL * pw) % MOD;
    ll ans = mulmod(coeff, triMod(y));
    for (int i = 0; i <= LOG && (1LL << i) <= y; ++i) {
        ans = (ans + mulmod(i + t + 14, countOnes(y, i))) % MOD;
    }
    return ans;
}
inline ll sumH0V2Prefix(ll x) {
    if (x <= 0) return 0;
    ll ans = 0;
    for (int t = 1; t <= LOG && (1LL << t) <= x; ++t) {
        ans += sumH0MultiplesPrefix(x, t);
        if (ans >= MOD) ans -= MOD;
    }
    return ans;
}
inline ll sumZPrefix(ll x) {
    if (x <= 0) return 0;
    return (28LL * sumH0Prefix(x) + 2LL * sumH0V2Prefix(x)) % MOD;
}
inline ll sumAPrefix(ll x) {
    if (x < 0) return 0;
    ll n = x + 1;
    ll ans = 0;
    for (int t = 0; t <= LOG; ++t) {
        ll cnt = n / (1LL << t) - n / (1LL << (t + 1));
        ans = (ans + mulmod(Acoef[t], cnt)) % MOD;
    }
    return ans;
}
inline ll prefixWeightedM(ll x) {
    if (x <= 0) return 0;
    ll blocks = x / P;
    int q = (int)(x % P);
    ll ans = 0;
    if (blocks > 0) {
        ans = (ans + mulmod(prefW[P - 1], sumH0Prefix(blocks - 1))) % MOD;
        ans = (ans + sumAPrefix(blocks - 1)) % MOD;
        ans = (ans + sumZPrefix(blocks - 1)) % MOD;
    }
    if (blocks >= 1) {
        ll wt = 2LL * (14 + __builtin_ctzll((unsigned long long)blocks));
        ans = (ans + mulmod(h0(blocks), wt)) % MOD;
    }
    if (q >= 1) {
        int t = __builtin_ctzll((unsigned long long)(blocks + 1));
        ans = (ans + mulmod(h0(blocks), prefW[q])) % MOD;
        ans = (ans + prefMin[t][q]) % MOD;
    }
    return ans;
}
inline ll G(ll r) {
    return 4LL * r - 2LL * __builtin_popcountll((unsigned long long)r);
}
inline ll lowerBoundG(ll x) {
    ll lo = 1, hi = x;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (G(mid) >= x) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
inline ll Mvalue(ll r) {
    ll p = r / P;
    int q = (int)(r % P);
    int t = __builtin_ctzll((unsigned long long)(p + 1));
    return h0(p) + min(Cval[q], Dval[t]);
}
inline ll sumMForXRange(ll L, ll R) {
    if (L > R) return 0;
    ll a = lowerBoundG(L);
    ll b = lowerBoundG(R);
    if (a == b) return mulmod(Mvalue(a), R - L + 1);
    ll ans = mulmod(Mvalue(a), G(a) - L + 1);
    ll middle = (prefixWeightedM(b - 1) - prefixWeightedM(a)) % MOD;
    if (middle < 0) middle += MOD;
    ans = (ans + middle) % MOD;
    ans = (ans + mulmod(Mvalue(b), R - G(b - 1))) % MOD;
    return ans;
}
inline ll sum1to(ll x) {
    if (x <= 0) return 0;
    return triMod(x);
}
inline ll solve(ll l, ll r) {
    ll ans = 0;
    if (l <= 1 && 1 <= r) ans = 1;
    ll lo = max(l, 2LL);
    if (lo <= r) {
        ll xsum = sumMForXRange(lo - 1, r - 1);
        ll nsum = (sum1to(r) - sum1to(lo - 1) + MOD) % MOD;
        ans = (ans + xsum - nsum) % MOD;
        if (ans < 0) ans += MOD;
    }
    return ans;
}
inline void Marionette_() {
}
inline void mian() {
    init();
    int t = read();
    while (t--) {
        ll l = readll();
        ll r = readll();
        cout << solve(l, r) << '\n';
    }
}
}

int main() {
#ifdef LOCAL_DEBUG
#endif
    Solver::mian();
    return 0;
}