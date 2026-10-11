#include <bits/stdc++.h>

using std :: cin;
using std :: cout;

typedef long long ll; 
typedef unsigned long long ull;

int main() {
    ll n, s; 
    cin >> n >> s;
    while(n --) {
        int x; cin >> x;
        s -= x; 
    }
    puts(s >= 0 ? "Yes" : "No"); 
    return 0; 
}