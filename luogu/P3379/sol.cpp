// Date: 2025-03-07
// Time: 16:57:35

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> adj(n + 1, vector<int>());
    // vector<vector<pair<int, int>>>adj(n+1,vector<pair<int,int>>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dep(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(25));
    auto dfs = [&](auto&& self, int u) -> void {
        dep[u] = dep[f[u][0]] + 1;
        for (int i = 1; i < 25; i++) {
            f[u][i] = f[f[u][i-1]][i - 1];
        }
        for (auto v : adj[u]) {
            if (v == f[u][0])
                continue;
            f[v][0] = u;
            self(self, v);
        }
    };
    dfs(dfs, s);
    auto lca = [&](int x, int y) {
        if (dep[x] < dep[y])
            swap(x, y);
        for (int i = 0, z = dep[x] - dep[y]; z; i++, z >>= 1) {
            if (z & 1)
                x = f[x][i];
        }
        if (x == y)
            return x;
        for (int i = 24; i >= 0 && x!=y ; i--) {
            if (f[x][i] != f[y][i]) {
                x = f[x][i], y = f[y][i];
            }
        }
        return f[x][0];
    };
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cerr<<(2<<24);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}