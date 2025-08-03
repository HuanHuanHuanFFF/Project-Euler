//
// Created by 幻 on 2025/8/3.
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

void bf() {
}

/*
 Project Euler 27: Quadratic primes
 link: https://projecteuler.net/problem=27
 标签: 枚举, 筛法, 剪枝, 数论
 思路:
 1. 先用线性筛生成 2…1e6 的质数表 isp 和素数列表 p
 2. 枚举 a∈[-999,1000]（步长2）与 b∈p且b≤1000
 3. 对每对 (a,b) 用长除法式检查 f(n)=n²+a n+b 是否为质数
 4. 记录连续生成质数的最大 nmax 与对应 (a,b)
 剪枝特性:
  - b 只枚举质数且 b≤1000：因为 f(0)=b 必须为质数
  - a 只枚举与 b 同奇偶性（这里步长2）：保证 f(1)=1+a+b 也是奇数
  - 当 b>1000 立即 break：素数列表预排序
  - 当 f(n) 首次合数时立即 break：无需继续测试更大 n
  - a,b 的取值范围按题限 |a|<1000, |b|≤1000
 时间复杂度: O(P·A·L) ≈ O(168·500·nmax)  ≪ 原始 O(2001·2001·n)
 空间复杂度: O(1e6)
*/
void solve() {
    int n = 1e6;
    vector<bool> isp(n + 1, true);
    isp[0] = isp[1] = false;
    vector<int> p;
    p.reserve(n * log(n));
    for (int i = 2; i <= n; ++i) {
        if (isp[i]) p.emplace_back(i);
        for (auto &x: p) {
            if (x * i > n) break;
            isp[x * i] = false;
            if (i % x == 0) break;
        }
    }
    int max = 0, A = 0, B = 0;
    for (int a = -N + 1; a <= N; a += 2) {
        for (auto &b: p) {
            if (b > 1000) break;
            int now = 0;
            for (int i = 0; ; ++i) {
                int q = i * i + a * i + b;
                if (!isp[q]) break;
                ++now;
            }
            if (now > max) {
                A = a, B = b, max = now;
            }
        }
    }
    cout << std::format("{} {} {} {}\n", max, A, B, A * B);
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
