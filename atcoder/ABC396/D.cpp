// Date: 2025-03-08
// Time: 20:19:40

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1, vector<pair<ll, ll>>());
    for (int i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    ll ans = 2e18;
    auto dfs = [&](auto&& self, int u, int s, ll res) -> void {
        if (u == n) {
            // cerr << s << " ";
            if (!s)
                ans = min(ans, res);
            return;
        }
        for (auto [v, w] : adj[u]) {
            if (s >> (v - 1) & 1) {
                self(self, v, s ^ (1 << (v - 1)), res ^ w);
            }
        }
    };
    for (int i = 1; i < (1 << n); i++) {
        if (i % 2 == 0)
            continue;
        // cerr<<i<<" "<<(i>>(n-1)&1)<<'\n';
        if (!(i >> (n - 1) & 1))
            continue;
        // cerr << i << "\n";
        // 1111
        dfs(dfs, 1, i - 1, 0);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cerr<<(1LL<<60)<<'\n';
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}