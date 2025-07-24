//
// Created by 幻 on 2025/7/24.
//
#include <algorithm>
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void bf() {
}

/* Problem18-最大路径和I
 * link: https://projecteuler.net/problem=18
 * 标签: 动态规划, 金字塔路径, 状态压缩
 * 思路:
 * 1 定义 dp[i][j] 为从顶点走到第 i 行第 j 列的最大路径和
 * 2 转移：只能从上一行第 j-1 或 j 过来
 *     dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j]
 * 3 边界：dp[0][*]=0 或 dp[*][0]=0
 * 4 最终答案为第 n 行的最大值
 * 时间复杂度: O(n^2)
 * 空间复杂度: O(n^2)
 */
void solve() {
    int n = 15;
    vector a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }
    vector dp(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
        }
    }
    cout << std::ranges::max(dp[n]);
}

signed main() {
    bf();
    solve();
    return 0;
}
