//
// Created by 幻 on 2025/7/4.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;

using ll = long long;
using ull = unsigned long long;

// 对1~20分解质因数,取所有质因数的最高次幂,即可构造出答案
signed main() {
    ll ans = 1;
    std::vector<int> p({2, 3, 5, 7, 11, 13, 17, 19});
    std::map<int, int> max_cnt;
    for (int i = 2; i <= 20; ++i) {
        std::map<int, int> cnt;
        int a = i;
        for (auto &x: p) {
            while (a % x == 0) {
                ++cnt[x];
                a /= x;
            }
        }
        for (auto &[x,y]: cnt) {
            max_cnt[x] = std::max(y, max_cnt[x]);
        }
    }
    for (auto &[x,y]: max_cnt) {
        for (int i = 0; i < y; ++i) {
            ans *= x;
        }
    }
    for (int i = 1; i <= 20; ++i) {
        if (ans % i == 0) cout << "YES ";
    }
    cout << "\n" << ans;
    return 0;
}
