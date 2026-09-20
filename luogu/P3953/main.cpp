#include <bits/stdc++.h>
using namespace std;
using LL = long long;

vector<vector<pair<int, int>>> g, g1;
vector<int> dis;
vector<vector<int>> dp;
int n, m, k, mod;
bool vis[100010][55];
struct node{
    int dis, id;
};
bool flag;
int dfs(int u, int kk)
{
    // dis[v] + nk + w = dis[u] + kk 
    // nk = dis[u] + kk - dis[v] - w
    if(vis[u][kk]){
        flag = true; return 0;
    }
    if(dp[u][kk] != -1) return dp[u][kk];
    vis[u][kk] = true;
    dp[u][kk] = 0;
    for(auto [v, w] : g1[u]){
        LL nk = 0ll + dis[u] + kk - w - dis[v];
        if(nk < 0 || nk > k) continue;
        dp[u][kk] = (dp[u][kk] + dfs(v, nk)) % mod;
        if(flag){
            vis[u][kk] = false;
            return 0;
        }
    }
    if(u == 1 && kk == 0) dp[u][kk] = 1;
    vis[u][kk] = false;
    return dp[u][kk];
}
void solve()
{
    cin >> n >> m >> k >> mod;
    g = g1 = vector<vector<pair<int, int>>> (n + 1);
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g1[v].push_back({u, w});
    }
    // vector<int> dis(n + 1, INT_MAX);
    dis = vector<int> (n + 1, int(1e9));
    dis[1] = 0;
    auto cmp = [&](node x, node y){
        return x.dis > y.dis;
    };
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    pq.push({0, 1});
    while(!pq.empty()){
        auto [dist, u] = pq.top(); pq.pop();
        // cerr << dist << " " << u << '\n';
        if(dist > dis[u]) continue;
        for(auto [v, w] : g[u]){
            if(dis[v] > dist + w){
                dis[v] = dist + w;
                pq.push({dis[v], v});
            }
        }
    }
    if(dis[n] == int(1e9))
        cout << "0\n";
    else{
        int ans = 0;
        flag = false;
        dp = vector<vector<int>> (n + 1, vector<int> (k + 1, -1));
        for(int i = 0; i <= k; i++){
            ans = (ans + dfs(n, i)) % mod;
            if(flag){
                ans = -1; break;
            }
        }
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}