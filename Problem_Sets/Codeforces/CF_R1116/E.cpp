#include<bits/stdc++.h>

using ll = long long; 
using ull = unsigned long long; 
using db = double; 

using std :: cin; 
using std :: cout; 

const int M = 1e6 + 5; 
const int INF = 0x3f3f3f3f; 
const int mod = 998244353; 

namespace Marionette_ {
    int n, k, x, y;
    inline void get(int u) {
        if(u & 1) y ++; else x ++; 
    }
    char s[M]; 
    inline void mian() {
        cin >> n >> k; 
        scanf("%s", s + 1); 
        int S = 0;
        int cur = 0; 
        for(int i = 2 * n + 1; i <= 4 * n; ++i) s[i] = s[i - 2 * n], S += s[i] == '1';
        if(S == 2 * n) return cout << n << ' ' << n << '\n', void(); 
        for(int i = 2 * n + 1; i <= 4 * n; ++i) if(s[i - 1] == '0' && s[i] == '1') {cur = i; break;}
        if(!cur) return cout << 0 << ' ' << 0 << '\n', void();
        x = 0, y = 0, cur -= 2 * n; 
        for(int l = cur, r; l < cur + 2 * n; l = r) {
            r = l; if(s[l] == '0') {r ++; continue ; }
            while(r < cur + 2 * n && s[r] == s[l]) ++r;
            for(int i = l; i < r - 1; ++i) get(i); 
            get(r); 
        }
        cout << x << ' ' << y << '\n'; 
        
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}