#include <bits/stdc++.h>

using std :: cin;
using std :: cout;

typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;

const int M = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

inline int read() {
    int f = 1, s = 0; char ch = getchar(); 
    while(!isdigit(ch)) (ch == '-') && (f = -f), ch = getchar(); 
    while(isdigit(ch)) s = (s << 1) + (s << 3) + ch - 48, ch = getchar(); 
    return f * s; 
}

namespace Solver {
    int n, m, lg[M], a[M];
    int st[19][M];
    inline int query(int l, int r) {
        int t = lg[r - l + 1];
        return std :: max(st[t][l], st[t][r - (1 << t) + 1]); 
    }
    inline void Marionette_() {
        n = read(), m = read(), lg[0] = -1; 
        for(int i = 1; i <= n; ++i) a[i] = st[0][i] = read(), lg[i] = lg[i >> 1] + 1;
        for(int t = 1; (1 << t) <= n; ++t)
            for(int i = 1; i + (1 << t) - 1 <= n; ++i) st[t][i] = std :: max(st[t - 1][i], st[t - 1][i + (1 << t - 1)]);
        while(m --) {
            int l = read(), r = read(); 
            printf("%d\n", query(l, r)); 
        }
    }
    inline void mian() {
        int t = 1; 
        // t = read();
        while(t --) Marionette_(); 
    }
}

int main() {
    Solver :: mian(); 
    return 0; 
}