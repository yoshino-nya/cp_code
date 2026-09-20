#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 200000 + 5;
vector<int> g[N], colors[N];
int w[N], c[N], f[N][21], dep[N], dfn[N], tot, cnt[N], col[N], cutie[N];
void dfs(int u, int p)
{
    dfn[u] = ++tot, dep[u] = dep[p] + 1;
    for(int i = 1; i <= 20; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for(auto v : g[u]){
        if(v == p) continue;
        f[v][0] = u;
        dfs(v, u);
    }
}
int lca(int x, int y)
{
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 0, z = dep[x] - dep[y]; z; i++, z >>= 1)
        if(z & 1) x = f[x][i];
    if(x == y) return x;
    for(int i = 20; i >= 0; i--){
        if(f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}
set<int> build(vector<int>& p)
{
    set<int> st;
    ranges::sort(p, [&](int x, int y){return dfn[x] < dfn[y];});
    for(int i = 0, k = p.size(); i + 1 < k; i++)
        st.insert(lca(p[i], p[i + 1]));
    return st;
}
void dfs1(int u, int cc)
{
    if(c[u]) cc = c[u];
    else c[u] = cc;
    for(auto v : g[u]){
        if(v == f[u][0]) continue;
        dfs1(v, cc);
    }
}
void solve()
{
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 0; i <= k; i++) colors[i].clear();
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        colors[c[i]].push_back(i);
        g[i].clear(), cnt[i] = 0, col[i] = 0, cutie[i] = 0;
    }
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(colors[0].size() == n){
        cout << "0\n";
        for(int i = 1; i <= n; i++)
            cout << "1 ";
        cout << '\n';
        return;
    }
    tot = 0;
    dfs(1, 0);
    for(int i = 1; i <= k; i++){
        if(colors[i].size()){
            set<int> st = build(colors[i]);
            for(auto x : st){
                if(c[x]){
                    if(c[x] != i) cutie[x] = 1;
                    continue;
                }
                cnt[x]++, col[x] = i;
            }
        }
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        if(cutie[i] || cnt[i] > 1) ans += w[i];
        if(cnt[i] && c[i] == 0) c[i] = col[i];
    }
    for(int i = 1; i <= n; i++){
        if(c[i]){
            dfs1(1, c[i]);
            break;
        }
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; i++){
        cout << c[i] << " \n" [i == n];
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while(T--)
    {solve();} return 0;
}