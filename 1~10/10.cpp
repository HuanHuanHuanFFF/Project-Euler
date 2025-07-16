//
// Created by 幻 on 2025/7/16.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
constexpr int N = 2e6;

/* Prime Sum Under N
 * link: https://projecteuler.net/problem=10
 * 标签: 线性筛, 素数定理, 数论
 * 思路:
 * 1 预分配大小 N 的标记数组, 用 vector<bool> isp 记录素性
 * 2 线性筛原理: 对每个 i, 若 isp[i] 为真则加入素数列表 p
 *    然后遍历 p, 对于每个素数 x:
 *      - 标记 i*x 为合数
 *      - 若 x 是 i 的最小素因子 (i%x==0), 则提前退出, 保证每个合数只被一次标记
 *    从而实现 O(N) 时间
 * 3 根据素数定理 π(N)≈N/lnN, 在 p.reserve 中使用 N/log(N) 估算素数个数, 降低扩容开销
 * 4 遍历 p 累加所有素数得到 ans
 * 时间复杂度: O(N)
 * 空间复杂度: O(N)
 */
signed main() {
    vector<bool> isp(N, true);
    vector<int> p;
    p.reserve(N / log(N));
    isp[0] = isp[1] = false;
    for (int i = 2; i < N; ++i) {
        if (isp[i]) {
            p.emplace_back(i);
        }
        for (auto &x: p) {
            if (i * x > N) break;
            isp[i * x] = false;
            if (i % x == 0) break;
        }
    }
    ll ans = 0;
    for (auto &x: p) ans += x;
    cout << ans;
    return 0;
}
