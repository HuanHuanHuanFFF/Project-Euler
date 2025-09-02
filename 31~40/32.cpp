//
// Created by 幻 on 2025/9/1.
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

/* Problem 32: Pandigital products
 * link: https://projecteuler.net/problem=32
 * 标签: 枚举, 因子分解, 位掩码, 全排列
 * 思路:
 *  1) 位数推断：唯一可能的形态是 (1位 × 4位 = 4位) 或 (2位 × 3位 = 4位) ⇒ 积必为4位。
 *  2) 方法A（枚举“积”+ 因子）：
 *     - 枚举 p ∈ [1234, 9876]（所有4位数）。
 *     - 快速检查 p 是否含0或有重复数字（位掩码）。
 *     - 枚举 p 的因子 a（到 sqrt(p)），令 b = p / a；
 *       仅接受 (da,db) ∈ {(1,4),(2,3)}（或对调）。
 *       再用位掩码校验 a、b、p 三者数位互不相交，且并集正好是 {1..9}。
 *     - 用 bitset/set 对 p 去重，累加答案。
 *  3) 方法B（9个数字全排列 + 切分）：
 *     - 对 1..9 做全排列（9! 次）。
 *     - 在排列里用两种固定切法构出 (a,b,p)：
 *         切法1: 1 | 2345 | 6789  → (1×4=4)
 *         切法2: 12 | 345 | 6789  → (2×3=4)
 *       判断 a*b==p，合法则把 p 计入（去重后求和）。
 * 时间复杂度:
 *  - 方法A: 约 O(9e3 × 平均因子数) ≈ 1e6 级别，常数小；
 *  - 方法B: O(9! × 9) ≈ 3.2e6 操作，也足够快。
 * 空间复杂度: O(1)（用到少量辅助结构）
 */
void bf() {
    ll ans = 0;
    std::set<int> st;
    auto cacl = [&](int a, int b, int c, int d) {
        for (int i = a; i < b; ++i) {
            string si = std::to_string(i);
            for (int j = c; j < d; ++j) {
                int now = i * j;
                if (st.contains(now)) continue;
                std::set<char> has;
                string s = std::to_string(now);
                string sj = std::to_string(j);
                if (s.length() > 4) break;
                bool tag = true;
                for (auto c: si) {
                    if (has.contains(c) || c == '0') {
                        tag = false;
                        break;
                    }
                    has.insert(c);
                }
                if (tag)
                    for (auto c: sj) {
                        if (has.contains(c) || c == '0') {
                            tag = false;
                            break;
                        }
                        has.insert(c);
                    }
                if (tag)
                    for (auto c: s) {
                        if (has.contains(c) || c == '0') {
                            tag = false;
                            break;
                        }
                        has.insert(c);
                    }
                if (tag) {
                    st.insert(now);
                    ans += now;
                }
            }
        }
    };
    cacl(1, 10, 1e3, 1e4);
    cacl(10, 1e2, 1e2, 1e3);
    cout << ans << "\n";
}

//B
void solve() {
    vector<int> nums({1, 2, 3, 4, 5, 6, 7, 8, 9});
    std::set<int> st;
    auto val = [&](int l, int r) {
        int ans = 0;
        for (int i = l; i <= r; ++i) {
            ans = ans * 10 + nums[i];
        }
        return ans;
    };
    ll ans = 0;
    do {
        int a = val(0, 0), b = val(1, 4), p = val(5, 8);
        if (a * b == p && !st.contains(p)) {
            ans += p;
            st.insert(p);
        }
        a = val(0, 1), b = val(2, 4), p = val(5, 8);
        if (a * b == p && !st.contains(p)) {
            ans += p;
            st.insert(p);
        }
    } while (std::next_permutation(nums.begin(), nums.end()));
    cout << ans << "\n";
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
