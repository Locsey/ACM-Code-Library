#include <bits/stdc++.h>

using std :: cin;
using std :: cout;

typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;

const int M = 3e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

inline int read() {
    int f = 1, s = 0; char ch = getchar(); 
    while(!isdigit(ch)) (ch == '-') && (f = -f), ch = getchar(); 
    while(isdigit(ch)) s = (s << 1) + (s << 3) + ch - 48, ch = getchar(); 
    return f * s; 
}

namespace Solver {
    int n;
    std :: string s;
    int nxt[M][4];
    ll pre[M]; 
    inline void Marionette_() {
        n = read(); cin >> s; s = " " + s;
        for(int i = 0; i < 4; ++i) nxt[n][i] = nxt[n + 1][i] = n + 1; 
        for(int i = n - 1; ~i; --i) {
            for(int j = 0; j < 4; ++j) nxt[i][j] = nxt[i + 1][j];
            if(s[i + 1] == '0') nxt[i][0] = i + 1; 
            if(s[i + 1] == '2') nxt[i][1] = i + 1;
            if(s[i + 1] == '5') nxt[i][2] = i + 1;
            if(s[i + 1] == '6') nxt[i][3] = i + 1; 
        }
        ll an = 0, as = 0; 
        for(int i = 1; i <= n; ++i) {
            int c1 = i - 1, c2 = i - 1; 
            c1 = nxt[c1][1], c1 = nxt[c1][0], c1 = nxt[c1][1], c1 = nxt[c1][2];
            c2 = nxt[c2][1], c2 = nxt[c2][0], c2 = nxt[c2][1], c2 = nxt[c2][3]; 
            if(c1 < c2) pre[c1 + 1] ++, pre[c2 + 1] --, an += c2 - c1;
            as += pre[i]; 
            an -= as; 
            cout << (ll)i * (n - i + 1) - an << ' '; 
        }
        cout << '\n'; 
        for(int i = 1; i <= n + 2; ++i) pre[i] = 0; 
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