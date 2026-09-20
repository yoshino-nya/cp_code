// 一定只用看长度为2和3的
//  Date: 2025-03-03
//  Time: 19:28:46

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    string s(n, '0');
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<set<int>> g(n + 1);
    // vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (a[u] == a[v]) {
            s[a[u] - 1] = '1';
        }
        if (g[u].contains(a[v])) {
            s[a[v] - 1] = '1';
        } else
            g[u].insert(a[v]);
        if (g[v].contains(a[u])) {
            s[a[u] - 1] = '1';
        } else
            g[v].insert(a[u]);
        // g[u].insert(a[v]), g[v].insert(a[u]);
    }
    // auto dfs = [&](auto&& self, int u, int pre, int val, int cnt, int len) -> void {
    //     if ((s[val - 1] == '1') || (pre && cnt > 0)) {
    //         // cerr << pre << " " << u << " " << val << '\n';
    //         s[val - 1] = '1';
    //         return;
    //     }
    //     if (len == 3)
    //         return;
    //     for (auto v : adj[u]) {
    //         if (v == pre)
    //             continue;
    //         if (a[v] == val)
    //             self(self, v, u, val, cnt + 1, len + 1);
    //         else
    //             self(self, v, u, val, cnt - 1, len + 1);
    //     }
    // };
    // for (int i = 1; i <= n; i++) {
    //     dfs(dfs, i, 0, a[i], 1, 0);
    // }
    cout << s << '\n';
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