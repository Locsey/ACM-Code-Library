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
    int dp[M][2][2]; 
    inline void chkmx(int &x, int y) { if(x < y) x = y; }
    inline void mian() {
        cin >> n >> s; s = ' ' + s; 
        int x = 0, y = 0;
        for(int i = 1; i <= n; ++i) x += s[i] == '0', y += s[i] == '1';
        int z = std :: abs(x - y);
        if(z > 2) return puts("-1"), void(); 
        for(int i = 1; i <= n; ++i) 
            for(int j = 0; j < 2; ++j)
                for(int k = 0; k < 2; ++k) dp[i][j][k] = -INF; 
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 2; ++j)
                for(int k = 0; k < 2; ++k) if(dp[i - 1][j][k] > 0) {
                    int v = dp[i - 1][j][k]; 
                    chkmx(dp[i][j][k], v);
                    if(k && s[i] == '0') chkmx(dp[i][j][0], v + 1);
                    if((!k) && s[i] == '1') chkmx(dp[i][j][1], v + 1);
                }
            int w = s[i] - '0';
            chkmx(dp[i][w][w], 1); 
        }
        int an = -INF; 
        if(x - y == 2) an = dp[n][0][0]; 
        else if(y - x == 2) an = dp[n][1][1];
        else if(x - y == 1) an = std :: max(dp[n][0][0], std :: max(dp[n][1][0], dp[n][0][1]));
        else if(y - x == 1) an = std :: max(dp[n][1][1], std :: max(dp[n][0][1], dp[n][1][0]));
        else {
            an = std :: max(dp[n][0][0], dp[n][1][1]);
            an = std :: max(an, dp[n][0][1]);
            an = std :: max(an, dp[n][1][0]);
        }
        if(an < 0) return puts("-1"), void(); 
        std :: cout << n - an << '\n';
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}