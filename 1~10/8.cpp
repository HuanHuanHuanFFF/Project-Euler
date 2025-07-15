//
// Created by 幻 on 2025/7/16.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::string;

using ll = long long;
using ull = unsigned long long;

// 双指针 模拟
signed main() {
    string s;
    for (int i = 0; i < 20; ++i) {
        string x;
        cin >> x;
        s += x;
    }
    ll cnt0 = 0, now = 1, ans = 0;
    for (int i = 0; i < 13; ++i) {
        if (s[i] == '0') ++cnt0;
        else now *= s[i] - '0';
    }
    if (cnt0 == 0) ans = std::max(ans, now);
    for (int i = 1; i < 1000 - 13; ++i) {
        if (s[i - 1] == '0') --cnt0;
        else now /= s[i - 1] - '0';
        if (s[i + 12] == '0') ++cnt0;
        else now *= s[i + 12] - '0';
        if (cnt0 == 0) ans = std::max(ans, now);
    }
    cout << ans;
    return 0;
}
