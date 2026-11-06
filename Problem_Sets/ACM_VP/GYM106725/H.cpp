#include <bits/stdc++.h>

const int M = 2005; 
using ull = unsigned long long; 

int n, p[M], q[M], u[M], a[M][M]; 
using std :: cin;
using std :: cout; 
std :: string str; 

std :: map < ull, int > mp; 
inline ull get(int *a, int op = 0) {
    ull s = 0;
    for(int i = 1; i <= n; ++i) s = s * 19260817 + (op ? (n - a[i] + 1) : a[i]); 
    return s; 
}
inline void out(int *a, int op = 0) {
    for(int i = 1; i <= n; ++i) printf("%d ", op ? (n - a[i] + 1) : a[i]); 
    cout << '\n'; 
}

inline bool ck() {
    for(int i = 1; i <= n; ++i) if(p[i] < n - p[i] + 1) return 1; else if(p[i] > n - p[i] + 1) return 0; 
    return 0; 
}
inline void A() {
    for(int i = 1; i <= n; ++i) cin >> p[i], q[i] = i; 
    if(n & 1) {
        out(p), mp[get(p)] = 1, mp[get(p, 1)] = 1; int rem = n - 1; 
        while(rem) {
            std :: random_shuffle(q + 1, q + n + 1); 
            if(n <= 1000) {
            ull w = get(q); 
            if(mp[w]) continue ;
            mp[w] = 1, w = get(q, 1), mp[w] = 1; 
            }
            out(q), out(q, 1); 
            rem -= 2; 
        }
    }
    else {
        out(p), out(p, 1), mp[get(p)] = 1, mp[get(p, 1)] = 1; 
        int z = ck(), rem = n; rem -= 2; 
        while(rem) {
            for(int i = 1; i < n; ++i) u[i] = i; 
            if(z) {
                q[1] = 1; 
                std :: random_shuffle(u + 1, u + n);
                for(int i = 2; i <= n; ++i) q[i] = u[i - 1] + 1; 
            }
            else {
                q[1] = n; 
                std :: random_shuffle(u + 1, u + n);
                for(int i = 2; i <= n; ++i) q[i] = u[i - 1];  
            }
            if(n <= 1000) {
            ull w = get(q); 
            if(mp[w]) continue ;
            mp[w] = 1; 
            }out(q); 
            rem --; 
        }
    }
    cout << '\n'; 
    
}

int S[M], id[M]; 
inline void B() {
    for(int i = 1; i <= n; ++i) {
        id[i] = i;
        for(int j = 1; j <= n; ++j) scanf("%d", &a[i][j]), S[j] += a[i][j]; 
    }
    if(n & 1) {
        std :: sort(id + 1, id + n + 1, [&] (int x, int y) {return S[x] < S[y];}); 
        for(int i = 1; i <= n; ++i) p[id[i]] = i;  
    }
    else {
        int u = 0, v = 0; 
        for(int i = 1; i <= n; ++i) {
            ull w = get(a[i]), w2 = get(a[i], 1); 
            if(mp[w2]) {u = mp[w2], v = i; for(int j = 1; j <= n; ++j) p[j] = a[i][j]; break;}
            mp[w] = i; 
        } int op = 0; 
        for(int i = 1; i <= n; ++i) if(i != u && i != v) {
            op = (a[i][1] == 1); 
            break;
        }
        int oop = ck();
        if(oop ^ op) {for(int j = 1; j <= n; ++j) p[j] = a[u][j];}
    }
    for(int i = 1; i <= n; ++i) cout << p[i] << ' '; 
}
int main() {
    srand(time(NULL)); 
    cin >> str >> n;
    if(str == "first") A();
    else B(); 
    return 0; 
}

// first 4
// 2 4 1 3

// second 4
// 2 4 1 3 
// 3 1 4 2 
// 1 2 3 4 
// 1 3 4 2