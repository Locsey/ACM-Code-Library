#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;

#define M 200005
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int read() {
    int f = 1, s = 0; char ch = getchar(); 
    while(!isdigit(ch)) {if(ch == '-') f = -f; ch = getchar();}
    while(isdigit(ch)) {s = (s << 1) + (s << 3) + ch - 48; ch = getchar();}
    return f * s; 
}

int n, m, b;
int c[M], a[M], f[M], sz[M], pw[M]; 
int dec(int x, int y) {x -= y; if(x < 0) x += mod; return x;}
int find(int x) {if(f[x] == x) return x; return f[x] = find(f[x]);}
inline void merge(int x, int y) {
    x = find(x), y = find(y);
    if(x != y) f[x] = y, sz[y] += sz[x]; 
}
int qpow(int a, int b, int p) {
    int s = 1; 
    for(int bas = a; b; b >> 1, bas = (ll)bas * bas % p)
        if(b & 1) s = (ll)s * bas % p;
    return s; 
}

void Marionette_() {
    n = read(), m = read(), b = read(), pw[0] = 1; 
    for(int i = 1; i <= n; ++i) f[i] = i, pw[i] = (ll)pw[i - 1] * 2 % mod;
    for(int i = 1, x; i < n; ++i) {
        x = read();
        if(!x) merge(i, i + 1); 
    }
    int cnt = 0, cur = 1; 
    for(int i = 1; i <= n; ++i) if(find(i) == i) cur = (ll)cur * dec(pw[sz[i]], 1) % mod; 
    int ans = 1, all = pw[n]; 
    for(int i = 0; i < m; ++i) {
        if((b >> i) & 1) ans = (ll)ans * dec(pw[n], cur) % mod;
        else ans = (ll)ans * cur % mod;  
    }
    cout << ans; 
}

int main() {
    int t = 1; 
    while(t --) Marionette_(); 
    return 0; 
}