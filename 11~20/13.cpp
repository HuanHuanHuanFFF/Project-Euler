//
// Created by 幻 on 2025/7/20.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;

/* Large Sum
 * link: https://projecteuler.net/problem=13
 * 标签: 大整数求和, 字符串模拟, 前缀截断
 * 思路:
 * 1 读取 100 个 50 位数字字符串，将每个字符串的前 15 位截断并转换为整数 now
 * 2 累加到 ans（long long 足以存储截断后高位和）
 * 3 转为字符串后输出前 10 位即为所求
 * 时间复杂度: O(n·d)  n=100, d=15
 * 空间复杂度: O(d)
 */
void solve() {
    ll ans = 0;
    string s;
    int n = 100;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        ll now = 0;
        for (int k = 0; k < 15; ++k) {
            now *= 10;
            now += s[k] - '0';
        }
        ans += now;
    }
    s = std::to_string(ans);
    for (int i = 0; i < 10; ++i) {
        cout << s[i];
    }
}

signed main() {
    solve();
    return 0;
}
