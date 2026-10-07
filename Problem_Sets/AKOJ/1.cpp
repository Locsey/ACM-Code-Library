#include <bits/stdc++.h>

using ll = long long; 
using ull = unsigned long long; 
using db = double; 

using std :: cin; 
using std :: cout; 

const int M = 2e5 + 5; 
const int INF = 0x3f3f3f3f; 
const int mod = 998244353; 

namespace Solver {
    int n, a[M], c[M], b[M], pq; 
    ll ans;
    inline void add(int x) {while(x <= pq) c[x] ++, x += x & -x;}
    inline int Q(int x) {int s = 0; while(x) s += c[x], x -= x & -x; return s;}
    inline void mian() {
        cin >> n; 
        for(int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i]; 
        std :: sort(b + 1, b + n + 1), pq = std :: unique(b + 1, b + n + 1) - b - 1;
        cout << pq << '\n'; 
        for(int i = n; i; --i) a[i] = std :: lower_bound(b + 1, b + n + 1, a[i]) - b, ans += Q(a[i] - 1), add(a[i]);
        cout << ans; 
    }
} ; 

int main() {
    Solver :: mian();
    return 0; 
}