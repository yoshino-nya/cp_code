// ABC419: G
#include<bits/stdc++.h>
using namespace std;

constexpr int N = int(2e5) + 50;
int head[N], from[N << 1], to[N << 1], nxt[N << 1], totEdges = 1;
int dep[N], dfn[N], f[N][21], tot;
bool vis[N], edges[N << 1];
int ans[N];
int n;
vector<pair<int, int>> g[N];
void addEdge(int u, int v)
{
    nxt[totEdges] = head[u];
    head[u] = totEdges;
    from[totEdges] = u;
    to[totEdges] = v;
    ++totEdges;
}
void dfs(int u)
{
    // cerr << u << '\n';
    vis[u] = true;
    dfn[u] = ++tot;
    dep[u] = dep[f[u][0]] + 1;
    for(int i = 1; i <= 20; ++i)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(vis[v]) continue;
        edges[i] = true;
        f[v][0] = u;
        dfs(v);
    }
}
int lca(int x, int y)
{
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 0, z = dep[x] - dep[y]; z; i++, z >>= 1)
        if(z & 1) x = f[x][i];
    if(x == y) return x;
    for(int i = 20; i >= 0; i--)
        if(f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}
void build(vector<int> &p)
{
    p.push_back(1), p.push_back(n);
    ranges::sort(p, [&](int x, int y){return dfn[x] < dfn[y];});
    p.erase(unique(p.begin(), p.end()), p.end());
    for(int i = 0, k = p.size(); i + 1 < k; i++)
        p.push_back(lca(p[i], p[i + 1]));
    ranges::sort(p, [&](int x, int y){return dfn[x] < dfn[y];});
    p.erase(unique(p.begin(), p.end()), p.end());
    for(int i = 0; i + 1 < p.size(); i++){
        int L = lca(p[i], p[i + 1]);
        int w = dep[p[i + 1]] - dep[L];
        g[L].push_back({p[i + 1], w});
        g[p[i + 1]].push_back({L, w});
    }
}
void dfs1(int u, int len)
{
    if(u == n){
        ans[len]++;
        return;
    }
    vis[u] = false;
    for(auto [v, w] : g[u]){
        if(!vis[v]) continue;
        dfs1(v, len + w);
    }
    vis[u] = true;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        addEdge(u, v), addEdge(v, u);
    }
    dfs(1);
    vector<int> p;
    for(int i = 1; i < totEdges; i += 2){
        if(!(edges[i] | edges[i + 1])){
            int u = from[i], v = to[i];
            g[u].push_back({v, 1});
            g[v].push_back({u, 1});
            p.push_back(u), p.push_back(v);
        }
    }
    build(p);
    dfs1(1, 0);
    for(int i = 1; i < n; i++)
        cout << ans[i] << " \n" [i == n - 1];
    return 0;
}