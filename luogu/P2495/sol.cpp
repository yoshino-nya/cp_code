#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 250000 + 1;
constexpr int inf = int(1e9);
vector<pair<int, int>> g[N], vg[N];
LL dp[N];
int tot, fa[N][21], we[N][21], dep[N], dfn[N];
bool have[N];
void dfs1(int u, int p)
{
    dfn[u] = ++tot;
    dep[u] = dep[p] + 1;
    for(int i = 1; i <= 20; i++){
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        we[u][i] = min(we[u][i - 1], we[fa[u][i - 1]][i - 1]);
    }
    for(auto [v, w] : g[u]){
        if(v == p) continue;
        fa[v][0] = u;
        we[v][0] = w;
        dfs1(v, u);
    }
}
int lca(int x, int y)
{
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 0, z = dep[x] - dep[y]; z; i++, z >>= 1){
        if(z & 1)
            x = fa[x][i];
    }
    if(x == y) return x;
    for(int i = 20; i >= 0; i--){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}
int get(int x, int y)
{
    if(dep[x] < dep[y]) swap(x, y);
    int res = inf;
    for(int i = 0, z = dep[x] - dep[y]; z; i++, z >>= 1){
        if(z & 1)
            res = min(res, we[x][i]), x = fa[x][i];
    }
    return res;
}
void build(vector<int> p)
{
    int k = p.size();
    for(auto x : p)
        have[x] = true;
    ranges::sort(p, [&](int x, int y){return dfn[x] < dfn[y];});
    for(int i = 0; i + 1 < k; i++){
        p.push_back(lca(p[i], p[i + 1]));
    }
    ranges::sort(p, [&](int x, int y){return dfn[x] < dfn[y];});
    p.erase(unique(p.begin(), p.end()), p.end());
    for(int i = 0; i + 1 < p.size(); i++){
        int L = lca(p[i], p[i + 1]);
        int w = get(L, p[i + 1]);
        vg[L].push_back({p[i + 1], w});
    }
    if(p[0] != 1) vg[1].push_back({p[0], get(1, p[0])});
}
void dfs2(int u)
{
    if(have[u]){
        dp[u] = inf;
    }else{
        for(auto [v, w] : vg[u]){
            dfs2(v);
            dp[u] += min(dp[v], w + 0ll);
        }
    }
    for(auto [v, _] : vg[u])
        dp[v] = 0, vg[v].clear();
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs1(1, 0);
    int m;
    cin >> m;
    while(m--){
        int k; cin >> k;
        vector<int> p(k);
        for(int i = 0; i < k; i++)
            cin >> p[i];
        build(p);
        dfs2(1);
        cout << dp[1] << '\n';
        for(auto x : p) have[x] = false;
        vg[1].clear();
        dp[1] = 0;
    }
    return 0;
}