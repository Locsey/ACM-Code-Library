#include <bits/stdc++.h>

using std :: vector;
#define vi vector < int > 
#define pii std :: pair < int, int > 
#define vp vector < pii > 

const int M = 4e5 + 5; 
int a[M]; 

int n, m, sgn; 
vi adj[M]; 
char str[114]; 
inline void dfs(int x, int fa) {
    a[x] = ++sgn; 
    for(int &y : adj[x]) if(y ^ fa) {
        dfs(y, x); 
    }
    ++sgn; 
}

inline void Cat() {
    std :: cin >> n >> m; 
    for(int i = 1, x, y; i <= m; ++i) {
        std :: cin >> x >> y; 
        adj[x].push_back(y); 
        adj[y].push_back(x); 
    }
    sgn = 0; for(int i = 1; i <= n; ++i) if(!a[i]) dfs(i, 0);

    for(int i = 1; i <= n; ++i) std :: cout << a[i] << ' ', adj[i].clear(), a[i] = 0; 
    puts(""); 
}

vp an; 
int prt[M], to[M]; 
inline void dfs2(int x, int sgn) {
    if(sgn == 2 * n - 1) return ; 
    if(to[sgn + 1]) {
        if(x) an.push_back(pii(x, to[sgn + 1])); prt[to[sgn + 1]] = x; 
        dfs2(to[sgn + 1], sgn + 1); 
    }
    else dfs2(prt[x], sgn + 1); 
}

inline void Dog() {
    std :: cin >> n; 
    for(int i = 1, x; i <= n; ++i) {
        std :: cin >> x;
        to[x] = i; 
    }
    dfs2(0, 0); 
    std :: cout << an.size() << '\n'; 
    for(auto &it : an) std :: cout << it.first << ' ' << it.second << '\n'; 
    for(int i = 1; i <= 2 * n; ++i) to[i] = 0; an.clear(); 
}

int main() { int t; 
    scanf("%s", str + 1); std :: cin >> t; 
    if(str[1] == 'c') while(t --) Cat(); 
    else while(t --) Dog(); 
}