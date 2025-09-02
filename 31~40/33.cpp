//
// Created by 幻 on 2025/9/2.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e5;

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

/* Problem 33: Digit Cancelling Fractions
 * link: https://projecteuler.net/problem=33
 * 标签: 枚举, 数位, 最大公约数
 * 思路:
 *  1) 只考虑两位数 n,d 且 n<d，且末位不能为 0（排除平凡解）。
 *  2) 若 n 与 d 共享某个非 0 数字，去掉该数字后得一位数 n', d'，
 *     若 n/d == n'/d'，则记为一组。
 *  3) 把四组分数连乘，最后约到最简，输出分母。
 * 时间复杂度: O(90*90)  常数小
 * 空间复杂度: O(1)
 */
void bf() {
    int x = 1, y = 1;
    for (int i = 10; i < 100; ++i) {
        int a = i / 10, b = i % 10;
        for (int j = i + 1; j < 100; ++j) {
            int c = j / 10, d = j % 10;
            bool ok = false;
            if (a == c && a) ok |= (d * i == b * j);
            if (a == d && a) ok |= (c * i == b * j);
            if (b == c && b) ok |= (a * j == d * i);
            if (b == d && b) ok |= (a * j == c * i);
            if (ok) x *= i, y *= j;
        }
    }
    int g = std::gcd(x, y);
    cout << y / g << "\n";
}

/* —— 方法B：按位枚举“共享数字”的结构（更精简）——
 * 仅存在四种模式：
 *   ab/bc = a/c, ab/cb = a/c, ab/ac = b/c, ab/ca = b/c
 * 直接枚举 a,b,c∈[1..9]，构出 n,d，判断 <1 并验证等式。
 * O(9*9*9)
 */
void solve() {
    ll P = 1, Q = 1;
    for (int a = 1; a <= 9; ++a)
        for (int b = 1; b <= 9; ++b)
            for (int c = 1; c <= 9; ++c) {
                int n, d;
                // ab/bc = a/c
                n = 10 * a + b;
                d = 10 * b + c;
                if (n < d && 1LL * n * c == 1LL * d * a) {
                    P *= n;
                    Q *= d;
                }
                // ab/cb = a/c
                n = 10 * a + b;
                d = 10 * c + b;
                if (n < d && 1LL * n * c == 1LL * d * a) {
                    P *= n;
                    Q *= d;
                }
                // ab/ac = b/c
                n = 10 * a + b;
                d = 10 * a + c;
                if (n < d && 1LL * n * c == 1LL * d * b) {
                    P *= n;
                    Q *= d;
                }
                // ab/ca = b/c
                n = 10 * a + b;
                d = 10 * c + a;
                if (n < d && 1LL * n * c == 1LL * d * b) {
                    P *= n;
                    Q *= d;
                }
            }
    ll g = std::gcd(P, Q);
    cout << (Q / g) << "\n";
}

signed main() {
    auto t1 = get_now();
    bf();
    auto t2 = get_now();
    cout << ms_dis(t2, t1) << "ms\n";
    solve();
    auto t3 = get_now();
    cout << ms_dis(t3, t2) << "ms\n";
    return 0;
}
