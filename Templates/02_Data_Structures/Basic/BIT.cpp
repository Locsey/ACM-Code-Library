#include <bits/stdc++.h> 

using std :: cin;
using std :: cout;
using std :: vector;

typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;

struct BIT {
    int n; 
    std :: vector < ll > a;
    BIT(int n) : n(n), a(n + 1, 0) {}
    inline void add(int x, ll k) {while(x <= n) a[x] += k, x += x & -x;}
    inline ll Q(int x) {if(x <= 0) return 0; ll s = 0; while(x) s += a[x], x -= x & -x; return x;}
} ; 

int main() {

    return 0; 
}