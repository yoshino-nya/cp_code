#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void solve()
{
    // 基本上一模一样 https://codeforces.com/gym/104857/problem/J
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<int> f(n + 1), mn(n + 1, 1e9);
    iota(f.begin() + 1, f.end(), 1);

    auto find = [&](auto &&self, int x) -> int{
        return f[x] == x ? x : f[x] = self(self, f[x]);
    };
    ranges::sort(edges, [](array<int, 3> x, array<int, 3> y){
        return x[2] < y[2];
    });
    int ans = 2e9;
    for(auto [u, v, w] : edges){
        int fu = find(find, u), fv = find(find, v);
        mn[fv] = min(mn[fv], w);
        mn[fu] = min(mn[fu], mn[fv]);
        f[fv] = fu;
        if(find(find, 1) == find(find, n)){
            ans = min(ans, mn[f[1]] + w);
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}