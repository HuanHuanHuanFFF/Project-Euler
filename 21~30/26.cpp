//
// Created by 幻 on 2025/7/30.
//
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
constexpr int N = 1e3;

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

/* 026-ReciprocalCycles
 * link: https://projecteuler.net/problem=26
 * 标签: 取余, 循环节, 数论, 长除法
 * 思路:
 * 1. 对每个 d(2≤d<1000)，用长除法求 1/d 的小数部分
 * 2. 设 rem 为当前余数 remainder，维护 pos[rem] = 出现位置
 *    - 每轮: rem*=10, rem%=d
 *    - 若 rem==0 → 无循环节，长度=0
 *    - 若 pos[rem] 已记录 → 循环节长度 = 当前 idx - pos[rem]
 * 3. 记录最长循环节及其 d
 * 时间复杂度: O(N^2)  (N=1000，外层 998，内层 ≤d)
 * 空间复杂度: O(N)
 */
void bf() {
    int ans = 0, max = 0;
    for (int i = 1; i <= N; ++i) {
        vector<int> p(i, -1);
        int rem = 1 % i, idx = 0;
        while (rem != 0 && p[rem] == -1) {
            p[rem] = idx++;
            rem = (rem * 10) % i;
        }
        int len = (rem == 0 ? 0 : idx - p[rem]);
        if (len > max) {
            max = len;
            ans = i;
        }
    }
    cout << ans << "\n";
}

void solve() {
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
