#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = int(1e5) + 10;
int C[N], sz[N];
LL f[N], r[N];
vector<vector<pair<int, int>>> g;
void dfs(int u, int p)
{
    // f[u] : u 的子树里的点都走到 u 的 cost
    sz[u] = C[u];
    for(auto [v, w] : g[u]){
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        f[u] += f[v] + 1LL * sz[v] * w;
    }
    // cerr << u << " " << f[u] << '\n';
}
void dfs1(int u, int p)
{
    // 除了子树里的点， 其他的点走到u，一定要经过它的父节点
    // r[u] 表示，所有点走到u的答案
    // 那么 r[v] = r[u] - w * f[v]
    for(auto [v, w] : g[u]){
        if(v == p) continue;
        r[v] = r[u] + (sz[1] - 2LL * sz[v]) * w;
        dfs1(v, u);
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    g.assign(n + 1, vector<pair<int, int>>());
    for(int i = 1; i <= n; i++)
        cin >> C[i];
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    r[1] = f[1];
    // cerr << f[1] << '\n';
    dfs1(1, 0);
    cout << *min_element(r + 1, r + n + 1) << '\n';
    return 0;
}