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
    int n, stk[M], tp; 
    int vis[M]; 
    inline void Marionette_() {
        n = read(); 
        std :: string s; cin >> s; tp = 0; 
        for(int i = 1; i <= n; ++i) {
            char ch = s[i - 1]; 
            if(ch == '1') stk[++tp] = i; 
            if(ch == '2') {
                if(!tp) vis[i] = 1; 
                else vis[stk[tp--]] = 1; 
            }
            if(ch == '3') vis[i] = 1; 
        } std :: vector < int > ans; 
        for(int i = 1; i <= n; ++i) if(!vis[i]) ans.push_back(i); 
        cout << ans.size() << '\n'; 
        for(int &x : ans) cout << x << ' ';  cout << '\n'; 
        for(int i = 1; i <= n; ++i) vis[i] = 0;
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