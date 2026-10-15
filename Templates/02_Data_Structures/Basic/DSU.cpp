#include <bits/stdc++.h> 

using std :: cin;
using std :: cout;
using std :: vector;

typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;

struct DSU {
    std :: vector < int > fa, sz;
    inline void init(int n) {
        fa.resize(n + 1);
        sz.assign(n + 1, 1); 
        std :: iota(fa.begin(), fa.end(), 0); 
    }
    inline int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]); 
    }
    inline bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return 0;
        if(sz[x] > sz[y]) std :: swap(x, y);
        fa[x] = y, sz[y] += sz[x]; 
        return 1; 
    }
    inline bool same(int x, int y) {
        return find(x) == find(y); 
    }
} ; 

int main() { 
    DSU a; int n; cin >> n;
    a.init(n);
    a.merge(1, 2);
    cout << a.same(1, 2); 
    return 0; 
}