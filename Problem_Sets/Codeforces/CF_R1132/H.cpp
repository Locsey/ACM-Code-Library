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
using std::count;
using std::mt19937;
using std::chrono::steady_clock;
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
static const int MOD = 1e9 + 7;
struct Node {
    int l = 0, r = 0;
    int sz = 1;
    unsigned pri = 0;
    int q = 0;
    bool hit = false;
    ll w = 1;
    ll prod = 1;
    ll sum = 1;
};
struct Treap {
    vector<Node> t;
    vector<ll> inv2;
    mt19937 rng{steady_clock::now().time_since_epoch().count()};
    int tot = 0;
    int root = 0;
    Treap(int n) {
        t.resize(2 * n + 5);
        inv2.resize(n + 1);
        inv2[0] = 1;
        for (int i = 1; i <= n; i++)
            inv2[i] = inv2[i - 1] * ((MOD + 1LL) / 2) % MOD;
    }
    int size(int x) {
        return x ? t[x].sz : 0;
    }
    ll getProd(int x) {
        return x ? t[x].prod : 1;
    }
    ll getSum(int x) {
        return x ? t[x].sum : 0;
    }
    int newNode(int q, bool hit) {
        int x = ++tot;
        t[x].q = q;
        t[x].hit = hit;
        t[x].pri = rng();
        t[x].w = hit ? 1 : (1 - inv2[q] + MOD) % MOD;
        t[x].prod = t[x].w;
        t[x].sum = t[x].w;
        return x;
    }
    void pull(int x) {
        int l = t[x].l;
        int r = t[x].r;
        t[x].sz = size(l) + size(r) + 1;
        ll w = t[x].w;
        t[x].prod = getProd(l) * w % MOD * getProd(r) % MOD;
        t[x].sum = (
            getSum(l)
            + getProd(l) * w % MOD
            + getProd(l) * w % MOD * getSum(r) % MOD
        ) % MOD;
    }
    int merge(int a, int b) {
        if (!a || !b) return a | b;
        if (t[a].pri > t[b].pri) {
            t[a].r = merge(t[a].r, b);
            pull(a);
            return a;
        } else {
            t[b].l = merge(a, t[b].l);
            pull(b);
            return b;
        }
    }
    void split(int x, int k, int &a, int &b) {
        if (!x) {
            a = b = 0;
            return;
        }
        if (size(t[x].l) >= k) {
            b = x;
            split(t[x].l, k, a, t[b].l);
            pull(b);
        } else {
            a = x;
            split(t[x].r, k - size(t[x].l) - 1, t[a].r, b);
            pull(a);
        }
    }
    void init(const string &s) {
        int n = (int)s.size();
        for (int i = 0; i < n; i++) {
            int x = newNode(s[i] == '0', s[i] == '1');
            root = merge(root, x);
        }
    }
    int combine(int a, int b) {
        int q = t[a].q + t[b].q;
        bool hit = t[a].hit || t[b].hit;
        return newNode(q, hit);
    }
    ll solve(const string &s) {
        int n = (int)s.size();
        int cnt = count(s.begin(), s.end(), '1');
        int Q = n - cnt;
        init(s);
        ll base = qpow(2, Q, MOD);
        ll ans = 0;
        for (int m = n - 1; m >= 1; m--) {
            if (m == 1) {
                int a, b;
                split(root, 1, a, b);
                root = combine(a, b);
            } else {
                int pre, suf;
                int a0, mid;
                int am1, am;
                split(root, m - 1, pre, suf);
                split(pre, 1, a0, mid);
                split(suf, 1, am1, am);
                int merged = combine(am, a0);
                root = merge(merge(am1, merged), mid);
            }
            ans = (ans + base * getSum(root)) % MOD;
        }
        return ans;
    }
};
inline void Marionette_() {
    int n = read();
    string s;
    cin >> s;
    Treap tr(n);
    cout << tr.solve(s) << '\n';
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