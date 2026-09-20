#include<bits/stdc++.h>
using namespace std;

constexpr int N = 110;
int n, m, w[N], v[N], dp[N][510];
int head[N], nxt[N], to[N], ecnt = 1;
int dfn[N], low[N], instk[N], tot;
int scc[N], sz[N], sc;
vector<int> stk;
vector<vector<int>> g;
int nv[N], nw[N];
void add(int u, int v)
{
    nxt[ecnt] = head[u];
    head[u] = ecnt;
    to[ecnt] = v;
    ++ecnt;
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++tot;
    instk[u] = 1, stk.push_back(u);
    for(int e = head[u]; e; e = nxt[e]){
        int v = to[e];
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
            scc[k] = sc, sz[sc]++;
            nv[sc] += v[k], nw[sc] += w[k];
            instk[k] = 0;
        }
    }
}
void dfs(int u)
{
    for(int x = nw[u]; x <= m; x++)
        dp[u][x] = nv[u];
    for(auto v : g[u]){
        dfs(v);
        for(int x = m; x >= nw[u]; x--){
            for(int y = 0; y + x <= m; y++)
                dp[u][x + y] = max(dp[u][x + y], dp[u][x] + dp[v][y]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++){
        int d; cin >> d;
        if(d) add(d, i);
    }
    for(int i = 1; i <= n; i++){
        if(!dfn[i]) tarjan(i);
    }
    g.assign(sc + 1, vector<int>());
    vector<int> deg(sc + 1);
    for(int i = 1; i <= n; i++){
        for(int e = head[i]; e; e = nxt[e]){
            int v = to[e];
            if(scc[i] != scc[v]){
                g[scc[i]].push_back(scc[v]);
                deg[scc[v]]++;
            }
        }
    }
    for(int i = 1; i <= sc; i++){
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    }
    for(int i = 1; i <= sc; i++){
        if(deg[i] == 0){
            dfs(i);
            for(int x = m; x >= 0; x--){
                for(int y = 0; y + x <= m; y++)
                    dp[0][x + y] = max(dp[0][x + y], dp[0][x] + dp[i][y]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++) ans = max(ans, dp[0][i]);
    cout << ans << '\n';
    return 0;
}