#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;

#define M 5005
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

int read() {
    int f = 1, s = 0; char ch = getchar(); 
    while(!isdigit(ch)) {if(ch == '-') f = -f; ch = getchar();}
    while(isdigit(ch)) {s = (s << 1) + (s << 3) + ch - 48; ch = getchar();}
    return f * s; 
}

int n, cnt, nxt[M * 2], to[M * 2], sz[M * 2], head[M]; 
int add(int x, int y) {x += y; if(x >= mod) x -= mod; return x;}
int **dp[M]; 
int **get_new(int sz) {
    sz *= 3; 
    int **a = (int **)malloc((sz + 1) * sizeof(int *));
    for(int i = 0; i <= sz; ++i) {
        a[i] = (int *)calloc(4, sizeof(int)); 
    }
    return a; 
}

void Del(int **a, int sz) {
    sz *= 3; 
    for(int i = 0; i <= sz; ++i) free(a[i]); 
    free(a); 
}

void adde(int x, int y) {
    to[++cnt] = y; nxt[cnt] = head[x];  head[x] = cnt; 
}

void dfs(int x, int fa) {
    sz[x] = 1, dp[x] = get_new(1);
    dp[x][2 * sz[x] + 1][0] = dp[x][2 * sz[x]][1] = 1;
    for(int z = head[x]; z; z = nxt[z]) {
        int y = to[z]; if(y == fa) continue ; dfs(y, x);
        int **tmp = get_new(sz[x] + sz[y]); 
        for(int i = 0; i <= 3 * sz[x]; ++i) 
                for(int k = 0; k < 4; ++k) {
                    int v1 = dp[x][i][k]; if(!v1) continue ;
                    tmp[i][k] = add(tmp[i][k], v1);
                    for(int i1 = 0; i1 <= 3 * sz[y]; ++i1)
                            for(int k1 = 0; k1 < 4; ++k1) if(k1 != 1) {
                                int v2 = dp[y][i1][k1]; if(!v2) continue ;
                                v2 = (ll)v2 * v1 % mod; int k2, dt = 0; 
                                if(!k) k2 = 0;
                                if(k == 1) k2 = 2; 
                                if(k == 2) dt = -2, k2 = 3; 
                                if(k == 3) k2 = 3; 
                                int nz = i + i1 + dt; 
                                if(nz >= 0) tmp[nz][k2] = add(tmp[nz][k2], v2); 
                            }
                }
        Del(dp[x], sz[x]); dp[x] = tmp; 
        sz[x] += sz[y]; 
    } 
}
void Marionette_() {
    n = read();
    for(int i = 1; i < n; ++i) {
        int u = read(), v = read(); 
        adde(u, v), adde(v, u);
    }
    dfs(1, 0);
    int ans = 0;
    for(int i = 2 * n; i <= 3 * n; ++i) {
        ans = add(ans, dp[1][i][0]); 
        ans = add(ans, dp[1][i][1]); 
        ans = add(ans, dp[1][i][2]); 
        ans = add(ans, dp[1][i][3]); 
    }
    printf("%d", ans); 
}

int main() {
    int t = 1; 
    while(t --) Marionette_(); 
    return 0; 
}