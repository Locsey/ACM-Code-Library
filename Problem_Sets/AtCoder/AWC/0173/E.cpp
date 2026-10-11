#include <bits/stdc++.h>

using std :: cin;
using std :: cout;

typedef long long ll; 
typedef unsigned long long ull;

int n, K; 
__int128 dp[55][55][55]; int a[55]; 
inline void chkmx(__int128 &x, __int128 y) {if(x < y) x = y;}
inline void print(__int128 x) {
    if(!x) return ;
    print(x / 10), putchar(x % 10 + '0'); 
}

int main() {
    cin >> n >> K; 
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) dp[i][i][0] = a[i];
    for(int t = 2; t <= n; ++t)  
        for(int l = 1; l + t - 1 <= n; ++l) {
            int r = l + t - 1;
            for(int k = l; k < r; ++k) 
                for(int u = 0; u <= K; ++u)
                    for(int v = 0; u + v <= K; ++v) {
                        __int128 x = dp[l][k][u], y = dp[k + 1][r][v];
                        if(x <= 0 || y <= 0) continue ; 
                        chkmx(dp[l][r][u + v], x + y); 
                        chkmx(dp[l][r][u + v + 1], (x + y) * 2); 
                    }
        } 
    __int128 ans = 0;
    for(int i = 0; i <= K; ++i) chkmx(ans, dp[1][n][i]);
    print(ans); 
    return 0; 
}