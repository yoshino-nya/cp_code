#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 300005;
int n, m, w[N], dep[N], f[N][20];
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
struct node{
    int l, r, cnt;
};
#define lson seg[p].l
#define rson seg[p].r
#define mi ((l + r) >> 1)
node seg[N * 50];
int stot = 0, rt[N][2], ans[N];
void update(int &p, int l, int r, int pos, int val)
{
    if(!p) p = ++stot;
    if(l == r){
        seg[p].cnt += val;
        return;
    }
    if(pos <= mi) update(lson, l, mi, pos, val);
    else update(rson, mi + 1, r, pos, val);
}
int merge(int p, int q, int l, int r)
{
    if(!p || !q) return p + q;
    if(l == r){
        seg[p].cnt += seg[q].cnt;
        return p;
    }
    lson = merge(lson, seg[q].l, l, mi);
    rson = merge(rson, seg[q].r, mi + 1, r);
    return p;
}
int query(int p, int l, int r, int pos)
{
    if(l == r)
        return seg[p].cnt;
    if(pos <= mi) return query(lson, l, mi, pos);
    return query(rson, mi + 1, r, pos);
}
void dfs(int u)
{
    for(auto v : g[u]){
        if(v == f[u][0]) continue;
        dfs(v);
        rt[u][0] = merge(rt[u][0], rt[v][0], -N, N);
        rt[u][1] = merge(rt[u][1], rt[v][1], -N, N);
    }
    ans[u] += query(rt[u][1], -N, N, w[u] - dep[u]);
    if(w[u] + dep[u] <= N)
        ans[u] += query(rt[u][0], -N, N, w[u] + dep[u]);
}
void solve()
{
    cin >> n >> m;
    g = vector<vector<int>> (n + 1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init(1, 0);
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    while(m--){
        int s, t;
        cin >> s >> t;
        int l = lca(s, t);
        update(rt[s][0], -N, N, dep[s], 1);
        update(rt[f[l][0]][0], -N, N, dep[s], -1);
        int x = dep[s] - 2 * dep[l];
        if(x >= -N){
            update(rt[t][1], -N, N, x, 1);
            update(rt[l][1], -N, N, x, -1);
        }
    }
    dfs(1);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " \n" [i == n];
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}
/*
dep[s] - dep[j] = w[j]
w[j] + dep[j] = dep[s]

dep[s] + dep[j] - 2dep[l] = w[j]
w[j] - dep[j] = dep[s] - 2dep[l]
*/