//
// Created by 幻 on 2025/7/28.
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
constexpr int N = 1e5;

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void bf() {
    ll ans = 0;
    string token, line;
    vector<string> names;
    names.reserve(6000);
    freopen("21~30/name.txt", "r",stdin);
    std::getline(cin, line);
    std::istringstream ss(line);
    while (std::getline(ss, token, ',')) {
        names.emplace_back(token.substr(1, token.size() - 2));
    }
    std::ranges::sort(names);
    int idx = 0;
    for (auto &s: names) {
        ll val = 0;
        for (auto &c: s) val += c - 'A' + 1;
        ans += val * ++idx;
    }
    cout << ans << "\n";
}

void solve() {
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
