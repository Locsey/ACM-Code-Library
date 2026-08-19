#include<bits/stdc++.h>

using ll = long long; 
using ull = unsigned long long; 
using db = double; 

using std :: cin; 
using std :: cout; 

const int M = 1e5 + 5; 
const int INF = 0x3f3f3f3f; 
const int mod = 998244353; 

namespace Marionette_ {
    int a[3]; 
    inline void mian() {
        cin >> a[0] >> a[1] >> a[2];
        std :: sort(a, a + 3);
        if(a[0] + a[1] < a[2]) return cout << a[1] << '\n', void();
        cout << a[2] - a[0] << '\n'; 
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}