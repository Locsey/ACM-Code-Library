#include <bits/stdc++.h>
#define int long long 

using ll = long long; 

const int mod = 998244353; 
const int M = 2e5 + 5; 

int n, x, a[M], pw[M], fac[M], ifac[M];
inline int qpow(int a, int b, int p) {
    int s = 1; 
    for(int bas = a; b; b >>= 1, bas = (ll)bas * bas % p)
        if(b & 1) s = (ll)s * bas % p;
    return s; 
}
inline void init(int n) {
    fac[0] = ifac[0] = 1; 
    for(int i = 1; i <= n; ++i) fac[i] = (ll)fac[i - 1] * i % mod; 
    ifac[n] = qpow(fac[n], mod - 2, mod); 
    for(int i = n; i; --i) ifac[i - 1] = (ll)ifac[i] * i % mod; 
}
inline int binom(int n, int m) {
    if(n < 0 || m < 0 || n < m) return 0; 
    return (ll)fac[n] * ifac[m] % mod * ifac[n - m] % mod; 
}

inline int add(int x, int y) {x += y; return (x >= mod) ? x - mod : x;}
inline int dec(int x, int y) {x -= y; return (x < 0) ? x + mod : x;}
inline void solve() {
    std :: cin >> n >> x; 
    for(int i = 1; i <= n; ++i) std :: cin >> a[i]; 
    std :: sort(a + 1, a + n + 1); 
    int ans = 0; 
    std :: map < int, int > mp1, mp2; 
    for(int i = 1; i <= n; ++i) {
        if(a[i] == x) ans = add(ans, binom(n - 1, i - 1)); 
        int r = mp2[2 * x - a[i]], l; 
        if(r) {
            l = mp1[2 * x - a[i]]; 
            l = n - (i - l + 1), r = n - (i - r + 1); 
            ans = add(ans, dec(binom(r + 1, n - i + 1), binom(l, n - i + 1))); 
        }
        if(mp1.find(a[i]) == mp1.end()) mp1[a[i]] = i; 
        mp2[a[i]] = i; 
    }
    std :: cout << ans << '\n'; 
}
signed main() {
    int T; std :: cin >> T;  init(M - 1); 
    while(T --) solve(); 
}