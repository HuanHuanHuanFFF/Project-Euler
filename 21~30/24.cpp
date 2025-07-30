//
// Created by 幻 on 2025/7/29.
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
constexpr int N = 3628800;

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

/* 024-Lexicographic permutations
 * link: https://projecteuler.net/problem=24
 * 标签: 全排列, 字典序, 阶乘进制, next_permutation, DFS
 * 思路:
 *   - 题意: 10 个数字 0‒9 的 1000000-th (1e6) 字典序排列
 *   - 方法一 bf(): DFS 生成 10! 全排列再取下标, 复杂度 O(10!)
 *   - 方法二 solve(): 调用 std::next_permutation 前进 999999 次, 复杂度 O(k·n)
 *   - 方法三 solve2(): 阶乘进制 kth_permutation_with_dup, 逐位计算系数,
 *                     复杂度 O(n²) (删除字符耗时), 空间 O(n)
 *   - 推荐用方法三, 常数最小且不依赖 STL 迭代
 * 时间复杂度:
 *   bf   O(10!)      (仅演示, 实际不可取)
 *   solve O(k·n)     (k=1e6, n=10)
 *   solve2 O(n²)     (n=10)
 * 空间复杂度:
 *   bf   O(10!)
 *   solve O(1)
 *   solve2 O(n)
 */
void bf() {
    vector<string> ss;
    ss.reserve(N);
    vector<bool> used(10, false);
    char a[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    auto dfs = [&](auto &self, string s, int cnt)-> void {
        if (cnt == 10) {
            ss.emplace_back(s);
            return;
        }
        for (int i = 0; i < 10; ++i) {
            if (!used[i]) {
                used[i] = true;
                self(self, s + a[i], cnt + 1);
                used[i] = false;
            }
        }
    };
    dfs(dfs, "", 0);
    cout << ss[1000000 - 1] << "\n";
}

void solve() {
    string s = "0123456789";
    for (int i = 1; i < 1000000; ++i) {
        std::ranges::next_permutation(s);
    }
    cout << s << "\n";
}

string kth_permutation_with_dup(string s, ll k) {
    int n = s.size();
    // 1. 统计每个字符的频次
    std::map<char, int> freq;
    for (char c: s) ++freq[c];
    // 2. 预计算阶乘
    vector<ll> fact(n + 1, 1);
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
    // 3. 构造答案
    string ans;
    for (int pos = 0; pos < n; ++pos) {
        ll rem = n - pos - 1;
        for (auto &[c, cnt]: freq) {
            if (cnt == 0) continue;
            // 暂减一个 c，计算以 c 开头的排列数
            cnt--;
            ll tot = fact[rem];
            for (auto &[_c, f]: freq) tot /= fact[f];
            if (k < tot) {
                ans.push_back(c);
                break; // 确定此位字符为 c
            }
            // 否则跳过这批，恢复并减去已跳过的数量
            k -= tot;
            cnt++;
        }
    }
    return ans;
}

void solve2() {
    string digits = "0123456789";
    int k = 1000000 - 1;
    string ans = kth_permutation_with_dup(digits, k);
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
    solve2();
    auto t4 = get_now();
    cout << ms_dis(t4, t3) << "ms\n";
    return 0;
}
