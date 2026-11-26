#include <bits/stdc++.h>

typedef long long ll; 

const int mod = 998244353; 
const int M = 105; 
int dp[2][105], f[101][101][5005]; 

inline int add(int x, int y) {return (x += y) >= mod ? x - mod : x;}
inline void Add(int &x, int y) {x = add(x, y);}
int A[M], B[M]; 
inline void init() {
    f[0][0][0] = 1; int W = 0; 
    for(int i = 0; i < 99; ++i, W += i) 
        for(int j = 0; j <= i; ++j)
            for(int k = 0, v; k <= W; ++k) if(v = f[i][j][k]) {
                Add(f[i + 1][j][k], v); 
                Add(f[i + 1][j + 1][k + i + 1], v); 
            }
}

inline void solve() {
    int n, m; scanf("%d%d", &n, &m); 
    for(int i = 1; i <= m; ++i) scanf("%d%d", &A[i], &B[i]); 
    A[0] = 1; 
    int p = 0, q = 1; std :: memset(dp, 0, sizeof(dp)); 
    dp[0][0] = 1; 
    for(int i = 1; i <= m; ++i, std :: swap(p, q), memset(dp[q], 0, sizeof(dp[q]))) {
        int z = A[i] - A[i - 1], dlt = B[i] - B[i - 1]; 
        for(int j = 0, v; j < A[i - 1]; ++j) if(v = dp[p][j]) {
            for(int k = j; k < A[i]; ++k) {
                int d = dlt - j * z; 
                if(d >= 0 && d <= 5000) Add(dp[q][k], (ll)f[z][k - j][d] * v % mod); 
            }
        }
    }
    int S = 0; for(int i = 0; i <= n; ++i) Add(S, dp[p][i]); 
    for(int i = A[m] + 1; i <= n; ++i) Add(S, S); 
    printf("%d\n", S); 
}

int main() {
    int t; std :: cin >> t;
    init(); 
    while(t --) solve(); 
}