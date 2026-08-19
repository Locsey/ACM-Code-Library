#include <bits/stdc++.h>

using std :: cin; 
using std :: string; 
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

namespace Solver {
	int n, q; 
	std :: string s, t;  
	struct nd {
		int a, b, c, d; 
		nd(int A = 0, int B = 0, int C = 0, int D = 0) {a = A, b = B, c = C, d = D; }
		inline nd operator - (const nd &rhs) const {
			return nd(a - rhs.a, b - rhs.b, c - rhs.c, d - rhs.d); 
		}
	} a[M]; 
	inline void mian() {
		int T = 1;
		 T = read();
		while(T --) {
			n = read(), q = read(); 
			cin >> s >> t; s = ' ' + s, t = ' ' + t; 
			for(int i = 1; i <= n; ++i) {
				a[i] = a[i - 1]; 
				if(s[i] == '0' && t[i] == '0') a[i].a ++; 
				else if(s[i] == '0' && t[i] == '1') a[i].b ++; 
				else if(s[i] == '1' && t[i] == '0') a[i].c ++; 
				else a[i].d ++; 
			}
			while(q --) {
				int l = read(), r = read(); 
				nd w = a[r] - a[l - 1]; 
				int z = std :: abs(w.b - w.c);
				if(w.a + w.d >= z) puts("YES"); 
				else puts("NO"); 
			}
		}
	}
}

int main() {
	
	Solver :: mian();
}
