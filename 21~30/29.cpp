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
constexpr int N = 1e2;

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void bf() {
}

/*
 Problem 29: Distinct Powers
 link: https://projecteuler.net/problem=29
 标签: 质因数分解, 幂, 去重, 集合
 思路:
 1. 对每个 a∈[2,100]，质因数分解 a=∏pᵢ^{eᵢ}
 2. 计算 k=gcd(e₁,e₂,…)，最简底 c=∏pᵢ^{(eᵢ/k)}，使 a=c^k
 3. 对每个 b∈[2,100]，a^b=(c^k)^b=c^{k·b}，用 (c, k·b) 对唯一性去重
 4. 最终集合大小即为不同 a^b 的个数
 时间复杂度: O(A·logA + A·B)  (A=B=99)
 空间复杂度: O(A·B)
*/
void solve() {
    vector<int> spf(N + 1);
    std::ranges::iota(spf, 0);
    for (int i = 2; i * i <= N; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
    std::set<PII> s;
    for (int i = 2; i <= N; ++i) {
        int x = i;
        std::map<int, int> cnt;
        while (x > 1) {
            int p = spf[x];
            while (x % p == 0) {
                x /= p;
                ++cnt[p];
            }
        }
        int k = 0;
        for (auto &[x,y]: cnt) k = std::gcd(k, y);
        int c = 1;
        for (auto &[x,y]: cnt) {
            int e = y / k;
            while (e--) c *= x;
        }
        for (int b = 2; b <= N; ++b) {
            s.emplace(c, k * b);
        }
    }
    cout << s.size() << "\n";
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
