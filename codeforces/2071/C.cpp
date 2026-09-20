// Date: 2025-02-28
// Time: 23:03:08

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, st, en;
    cin >> n >> st >> en;
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dep(n + 1);
    vector<vector<int>> g(n + 1, vector<int>());
    auto dfs1 = [&](auto&& self, int u, int pre) -> void {
        g[dep[u]].push_back(u);
        for (auto v : adj[u]) {
            if (v == pre)
                continue;
            dep[v] = dep[u] + 1;
            self(self, v, u);
        }
    };
    dfs1(dfs1, en, -1);
    vector<int> ans;
    for (int i = n; i >= 0; i--) {
        for (auto v : g[i])
            ans.push_back(v);
    }
    for (auto x : ans)
        cout << x << " ";
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}