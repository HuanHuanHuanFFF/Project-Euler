//
// Created by 幻 on 2025/7/4.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;

using ll = long long;
using ull = unsigned long long;

signed main() {
    ll x = 600851475143ll;
    while (x % 2 == 0) x /= 2;
    ll max_p = 2;
    for (int i = 3; i * i < x; i += 2) {
        while (x % i == 0) {
            max_p = i;
            x /= i;
        }
    }
    if (x > 1) max_p = std::max(max_p, x);
    cout << max_p;
    return 0;
}
