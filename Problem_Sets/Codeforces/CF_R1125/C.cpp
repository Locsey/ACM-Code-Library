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
    int n, a[M]; 
    inline void Marionette_() {
        n = read(); 
        std :: map < int, int > mp; 
        for(int i = 1; i <= n; ++i) a[i] = read(); 
        ll ans = 0; 
        for(int i = n; i; --i) {
            if(i + 9 <= n) mp[a[i + 5] + a[i + 7] - a[i + 9]] ++;
            if(i + 4 <= n) ans += mp[a[i] + a[i + 2] - a[i + 4]];
            for(int j = i + 1; j + 4 <= n && j - i <= 4; j += 2) if(a[i] + a[i + 2] - a[i + 4] == a[j] + a[j + 2] - a[j + 4]) ans ++; 
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