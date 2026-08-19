
#  ACM 算法笔记 LaTeX 速查表 (Cheatsheet)

> 专为 Locsey 的 ACM 模板库定制，涵盖公式、排版、日期、代码与算法伪代码。

##  1. 常用数学公式

### 基础运算与代数
| 描述 | LaTeX 代码 | 渲染效果 |
| :--- | :--- | :--- |
| 分数 | `\frac{a}{b}` | $\frac{a}{b}$ |
| 上下标 | `x_i^2` | $x_i^2$ |
| 根号 | `\sqrt{x}`, `\sqrt[n]{x}` | $\sqrt{x}, \sqrt[n]{x}$ |
| 绝对值 | `\lvert x \rvert` | $\lvert x \rvert$ |
| 取整(下) | `\lfloor x \rfloor` | $\lfloor x \rfloor$ |
| 取整(上) | `\lceil x \rceil` | $\lceil x \rceil$ |
| 组合数 | `\binom{n}{k}` | $\binom{n}{k}$ |

### 复杂度分析与极限
| 描述 | LaTeX 代码 | 渲染效果 |
| :--- | :--- | :--- |
| 大O表示法 | `O(n \log n)` | $O(n \log n)$ |
| 求和符号 | `\sum_{i=1}^{n} a_i` | $\sum_{i=1}^{n} a_i$ |
| 连乘符号 | `\prod_{i=1}^{n} i` | $\prod_{i=1}^{n} i$ |
| 极限 | `\lim_{n \to \infty}` | $\lim_{n \to \infty}$ |

### 数论与模运算
| 描述 | LaTeX 代码 | 渲染效果 |
| :--- | :--- | :--- |
| 整除 / 不整除 | `a \mid b`, `a \nmid b` | $a \mid b$, $a \nmid b$ |
| 同余 | `a \equiv b \pmod m` | $a \equiv b \pmod m$ |
| 最大公约数 | `\gcd(a, b)` | $\gcd(a, b)$ |
| 最小公倍数 | `\operatorname{lcm}(a, b)` | $\operatorname{lcm}(a, b)$ |
| 欧拉函数 | `\phi(n)` | $\phi(n)$ |

### 集合论与逻辑
| 描述 | LaTeX 代码 | 渲染效果 |
| :--- | :--- | :--- |
| 属于 / 不属于 | `x \in S`, `x \notin S` | $x \in S$, $x \notin S$ |
| 子集 / 真子集 | `A \subseteq B`, `A \subsetneq B` | $A \subseteq B$, $A \subsetneq B$ |
| 并集 / 交集 | `A \cup B`, `A \cap B` | $A \cup B, A \cap B$ |
| 任意 / 存在 | `\forall x`, `\exists x` | $\forall x, \exists x$ |
| 蕴含 / 等价 | `\Rightarrow`, `\Leftrightarrow` | $\Rightarrow, \Leftrightarrow$ |

### 常用希腊字母
- **小写**: `\alpha` ($\alpha$), `\beta` ($\beta$), `\gamma` ($\gamma$), `\delta` ($\delta$), `\epsilon` ($\epsilon$), `\theta` ($\theta$), `\lambda` ($\lambda$), `\mu` ($\mu$), `\pi` ($\pi$), `\sigma` ($\sigma$), `\phi` ($\phi$), `\omega` ($\omega$)
- **大写**: `\Gamma` ($\Gamma$), `\Delta` ($\Delta$), `\Theta` ($\Theta$), `\Lambda` ($\Lambda$), `\Pi` ($\Pi$), `\Sigma` ($\Sigma$), `\Omega` ($\Omega$)

---

##  2. 日期排版

### 基础日期
- **自动获取当前日期**: `\today` 
- **中文原生日期**: `\number\year 年 \number\month 月 \number\day 日`

### 自定义格式 (需引入 `datetime` 宏包)
```latex
\usepackage{datetime}
\ddmmyyyydate{\today} % 纯数字格式 (DD/MM/YYYY)
\yyyymmdddate{\today} % ISO 格式 (YYYY/MM/DD)
```

---

## 3. 字体与字号控制

### 常用字体样式

- **加粗**: `\textbf{words in bold}` $\rightarrow$ **words in bold**
- **斜体**: `\textit{words in italics}` $\rightarrow$ *words in italics*
- **等宽字体(适合代码)**: `\texttt{words in teletype}` $\rightarrow$ `words in teletype`
- **无衬线字体**: `\textsf{sans serif words}` $\rightarrow$ sans serif words
- **下划线**: `\underline{underlined words}` $\rightarrow$ underlined words

### 字体大小调整

- `\Huge` $\rightarrow$ 超大字号
- `\Large` $\rightarrow$ 大字号
- `\large` $\rightarrow$ 稍大字号
- `\small` $\rightarrow$ 小字号
- `\footnotesize` $\rightarrow$ 特小字号（适合写注释）

---

## 4. 代码排版

### 行内代码

- **语法**: 使用单反引号包裹，例如 ``std::vector<int>`` $\rightarrow$ `std::vector<int>`

### 多行代码块

- **语法**: 使用三个反引号包裹，并可指定语言高亮。

```cpp
#include <iostream>
using namespace std;
int main() {
    cout << "Hello, ACM!" << endl;
    return 0;
}
```

### 带行号的代码块 (Markdown 扩展语法)

- **语法**: 在三个反引号后加上 `{.line-numbers}` (部分编辑器支持)

```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

---

## ️ 5. 算法伪代码排版 (100% 还原比例)

**注意**：需引入 `algorithm` 和 `algpseudocode` 宏包，两者不可与 `algorithm2e` 混用。

### 核心命令速查

- **赋值**: `\State $x \gets x + 1$`
- **条件判断**: `\If{condition}` ... `\Else` ... `\EndIf`
- **循环**: `\For{$i = 1$ to $n$}` ... `\EndFor`
- **While 循环**: `\While{condition}` ... `\EndWhile`
- **返回值**: `\State \textbf{return} $result$`

### 完整模板 (带行号)

在 `algorithmic` 后加 `` 即可自动生成行号：

```latex
\begin{algorithm}[H]
\caption{Dijkstra 最短路径算法}
\label{alg:dijkstra}
\begin{algorithmic}
\State 初始化距离数组 $dist$，令 $dist[s] = 0$，其余为 $\infty$
\State 初始化优先队列 $Q$，将起点 $s$ 入队
\While{$Q$ 不为空}
    \State 取出 $Q$ 中 $dist$ 值最小的节点 $u$
    \For{每一条从 $u$ 出发的边 $(u, v, w)$}
        \If{$dist[u] + w < dist[v]$}
            \State $dist[v] \gets dist[u] + w$
            \State 更新 $Q$ 中的节点 $v$
        \EndIf
    \EndFor
\EndWhile
\State \textbf{return} $dist$
\end{algorithmic}
\end{algorithm}
```

### 进阶：支持中文关键字

```latex
\renewcommand{\algorithmicrequire}{\textbf{输入:}}
\renewcommand{\algorithmicensure}{\textbf{输出:}}
```

```

---

这份终极版速查表现在包含了**公式、日期、字体、代码、伪代码**五大核心板块，非常适合放在你的 ACM 笔记库中随时查阅
```

