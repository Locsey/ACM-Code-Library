#include <bits/stdc++.h>

using std :: cin;
using std :: cout;

typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;

const int M = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

inline int read() {
    int f = 1, s = 0; char ch = getchar(); 
    while(!isdigit(ch)) (ch == '-') && (f = -f), ch = getchar(); 
    while(isdigit(ch)) s = (s << 1) + (s << 3) + ch - 48, ch = getchar(); 
    return f * s; 
}

namespace Solver {
    int n, vis[M], prime[M], cnt, rnd[M]; 
    inline void sieve(int n) {
        for(int i = 2; i <= n; ++i) {
            if(!vis[i]) prime[++cnt] = i, rnd[i] = cnt; 
            for(int j = 1; j <= cnt && prime[j] * i <= n; ++j) {
                vis[prime[j] * i] = 1; 
                if(i % prime[j] == 0) continue ; 
            }
        }
    }
    int a[M], ha[M]; 
    inline void Marionette_() {
        n = read(); ll ans = 0; int mx = 0; 
        for(int i = 1; i <= n; ++i) a[i] = read(), ha[a[i]] ++, mx = std :: max(mx, a[i]); 
         int num = 0; std :: map < int, int > mp; 
        for(int i = 1; i <= n; ++i) {
            int x = a[i]; 
            for(int j = 1; j <= cnt && prime[j] * prime[j] <= x; ++j) if(x % prime[j] == 0) {
                int z = 0; 
                while(x % prime[j] == 0) x /= prime[j], ++z; 
                if(z & 1) {
                    if(mp.find(j) == mp.end()) mp[j] = 1, ++num;
                    else mp.erase(j), --num; 
                }
            }
            if(x > 1) {
                int w = rnd[x]; 
                    if(mp.find(w) == mp.end()) mp[w] = 1, ++num;
                    else mp.erase(w), --num; 
            }
            if(num <= 9) {
                ll cur = 1; 
                for(auto &x : mp) {
                    int u = x.first; cur *= prime[u];
                    if(cur > M - 5) break ; 
                }
                if(cur <= M - 5 && cur <= mx) {
                    for(int u = 1; u * u * cur <= mx; ++u) ans += ha[u * u * cur]; 
                }
            }
        }
        for(int i = 1; i <= n; ++i) ha[a[i]] = 0; 
        cout << ans << '\n'; 
    }
    inline void mian() {
        int t = 1; 
        t = read(); sieve(M - 5); 
        while(t --) Marionette_(); 
    }
}

int main() {
    Solver :: mian(); 
    return 0; 
}