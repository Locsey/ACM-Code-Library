#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;

#define M 200005
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

int read() {
    int f = 1, s = 0; char ch = getchar(); 
    while(!isdigit(ch)) {if(ch == '-') f = -f; ch = getchar();}
    while(isdigit(ch)) {s = (s << 1) + (s << 3) + ch - 48; ch = getchar();}
    return f * s; 
}

int n, m, k; 
int a[M], b[M]; 
void MS(int l, int r) {
    if(l >= r) return ;
    int mid = l + r >> 1; 
    MS(l, mid), MS(mid + 1, r);
    int i = l, j = mid + 1, p = l; 
    while(i <= mid && j <= r) {
        if(a[i] <= a[j]) b[p ++] = a[i ++];
        else b[p ++] = a[j ++]; 
    }
    while(i <= mid) b[p ++] = a[i ++];
    while(j <= r) b[p ++] = a[j ++];
    for(int i = l; i <= r; ++i) a[i] = b[i]; 
}
void Marionette_() {
    n = read(), m = read(), k = read(); 
    for(int i = 1; i <= n; ++i) a[i] = read(); 
    MS(1, n); 
    int op = 0; 
    for(int i = k; i <= n; ++i) if(a[i] - a[i - k + 1] + 1 <= m) op = 1;
    puts(op ? "Yes" : "No"); 
}

int main() {
    int t = read();
    while(t --) Marionette_(); 
    return 0; 
}