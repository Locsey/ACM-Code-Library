#include <bits/stdc++.h>
#include <cassert> 

namespace Polynomials {
    const int mod = 998244353; 
    const int G = 3; 
    using ll = long long; 
    using std :: vector; 
    #define vi vector < int > 
    #define Poly vi 
    #define pb push_back
    #define sz(A) (A).size()
    #define all(A) (A).begin(), A.end() 
    vi rev;
    inline int norm(int x) {
        if(x >= mod) x -= mod; 
        if(x < 0) x += mod;
        return x; 
    }
    inline int add(int x, int y) {return (x += y) >= mod ? x - mod : x;}
    inline int dec(int x, int y) {return (x -= y) < 0 ? x + mod : x;}
    inline void Add(int &x, const int y) {x = add(x, y);}
    inline void Dec(int &x, const int y) {x = dec(x, y);}
    inline int qpow(int a, int b, int p) {
        int s = 1; 
        for(int bas = a; b; b >>= 1, bas = (ll)bas * bas % p)
            if(b & 1) s = (ll)s * bas % p;
        return s; 
    }
    inline void init_rev(int n) {
        if(sz(rev) != n) rev.resize(n); 
        for(int i = 1; i < n; ++i) rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? (n >> 1) : 0); 
    }
    inline void Print(Poly a) {
        int n = a.size(); 
        for(int i = 0; i < n; ++i) printf("%d ", a[i]); 
        puts(""); 
    }
    inline Poly Read(int n) {
        Poly a(n); for(int &x : a) scanf("%d", &x); 
        return a; 
    }
    inline void DFT(Poly &a) {
        int n = a.size(); 
        if(n == 1) return ; 
        init_rev(n); 
        for(int i = 0; i < n; ++i) if(i < rev[i]) std :: swap(a[i], a[rev[i]]); 
        Poly temp(n >> 1); temp[0] = 1; 
        for(int i = 1; i < n; i <<= 1) {
            int w = qpow(G, (mod - 1) / (i << 1), mod);
            for(int j = 1; j < i; ++j) temp[j] = (ll)temp[j - 1] * w % mod; 
            for(int j = 0; j < n; j += (i << 1)) 
                for(int k = 0, *x = &a[j], *y = &a[j | i], *z = &temp[0], v; k < i; ++k, ++x, ++y, ++z) {
                    v = (ll)(*z) * (*y) % mod; 
                    (*y) = dec(*x, v), (*x) = add(*x, v); 
                }
        }
    }
    inline void IDFT(Poly &a) {
        int n = a.size(); 
        if(n == 1) return ; 
        init_rev(n); 
        for(int i = 0; i < n; ++i) if(i < rev[i]) std :: swap(a[i], a[rev[i]]); 
        Poly temp(n >> 1); temp[0] = 1; 
        for(int i = 1; i < n; i <<= 1) {
            int w = qpow(qpow(G, mod - 2, mod), (mod - 1) / (i << 1), mod);
            for(int j = 1; j < i; ++j) temp[j] = (ll)temp[j - 1] * w % mod; 
            for(int j = 0; j < n; j += (i << 1)) 
                for(int k = 0, *x = &a[j], *y = &a[j | i], *z = &temp[0], v; k < i; ++k, ++x, ++y, ++z) {
                    v = (ll)(*z) * (*y) % mod; 
                    (*y) = dec(*x, v), (*x) = add(*x, v); 
                }
        } 
        int in = qpow(n, mod - 2, mod); 
        for(int i = 0; i < n; ++i) a[i] = (ll)a[i] * in % mod; 
    }
    inline Poly operator * (Poly a, Poly b) {
        int n = sz(a), m = sz(b), lim = 1; 
        if(!n || !m) return Poly(0); 
        while(lim <= n + m) lim <<= 1; a.resize(lim), b.resize(lim); 
        DFT(a), DFT(b); 
        for(int i = 0; i < lim; ++i) a[i] = (ll)a[i] * b[i] % mod;
        IDFT(a); 
        return a.resize(n + m - 1), a; 
    }
    inline Poly operator + (Poly a, Poly b) {
        int n = a.size(), m = b.size(); n = std :: max(n, m);
        a.resize(n), b.resize(n); 
        for(int i = 0; i < n; ++i) Add(a[i], b[i]); 
        return a; 
    }
    inline Poly operator - (Poly a, Poly b) {
        int n = a.size(), m = b.size(); n = std :: max(n, m); 
        a.resize(n), b.resize(n); 
        for(int i = 0; i < n; ++i) Dec(a[i], b[i]); 
        return a; 
    }
    inline Poly Inv(const Poly &a) {
        int n = a.size(); if(!n) return Poly(0);  
        if(!a[0]) assert(0); 
        Poly b; b.pb(qpow(a[0], mod - 2, mod)); 
        for(int lim = 1; lim < n; lim <<= 1) {
            int nl = lim << 2; 
            b.resize(nl); Poly na(nl); 
            for(int i = 0; i < (lim << 1); ++i) na[i] = (i < n ? a[i] : 0); 
            DFT(na), DFT(b); 
            for(int i = 0; i < nl; ++i) b[i] = (ll)b[i] * dec(2, (ll)na[i] * b[i] % mod) % mod; 
            IDFT(b); 
            for(int i = (lim << 1); i < nl; ++i) b[i] = 0;
        }
        return b.resize(n), b; 
    }
}

using namespace Polynomials; 
int main() {
    int n; std :: cin >> n; 
    Print(Inv(Read(n))); 
    return 0; 
}