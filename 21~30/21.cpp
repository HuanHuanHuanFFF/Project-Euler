//
// Created by 幻 on 2025/7/28.
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
constexpr int N = 1e4;

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

// 暴力方法：O(N^2)
void bf() {
    vector<ll> d(N, 1);
    for (int i = 1; i < N; ++i) {
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0)
                if (j * j != i)
                    d[i] += j + i / j;
                else d[i] += j;
        }
    }
    ll ans = 0;
    std::set<int> st;
    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (d[i] == j && d[j] == i) {
                st.insert(i);
                st.insert(j);
            }
        }
    }
    for (auto x: st) ans += x;
    cout << ans << "\n";
}

/* Amicable Numbers with Timing
 * link: https://projecteuler.net/problem=21
 * 标签: 时间测量, 计时, 线性筛, 暴力 vs 优化
 */
// 优化方法：O(N log N)
void solve() {
    vector<ll> d(N, 0);
    for (int i = 1; i < N; ++i) {
        for (int j = i << 1; j < N; j += i) {
            d[j] += i;
        }
    }
    ll ans = 0;
    for (int i = 1; i < N; ++i) {
        ll j = d[i];
        if (j > i && j < N && d[j] == i)
            ans += i + j;
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
