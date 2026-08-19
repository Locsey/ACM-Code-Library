#include <bits/stdc++.h>
using std :: cin; 
using std :: cout; 
using ll = long long;
using ull = unsigned long long;
using db = double;

const int M = 2e5 + 5;
const int mod = 998244353;
const int INF = 1e9 + 7;

inline int read() {
	int f = 1, s = 0; char ch = getchar();
	while(!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar();
	while(isdigit(ch)) s = s * 10 + (ch - 48) , ch = getchar();
	return f * s;
}

inline void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int a[M], b[M], vis[M], bm[M]; 
namespace Solver {
	inline void mian() {
		int t = 1;
		 t = read();
		while(t --) {
			int n, m; 
			cin >> n >> m; 
			for(int i = 1; i <= n; ++i) cin >> a[i], vis[i] = bm[i] = 0; 
			for(int i = 1; i <= m; ++i) cin >> b[i];  
			std :: sort(a + 1, a + n + 1), std :: sort(b + 1, b + m + 1); 
			int l = 1, op = 1; 
			for(int i = 1; i <= m; ++i) {
				int v = b[i]; 
				if(l <= n && a[l] <= v) vis[l] = 1, ++l; 
				else {op = 0; break;}
				int z = std :: lower_bound(a + 1, a + n + 1, b[i]) - a; 
				bm[z] ++; 
			}
			int z = 0, u = 0; 
			for(int i = 1; i <= n; ++i) {
				u += bm[i]; 
				if(vis[i]) ++z; 
				else {
					if(z && u) --z, --u; 
				}
			}
			if(z) op = 0; 
			puts(op ? "YES" : "NO"); 
		}
	}
}

int main() {
	Solver :: mian();
}
