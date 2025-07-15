//
// Created by 幻 on 2025/7/4.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using ll = long long;
using ull = unsigned long long;

signed main() {
    ll ans = 2, max = 4000000;
    int a = 1, b = 2;
    while (b <= max) {
        int cb = b;
        b += a;
        a = cb;
        if (b % 2 == 0) ans += b;
    }
    cout << ans;
    return 0;
}
