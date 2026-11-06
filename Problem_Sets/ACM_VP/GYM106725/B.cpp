#include <bits/stdc++.h>

using ll = long long; 

int a[6], c[6]; 
ll k, b[6];  
inline void ck() {
    ll sm = 6 - c[0]; ll lst = 0; 
    int w = 0; for(int i = 0; i < 6; ++i) w += c[i];
    if(w <= 18) return ; 
    for(int i = 0; i < 6; ++i) {
        sm += 1ll * (a[i] + 1 - lst) * c[i], lst = a[i] + 1; 
    }
    if(sm <= k) {
        puts("YES"); 
        for(int i = 0; i < 6 - c[0]; ++i) b[i] = 1; 
        int cur = 6 - c[0]; 
        for(int i = 0; i < 6; ++i) {
            for(int j = 6 - c[i]; j < 6; ++j) b[j] = a[i] + 1; 
        }
        b[5] += k - sm; 
        for(int i = 0; i < 6; ++i) std :: cout << b[i] << ' '; 
        exit(0); 
    }
}
inline void dfs(int x, int pre) {
    if(x == 6) return ck(), void(); 
    if(!x) {
        for(int i = 6; i > 3; --i) c[x] = i, dfs(x + 1, i); 
    }
    else {
        for(int i = pre; ~i; --i) c[x] = i, dfs(x + 1, i); 
    }
}
int main() {
    for(int i = 0; i < 6; ++i) std :: cin >> a[i]; 
    std :: cin >> k;
    std :: sort(a, a + 6); 
    dfs(0, 0); 
    puts("NO"); 
    return 0; 
}