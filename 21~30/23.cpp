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
constexpr int N = 28123;

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void bf() {
}

/*
 Project Euler 23: Non-abundant sums
 link: https://projecteuler.net/problem=23
 标签: 筛法, 枚举, 位运算
 思路:
 1. 用筛法计算 1…N 每个数的真因子和 d[i]
 2. 收集所有盈数 abundant（d[i] > i）
 3. solve(): 双重循环枚举 (a,b) 配对，标记能表示为和的数
 4. solve2(): 用 bitset 将盈数集合 A 映射到 A<<a，再累或，批量标记和集
 5. 遍历判断未被标记的数累加得最终答案
 时间复杂度:
   solve  O(k^2)
   solve2 O(k·(N/64))
 空间复杂度: O(N)
*/
void solve() {
    vector<ll> d(N + 1);
    for (int i = 1; i <= N; ++i) {
        for (int j = i << 1; j <= N; j += i) {
            d[j] += i;
        }
    }
    vector<bool> is(N + 1, true);
    vector<int> abundant;
    abundant.reserve(N);
    for (int i = 1; i <= N; ++i) {
        if (d[i] > i) abundant.emplace_back(i);
    }
    int len = abundant.size();
    for (int i = 0; i < len; ++i) {
        int x = abundant[i];
        for (int j = i; j < len; ++j) {
            int y = abundant[j];
            if (x + y > N) break;
            is[x + y] = false;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (is[i]) ans += i;
    }
    cout << ans << "\n";
}

void solve2() {
    vector<ll> d(N + 1);
    for (int i = 1; i <= N; ++i) {
        for (int j = i << 1; j <= N; j += i) {
            d[j] += i;
        }
    }

    vector<int> abundant;
    abundant.reserve(N);
    std::bitset<N + 1> A, IS;
    A.reset();
    IS.reset();
    for (int i = 1; i <= N; ++i) {
        if (d[i] > i) {
            abundant.emplace_back(i);
            A[i] = true;
        }
    }
    for (auto &a: abundant) {
        IS |= A << a;
    }
    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (!IS[i]) ans += i;
    }
    cout << ans << "\n";
}

signed main() {
    auto t1 = get_now();
    solve();
    auto t2 = get_now();
    cout << ms_dis(t2, t1) << "ms\n";
    solve2();
    auto t3 = get_now();
    cout << ms_dis(t3, t2) << "ms\n";
    return 0;
}
