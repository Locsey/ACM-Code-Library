#include <bits/stdc++.h>
using ll = long long;

const int M = 1e5 + 5; 
int a[M], n, k, q, b[M], m;
ll an, cnt; 

std :: priority_queue < st
inline void get(int K) {
    
}
inline ll get(int m) {
    int l = 0, r = 1e6, ans = 0; 
    while(l <= r) {

    }
}
int main() {
    scanf("%d%d%d", &n, &k, &q); 
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]); 
    while(q --) {
        int l, r; scanf("%d%d", &l, &r); m = 0; 
        if(l <= r) {
            for(int i = l; i <= r; ++i) b[++m] = a[i]; 
        }
        else {
            for(int i = r; i <= n; ++i) b[++m] = a[i]; 
            for(int i = 1; i <= l; ++i) b[++m] = a[i]; 
        }
    }
}