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

const int M = 2e5 + 5;
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
    int n, a[M], pre[M]; 
    int c[M]; 
    inline void add(int x, int k) {++x;while(x <= n + 1) c[x] += k, x += x & -x;}
    inline int Q(int x) {++x; int s = 0; while(x) s += c[x], x -= x & -x; return s; }
    inline void Marionette_() {
        cin >> n; int ans = 0; 
        for(int i = 1; i <= n; ++i) {
            cin >> a[i]; if(a[i] >= n) a[i] = n; 
            int w = 0; 
            if(a[i] < n) {
                w = i - 1 - Q(a[i] - 1); 
                add(a[i], 1); 
            }
            pre[i] = w; 
        } for(int i = 1; i <= n + 1; ++i) c[i] = 0; 
        for(int i = n; i; --i) if(a[i] < n) {
            int s = pre[i] + n - i - Q(a[i] - 1) + 1; 
            if(a[i] < s) ans = std :: max(ans, s);
            add(a[i], 1); 
        }
        for(int i = 1; i <= n + 1; ++i) c[i] = 0; 
        cout << ans << '\n'; 
    }

    inline void mian() {
        int t = 1;
        t = read();
        while (t--) Marionette_();
    }
}

int main() {
    #ifdef LOCAL_DEBUG
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif
    Solver::mian();
    return 0;
}