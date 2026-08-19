#include<bits/stdc++.h>

using ll = long long; 
using ull = unsigned long long; 
using db = double; 

using std :: cin; 
using std :: cout; 

const int M = 1e5 + 5; 
const int INF = 0x3f3f3f3f; 
const int mod = 998244353; 

namespace Combinatorics_ {
    std :: vector<int> fac, ifac, inv;
    inline int qpow(int a, int b, int p) {
        int s = 1, bas = a; 
        while(b) {
            if(b & 1) s = 1ll * s * bas % p;
            bas = 1ll * bas * bas % p;
            b >>= 1;
        }
        return s;
    }
    inline void Init_(int n) {
        fac.resize(n + 1), ifac.resize(n + 1), inv.resize(n + 1); 
        fac[0] = inv[1] = 1; 
        for(int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
        ifac[n] = qpow(fac[n], mod - 2, mod);
        for(int i = n - 1; i >= 0; --i) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod; 
        for(int i = 2; i <= n; ++i) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    }
    inline int binom(int n, int m) {
        if(n < m || m < 0) return 0; 
        assert(n < (int)fac.size() && m < (int)fac.size()); 
        return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
    }
    inline int Inv(int a) {
        return qpow(a, mod - 2, mod);
    }
    inline int Catalan(int n) {
        // ensure 2 * n < N
        return 1ll * fac[2 * n] * ifac[n] % mod * ifac[n + 1] % mod;
    }
    
    inline void mian() {
        
    }
} ; 

int main() {
    Combinatorics_ :: mian();
    return 0; 
}