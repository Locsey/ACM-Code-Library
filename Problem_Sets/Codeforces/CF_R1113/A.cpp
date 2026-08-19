#include <bits/stdc++.h>

using std :: cin; 
using std :: cout; 

using ll = long long;
using ull = unsigned long long;
using db = double;

const int M = 1e5 + 5;
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
	inline void mian() {
		int t = 1;
		 t = read();
		while(t --) {
			std :: string s, t = ""; 
			cin >> s; int n = s.length(); s += '1'; 
			for(int i = 0; i < n; ++i) {
				if(s[i] == '0' && s[i + 1] == '1') {
					for(int j = 0; j < i; ++j) t += s[j]; 
					for(int j = i + 1; j < n; ++j) t += s[j];
					break;
				}
			}
			t += '0'; 
			for(int i = 0; i + 1 < n; ++i) {
				if(t[i] == '1' && t[i + 1] == '0') {
					for(int j = 0; j < i; ++j) cout << t[j] - '0'; 
					for(int j = i + 1; j < n - 1; ++j) cout << t[j] - '0';  
					break;
				}
			}
			puts(""); 
		}
	}
}

int main() {
	Solver :: mian();
}
