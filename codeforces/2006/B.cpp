// Date: 2025-03-05
// Time: 09:30:28

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    long long w;
    cin >> n >> w;
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<vector<int>> f(n + 1, vector<int>());
    vector<int> p(n + 1), cnt(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    auto dfs = [&](auto&& self, int u) -> int {
        int mx = u;
        // cerr<<u<<'\n';
        for (auto v : adj[u]) {
            cnt[mx]++;
            f[v].push_back(mx);
            mx = max(mx, self(self, v));
            cnt[mx]++;
            f[v].push_back(mx);
        }
        return mx;
    };
    dfs(dfs, 1);
    // for(int i=1;i<=n;i++)
    //     cerr<<cnt[i]<<" \n"[i==n];
    // return ;
    long long ans = 0, sum = 0;
    int tot = n;
    for (int z = 1; z < n; z++) {
        int x;
        long long y;
        cin >> x >> y;
        for (auto v : f[x]) {
            cnt[v]--;
            if (!cnt[v]) {
                --tot;
            }
        }
        w -= y;
        ans += 2 * y;
        cout << ans + 1LL * tot * w << ' ';
    }
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