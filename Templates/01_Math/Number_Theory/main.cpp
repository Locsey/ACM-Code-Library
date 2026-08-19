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

namespace Number_Theory_ {
    inline int gcd(int x, int y) {
        return y ? gcd(y, x % y) : x; 
    }
    inline int lcm(int x, int y) {
        return x / gcd(x, y) * y; 
    }
    inline void exgcd(ll a, ll b, ll &x, ll &y, ll &d) {
        if(!b) return x = 1, y = 0, d = a, void();
        exgcd(b, a % b, y, x, d); 
        y -= a / b * x; 
    }
    std :: vector < int > primes; 
    std :: vector < int > phi, mu; 
    inline void euler_sieve(int n) {
        std :: vector < bool > vis(n + 1, false); 
        phi.resize(n + 1), mu.resize(n + 1), phi[1] = mu[1] = 1; 
        for(int i = 2; i <= n; ++i) {
            if(!vis[i]) primes.push_back(i), phi[i] = i - 1, mu[i] = -1; 
            for(int j = 0, sz = primes.size(); j < sz && i * primes[j] <= n; ++j) {
                int t = i * primes[j]; vis[t] = 1; 
                if(i % primes[j] == 0) {phi[t] = phi[i] * primes[j], mu[t] = 0; break;}
                phi[t] = phi[i] * (primes[j] - 1), mu[t] = -mu[i]; 
            }
        }
    }
    inline int Phi(int n) {
        int res = n; 
        for(int i = 2; i <= n; ++i) {
            if(n % i == 0) {
                while(n % i == 0) n /= i; 
                res = res / i * (i - 1); 
            }
        }
        return res; 
    }
    inline int Mu(int n) {
        int res = 1; 
        for(int i = 2; i <= n; ++i) {
            if(n % i == 0) {
                n /= i; if(n % i == 0) return 0; 
                res = -res; 
            }
        }
        return res; 
    }
    inline int Inv(ll a, ll p) {
        ll x, y, d; 
        exgcd(a, p, x, y, d); 
        assert(d == 1); 
        return (x % p + p) % p; 
    }
    inline ll CRT(int n, std :: vector < int > &a, std :: vector < int > &b) {
        ll prod = 1, ans = 0; int n = a.size(); assert(n == b.size()); 
        for(int i = 0; i < n; ++i) prod *= b[i]; 
        for(int i = 0; i < n; ++i) {
            ll m = prod / b[i]; 
            ans += 1ll * a[i] * m % prod * Inv(m, b[i]) % prod; 
            ans %= prod; 
        }
        return ans; 
    }
    inline ll lucas(ll n, ll m, ll p) {
        if(m == 0) return 1; 
        return 1ll * lucas(n / p, m / p, p) * Combinatorics_ :: binom(n % p, m % p) % p; 
    }
    inline 
    inline void mian() {
        
    }
} ; 

int main() {
    Number_Theory_ :: mian();
    return 0; 
}