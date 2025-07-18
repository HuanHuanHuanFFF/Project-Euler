//
// Created by 幻 on 2025/7/18.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;

void bf() {
    ll add = 1, now = 0;
    while (true) {
        now += add;
        ++add;
        ll p = now, cnt = 0;
        for (int i = 1; i * i <= p; ++i) {
            if (p % i == 0)
                if (i * i == p) ++cnt;
                else cnt += 2;
        }
        if (cnt >= 500) {
            cout << now << "\n";
            break;
        }
    }
}

constexpr int N = 5e5 + 10;

void solve() {
    // cout << 500 * log(500);
    vector<int> p, spf(N);
    p.reserve((int) N / log(N));
    vector<bool> isp(N, true);
    isp[0] = isp[1] = false;
    for (int i = 2; i < N; ++i) {
        if (isp[i]) {
            spf[i] = i;
            p.emplace_back(i);
        }
        for (auto x: p) {
            if (x * i > N) break;
            isp[x * i] = false;
            spf[x * i] = x;
            if (i % x == 0) break;
        }
    }
    auto getd = [&](ll x) {
        int ans = 1;
        while (x > 1) {
            int f = spf[x], cnt = 0;
            while (x % f == 0) x /= f, ++cnt;
            ans *= (cnt + 1);
        }
        return ans;
    };
    ll n = 1;
    while (true) {
        ll a = (n % 2 == 0 ? n / 2 : n), b = (n % 2 == 0 ? n + 1 : (n + 1) / 2);
        if (getd(a) * getd(b) >= 500) {
            cout << a * b << "\n";
            break;
        }
        ++n;
    }
}

signed main() {
    bf();
    solve();
    return 0;
}
