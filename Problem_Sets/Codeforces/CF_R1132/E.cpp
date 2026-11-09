#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::vector;
using std::mt19937;
using std::chrono::steady_clock;

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
    inline int gcd(int a, int b) {
        return !b ? a : gcd(b, a % b); 
    }
    int dp[55], to[55], pre[55];
    mt19937 rng{steady_clock::now().time_since_epoch().count()};
    inline void upd(int x, int y) {
        if(dp[x] + 1 <= dp[y]) dp[y] = dp[x] + 1, pre[y] = x; 
    }
    inline void Marionette_() {
        int a = read(), b = read(); 
        int pq = 0; 
        if(a == b) {puts("0"); return ; } 
        if(gcd(a, b) == 1) {puts("1"); cout << b - a << '\n'; return ;}
        if(b - a >= 32768) {
            while(1) {
                int w = rng() % (b - a + 1) + a;
                if(gcd(a, w) == 1) {
                    if(gcd(w, b) == 1) {
                        puts("2");
                        cout << w - a << ' ' << b - w << '\n'; 
                        return ;
                    }
                }
            }
        }
        to[++pq] = a; 
        for(int i = 1; i <= std :: min(20, b - a - 1); ++i) to[++pq] = a + i; 
        
        if(b - a > 100) {
            int L = b - a >> 1; 
            for(int i = a + L - 5; i <= a + L + 5; ++i) to[++pq] = i; 
        }
        for(int i = std :: max(std :: min(a + 21, b), b - 20); i < b; ++i) to[++pq] = i; 
        to[++pq] = b;
        memset(dp, 0x3f, sizeof(dp)), memset(pre, 0, sizeof(pre)), dp[1] = 0; 
        for(int i = 2; i <= pq; ++i) 
           for(int j = 1; j < i; ++j) if(gcd(to[j], to[i]) == 1) upd(j, i); 
        vi an; cout << dp[pq] << '\n'; int cur = pq;
        while(cur > 1) {an.pb(to[cur] - to[pre[cur]]), cur = pre[cur];}
        std :: reverse(all(an));
        for(int &x : an) cout << x << ' ';
        puts(""); 
    }

    inline void mian() {
        int t = 1;
        t = read();
        while (t--) Marionette_();
    }
}

int main() {
    srand(time(NULL)); 
    #ifdef LOCAL_DEBUG
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif
    Solver::mian();
    return 0;
}