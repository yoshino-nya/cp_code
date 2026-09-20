#include <bits/stdc++.h>
using namespace std;
using LL = long long;

vector<vector<int>> g;
vector<pair<int, int>> edges;
constexpr int N = 10010;
int dfn[N], low[N], instk[N], tot;
int scc[N], A[N], sc, a[N];
vector<int> stk;
void tarjan(int u)
{
    dfn[u] = low[u] = ++tot;
    instk[u] = 1, stk.push_back(u);
    for(auto v : g[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if(instk[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]){
        ++sc;
        for(int k = -1; k != u; ){
            k = stk.back(); stk.pop_back();
            scc[k] = sc, A[sc] += a[k];
            instk[k] = false;
        }
    }
}
void solve()
{
    int n, m; cin >> n >> m;
    g.assign(n + 1, vector<int>()), edges.assign(m, {0, 0});
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        edges[i] = {u, v};
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) tarjan(i);
    g.assign(sc + 1, vector<int>());
    for(auto [u, v] : edges){
        u = scc[u], v = scc[v];
        if(u != v){
            g[u].push_back(v);
        }
    }
    vector<int> dp(sc + 1);
    for(int i = 1; i <= sc; i++){
        dp[i] = A[i];
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    }
    for(int i = sc; i >= 1; i--){
        for(auto v : g[i]){
            dp[v] = max(dp[v], A[v] + dp[i]);
        }
    }
    cout << ranges::max(dp) << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}