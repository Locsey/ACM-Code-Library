#include<bits/stdc++.h>

using ll = long long; 
using ull = unsigned long long; 
using db = double; 

using std :: cin; 
using std :: cout; 

const int M = 1e5 + 5; 
const int INF = 0x3f3f3f3f; 
const int mod = 998244353; 

namespace Marionette_ {
    int n; int a[M]; 
    inline void mian() {
        cin >> n; int S = 0; 
        for(int i = 1; i <= n; ++i) cin >> a[i], S += a[i]; 
        std :: sort(a + 1, a + n + 1);  int an = 0; 
        if(n <= 2) return cout << S << '\n', void(); 
        if(a[1] == a[n]) return cout << 2 * a[1] << '\n', void(); 
        int lim = n / 2 + 1; 
        for(int l = 1, r; l <= n; l = r) {
            r = l;
            while(r <= n && a[r] == a[l]) ++r;
            int z = r - l;
            if(z > lim) {
                for(int j = z - 1; j; --j) if(2 * j + z - j <= n) {
                    an += (j + 2) * a[l]; break ;
                    }
                continue ; 
            }
            else an += (r - l) * a[l];
        }
        cout << an << '\n'; 
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}