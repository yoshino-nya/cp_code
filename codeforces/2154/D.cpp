#include<bits/stdc++.h>
using namespace std;

using LL = long long;
void solve()
{
    int n; cin >> n;
    vector<vector<int>> g(n + 1, vector<int> ());
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> fa(n + 1), ch(n + 1), dep(n + 1);
    auto init = [&](auto &&self, int u, int p) -> void {
        fa[u] = p, dep[u] = dep[p] + 1;
        for(auto v : g[u]){
            if(v == p) continue;
            ch[u]++;
            self(self, v, u);
        }
    };
    init(init, n, 0);
    vector<vector<int>> ans;
    vector<vector<int>> leaves(2, vector<int> ());
    for(int i = 1; i < n; i++)
        if(ch[i] == 0) leaves[dep[i] & 1].push_back(i);
    auto dfs = [&](auto &&self, int col) -> void {

        if(!leaves[col ^ 1].empty()){
            int k = leaves[col ^ 1].back();
            leaves[col ^ 1].pop_back();
            ans.push_back({2, k});
            if(--ch[fa[k]] == 0 && fa[k] != n)
                leaves[col].push_back(fa[k]);
        }
        ans.push_back({1});
        if(leaves[0].empty() && leaves[1].empty()) return;
        self(self, col ^ 1);
    };
    dfs(dfs, dep[1] & 1);
    cout << ans.size() << "\n";
    for(auto v : ans){
        for(auto x : v) cout << x << " ";
        cout << "\n";
    }
}
int main()
{
// #define LOCAL
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}