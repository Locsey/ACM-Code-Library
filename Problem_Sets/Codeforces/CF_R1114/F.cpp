#include<bits/stdc++.h>

using ll = long long; 
using ull = unsigned long long; 
using db = double; 

using std :: cin; 
using std :: cout; 

const int M = 2e5 + 5; 
const int INF = 0x3f3f3f3f; 
const int mod = 998244353; 

namespace Marionette_ {
    struct Basis {
        int v[30]; 
        Basis() {std :: memset(v, 0, sizeof(v));}
        inline void insert(int x) {
            for(int i = 29; i >= 0; --i) if((x >> i) & 1) {
                if(!v[i]) {v[i] = x; return ;}
                x ^= v[i]; 
            }
        } ;
        inline void build() {
            for(int i = 29; i >= 0; --i) if(v[i]) {
                for(int j = i - 1; j >= 0; --j) if(v[j] && ((v[i] >> j) & 1)) v[i] ^= v[j]; 
            }
        }
    } ; 
    int a[M], b[M]; 
    inline void mian() {
        int n; cin >> n; 
        Basis A, B; int u = 0; 
        for(int i = 1, x; i <= n; ++i) cin >> x, A.insert(x), a[i] = x; 
        for(int i = 1, x; i <= n; ++i) cin >> x, B.insert(x), b[i] = x; 
        // A.build(), B.build(); 
        // for(int i = 29; ~i; --i) if(A.v[i] != B.v[i]) return puts("NO"), void(); 
        for(int i = 29; ~i; --i) {
            int x = 0, y = 0; 
            for(int j = 1; j <= n; ++j) x += (a[j] >> i) & 1, y += (b[j] >> i) & 1;
            if(x == 0 || y == 0) {
                if(x + y == 0) continue ; 
                else return puts("NO"), void();
            }
            // if(x != y) x = n - x + 1; 
            if(x != y) return puts("NO"), void(); 
        }
        puts("YES"); 
        
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}