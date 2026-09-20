#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n, q; cin >> n >> q;
    vector<int> a(n + 1), f(n + 1), we(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<pair<int, int>>> g(n + 1);
    for(int i = 1; i < n; i++){
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back({v, c}), g[v].push_back({u, c});
    }
    vector<map<int, LL>> mp(n + 1);
    LL ans = 0;
    auto dfs = [&](auto &&self, int u, int p) -> void {
        for(auto [v, w] : g[u]){
            if(v == p) continue;
            mp[u][a[v]] += w;
            we[v] = w, f[v] = u;
            if(a[u] != a[v]) ans += w;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    while(q--){
        int u, x; cin >> u >> x;
        // cerr << u << " " << x << " ]u v \n";
        assert(u <= n);
        ans += mp[u][a[u]] - mp[u][x];
        if(u != 1){
            assert(f[u] <= n && f[u] >= 0);
            mp[f[u]][a[u]] -= we[u];
            mp[f[u]][x] += we[u];
            if(a[f[u]] != a[u]) ans -= we[u];
            
            if(a[f[u]] != x) ans += we[u];

        }
        a[u] = x;
        cout << ans << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while(T--)
    {solve();} return 0;
}