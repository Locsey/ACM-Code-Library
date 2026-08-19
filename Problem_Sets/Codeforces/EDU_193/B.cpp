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
    int n, a[M]; 
    inline void mian() {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i]; int an = 0; 
        for(int l = 1, r; l <= n; l = r) {
            r = l;
            while(a[r] == a[l] && r <= n) ++r;
            an ++;
        }
        int v = an; 
        for(int i = 1; i < n; ++i) if(a[i] ^ a[i + 1]) {
            int t = an; 
            if(i > 1) {
                if(a[i] == a[i - 1]) t ++; 
                else if(a[i - 1] == a[i + 1]) t --; 
            }
            if(i < n - 1) {
                if(a[i + 1] == a[i + 2]) t ++;
                else if(a[i + 2] == a[i]) t --;
            }
            v = std :: max(v, t); 
        }
        cout << v << '\n'; 
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}