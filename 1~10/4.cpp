//
// Created by 幻 on 2025/7/4.
//
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
    int ans = 0, n = 1000, a = 0, b = 0;
    for (int i = 100; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int x = i * j;
            string s = to_string(x);
            bool is = true;
            for (int k = 0; k < 3; ++k) {
                if (s[k] != s[5 - k]) {
                    is = false;
                    break;
                }
            }
            if (is) {
                if (ans < x) {
                    ans = x, a = i, b = j;
                }
            }
        }
    }
    cout << ans << "=" << a << "*" << b;
    return 0;
}
