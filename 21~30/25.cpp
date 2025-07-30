//
// Created by 幻 on 2025/7/29.
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
constexpr int N = 1e5;

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void bf() {
}

void solve() {
    long double a = 1, b = 1, c = 2;
    int cnt = 3;
    while (std::log10(c) < 999) {
        long double t = b;
        b = c;
        a = t;
        c = b + a;
        ++cnt;
    }
    cout << c << " " << cnt << "\n";
}

void solve2() {
    long double phi = (1 + std::sqrt(5)) / 2;
    int ans = std::ceil((999 + 0.5L * std::log10(5.0L)) / std::log10(phi));
    cout << ans << "\n";
}

/* 025-1000位斐波那契数
 * link: https://projecteuler.net/problem=25
 * 标签: 斐波那契, 黄金分割, 对数, 近似公式
 * 思路:
 *   法一 solve(): 迭代 F(n)=F(n-1)+F(n-2)，用 long double 判断位数，O(k)≈4782
 *   法二 solve2(): 黄金分割近似 F(n)≈φ^n/√5，解 n> (999+½log₁₀5)/log₁₀φ，O(1)
 * 时间复杂度: solve  O(k)  k≈4782
 *            solve2 O(1)
 * 空间复杂度: O(1)
 */
signed main() {
    auto t1 = get_now();
    bf();
    auto t2 = get_now();
    cout << ms_dis(t2, t1) << "ms\n";
    solve();
    auto t3 = get_now();
    cout << ms_dis(t3, t2) << "ms\n";
    solve2();
    auto t4 = get_now();
    cout << ms_dis(t4, t3) << "ms\n";
    return 0;
}
