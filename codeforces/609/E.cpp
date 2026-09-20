#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-10 23:30:33
using LL = long long;
using pii = pair<int, int>;
int n, m;
vector<vector<pii>> g;
struct edge{
    int u, v, w, id;
};
vector<edge> e;
constexpr int N = int(2e5) + 5;
int f[N];
int find(int x){return f[x] == x ? f[x] : f[x] = find(f[x]);}
int dfn[N], dep[N], fa[N], son[N], top[N], siz[N], rnk[N], W[N], cntd;
void dfs1(int u, int p){
    siz[u] = 1, fa[u] = p, dep[u] = dep[p] + 1;
    for(auto [v, w] : g[u]){
        if(v == p) continue;
        dfs1(v, u);
        siz[u] += siz[v], W[v] = w;
        if(siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u){
    dfn[u] = ++cntd, rnk[cntd] = u;
    top[u] = son[fa[u]] == u ? top[fa[u]] : u;
    if(son[u]) dfs2(son[u]);
    for(auto [v, w] : g[u]){
        if(v == fa[u] || v == son[u])
            continue;
        dfs2(v);
    }
}
#define ls p << 1
#define rs p << 1 | 1
#define mi ((l + r) >> 1)
int tr[N << 2];
void build(int p, int l, int r){
    if(l == r){
        tr[p] = W[rnk[l]];
        return;
    }
    build(ls, l, mi), build(rs, mi + 1, r);
    tr[p] = max(tr[ls], tr[rs]);
}
int query(int p, int l, int r, int lx, int rx){
    if(lx > rx) return 0;
    if(l >= lx && r <= rx) return tr[p];
    int res = 0;
    if(lx <= mi) res = max(res, query(ls, l, mi, lx, rx));
    if(rx > mi) res = max(res, query(rs, mi + 1, r, lx, rx));
    return res;
}
int lca(int x, int y){
    int res = 0;
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        res = max(res, query(1, 1, n, dfn[top[x]], dfn[x]));
        // cerr << top[x] << " " << x << '\n';
        x = fa[top[x]];
    }
    if(dfn[x] > dfn[y]) swap(x, y);
    if(x != y) res = max(res, query(1, 1, n, dfn[x] + 1, dfn[y]));
    return res;
}
void solve(){
    cin >> n >> m;
    g = vector<vector<pii>> (n + 1);
    e = vector<edge> (m);
    vector<LL> ans(m);
    for(int i = 1; i <= n; i++) f[i] = i;
    for(int i = 0; i < m; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].id = i;
    }
    sort(e.begin(), e.end(), [](edge x, edge y){return x.w < y.w;});
    LL sum = 0;
    for(auto x : e){
        auto [u, v, w, id] = x;
        int fu = find(u), fv = find(v);
        if(fu != fv){
            f[fu] = fv;
            sum += w;
            // cerr << u << " " << v << " " << w << '\n';
            ans[id] = -1;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
    }
    dfs1(1, 0), dfs2(1);
    build(1, 1, n);
    // for(int i = 1; i <= n; i++)
    //     cerr << dfn[i] << " " << W[i] << '\n';
    for(auto x : e){
        auto [u, v, w, id] = x;
        if(ans[id] == -1){
            ans[id] = sum;
            continue;
        }
        // cerr << u << " " << v << " " << lca(u, v) << " \n";
        ans[id] = sum - lca(u, v) + w;
    }
    for(auto x : ans)
        cout << x << "\n";
}
int main(){
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}