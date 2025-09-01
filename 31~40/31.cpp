//
// Created by 幻 on 2025/9/1.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e5;

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void bf() {
}

/* Problem 31: Coin Sums
 * link: https://projecteuler.net/problem=31
 * 标签: 完全背包, 计数DP, 组合数去重
 * 思路:
 *  1. 我们需要统计用 {1p,2p,5p,10p,20p,50p,£1,£2} 凑成 200p 的方案数；
 *  2. 定义 dp[x] = 凑出 x 便士的方案数；
 *  3. 初始化 dp[0]=1，表示凑出 0 有 1 种方式（什么都不选）；
 *  4. 遍历每个硬币面额 v，再遍历金额 i 从 v 到 200：
 *       dp[i] += dp[i-v]
 *     ——相当于完全背包：每加入一种新硬币，就把它能贡献的方案数累加进去；
 *  5. 遍历顺序很重要：先枚举硬币，再枚举金额，避免了排列重复（只保留组合）。
 * 复杂度:
 *   时间复杂度: O(#coins × target) ≈ 8 × 200 = 1600
 *   空间复杂度: O(target) = 201
 */
void solve() {
    vector<int> val({1, 2, 5, 10, 20, 50, 100, 200});
    vector<ll> dp(201);
    dp[0] = 1;
    for (auto &v: val)
        for (int i = v; i <= 200; ++i) {
            dp[i] += dp[i - v];
        }
    cout << dp[200] << "\n";
}

signed main() {
    auto t1 = get_now();
    bf();
    auto t2 = get_now();
    cout << ms_dis(t2, t1) << "ms\n";
    solve();
    auto t3 = get_now();
    cout << ms_dis(t3, t2) << "ms\n";
    return 0;
}
