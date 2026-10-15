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
    int n, a[M]; ll s[M]; int k;
    inline void Marionette_() {
        n = read(), k = read(); 
        std :: map < ll, int > mp; 
        for(int i = 1; i <= n; ++i) a[i] = read(), s[i] = s[i - 1] + a[i];
        ll ans = 0; 
        for(int i = n; i; --i) {
            if(i + k <= n) mp[s[i + k] % k] ++;
            ans += mp[s[i - 1] % k]; 
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