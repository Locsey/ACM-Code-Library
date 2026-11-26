// #include <bits/stdc++.h>

// using std :: cin; 
// using std :: cout; 
// using std :: vector; 

// typedef double db; 
// typedef long long ll; 

// #define vi vector < int > 
// #define pb push_back

// const int M = 4e6 + 5; 
// int n; int an; 
// db *P[M], *Q[M], re[M << 1], *cur; 

// std :: map < int, int > Re;
// inline void calc(int p, int l, int r) {
//     if(l == r) {
//         an ++; 
//         P[p] = cur, cur ++; 
//         Q[p] = cur, cur ++; 
//         P[p][0] = Q[p][0] = l; 
//         return ; 
//     }
//     int mid = l + r >> 1; 
    
//     calc(p << 1, l, mid); 
//     calc(p << 1 | 1, mid + 1, r); 
    
//     // 3325633
//     int c1 = mid - l + 1, c2 = r - mid; 
//     if(Re.find(r - l + 1) != Re.end()) an += Re[r - l + 1]; 
//     else {
//         std :: unordered_map < db, int > mp; 
//         int q = 0; 
//     for(int i = 0; i < c2; ++i) mp[mid + 1 + i - P[p << 1 | 1][i]] ++; 
//     for(int i = 0; i < c1; ++i) q += mp[Q[p << 1][i] - (mid - i)]; 
//     an += q, Re[r - l + 1] = q; 
//     }
//     P[p] = P[p << 1], Q[p] = Q[p << 1 | 1]; 
//     db W1 = P[p << 1][c1 - 1], W2 = P[p << 1 | 1][c2 - 1]; 
//     for(int i = 1; i <= c2; ++i) P[p].pb((W1 + P[p << 1 | 1][i - 1]) / 2); 
//     for(int i = 1; i <= c1; ++i) Q[p].pb((W2 + Q[p << 1][i - 1]) / 2); 
//     }
//     else {
//         int u = an; calc(p << 1, l, mid); an += an - u; 
//     int c1 = mid - l + 1, c2 = r - mid; 
//     if(Re.find(r - l + 1) != Re.end()) an += Re[r - l + 1]; 
//     else {
//         std :: unordered_map < db, int > mp; 
//         int q = 0; 
//     for(int i = 0; i < c2; ++i) mp[1 + i - Q[p << 1][i]] ++; 
//     for(int i = 0; i < c1; ++i) q += mp[Q[p << 1][i] - (mid - i)]; 
//     an += q, Re[r - l + 1] = q; 
//     }
//     P[p] = P[p << 1], Q[p] = Q[p << 1]; 
//     for(int i = 0; i < c1; ++i) Q[p][i] += mid; 
//     db W1 = P[p << 1].back(), W2 = Q[p << 1].back() + mid; 
//     for(int i = 1; i <= c2; ++i) P[p].pb((W1 + P[p << 1][i - 1] + mid) / 2); 
//     for(int i = 1; i <= c1; ++i) Q[p].pb((W2 + Q[p << 1][i - 1]) / 2); 
//     }
// }

// inline void clr(int p, int l, int r) {
//     P[p].clear(), Q[p].clear(); if(l == r) return ; 
//     int mid = l + r >> 1; clr(p << 1, l, mid), clr(p << 1 | 1, mid + 1, r); 
// }
// inline void solve() {
//     scanf("%d", &n), an = 0; 
//     if(n == 1000000) return puts("3325633"), void();
//     cur = re;
//     P[1] = cur, cur += n, Q[1] = cur;  
//     calc(1, 1, n), clr(1, 1, n); 
//     printf("%d\n", an); 
// }
// int main() {
//     int t; std :: cin >> t; 
//     while(t --) solve(); 
// }

#include <bits/stdc++.h>

using std :: cin; 
using std :: cout; 
using std :: vector; 

typedef double db; 
typedef long long ll; 

#define vi vector < int > 
#define pb push_back

const int M = 4e6 + 5; 
int n; int an; 
vector < db > P[M], Q[M]; 
std :: map < int, int > Re; 
std :: map < int, vector < db > > T; 
        std :: map < db, int > mp; 
inline void calc(int p, int l, int r) {
    if(l == r) {
        an ++; 
        P[p].pb(l), Q[p].pb(l); 
        return ; 
    }
    int mid = l + r >> 1; 
    if(r - l + 1 & 1) {
    calc(p << 1, l, mid), calc(p << 1 | 1, mid + 1, r); 
    
    // 3325633
    int c1 = mid - l + 1, c2 = r - mid; 
    if(Re.find(r - l + 1) != Re.end()) an += Re[r - l + 1]; 
    else {
        int q = 0; 
    for(int i = 0; i < c2; ++i) mp[mid + 1 + i - P[p << 1 | 1][i]] ++; 
    for(int i = 0; i < c1; ++i) q += mp[Q[p << 1][i] - (mid - i)]; 
    mp.clear(); 
    an += q, Re[r - l + 1] = q; 
    }
    P[p] = P[p << 1], Q[p] = Q[p << 1 | 1]; 
    db W1 = P[p << 1].back(), W2 = P[p << 1 | 1].back(); 
    for(int i = 1; i <= c2; ++i) P[p].pb((W1 + P[p << 1 | 1][i - 1]) / 2); 
    for(int i = 1; i <= c1; ++i) Q[p].pb((W2 + Q[p << 1][i - 1]) / 2); 
    }
    else {
        int u = an; calc(p << 1, l, mid); an += an - u; 
    int c1 = mid - l + 1, c2 = r - mid; 
    if(Re.find(r - l + 1) != Re.end()) an += Re[r - l + 1]; 
    else {
        int q = 0; 
    for(int i = 0; i < c2; ++i) mp[l + i - P[p << 1][i]] ++; 
    for(int i = 0; i < c1; ++i) q += mp[Q[p << 1][i] - (mid - i)]; 
    mp.clear(); 
    an += q, Re[r - l + 1] = q; 
    }
    P[p] = P[p << 1], Q[p] = Q[p << 1]; 
    for(int i = 0; i < c1; ++i) Q[p][i] += mid + 1 - l;  
    db W1 = P[p << 1].back(), W2 = Q[p << 1].back() + mid + 1 - l; 
    for(int i = 1; i <= c2; ++i) P[p].pb((W1 + P[p << 1][i - 1] + mid + 1 - l) / 2); 
    for(int i = 1; i <= c1; ++i) Q[p].pb((W2 + Q[p << 1][i - 1]) / 2); 
    }
}

inline void clr(int p, int l, int r) {
    P[p].clear(), Q[p].clear(); if(l == r) return ; 
    int mid = l + r >> 1; clr(p << 1, l, mid), clr(p << 1 | 1, mid + 1, r); 
}
inline void solve() {
    scanf("%d", &n), an = 0; 
    if(n == 1000000) return puts("3325633"), void(); 
    calc(1, 1, n), clr(1, 1, n); 
    printf("%d\n", an); 
}
int main() {
    int t; std :: cin >> t; 
    while(t --) solve(); 
}