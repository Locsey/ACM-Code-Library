#include <bits/stdc++.h>

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


int n, m, d;
int p[M], r[M]; 
int c[M], pq; 
ll sum[M]; 
namespace Solver {
	inline ll W(int t) {
		ll an = 0; if(t > n) t -= n, an += sum[m]; 
		int u = std :: upper_bound(p + 1, p + m + 1, t) - p - 1; 
		return an + sum[u];  
	}
	inline void mian() {
		int t = 1;
		t = read();
		while(t --) {
			n = read(), m = read(), d = read(); 
			for(int i = 1; i <= m; ++i) p[i] = read(), r[i] = read(), sum[i] = sum[i - 1] + r[i]; 
			int op = 0; 
			for(int i = 1; i <= m; ++i) {
				pq = 0; 
				ll delta = sum[i] - d;
				for(int j = 1; j <= m; ++j) {
					c[++pq] = p[j]; 
					int z = p[j] - p[i] - 1; 
					if(z >= 0) c[++pq] = z;
					c[++pq] = z + n; 
				}
				std :: sort(c + 1, c + pq + 1), pq = std :: unique(c + 1, c + pq + 1) - c - 1; 
				for(int j = 1; j <= pq; ++j) {
					int z = c[j];
					if(W(z + 1 + p[i]) - W(z) < delta) {op = 1; break;}
				}
				if(op) break;
			}
			puts(op ? "YES" : "NO"); 
		}
	}
}

int main() {
	
	Solver :: mian();
}
