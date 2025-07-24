//
// Created by 幻 on 2025/7/24.
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
constexpr int N = 1e7 + 7;

void bf() {
}

/* Problem19-Counting Sundays
 * link: https://projecteuler.net/problem=19
 * 标签: Sakamoto算法, 日期计算, 模拟
 * 思路:
 * 1 使用 Sakamoto 算法定义函数 dow(year,month,day) 计算给定日期的星期
 * 2 遍历 1901–2000 年，每年 1–12 月，调用 dow(y,m,1)
 * 3 若返回值为 0（Sunday），则计数
 * 4 最终输出计数 ans
 */
void solve() {
    //Sakamoto 算法
    auto down = [](int year, int month, int day) {
        int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        if (month < 3) --year;
        return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
    };
    int ans = 0;
    for (int y = 1901; y <= 2000; ++y) {
        for (int m = 1; m <= 12; ++m) {
            if (down(y, m, 1) == 0) ++ans;
        }
    }
    cout << ans;
}

signed main() {
    bf();
    solve();
    return 0;
}
