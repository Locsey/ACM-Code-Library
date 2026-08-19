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
    int n;
    std :: string s;
    int dp[2][3][2]; 
    inline void Add(int &x, const int y) {x += y; if(x >= mod) x -= mod;}
    inline void mian() {
        cin >> n >> s; s = ' ' + s;
        int p = 0, q = 1; memset(dp, 0, sizeof(dp)); 
        for(int i = 0; i < 2; ++i) if(s[1] - '0' != 1 - i)
            for(int j = 0; j < 2; ++j) if(s[2] - '0' != 1 - j) dp[p][i + j][j] ++; 
        for(int i = 3; i <= n; ++i) {
            char ch = s[i];
            for(int j = 0; j < 3; ++j) 
                for(int k = 0, v; k < 2; ++k) if(v = dp[p][j][k]) {
                    for(int u = 0; u < 2; ++u) if(ch - '0' !=  1 - u) {
                        int cur = k + u;
                        if(cur ^ j) Add(dp[q][cur][u], v); 
                    }
                }
            std :: swap(p, q), memset(dp[q], 0, sizeof(dp[q])); 
        }
        int ans = 0;
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 2; ++j) Add(ans, dp[p][i][j]);
        cout << ans << '\n'; 
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}