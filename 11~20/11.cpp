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

// 暴力
signed main() {
    int n = 20;
    vector g(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> g[i][j];
        }
    }
    ll ans = 0;
    int dx[] = {0, 1, 1, -1}, dy[] = {1, 0, 1, 1};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int d = 0; d < 4; ++d) {
                ll now = 1;
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[d] * k, y = j + dy[d] * k;
                    if (x < 1 || x > 20 || y < 1 || y > 20) {
                        now = 0;
                        break;
                    }
                    now *= g[x][y];
                }
                ans = std::max(ans, now);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
