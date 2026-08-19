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
    int n, a[M]; ll b[M]; 
    inline void mian() {
        cin >> n; ll S = 0; 
        for(int i = 1; i <= n; ++i) cin >> a[i], S += a[i]; 
        if(S <= 0) return puts("-1"), void(); 
        std :: sort(a + 1, a + n + 1); 
        std :: map < int, int > A, B;
        for(int i = 1; i <= n; ++i) {
            if(a[i] > 0) {
                for(int j = 1; j < i; ++j) A[a[j]] ++;
                for(int j = i + 1; j <= n; ++j) B[a[j]] ++; 
                ll nw = a[i]; cout << nw << ' '; int z = n - 1; 
                while(z --) {
                    auto it = A.upper_bound(-nw); 
                    if(it != A.end()) {
                        int w = it -> first; 
                        nw += w;
                        A[w] --;
                        if(A[w] == 0) A.erase(w); 
                    }
                    else {
                        it = B.begin(); 
                        int w = it -> first;
                        B[w] --, nw += w;
                        if(B[w] == 0) B.erase(w); 
                    }
                    cout << nw << ' '; 
                }
                return puts(""), void();  
            }
        }
    }
} ; 

int main() {
    int t = 1;
    cin >> t;
    while(t --) Marionette_ :: mian();
    return 0; 
}