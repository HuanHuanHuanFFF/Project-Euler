#include <bits/stdc++.h>

using std::cin;
using std::cout;
using ll = long long;
using ull = unsigned long long;

signed main() {
    ll ans = 0;
    for (int i = 0; i < 1000; ++i) {
        if (i % 3 == 0 || i % 5 == 0) ans += i;
    }
    cout << ans;
    return 0;
}
