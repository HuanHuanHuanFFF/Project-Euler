//
// Created by 幻 on 2025/7/20.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

// using ll = __int128;
using ll = long long;
using ull = unsigned long long;

/* Problem 15: Lattice Paths
 * link: https://projecteuler.net/problem=15
 * 标签: 组合数学, 阶乘, 迭代乘除
 * 思路:
 * 1 求解 20×20 网格从左上到右下的路径数等于 C(40,20)
 * 2 利用迭代乘除法计算组合数：
 *   - 分子连乘 21…40
 *   - 分母依次除以 1…20
 *   可保证每步整除，避免中间溢出
 * 时间复杂度: O(k) ，k=20
 * 空间复杂度: O(1)
 */
void bf() {
    ll ans = 1, n = 40;
    for (int i = 1; i <= 20; ++i) {
        ans *= n - 20 + i;
        ans /= i;
    }
    cout << ans;
}

signed main() {
    bf();
    return 0;
}
