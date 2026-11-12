#include <bits/stdc++.h>

namespace Pollard_Rho {
    using ll = long long; 
    using i128 = __int128; 
    using vi = std :: vector < int >; 
    using vll = std :: vector < ll >; 
    #define pb push_back 
    #define all(x) (x).begin(), (x).end()  
    std :: mt19937 en(time(nullptr)); 
    inline ll mul(ll a, ll b, ll p) {
        long double t = 1.0L * a / p * b;
        ll v = (i128)a * b - (i128)t * p; if(v < 0) v += p; if(v >= p) v -= p; 
        return v; 
    }
    inline ll add(ll a, ll b, ll p) {
        return (a += b) >= p ? a - p : a;
    }
    inline ll qpow(ll a, ll b, ll p) {
        ll s = 1;
        for(ll bas = a; b; b >>= 1, bas = mul(bas, bas, p))
            if(b & 1) s = mul(s, bas, p);
        return s; 
    }
    inline bool MR(ll n) {
        if(n < 3 || (!(n & 1))) return n == 2; 
        ll bas = n - 1, c = 0; while(!(bas & 1)) bas >>= 1, ++c;
        for(int x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
            if(n == x) return 1; 
            ll cur = qpow(x, bas, n); if(!cur) return 0; if(cur == 1 || cur == n - 1) continue ; 
            for(int i = 1; i < c; ++i, cur = mul(cur, cur, n)) if(cur == n - 1) break;
            if(cur ^ (n - 1)) return 0; 
        }
        return 1; 
    }
    inline ll nxt(ll x, ll c, ll n) {return add(mul(x, x, n), c, n);}
    inline ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
    inline ll Abs(ll x) {return x > 0 ? x : -x;}
    inline ll PR(ll n) {
        if(n == 4) return 2; 
        std :: uniform_int_distribution < ll > myr(3, n - 2);
        ll c = myr(en), x = 0, y = c; 
        for(int lim = 1; x ^ y; lim = std :: min(128, lim << 1)) {
            ll s = 1; 
            for(int i = 0; i < lim; ++i) {
                ll t = mul(s, Abs(x - y), n); 
                if(!t) break ; s = t, x = nxt(x, c, n), y = nxt(y, c, n), y = nxt(y, c, n); 
            }
            ll v = gcd(n, s); 
            if(v ^ 1) return v; 
        }
        return n; 
    }
    vll an;  
    inline void dfs(ll n) {
        if(MR(n)) return an.pb(n), void(); 
        ll d = PR(n); while(d == n) d = PR(n); 
        dfs(d), dfs(n / d); 
    }
    inline vll get_divisor(ll n) {
        an.clear(); dfs(n); 
        std :: sort(all(an)); 
        return an; 
    }
}

using namespace Pollard_Rho; 

int main() {
    ll n; std :: cin >> n; 
    vll an = get_divisor(n); 
    for(ll &x : an) std :: cout << x << ' '; 
}