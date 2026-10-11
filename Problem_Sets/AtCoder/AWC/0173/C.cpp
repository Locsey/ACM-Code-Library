#include <bits/stdc++.h>

using std :: cin;
using std :: cout;

typedef long long ll; 
typedef unsigned long long ull;

int main() {
    int n, k, m, l;
    cin >> n >> k >> m >> l;
    for(int i = 0, x; i < m; ++i) cin >> x;
    cout << (ll)n * l; 
    return 0; 
}