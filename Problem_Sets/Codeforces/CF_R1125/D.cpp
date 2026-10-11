#include <bits/stdc++.h>
#define int long long 

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
    int n, k; 
    int a[M][3], s[M], op[M], cst[M]; 
    inline void chkmn(int &x, int y) {if(x > y) x = y;}
    inline bool chk(int lim) {
        int ret = k; 
        for(int i = 1; i <= n && ret >= 0; ++i) if(s[i] < lim) {
            if(op[i] == 2) return 0; int dlt = lim - s[i];  
            if(op[i] == 1) {ret -= dlt; continue ; }
            if(op[i] == 0) {
                if(cst[i] == 1e18) return 0; 
                ret -= dlt, ret -= 2 * cst[i]; 
            }
        }
        return ret >= 0; 
    }
    inline void Marionette_() {
        n = read(), k = read(); int z = 1e18; 
        for(int i = 1; i <= n; ++i) {
            cin >> a[i][0] >> a[i][1] >> a[i][2], z = std :: min(z, s[i] = a[i][0] + a[i][1] + a[i][2]); 
            if(a[i][0] == a[i][1] && a[i][1] == a[i][2]) op[i] = 2; 
            else {
                if((a[i][0] > a[i][1]) || (a[i][0] > a[i][2]) || (a[i][1] > a[i][2])) op[i] = 1; 
                else {
                    op[i] = 0, cst[i] = 1e18;
                    for(int u = 0; u < 3; ++u) 
                        for(int v = u + 1; v < 3; ++v) if(a[i][u] < a[i][v]) {
                            int w = 3 - u - v; 
                            if(u < w && a[i][u] <= a[i][w]) chkmn(cst[i], a[i][w] - a[i][u] + 1);
                            if(v < w && a[i][v] <= a[i][w]) chkmn(cst[i], a[i][w] - a[i][v] + 1); 
                        }
                }
            }
        }
        int l = z, r = 3e9, ans = l; r += k; 
        while(l <= r) {
            int mid = l + r >> 1;
            chk(mid) ? (ans = mid, l = mid + 1) : (r = mid - 1); 
        }
        cout << ans << '\n'; 
    }
    inline void mian() {
        int t = 1; 
        t = read();
        while(t --) Marionette_(); 
    }
}

signed main() {
    Solver :: mian(); 
    return 0; 
}