#include <bits/stdc++.h>

using ll = long long; 
const int M = 1e6 + 5; 

int n, m, k, a[M];
int f[20][M]; 
inline bool chk(ll lim) {
    int cur = 2 * n; ll sum = 0; f[0][2 * n + 1] = 2 * n + 1; 
    for(int i = 2 * n; i; --i) {
        sum += a[i]; 
        while(cur > i && (sum > lim)) sum -= a[cur --]; 
        f[0][i] = cur + 1; 
    }
    for(int t = 1; t < 20; ++t) 
        for(int i = 1; i <= 2 * n + 1; ++i) f[t][i] = f[t - 1][f[t - 1][i]]; 
    for(int i = 1; i <= n; ++i) {
        int z = i, res = k;
        for(int j = 19; ~j; --j) if((k >> j) & 1) z = f[j][z];
        if(z - i >= n) return 1; 
    }
    return 0; 
}
int main() {
    scanf("%d%d%d", &n, &m, &k); ll S = 0, mx = 0; 
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), S += a[i], mx = std :: max(mx, (ll)a[i]); 
    for(int i = n + 1; i <= 2 * n; ++i) a[i] = a[i - n]; 
    ll l = mx, r = S, ans = r; 
    while(l <= r) {
        ll mid = l + r >> 1; 
        chk(mid) ? (ans = mid, r = mid - 1) : (l = mid + 1); 
    } 
    std :: cout << S + (m - 1) * ans; 
}