#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 300000 + 5;
vector<int> g[N], vg[N];
int tot, dep[N], dfn[N], f[N][21], siz[N], sum[N], ;
bool have[N];
void dfs(int u, int p)
{
    dfn[u] = ++tot, dep[u] = dep[p] + 1, siz[u] = 1;
    for(int i = 1; i <= 20; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for(auto v : g[u]){
        if(v == p) continue;
        f[v][0] = u;
        self(self, v, u);
        siz[u] += siz[v];
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
void build(vector<int> p)
{
    ranges::sort(p, [&](int x, int y){dfn[x] < dfn[y];});
    for(int i = 0, k = p.size(); i + 1 < k; i++){
        p.push_back(lca(p[i], p[i + 1]));
    }
    ranges::sort(p, [&](int x, int y){dfn[x] < dfn[y];});
    p.erase(unique(p.begin(), p.end()));
    for(int i = 0; i + 1 < p.size(); i++){
        vg[lca(p[i], p[i + 1])].push_back(p[i + 1]);
    }
    return p[0];
}
void dfs2(int u)
{
    if(have[u]){
        //子树里面最近的
        for(auto v : vg[u]){
            
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        sum[i] = 1;
    int q; cin >> q;
    while(q--){
        int m; cin >> m;
        vector<int> p(m);
        for(int i = 0; i < m; i++){
            cin >> p[i];
            have[p[i]] = true;
        }
        build(p);
        
        for(auto x : p)
            have[x] = false, sum[x] = 1;
    }
    return 0;
}