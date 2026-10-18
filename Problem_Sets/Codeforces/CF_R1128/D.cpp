#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    // 记录相邻点是否被原探测器的端点切开
    vector<bool> is_separated(n + 1, false);
    
    // 用差分数组统计每个点被覆盖的次数，用于生成特征
    vector<int> diff(n + 2, 0);
    
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        if (l > 1) is_separated[l - 1] = true;
        if (r < n) is_separated[r] = true;
        diff[l]++;
        diff[r + 1]--;
    }
    
    // 生成原始特征序列
    vector<int> orig(n + 1);
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur += diff[i];
        orig[i] = cur;
    }
    
    // 找到所有相邻未切开的“缝隙”
    vector<int> gaps;
    for (int i = 1; i < n; ++i) {
        if (!is_separated[i]) {
            gaps.push_back(i);
        }
    }
    
    vector<pair<int, int>> ans;
    
    if (!gaps.empty()) {
        // 正常情况：处理缝隙
        int i = 0;
        if (gaps.size() % 2 != 0) {
            ans.push_back({1, gaps[0]}); // 处理奇数个缝隙的开头
            i = 1;
        }
        for (; i < gaps.size(); i += 2) {
            ans.push_back({gaps[i] + 1, gaps[i + 1]}); // 两两配对
        }
    } else {
        // 特殊情况（如你的反例）：没有相邻缝隙，但可能存在非相邻的相同特征（如真空点）
        bool has_duplicate = false;
        map<int, int> freq;
        for (int i = 1; i <= n; ++i) {
            freq[orig[i]]++;
            if (freq[orig[i]] > 1) {
                has_duplicate = true;
                break;
            }
        }
        
        // 如果存在重复特征，使用倍增法强行区分所有点
        if (has_duplicate) {
            for (int len = 2; len <= n; len *= 2) {
                ans.push_back({1, len});
            }
        }
    }
    
    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}