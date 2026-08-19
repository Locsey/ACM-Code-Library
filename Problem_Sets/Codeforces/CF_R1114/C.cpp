#include<bits/stdc++.h>

using std :: string; 
using ll = long long; 
using ull = unsigned long long; 
using db = double; 

using std :: cin; 
using std :: cout; 

const int M = 2e5 + 5; 
const int INF = 0x3f3f3f3f; 
const int mod = 998244353; 

namespace Marionette_ {
    int n; 
    int p[M], q[M];
    inline ll get(int *a, int *b, int n) {
        ll an = 0;
        for(int i = 1; i <= n; ++i) an += std :: abs(a[i] - b[i]);
        return an; 
    }
    inline void mian() {
        string a, b;
        cin >> n; 
        cin >> a >> b; int S = 0;
        a = ' ' + a, b = ' ' + b; 
        for(int i = 1; i <= n; ++i) S += a[i] == '1';
        for(int i = 1; i <= n; ++i) S -= b[i] == '1';
        if(S) return puts("-1"), void(); 
        int x = 0, y = 0;
        for(int i = 1; i <= n; ++i) {
            x += (a[i] - '0' - i) & 1, y += (b[i] - '0' - i) & 1;
        }
        if(x != y) return puts("-1"), void(); 
        ll an = 0; x = y = 0; 
        for(int i = 1; i <= n; i += 2) {
            if(a[i] == '1') p[++x] = i / 2; 
            if(b[i] == '1') q[++y] = i / 2; 
         }
         an += get(p, q, x); x = y = 0;
         for(int i = 2; i <= n; i += 2) {
            if(a[i] == '1') p[++x] = i / 2; 
            if(b[i] == '1') q[++y] = i / 2; 
         }
         an += get(p, q, x); 
         cout << an << '\n'; 
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}