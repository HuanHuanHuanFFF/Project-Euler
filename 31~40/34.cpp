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

/* Problem 34: Digit Factorials
 * link: https://projecteuler.net/problem=34
 * 标签: 上界估计, 数位枚举, 阶乘预处理, 组合计数
 * 思路:
 *  1) 上界：d 位数各位阶乘和最大为 d*9!。当 10^(d-1) > d*9! 时，不可能存在 d 位解。
 *     计算得 d ≤ 7，因此只需枚举到 LIM = 7*9! (= 2,540,160)。
 *  2) bf()：直接枚举 10..LIM。预处理 0..9 的阶乘，函数 df(x) 计算各位阶乘和，
 *     若 df(i)==i 则累加答案。题面排除 1、2，因此从 10 开始。
 *  3) solve()：按“数字计数（多重集合）”枚举。枚举 0..9 每个数字出现次数 cnt[d]，
 *     总使用位数 used ≤ max(=7)。计算 sum = Σ cnt[d]*d!，再把 sum 拆位得到计数 c[d]。
 *     若 c[d] == cnt[d]（位数一致且无前导零），且 used ≥ 3（排除 1、2），则把 sum 加入答案。
 * 时间复杂度:
 *  - bf():  O(LIM * 位数) ≈ 2.54e6 * 7
 *  - solve(): 近似 Σ_{d=2..7} C(d+9,9) ≈ 1e4 状态，每状态 O(位数) 检验
 * 空间复杂度: O(1)
 */

/* ------------------------------ 直接枚举版 bf() ------------------------------
 * 步骤:
 *  1. 预处理 fac[0..9] 与 p10[i]=10^i；
 *  2. 用不等式 10^i - 1 > i*9! 找到最大位数 max（本题应为 7）；
 *  3. lim = max * 9!，枚举 i=10..lim，若 i 的各位阶乘和 df(i) 等于 i 则加入答案。
 */
void bf() {
    vector<ll> fac(10, 1), p10(16, 1);
    for (ll i = 1; i <= 9; ++i) fac[i] = i * fac[i - 1];
    for (int i = 1; i < 15; ++i) p10[i] = 10 * p10[i - 1];
    ll ans = 0, max = 1;
    for (int i = 2; i < 15; ++i) {
        if (p10[i] - 1 > fac[9] * i) {
            max = i - 1;
            break;
        }
    }
    auto df = [&](ll x) {
        ll sum = 0;
        while (x) {
            sum += fac[x % 10];
            x /= 10;
        }
        return sum;
    };
    ll lim = max * fac[9];
    for (ll i = 10; i <= lim; ++i) {
        if (i == df(i)) ans += i;
    }
    cout << ans << "\n";
}

/* -------------------------- 数字计数（多重集合）版 solve() --------------------------
 * 思想：不枚举具体数，而是枚举“每个数字用了几次”。对每种计数组合:
 *   sum = Σ cnt[d]*d!；把 sum 拆位得到计数 c[d]，若 c==cnt 且 used ≥ 3，则 sum 为一个解。
 * 细节:
 *   - used ≤ max（即 ≤7），避免无意义的更高位；
 *   - used ≤ 2 直接丢弃（题面排除 1、2）；
 *   - sum==0 不可能（仅当 all cnt[d]=0），直接丢弃；
 *   - c 与 cnt 完全相等即隐含“位数一致、无前导零”，无需额外判断。
 */
void solve() {
    vector<ll> fac(10, 1), p10(16, 1);
    for (ll i = 1; i <= 9; ++i) fac[i] = i * fac[i - 1];
    for (int i = 1; i < 15; ++i) p10[i] = 10 * p10[i - 1];
    ll ans = 0, max = 1;
    for (int i = 2; i < 15; ++i) {
        if (p10[i] - 1 > fac[9] * i) {
            max = i - 1;
            break;
        }
    }
    vector<int> cnt(10, 0);
    auto dfs = [&](auto &&self, int now, int used, int sum)-> void {
        if (used > max) return;
        if (now == 10) {
            if (used <= 2 || sum == 0) return;
            vector<int> c(10, 0);
            int s = sum;
            while (s) { ++c[s % 10], s /= 10; };
            for (int i = 0; i < 10; ++i) {
                if (cnt[i] != c[i]) return;
            }
            ans += sum;
            return;
        }
        for (int i = 0; i <= max - used; ++i) {
            cnt[now] = i;
            self(self, now + 1, used + i, sum + i * fac[now]);
        }
    };
    dfs(dfs, 0, 0, 0);
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
