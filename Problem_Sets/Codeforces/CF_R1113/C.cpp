#include <bits/stdc++.h>

using std :: cin; 
using std :: cout; 

using ll = long long;
using ull = unsigned long long;
using db = double;

const int M = 4e5 + 5;
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

int a[M], n, nx[M], to[M]; 
ll dp[M]; 
namespace Solver {
	inline void mian() {
		int t = 1;
		 t = read();
		while(t --) {
			n = read(); 
			for(int i = 1; i <= n; ++i) nx[i] = 0; 
			for(int i = 1; i <= 2 * n; ++i) a[i] = read(), to[i] = nx[a[i]], nx[a[i]] = i; 
			dp[0] = 0; 
			for(int i = 1; i <= 2 * n; ++i) {
				dp[i] = dp[i - 1] + 1; int z; 
				if(z = to[i]) dp[i] = std :: max(dp[i], dp[z - 1] + 1ll * (i - z + 1) * (i - z + 1));  
			}
			cout << dp[2 * n] << '\n'; 
		}
	}
}

int main() {
	
	Solver :: mian();
}
