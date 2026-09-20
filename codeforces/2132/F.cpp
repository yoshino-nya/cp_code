#include<bits/stdc++.h>
using namespace std;

constexpr int N = int(2e5) + 10;
constexpr int inf = int(1e9);
int head[N], from[N * 2], to[N * 2], nxt[N * 2], totEdge = 1;
int dfn[N], low[N], tot;
int bridge[N * 2];
int lst[N];
bool vis[N];
int n;
void add(int u, int v)
{
    nxt[totEdge] = head[u];
    head[u] = totEdge;
    from[totEdge] = u;
    to[totEdge] = v;
    ++totEdge;
}
void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++tot;
    for(int e = head[u]; e; e = nxt[e]){
        int v = to[e];
        if(!dfn[v]){
            tarjan(v, u);
            // cerr << low[v] << '\n';
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]){
                // cerr << v << " " << u << '\n';
                bridge[e] = 1;
            }
        }else if(v != fa)
            low[u] = min(low[u], dfn[v]);
        
    }
}
void dfs(int u)
{
    if(lst[n]){
        return;
    }
    vis[u] = true;
    for(int e = head[u]; e; e = nxt[e]){
        int v = to[e];
        if(!vis[v]){
            lst[v] = e;
            dfs(v);
        }
    }
    vis[u] = false;
}
void solve()
{
    int m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        add(u, v), add(v, u);
    }
    tarjan(1, 0);
    dfs(1);
    queue<int> q;
    vector<int> dis(n + 1, inf), ans(n + 1, inf);
    for(int e = lst[n]; e;){
        int u = from[e], v = to[e];
        if(bridge[e]){
            dis[u] = dis[v] = 0;
            ans[u] = min(ans[u], (e + 1) / 2);
            ans[v] = min(ans[v], (e + 1) / 2);
        }
        e = lst[u];
    }
    for(int i = 1; i <= n; i++){
        if(!dis[i]) q.push(i);
    }
    bool ok = q.empty();
    while(!q.empty()){
        int k = q.front(); q.pop();
        for(int e = head[k]; e; e = nxt[e]){
            int v = to[e];
            if(dis[v] > dis[k] + 1){
                dis[v] = dis[k] + 1;
                ans[v] = ans[k];
                q.push(v);
            }else if(dis[v] == dis[k] + 1){
                ans[v] = min(ans[v], ans[k]);
            }
        }
    }
    int Q; cin >> Q;
    while(Q--){
        int x; cin >> x;
        if(ok) cout << "-1 ";
        else cout << ans[x] << " ";
    }
    cout << "\n";
    for(int i = 1; i < totEdge; i++){
        from[i] = to[i] = nxt[i] = bridge[i] = 0;
    }
    for(int i = 1; i <= n; i++)
        lst[i] = dfn[i] = head[i] = 0;
    totEdge = 1, tot = 0;
}   
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}