#include <bits/stdc++.h>

using std :: cin;
using std :: cout;

typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;

const int M = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

inline int read() {
    int f = 1, s = 0; char ch = getchar(); 
    while(!isdigit(ch)) (ch == '-') && (f = -f), ch = getchar(); 
    while(isdigit(ch)) s = (s << 1) + (s << 3) + ch - 48, ch = getchar(); 
    return f * s; 
}

namespace Solver {
    std :: vector < std :: vector < int >  > a, s1, s2; 
    int n, m; 
    inline int add(int x, int y) {return (x += y) >= mod ? x - mod : x;}
    inline int dec(int x, int y) {return (x -= y) < 0 ? x += mod : x;}
    inline void Add(int &x, int y) {x = add(x, y); }
    inline void Dec(int &x, int y) {x = dec(x, y); }
    inline int C(int x, int y, int op) {
        if(op == 0) return (x & 1 ? mod - 1 : 0); 
        if(op == 1) return (y & 1 ? mod - 1 : 0); 
        if(op == 2) return (n - x + 1 & 1 ? mod - 1 : 0); 
        if(op == 3) return (m - y + 1 & 1 ? mod - 1 : 1); 
    }
    inline void Marionette_() {
        cin >> n >> m; 
        a.clear(), s1.clear(), s2.clear(); 
        a.resize(n + 2); 
        s1.resize(n + 2);
        s2.resize(n + 2); 
        int ans = 0; 
            a[0].resize(m + 1);
            s1[0].resize(m + 1);
            s2[0].resize(m + 1); 
            a[n + 1].resize(m + 1);
            s1[n + 1].resize(m + 1);
            s2[n + 1].resize(m + 1); 
        for(int i = 1; i <= n; ++i) {
            a[i].resize(m + 1);
            s1[i].resize(m + 1);
            s2[i].resize(m + 1); 
            for(int j = 1; j <= m; ++j) {
                a[i][j] = read(); 
                if((i & 1) && (j & 1) && (n - i + 1 & 1) && (m - j + 1 & 1)) Add(ans, (ll)a[i][j] * a[i][j] % mod); 
                int w1 = 0; if((i & 1) && (j & 1)) w1 = mod - a[i][j]; 
                s1[i][j] = s1[i][j - 1] + s1[i - 1][j] - s1[i - 1][j - 1]; 
                s1[i][j] = (s1[i][j] % mod + mod) % mod; 
                if((n - i + 1 & 1) && (m - j + 1 & 1)) Add(ans, (ll)s1[i][j] * a[i][j] % mod);
                s1[i][j] += w1; 
                s1[i][j] = (s1[i][j] % mod + mod) % mod; 
            }
        }
        for(int i = n; i; --i) 
            for(int j = 1; j <= m; ++j) {
                int w1 = 0; if((n - i + 1 & 1) && (j & 1)) w1 = mod - a[i][j]; 
                s2[i][j] = s2[i][j - 1] + s2[i + 1][j] - s2[i + 1][j - 1]; 
                s2[i][j] = (s1[i][j] % mod + mod) % mod; 
                if((i & 1) && (m - j + 1 & 1)) Add(ans, (ll)s2[i][j] * a[i][j] % mod);
                s2[i][j] += w1; 
                s2[i][j] = (s2[i][j] % mod + mod) % mod; 
            }
        cout << ans << '\n'; 
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