#include<bits/stdc++.h>

using std :: string; 
using ll = long long; 
using ull = unsigned long long; 
using db = double; 

using std :: cin; 
using std :: cout; 

const int M = 1e5 + 5; 
const int INF = 0x3f3f3f3f; 
const int mod = 998244353; 

namespace Marionette_ {
    inline void mian() {
        string s; int n; cin >> n; 
        cin >> s; int an = 0; 
        for(int l = 0, r; l < n; l = r) {
            r = l; 
            while(r < n && s[l] == s[r]) ++r; 
            an ++; 
        }
        int mn = n; 
        for(int i = 1; i < n - 1; ++i) {
            int z = an;
            if((s[i] != s[i - 1]) && (s[i] != s[i + 1])) z --;
            if(s[i - 1] == s[i + 1] && s[i] != s[i - 1]) z --;
            mn = std :: min(mn, z); 
        }
        cout << mn << '\n'; 
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}