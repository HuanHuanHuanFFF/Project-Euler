//
// Created by 幻 on 2025/7/16.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;

using ll = long long;
using ull = unsigned long long;

signed main() {
    ll ans = (1 + 100) * 100 / 2;
    ans *= ans;
    for (int i = 1; i <= 100; ++i) {
        ans -= i * i;
    }
    cout << ans;
    return 0;
}
