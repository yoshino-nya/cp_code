#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = int(2e5) + 10;
int a[N], n, m, V;
int head[N], nxt[N << 2], to[N << 2], ecnt;
int dfn[N], low[N], vis_bcc[N], tot;
bool bz[N << 2];
int col[N];
constexpr int mod = 998244353;
vector<vector<int>> bcc;
void add(int u, int v)
{
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
            low[u] = min(low[u], low[v]);
        }else if(e != (in ^ 1))
            low[u] = min(low[u], dfn[v]);
    }
}
void dfs(int u, int id)
{
    // assert(id - 1 < bcc.size());
    vis_bcc[u] = id, bcc[id - 1].push_back(u);
    for(int e = head[u]; e; e = nxt[e]){
        int v = to[e];
        if(vis_bcc[v] || bz[e]) continue;
        dfs(v, id);
    }
}
bool check(int u, int f)
{
    if(col[u] != -1) return col[u] == f;
    // cerr << u << " " << f << " " << vis_bcc[u] << '\n';
    col[u] = f;
    for(int e = head[u]; e; e = nxt[e]){
        int v = to[e];
        if(vis_bcc[u] == vis_bcc[v] && !check(v, f ^ 1))
            return false;
    }
    return true;
}
void solve()
{
    cin >> n >> m >> V;
    ecnt = 2, tot = 0;
    for(int i = 1; i <= n; i++)
        cin >> a[i], col[i] = -1;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        add(u, v), add(v, u);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) tarjan(i, 0);
    for(int i = 1; i <= n; i++)
        if(!vis_bcc[i]){
            bcc.push_back(vector<int> ());
            dfs(i, bcc.size());
        }
    int ans = 1;
    for(auto v : bcc){
        int val = -1;
        for(auto u : v){
            if(a[u] == -1) continue;
            if(val == -1) val = a[u];
            else if(val != a[u]){
                ans = 0;
                break;
            }
        }
        bool f = check(v[0], 0);
        // cerr << f << '\n';
        if(f){
            if(val == -1)
                ans = 1LL * ans * V % mod;
        }else if(val > 0)
            ans = 0;
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; i++)
        vis_bcc[i] = head[i] = dfn[i] = low[i] = 0;
    for(int e = 2; e < ecnt; e++)
        bz[e] = false, nxt[e] = 0;
    bcc.clear();
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}