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
    int n, a[M], b[M];
    int s[2][M]; 
    inline void chkmx(int &x, int y) {if(x < y) x = y;}
    inline void Marionette_() {
        n = read(); 
        for(int i = 1; i <= n; ++i) cin >> a[i]; 
        for(int i = 1; i <= n; ++i) cin >> b[i];
        s[0][n] = s[1][n] = 0; 
        for(int i = n - 1; i; --i) {
            s[0][i] = s[1][i + 1] + (a[i] == b[i + 1]);
            s[1][i] = s[0][i + 1] + (b[i] == a[i + 1]); 
        } int an = 0, cur = 0; 
        for(int i = 1; i <= n; ++i) {
            chkmx(an, cur + s[0][i] + s[1][i] + (a[n] == b[n])); 
            cur += a[i] == b[i]; 
            if(i == n) chkmx(an, cur);
            else cur += b[i] == a[i + 1];  
        }
        cout << 2 * n - 1 + an << '\n'; 
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