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
constexpr int N = 1e5;

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void bf() {
}

/*
 Problem 28: Number Spiral Diagonals
 link: https://projecteuler.net/problem=28
 标签: 数学规律, 螺旋, 对角线求和
 思路:
   从中心 1 开始，每向外扩一层，边长增加 2（即层号 i 对应边长 2i+1）
   该层的 4 个对角线上的数，每次在上一个对角值基础上加上 2i
   累加所有层的 4 个角值，再加上中心的 1 即为答案
 时间复杂度: O(n)（n 为层数，此处 n=500）
 空间复杂度: O(1)
*/
void solve() {
    ll ans = 1, now = 1;
    for (int i = 1; i < 501; ++i) {
        for (int j = 0; j < 4; ++j) {
            now += i * 2;
            ans += now;
        }
    }
    cout << ans << "\n";
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
