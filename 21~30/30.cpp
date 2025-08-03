//
// Created by 幻 on 2025/8/3.
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
constexpr int N = 1e6;

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void bf() {
    vector<int> p5(10);
    for (int i = 1; i <= 9; ++i) {
        p5[i] = i * i * i * i * i;
    }
    int l = 2, r = 6 * p5[9];
    ll ans = 0;
    for (int i = l; i <= r; ++i) {
        int x = i, sum = 0;
        while (x) {
            int num = x % 10;
            x /= 10;
            sum += p5[num];
        }
        if (sum == i) {
            // cout << sum << "\n";
            ans += i;
        }
    }
    cout << ans << "\n";
}

/* Problem 30: Digit fifth powers
 * link: https://projecteuler.net/problem=30
 * 标签: 组合枚举, 数位, 剪枝
 * 思路:
 *  1. 由于 6×9⁵ = 354 294，上界 ≤ 6 位。
 *  2. 只关心「每个数字用了几次」这一 **多重集**，因此对长度 2‒6 的
 *     **非递减数字序列**（组合）做 DFS，总数 C(15, 6)=5005。
 *     为什么是5005
 *     要从10个数中可重复地选6个数,不考虑顺序
 *     相当于把6个球放到10个不同的盒子中,盒子里放了几个就选了几个这个盒子上写的数字
 *     那么相当于用9个隔板去隔6个球,这一共是15个位置,我们只需要考虑哪些位置放隔板,哪些位置放球
 *     所以是(15,6)即(k+n-1,n)
 *  3. 计算组合各位数字五次幂之和 s，若把 s 的十进制拆开、排序后
 *     与原组合完全一致，则 s 就是答案之一。
 * 时间复杂度: O(5005 × log 6)≈O(3×10⁴)，远小于枚举 354294
 * 空间复杂度: O(6) = O(1)（递归栈 + 临时数组）
 */
void solve() {
    vector<int> p5(10);
    for (int i = 1; i <= 9; ++i) {
        p5[i] = i * i * i * i * i;
    }
    vector<int> comb;
    comb.reserve(6);
    std::set<int> st;
    auto dfs = [&](auto &&self, int start, int depth)-> void {
        if (depth >= 2) {
            int s = 0;
            for (auto x: comb) s += p5[x];
            if (s > 1) {
                string str = std::to_string(s);
                vector<int> now;
                now.reserve(6);
                for (auto c: str) now.emplace_back(c - '0');
                std::ranges::sort(now);
                if (std::ranges::equal(now, comb))
                    st.emplace(s);
            }
        }
        if (depth == 6) return;
        for (int nx = start; nx <= 9; ++nx) {
            comb.emplace_back(nx);
            self(self, nx, depth + 1);
            comb.pop_back();
        }
    };
    dfs(dfs, 0, 0);
    ll ans = 0;
    for (auto x: st) ans += x;
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
