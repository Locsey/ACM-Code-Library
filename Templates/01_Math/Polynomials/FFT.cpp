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

const int M = (1 << 21) + 1; 
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int G = 3; 
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

inline int add(int x, int y) {return (x += y) >= mod ? x - mod : x;}
inline int dec(int x, int y) {return (x -= y) < 0 ? x + mod : x;}
namespace Solver {
    int n, m, rev[M];
    #define Poly vi 
    inline void init_rev(int n) {
        for(int i = 1; i < n; ++i) rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? (n >> 1) : 0); 
    }
    inline void DFT(Poly &a) {
        int n = a.size(); 
        init_rev(n); 
        for(int i = 0; i < n; ++i) if(i < rev[i]) std :: swap(a[i], a[rev[i]]); 
        for(int i = 1; i < n; i <<= 1) {
            int w = qpow(G, (mod - 1) / (i << 1), mod);
            for(int j = 0; j < n; j += (i << 1))
                for(int k = 0, v = 1; k < i; ++k, v = (ll)v * w % mod) {
                    int x = a[j + k], y = (ll)v * a[j + k + i] % mod; 
                    a[j + k] = add(x, y), a[j + k + i] = dec(x, y); 
                }
        }
    }
    inline void IDFT(Poly &a) {
        int n = a.size(); 
        for(int i = 0; i < n; ++i) if(i < rev[i]) std :: swap(a[i], a[rev[i]]); 
        for(int i = 1; i < n; i <<= 1) {
            int w = qpow(qpow(G, mod - 2, mod), (mod - 1) / (i << 1), mod);
            for(int j = 0; j < n; j += (i << 1))
                for(int k = 0, v = 1; k < i; ++k, v = (ll)v * w % mod) {
                    int x = a[j + k], y = (ll)v * a[j + k + i] % mod; 
                    a[j + k] = add(x, y), a[j + k + i] = dec(x, y); 
                }
        }
        int in = qpow(n, mod - 2, mod); 
        for(int i = 0; i < n; ++i) a[i] = (ll)a[i] * in % mod; 
    }
    inline void Marionette_() {
        n = read(), m = read(); 
        Poly a, b; 
        for(int i = 0; i <= n; ++i) a.pb(read()); 
        for(int i = 0; i <= m; ++i) b.pb(read());
        int lim = 1; while(lim <= n + m) lim <<= 1; 
        a.resize(lim), b.resize(lim); 
        DFT(a), DFT(b);
        for(int i = 0; i < lim; ++i) a[i] = (ll)a[i] * b[i] % mod;
        IDFT(a); 
        for(int i = 0; i <= n + m; ++i) cout << a[i] << ' '; 
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