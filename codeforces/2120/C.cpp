#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; ll m;
    cin >> n >> m;
    ll now = 1LL * (1 + n) * n / 2;
    if(m > now || m < n){
        cout << "-1\n";
        return;
    }
    int root = 1;
    vector<pair<int, int>> edges;
    vector<vector<int>> g(n + 1);
    for(int i = n; i >= 1; i--){
        if(now == m){
            root = i;
            break;
        }
        assert(now > m);
        // cerr << now << '\n';
        if(i - 1 <= now - m){
            now -= i - 1;
            edges.push_back({1, i});
        }else{
            // 看 i 需要和谁连
            int x = i - (now - m);
            edges.push_back({x, i});
            now -= i - x;
            // now = m;
            assert(now == m);
            // i - x = now - m
            // x = i - (now - m)
        }
        // cerr << edges.size() << '\n';
    }
    for(int i = root - 1; i >= 1; i--)
        edges.push_back({root, i});
    cout << root << '\n';
    for(auto [u, v] : edges){
        cout << u << " " << v << '\n';
        // 2 + 2 + 1 + 1
        // g[u].push_back(v);
        // g[v].push_back(u);
    }
    // vector<int> x(n + 1, n + 1);
    // long long ans = 0;
    // auto dfs = [&](auto &&self, int u, int pre) -> void{
    //     x[u] = min(x[pre], u);
    //     ans += x[u];
    //     for(auto v : g[u]){
    //         if(v == pre) continue;
    //         self(self, v, u);
    //     }
    // };
    // dfs(dfs, root, 0);
    // // assert(ans == m);
    // cerr << ans << '\n';
}
int main()
{
    // freopen("1.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while(T--)
    solve();
    return 0;
}