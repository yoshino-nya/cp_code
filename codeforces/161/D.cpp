#include<bits/stdc++.h>
using namespace std;
// created: 2025-10-14 09:04:08

using LL = long long;
void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>> g(n + 1);
    vector<vector<LL>> dp(n + 1, vector<LL> (k + 1));
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    LL ans = 0;
    auto dfs = [&](auto &&dfs, int u, int p) -> void {
        dp[u][0] = 1;
        for(int v : g[u]){
            if(v == p) continue;
            dfs(dfs, v, u);
            for(int x = 0; x < k; x++)
                ans += dp[u][x] * dp[v][k - x - 1];
            for(int x = 0; x < k; x++)
                dp[u][x + 1] += dp[v][x];
        }
    };
    dfs(dfs, 1, 0);
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}