#include <iostream>

using std :: cin;
using std :: cout;

typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;

const int M = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

inline int read() {
    int f = 1, s = 0; char ch = getchar(); 
    while(!isdigit(ch)) (ch == '-') && (f = -f), ch = getchar(); 
    while(isdigit(ch)) s = (s << 1) + (s << 3) + ch - 48, ch = getchar(); 
    return f * s; 
}

namespace Solver {
    int n, m, k; 
    int a[M]; 
    inline void Marionette_() {
        n = read(), m = read(), k = read(); 
        for(int i = 1; i <= n; ++i) a[i] = read();
        std :: sort(a + 1, a + n + 1); 
        int op = 0; 
        for(int i = k; i <= n; ++i) if(a[i] - a[i - k + 1] + 1 <= m) op = 1;
        puts(op ? "Yes" : "No"); 
    }
    inline void mian() {
        int t = 1; 
        t = read();
        while(t --) Marionette_(); 
    }
}

int main() {
    Solver :: mian(); 
    return 0; 
}