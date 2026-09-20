#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 20005;
LL G[N];
int dep[N], f[N][20];
vector<vector<int>> g;
void init(int u, int p)
{
    dep[u] = dep[p] + 1, f[u][0] = p;
    for(int i = 1; i <= 19; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for(auto v : g[u]){
        if(v == p) continue;
        init(v, u);
    }
}
int lca(int x, int y)
{
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 0, z = dep[x] - dep[y]; z; i++, z >>= 1)
        if(z & 1) x = f[x][i];
    if(x == y) return x;
    for(int i = 19; i >= 0; i--)
        if(f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}
void ins(int p, vector<LL> &v, vector<int> &pos)
{
    LL x = G[p];
    for(int i = 60; i >= 0; i--){
        if(x >> i & 1){
            if(!v[i]){
                v[i] = x;
                pos[i] = p;
                return;
            }
            if(dep[p] > dep[pos[i]])
                swap(x, v[i]), swap(pos[i], p);
            x ^= v[i];
        }
    }
}
vector<vector<int>> pos;
vector<vector<LL>> vec;
void dfs(int u)
{
    // vec[u] = vec[f[u][0]], pos[u] = pos[f[u][0]];
    pos[u] = pos[f[u][0]], vec[u] = vec[f[u][0]];
    ins(u, vec[u], pos[u]);
    for(auto v : g[u]){
        if(v == f[u][0]) continue;
        dfs(v);
    }
}
void solve()
{
    int n, m; cin >> n >> m;
    g = vector<vector<int>> (n + 1);
    vec = vector<vector<LL>> (n + 1, vector<LL> (61));
    pos = vector<vector<int>> (n + 1, vector<int> (61));
    for(int i = 1; i <= n; i++)
        cin >> G[i];
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init(1, 0);
    dfs(1);
    while(m--){
        int x, y; cin >> x >> y;
        int z = lca(x, y);
        vector<LL> v(61);
        for(int i = 60; i >= 0; i--)
            if(dep[pos[x][i]] >= dep[z]) v[i] = vec[x][i];
        for(int i = 60; i >= 0; i--){
            if(dep[pos[y][i]] >= dep[z]){
                LL x = vec[y][i];
                if(!x) continue;
                for(int j = 60; j >= 0; j--){
                    if(x >> j & 1){
                        if(!v[j]){
                            v[j] = x;
                            break;
                        }
                        x ^= v[j];
                    }
                }
            }
        }
        LL ans = 0;
        for(int i = 60; i >= 0; i--)
            if((ans ^ v[i]) > ans) ans ^= v[i];
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}