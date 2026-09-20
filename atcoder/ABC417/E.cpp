#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> vis(n + 1);
    vector<int> son(n + 1);
    for(int i = 1; i <= n; i++)
        ranges::sort(g[i]);
    auto dfs = [&](auto &&self, int u) -> bool {
        if(u == y) return true;
        vis[u] = true;
        // ranges::sort(g[u]);
        for(auto v : g[u]){
            if(vis[v]) continue;
            if(self(self, v)){
                son[u] = v;
                return true;
            }
        }
        // vis[u] = false;
        return false;
    };
    dfs(dfs, x);
    int cur = x;
    while(cur){
        cout << cur << " ";
        // if(cur == y) break;
        cur = son[cur];
    }
    cout << '\n';
}
int main()
{
    // freopen("1.in", "r", stdin), freopen("1.out", "w", stdout), freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while(T--)
    {solve();} return 0;
}