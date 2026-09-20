#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = int(5e5) + 10;
constexpr int M = int(2e6) + 10;
int dfn[N], low[N], tot;
int head[N], nxt[M << 1], to[M << 1], ecnt = 2;
bool bz[M << 1];
int vis_bcc[N];
vector<vector<int>> bcc;
void add(int u, int v){
    nxt[ecnt] = head[u], head[u] = ecnt, to[ecnt++] = v;
}
void tarjan(int u, int in)
{
    dfn[u] = low[u] = ++tot;
    for(int e = head[u]; e; e = nxt[e]){
        int v = to[e];
        if(!dfn[v]){
            tarjan(v, e);
            if(dfn[u] < low[v]) bz[e] = bz[e ^ 1] = true;
            low[u] = min(low[v], low[u]);
        }else if(e != (in ^ 1))
            low[u] = min(low[u], dfn[v]);
    }
}
void dfs(int u, int id)
{
    vis_bcc[u] = id, bcc[id - 1].push_back(u);
    for(int e = head[u]; e; e = nxt[e]){
        int v = to[e];
        if(vis_bcc[v] || bz[e]) continue;
        dfs(v, id);
    }
}
void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        if(u == v) continue;
        add(u, v), add(v, u);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) tarjan(i, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!vis_bcc[i]){
            bcc.push_back(vector<int>());
            dfs(i, ++ans);
        }
    }
    cout << ans << '\n';
    for(auto v : bcc){
        cout << v.size() << " ";
        for(auto x : v)
            cout << x << " ";
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}