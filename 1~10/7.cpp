//
// Created by 幻 on 2025/7/16.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;

using ll = long long;
using ull = unsigned long long;
constexpr int N = 1e6 + 7;


signed main() {
    vector<int> p;
    std::bitset<N> isp;
    isp.set();
    isp[0] = isp[1] = false;
    for (int i = 2; i * i < N; ++i) {
        if (isp[i])
            for (int j = i * 2; j < N; j += i) {
                isp[j] = false;
            }
    }
    for (int i = 2; i < N; ++i) {
        if (isp[i]) p.emplace_back(i);
    }
    cout << p[10000];
    return 0;
}
