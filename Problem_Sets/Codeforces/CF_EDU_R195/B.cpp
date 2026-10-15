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
    int n;
    std :: string s; 
    inline void Marionette_() {
        cin >> s, n = s.length(), s = " " + s;
        int op1 = 0, op3 = 0; 
        for(int i = 2; i < n; ++i) {
            if(s[i - 1] == s[i] && s[i] == s[i + 1]) op1 = 1; 
            if(s[i - 1] != s[i] && s[i] != s[i + 1]) op3 = 1; 
        }
        cout << op1 + op3 + 1 << '\n'; 
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