#include <bits/stdc++.h>
#define int long long 

const int M = 1e5 + 5; 
int a[M], l[M]; 
bool dp[2][2]; 
int n; 

inline bool chk(int D) {
    memset(dp, 0, sizeof(dp)); 
    dp[0][0] = dp[0][1] = 1; 
    int p = 0, q = 1; 
    for(int i = 2; i <= n; ++i, std :: swap(p, q), memset(dp[q], 0, sizeof(dp[q]))) 
        for(int j = 0; j < 2; ++j) if(dp[p][j]) {
            int l1 = a[i] - D, l2 = a[i] + D; 
            int w = j ? (a[i - 1] - D) : (a[i - 1] + D);
            if(std :: abs(l1 - w) >= l[i]) dp[q][0] = 1; 
            if(std :: abs(l2 - w) >= l[i]) dp[q][1] = 1; 
        }
    return dp[p][0] | dp[p][1]; 
}

inline void solve() {
    std :: cin >> n; 
    for(int i = 1; i <= n; ++i) std :: cin >> a[i]; 
    for(int i = 2; i <= n; ++i) std :: cin >> l[i]; 
    int l = 0, r = 1e11, ans = r; 
    while(l <= r) {
        int mid = l + r >> 1; 
        chk(mid) ? (ans = mid, r = mid - 1) : (l = mid + 1); 
    }
    std :: cout << ans << '\n'; 
}

signed main() {
    int t; std :: cin >> t; 
    while(t --) solve(); 
}