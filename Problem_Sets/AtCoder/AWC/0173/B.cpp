#include <bits/stdc++.h>

using std :: cin;
using std :: cout;

typedef long long ll; 
typedef unsigned long long ull;

char s[15][15]; 
int main() {
    int n, m; cin >> n >> m; 
    int ans = 0; 
    for(int i = 0; i < n; ++i) cin >> s[i];
    for(int i = 0; i < m; ++i) {
        int op = 1; 
        for(int j = 0; j < n; ++j) if(s[j][i] == '#') op = 0;

        ans += op; 
    }
    cout << ans; 
    return 0; 
}