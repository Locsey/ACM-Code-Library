#include<bits/stdc++.h>

using ll = long long; 
using ull = unsigned long long; 
using db = double; 

using std :: cin; 
using std :: cout; 

const int M = 1e5 + 5; 
const int mod = 998244353; 
const int INF = 0x3f3f3f3f; 

int mod; 
namespace Combinatorics_ {
    int fac[M], ifac[M];
    inline int qpow(int a, int b, int p) {
        int s = 1, bas = a; 
        while(b) {
            if(b & 1) s = 1ll * s * bas % p;
            bas = 1ll * bas * bas % p;
            b >>= 1;
        }
        return s;
    }
    inline void Init_(int n) {
        fac[0] = 1; 
        for(int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
        ifac[n] = qpow(fac[n], mod - 2, mod);
        for(int i = n - 1; i >= 0; --i) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    }
    inline int binom(int n, int m) {
        if(n < m || m < 0) return 0; 
        return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
    }
    inline int Inv(int a) {
        return qpow(a, mod - 2, mod);
    }
    int inv[M]; 
    inline void Init_inv(int n) {
        inv[1] = 1; 
        for(int i = 2; i < n; ++i) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    }
    inline int lucas(int n, int m) {
        if(m == 0) return 1; 
        return 1ll * lucas(n / mod, m / mod) * binom(n % mod, m % mod) % mod;
    }
    inline int Catalan(int n) {
        // ensure 2 * n < N
        return 1ll * fac[2 * n] * ifac[n] % mod * ifac[n + 1] % mod;
    }
    
    inline void mian() {
        
    }
} ; 

namespace Linear_Algebra_ {
    // 返回值：-1 表示无解，0 表示唯一解，>0 表示多解（返回自由元的个数）
    inline int gauss(std::vector<std::vector<int>> a, std::vector<int> &ans, std::vector<std::vector<int>> &basis) {
        if(a.empty()) return 0; 
        int n = a.size(), m = a[0].size() - 1, r = 0; 
        std::vector<int> pt(m, -1); // pt[i] 记录第 i 列的主元在第几行，-1 表示该列无主元
        ans.assign(m, 0); 
        basis.clear();

        // 1. 高斯消元化为阶梯型
        for(int i = 0; i < m && r < n; ++i) {
            int p = -1;
            for(int j = r; j < n; ++j) {
                if(a[j][i] != 0) {
                    p = j;
                    break;
                }
            }
            if(p == -1) continue; // 当前列全为0，跳过

            if(p != r) {
                for(int j = 0; j <= m; ++j) std::swap(a[p][j], a[r][j]); 
            }
            
            int I = Combinatorics_::Inv(a[r][i]); 
            pt[i] = r; // 记录主元位置
            
            // 消去当前列的其他非零元
            for(int j = 0; j < n; ++j) {
                if(j != r && a[j][i] != 0) {
                    int t = 1ll * a[j][i] * I % mod;
                    for(int k = i; k <= m; ++k) {
                        a[j][k] -= 1ll * t * a[r][k] % mod;
                        if(a[j][k] < 0) a[j][k] += mod;
                    }
                }
            }
            ++r; 
        }
        
        // 2. 检查无解情况 (出现 0 = 非0)
        for(int i = r; i < n; ++i) {
            if(a[i][m] != 0) return -1; 
        }
        
        // 3. 求特解 (自由元设为0)
        for(int i = 0; i < m; ++i) {
            if(pt[i] == -1) {
                ans[i] = 0; // 自由元赋值为0
            } else {
                ans[i] = 1ll * a[pt[i]][m] * Combinatorics_::Inv(a[pt[i]][i]) % mod;
            }
        }
        
        // 4. 求基础解系
        for(int i = 0; i < m; ++i) {
            if(pt[i] == -1) { // 如果第 i 列是自由元
                std::vector<int> vec(m, 0);
                vec[i] = 1; // 令当前自由元为 1，其余自由元为 0
                
                // 回代求出主元变量的值
                for(int j = 0; j < m; ++j) {
                    if(pt[j] != -1) { // 如果第 j 列是主元
                        int row = pt[j];
                        int sum = 0;
                        // 计算当前主元方程中，自由元带来的常数项
                        for(int k = 0; k < m; ++k) {
                            if(pt[k] == -1) { // 只累加自由元对应的项
                                sum = (sum + 1ll * a[row][k] * vec[k]) % mod;
                            }
                        }
                        // 移项并除以主元系数
                        int val = (a[row][m] - sum + mod) % mod;
                        vec[j] = 1ll * val * Combinatorics_::Inv(a[row][j]) % mod;
                    }
                }
                basis.push_back(vec);
            }
        }
        return basis.size(); 
    }
    struct Matrix {
        int n, m; 
        std::vector<std::vector<int>> a; 
        
        Matrix(int n, int m) : n(n), m(m) {a.assign(n, std::vector<int>(m, 0));}
        
        Matrix(const std::vector<std::vector<int>> &data) {
            n = data.size();
            m = n ? data[0].size() : 0;
            a = data;
        }
        
        inline int & operator ()(int x, int y) {assert(0 <= x && x < n && 0 <= y && y < m); return a[x][y];}
        inline const int & operator ()(int x, int y) const {assert(0 <= x && x < n && 0 <= y && y < m); return a[x][y];}
        inline void Read() {
            for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> a[i][j], a[i][j] = (a[i][j] % mod + mod) % mod;
        }
        
        inline void Print() {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) cout << a[i][j] << ' '; 
                cout << '\n'; 
            }
        }
        inline Matrix operator * (const Matrix &b) const {
            assert(m == b.n);
            Matrix c(n, b.m);
            for(int i = 0; i < n; ++i) for(int j = 0, v; j < m; ++j) if(v = a[i][j]) for(int k = 0; k < b.m; ++k) c(i, k) = (c(i, k) + 1ll * v * b(j, k)) % mod;
            return c; 
        }

        inline int Solve(std::vector<int> &ans, std::vector<std::vector<int>> &basis) {
            return Linear_Algebra_::gauss(this->a, ans, basis);
        }
        // 求矩阵的逆（仅限方阵）
        inline Matrix Inverse() const {
            assert(n == m);
            int sz = n;
            std::vector<std::vector<int>> aug(sz, std::vector<int>(sz * 2, 0));
            
            for(int i = 0; i < sz; ++i) {
                for(int j = 0; j < sz; ++j) {
                    aug[i][j] = a[i][j]; // 左边是原矩阵 A
                }
                aug[i][sz + i] = 1;      // 右边是单位矩阵 I
            }
            
            for(int i = 0; i < sz; ++i) {
                // 1. 寻找主元
                int p = -1;
                for(int j = i; j < sz; ++j) {
                    if(aug[j][i] != 0) {
                        p = j;
                        break;
                    }
                }
                // 如果找不到非零主元，说明矩阵不可逆
                assert(p != -1 && "Matrix is not invertible!");
                
                // 2. 交换行
                if(p != i) {
                    for(int j = 0; j < sz * 2; ++j) {
                        std::swap(aug[i][j], aug[p][j]);
                    }
                }
                
                int inv_val = Combinatorics_::Inv(aug[i][i]);
                for(int j = 0; j < sz * 2; ++j) {
                    aug[i][j] = 1ll * aug[i][j] * inv_val % mod;
                }
                
                // 4. 消去其他行在当前列的元素
                for(int j = 0; j < sz; ++j) {
                    if(j != i && aug[j][i] != 0) {
                        int t = aug[j][i]; 
                        for(int k = 0; k < sz * 2; ++k) {
                            aug[j][k] -= 1ll * t * aug[i][k] % mod;
                            if(aug[j][k] < 0) aug[j][k] += mod;
                        }
                    }
                }
            }
            
            Matrix res(sz, sz);
            for(int i = 0; i < sz; ++i) {
                for(int j = 0; j < sz; ++j) {
                    res(i, j) = aug[i][sz + j];
                }
            }
            return res;
        }
        inline int Determinant() const {
            assert(n == m);
            int sz = n;
            std::vector<std::vector<int>> mat = a; 
            int det = 1;
            
            for(int i = 0; i < sz; ++i) {
                // 1. 寻找主元
                int p = -1;
                for(int j = i; j < sz; ++j) {
                    if(mat[j][i] != 0) {
                        p = j;
                        break;
                    }
                }
                // 如果找不到非零主元，说明行列式为0
                if(p == -1) return 0;
                
                // 2. 交换行
                if(p != i) {
                    std::swap(mat[i], mat[p]);
                    det = (mod - det) % mod; // 交换行会改变行列式的符号
                }
                
                det = 1ll * det * mat[i][i] % mod;
                int inv_val = Combinatorics_::Inv(mat[i][i]);
                
                for(int j = i + 1; j < sz; ++j) {
                    if(mat[j][i] != 0) {
                        int t = 1ll * mat[j][i] * inv_val % mod;
                        for(int k = i; k < sz; ++k) {
                            mat[j][k] -= 1ll * t * mat[i][k] % mod;
                            if(mat[j][k] < 0) mat[j][k] += mod;
                        }
                    }
                }
            }
            return det;
        }
    };
    inline void mian() {
        
    }
} ; 

int main() {
    Linear_Algebra_ :: mian();
    return 0; 
}