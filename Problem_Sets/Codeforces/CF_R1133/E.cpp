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
using std::fill;
using std::min;
using std::max;
using std::memset;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define mem(a, b) memset(a, b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u32;
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
constexpr int SZ = 1 << 22;
static unsigned char dp[SZ];
static vi tch;
struct CS {
    vector<u32> fst;
    vector<vector<u32>> df;
};
inline void gm(int n, int k, bool rv, u32 msk, vector<u32>& out) {
    if (k == 0) {
        out.push_back(msk);
        return;
    }
    if (k == n) {
        out.push_back(msk | ((1u << n) - 1));
        return;
    }
    u32 b = 1u << (n - 1);
    if (!rv) {
        gm(n - 1, k, false, msk, out);
        gm(n - 1, k - 1, true, msk | b, out);
    } else {
        gm(n - 1, k - 1, false, msk | b, out);
        gm(n - 1, k, true, msk, out);
    }
}
inline CS bld(int n, int lim) {
    CS s;
    lim = min(n, lim);
    s.fst.resize(lim + 1);
    s.df.resize(lim + 1);
    for (int k = 0; k <= lim; ++k) {
        vector<u32> ms;
        gm(n, k, false, 0, ms);
        s.fst[k] = ms[0];
        auto &v = s.df[k];
        v.reserve(ms.size() - 1);
        for (int i = 1; i < (int)ms.size(); ++i) v.push_back(ms[i] ^ ms[i - 1]);
    }
    return s;
}
inline int cst(u32 msk) {
    int k = __builtin_popcount(msk);
    int l = __builtin_ctz(msk);
    int r = 31 - __builtin_clz(msk);
    return 2 * (r - l) - k + 1;
}
inline vector<u32> gd(const vi& a, int st, int len) {
    int bas[25] = {};
    u32 rp[25] = {};
    vector<u32> d;
    for (int j = 0; j < len; ++j) {
        int x = a[st + j];
        u32 msk = 1u << j;
        for (int b = 24; b >= 0; --b) {
            if (!((x >> b) & 1)) continue;
            if (bas[b]) {
                x ^= bas[b];
                msk ^= rp[b];
            } else {
                bas[b] = x;
                rp[b] = msk;
                break;
            }
        }
        if (x == 0) d.push_back(msk);
    }
    return d;
}
struct DB {
    int bas[25] = {};
    int id[25];
    int rk = 0;
    DB() {
        fill(id, id + 25, -1);
    }
    inline void ins(int x) {
        for (int b = 24; b >= 0; --b) {
            if (!((x >> b) & 1)) continue;
            if (bas[b]) {
                x ^= bas[b];
            } else {
                bas[b] = x;
                id[b] = rk++;
                return;
            }
        }
    }
    inline pii dc(int x) const {
        int c = 0;
        for (int b = 24; b >= 0; --b) {
            if (((x >> b) & 1) && bas[b]) {
                x ^= bas[b];
                c ^= 1 << id[b];
            }
        }
        return {x, c};
    }
};
inline int sv(const vi& a) {
    int n = (int)a.size();
    for (int x : a) if (x == 0) return 0;
    int best = 49;
    if (n < 26) {
        auto d = gd(a, 0, n);
        if (d.empty()) return -1;
        for (u32 msk : d) best = min(best, cst(msk));
    } else {
        for (int st = 0; st + 26 <= n; ++st) {
            auto d = gd(a, st, 26);
            for (u32 msk : d) best = min(best, cst(msk));
        }
        if (best == 49) return 49;
    }
    vi pre(n + 1, 0);
    for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] ^ a[i];
    for (int d = 1; d < best; ++d) {
        int mt = best - d - 1;
        int m = d - 1;
        int h1 = m / 2;
        int h2 = m - h1;
        CS sl = bld(h1, mt);
        CS sr = bld(h2, mt);
        for (int l = 0; l + d < n; ++l) {
            int r = l + d;
            int tg = pre[r + 1] ^ pre[l];
            if (tg == 0) return d;
            int lim = min(mt, best - d - 1);
            if (lim <= 0) continue;
            DB bs;
            for (int j = 0; j < h1; ++j) bs.ins(a[l + 1 + j]);
            vi lc(h1);
            for (int j = 0; j < h1; ++j) lc[j] = bs.dc(a[l + 1 + j]).second;
            auto [tr, tc] = bs.dc(tg);
            vi rr(h2);
            vi rc(h2);
            for (int j = 0; j < h2; ++j) {
                auto [res, c] = bs.dc(a[l + 1 + h1 + j]);
                rr[j] = res;
                rc[j] = c;
            }
            tch.clear();
            int kl = min(lim, h1);
            for (int k = 0; k <= kl; ++k) {
                u32 msk = sl.fst[k];
                int x = 0;
                while (msk) {
                    int b = __builtin_ctz(msk);
                    x ^= lc[b];
                    msk &= msk - 1;
                }
                if (dp[x] == 255) {
                    dp[x] = (unsigned char)k;
                    tch.push_back(x);
                }
                for (u32 df : sl.df[k]) {
                    int b1 = __builtin_ctz(df);
                    df &= df - 1;
                    int b2 = __builtin_ctz(df);
                    x ^= lc[b1] ^ lc[b2];
                    if (dp[x] == 255) {
                        dp[x] = (unsigned char)k;
                        tch.push_back(x);
                    }
                }
            }
            bool stop = false;
            int kr = min(lim, h2);
            for (int k = 0; k <= kr && !stop; ++k) {
                u32 msk = sr.fst[k];
                int xr = 0;
                int xc = 0;
                while (msk) {
                    int b = __builtin_ctz(msk);
                    xr ^= rr[b];
                    xc ^= rc[b];
                    msk &= msk - 1;
                }
                auto qy = [&]() {
                    if (xr != tr) return;
                    int nd = tc ^ xc;
                    unsigned char v = dp[nd];
                    if (v == 255) return;
                    int tt = k + (int)v;
                    if (d + tt < best) {
                        best = d + tt;
                        if (best <= d + 1) stop = true;
                    }
                };
                qy();
                if (stop) break;
                for (u32 df : sr.df[k]) {
                    int b1 = __builtin_ctz(df);
                    df &= df - 1;
                    int b2 = __builtin_ctz(df);
                    xr ^= rr[b1] ^ rr[b2];
                    xc ^= rc[b1] ^ rc[b2];
                    qy();
                    if (stop) break;
                }
            }
            for (int idx : tch) dp[idx] = 255;
        }
        if (best <= d + 1) return best;
    }
    return best;
}
inline void Marionette_() {
    int n = read();
    vi a(n);
    for (int &x : a) x = read();
    cout << sv(a) << '\n';
}
inline void mian() {
    mem(dp, 255);
    tch.reserve(250000);
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