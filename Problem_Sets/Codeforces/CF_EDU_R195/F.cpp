#include <bits/stdc++.h>

using std :: cin;
using std :: cout;

typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;

const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

inline int read() {
    int f = 1, s = 0; char ch = getchar(); 
    while(!isdigit(ch)) (ch == '-') && (f = -f), ch = getchar(); 
    while(isdigit(ch)) s = (s << 1) + (s << 3) + ch - 48, ch = getchar(); 
    return f * s; 
}

namespace Solver {
    int n, k, p[M], f[M], sz[M], c[M], m; 
    inline int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
    inline void merge(int x, int y) {
        x = find(x), y = find(y); if(x == y) return ;
        f[x] = y, sz[y] += sz[x]; 
    }
    inline void chkmn(int &x, int y) {if(y < x) x = y;}
    int vis[M]; 
    int dp[2][25][25]; 
    inline void Marionette_() {
        n = read(), k = read(); 
        for(int i = 1; i <= n; ++i) f[i] = i, sz[i] = 1, vis[i] = 0; 
        for(int i = 1; i <= n; ++i) p[i] = read(), merge(i, p[i]); 
        m = 0; for(int i = 1; i <= n; ++i) if(find(i) == i) c[++m] = sz[i]; 
        std :: sort(c + 1, c + m + 1);
        if(c[m] > k + 1) return puts("Bob"), void();         
        if(k == 1) {
            if(c[m] == 1) return puts("Alice"), void();
            int c1 = 0;
            for(int i = 1; i <= m; ++i) if(c[i] == 1) c1 ++;
            if(c1 & 1) return puts("Alice"), void();
            return puts("Bob"), void(); 
        }
        if((m > 1) && (c[m] == k + 1 && c[m - 1] == k + 1)) return puts("Bob"), void();
        if(c[m] == k + 1) {
            int sum = 0, c1 = 0; 
            for(int i = 1; i < m; ++i) if(c[i] > 1) sum += c[i]; else c1 ++; 
            // printf("!!!, s = %d\n", sum); 
            if(sum > k) return puts("Bob"), void(); 
            int rem = k - sum;
            for(int i = 0; i <= std :: min(rem, c1); ++i) if((sum + i) && (c1 - i) % (k + 1) == 0) return puts("Alice"), void();
            return puts("Bob"), void(); 
        }
        int nm = std :: min(2 * k, m), p = 0, q = 1; 
        std :: memset(dp, 0x3f, sizeof(dp)), dp[0][0][0] = 0;
        for(int i = 1; i <= nm; ++i, std :: swap(p, q), memset(dp[q], 0x3f, sizeof(dp[q]))) {
            int cyc = c[m - i + 1];
            for(int u = 0; u <= k; ++u) for(int v = 0, w; v <= k; ++v) if((w = dp[p][u][v]) != INF) {
                if(v < k) chkmn(dp[q][u][v + 1], w + cyc - 1);
                else chkmn(dp[q][u][v], w); 
                if(u + cyc <= k) chkmn(dp[q][u + cyc][v], w); 
            }
        }
        for(int u = 0; u <= k; ++u) 
            for(int v = 0; v <= k; ++v) if(dp[p][u][v] <= k) return puts("Alice"), void();
        puts("Bob"); 
    }
    inline void mian() {
        int t = 1; 
        t = read();
        while(t --) Marionette_(); 
    }
}

int main() {
    Solver :: mian(); 
    return 0; 
}