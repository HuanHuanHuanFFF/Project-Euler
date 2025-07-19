//
// Created by 幻 on 2025/7/20.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
constexpr int N = 1e6 + 7;

/* Problem 14: Longest Collatz sequence
 * link: https://projecteuler.net/problem=14
 * 标签: 记忆化搜索, 递归, 数论
 * 思路:
 * 1 定义数组 len, len[1]=1, 用于缓存每个 x 到 1 的链长
 * 2 递归函数 dfs(x):
 *    - 若 x<N 且 len[x]>0, 直接返回 len[x]
 *    - 否则计算下一个值 y = (x%2 ? 3*x+1 : x/2), 递归 ans = dfs(y)+1
 *    - 若 x<N, 将 len[x]=ans 缓存
 *    - 返回 ans
 * 3 主循环遍历 2..N-1, 调用 dfs, 同时维护最大链长及对应起始值 p
 * 4 输出链最长的起始值 p
 * 时间复杂度: O(N)（每个 x 计算一次）
 * 空间复杂度: O(N)
 */
void solve() {
    vector<ll> len(N);
    len[1] = 1;

    auto dfs = [&](auto &&self, ll x)-> ll {
        if (x < N && len[x] > 0) return len[x];
        ll y = (x % 2 ? 3 * x + 1 : x / 2);
        ll ans = self(self, y) + 1;
        if (x < N) len[x] = ans;
        return ans;
    };

    ll max = 0, p = 0;
    for (int i = 2; i < N; ++i) {
        dfs(dfs, i);
        if (len[i] >= max) {
            max = len[i];
            p = i;
        }
    }
    cout << p;
}

signed main() {
    solve();
    return 0;
}
