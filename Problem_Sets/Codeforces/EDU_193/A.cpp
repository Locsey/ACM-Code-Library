#include<bits/stdc++.h>

using ll = long long; 
using ull = unsigned long long; 
using db = double; 

using std :: cin; 
using std :: cout; 

const int M = 2e5 + 5; 
const int INF = 0x3f3f3f3f; 
const int mod = 998244353; 

namespace Marionette_ {
    int n; 
    inline void mian() {   
        cin >> n;
        int op = 1; 
        for(int i = 2; i <= n; ++i) if((n + 1) % i == 0) {op = 0; break;}
        if(op == 1) return puts("YES"), void(); 
        puts("NO"); 
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}   