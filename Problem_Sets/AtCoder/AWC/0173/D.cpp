#include <bits/stdc++.h>

using std :: cin;
using std :: cout;

typedef long long ll; 
typedef unsigned long long ull;

const int M = 1e6 + 5;
int n, m; ll a[M]; ll s[M]; 
int main() {
    cin >> m >> n; 
    for(int i = 0; i < n; ++i) cin >> a[i]; 
    while(m --) {
        int l, r, x; cin >> l >> r >> x;
        l --, r --; 
        s[l] += x, s[r + 1] -= x; 
    } int ans = 0; 
    for(int i = 0; i < n; ++i) {
        if(i) s[i] += s[i - 1];
        if(s[i] >= a[i]) ans ++; 
    }
    cout << ans; 
    return 0; 
}