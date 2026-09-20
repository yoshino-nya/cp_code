#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> g(n + 1);
    vector<array<ll, 2>> dp(n + 1);
    dp[1][0] = 0, dp[1][1] = a[1];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](auto &&self, int u, int pre) -> void {
        for (auto v : g[u]) {
            if (v == pre) continue;
            // 最小值，av - dpu,max, av
            dp[v][0] = min(a[v] - dp[u][1], a[v]);
            dp[v][1] = max(a[v], a[v] - dp[u][0]);
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    for (int i = 1; i <= n; i++)
        cout << dp[i][1] << " \n"[i == n];
}

int main() {
    // freopen("1.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}