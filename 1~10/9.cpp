//
// Created by 幻 on 2025/7/16.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;

using ll = long long;
using ull = unsigned long long;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

signed main() {
    // 暴力枚举O(N^2)
    // int k = 1000;
    // for (int a = 1; a < k; ++a) {
    //     for (int b = a + 1; b < k; ++b) {
    //         double c = sqrt(a * a + b * b);
    //         if (a + b + c == k) {
    //             cout << a << " " << b << " " << c << "\n";
    //             cout << a * b * (int) c;
    //             break;
    //         }
    //     }
    // }

    /* Special Pythagorean Triplet
     * link: https://projecteuler.net/problem=9
     * 标签: 枚举因数, 欧几里得生成法, 数论
     * 思路:
     * 1 将 a+b+c=1000 转换为 k·m·(m+n)=500，简化到枚举因数问题
     * 2 对 D=500 做 √D 扫描，枚举 m|D，计算 n=D/m−m 并判断 n>0
     * 3 由 m,n 生成原始毕氏三元组 a=m²−n², b=2mn, c=m²+n²
     * 4 输出满足条件的 (a,b,c) 及乘积
     * 时间复杂度: O(√N)
     * 空间复杂度: O(1)
     */
    int d = 500;
    for (int m = 1; m * m <= d; ++m) {
        if (d % m) continue;
        int n = d / m - m;
        if (m > n && n > 0) {
            cout << n << " " << m << "\n";
            int a = m * m - n * n, b = 2 * n * m, c = m * m + n * n, ans = a * b * c;
            cout << a << " " << b << " " << c << "\n" << ans;
        }
    }
    return 0;
}
