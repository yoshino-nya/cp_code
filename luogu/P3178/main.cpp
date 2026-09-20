#include <bits/stdc++.h>
using namespace std;

using LL = long long;
constexpr int N = 100005;
int val[N << 2];
vector< vector<int> > g;
int siz[N], dep[N], son[N], dfn[N], top[N], fa[N], cntd, rnk[N];
void dfs1(int u, int p){
    dep[u] = dep[p] + 1, siz[u] = 1, fa[u] = p;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs1(v, u);
        if(siz[v] > siz[son[u]])
            son[u] = v;
        siz[u] += siz[v];
    }
}

void dfs2(int u){
    dfn[u] = ++cntd, rnk[cntd] = u;
    top[u] = son[fa[u]] == u ? top[fa[u]] : u;
    if(son[u]) dfs2(son[u]);
    for(auto v : g[u]){
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v);
    }
}
struct node{
    LL sum, lazy;
    node(){sum = lazy = 0;}
};
node seg[N << 2];
void build(int p, int l, int r){
    if(l == r){
        seg[p].sum = val[rnk[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
    seg[p].sum = seg[p << 1].sum + seg[p << 1 | 1].sum;
}
void push_down(int p, int l, int r){
    if(seg[p].lazy){
        int mid = (l + r) >> 1;
        seg[p << 1].sum += (mid - l + 1) * seg[p].lazy;
        seg[p << 1 | 1].sum += (r - mid) * seg[p].lazy;
        seg[p << 1].lazy += seg[p].lazy;
        seg[p << 1 | 1].lazy += seg[p].lazy;
        seg[p].lazy = 0;
    }
}
void upd(int p, int l, int r, int lx, int rx, LL x){
    if(l >= lx && r <= rx){
        seg[p].sum += (r - l + 1) * x;
        seg[p].lazy += x;
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if(lx <= mid) upd(p << 1, l, mid, lx, rx, x);
    if(rx > mid) upd(p << 1 | 1, mid + 1, r, lx, rx, x);
    seg[p].sum = seg[p << 1].sum + seg[p << 1 | 1].sum;
}
LL query(int p, int l, int r, int lx, int rx){
    if(l >= lx && r <= rx) return seg[p].sum;
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    LL res = 0;
    if(lx <= mid) res += query(p << 1, l, mid, lx, rx);
    if(rx > mid) res += query(p << 1 | 1, mid + 1, r, lx, rx);
    return res;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    g.assign(n + 1, {});
    for(int i = 1; i <= n; i++) cin >> val[i];
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0), dfs2(1);
    build(1, 1, n);
    int op, x, a;
    while(m--){
        cin >> op;
        if(op == 1){
            cin >> x >> a;
            upd(1, 1, n, dfn[x], dfn[x], a);
        }else if(op == 2){
            cin >> x >> a;
            upd(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, a);
        }else{
            cin >> x;
            LL res = 0;
            while(top[x] != 1){
                res += query(1, 1, n, dfn[top[x]], dfn[x]);
                x = fa[top[x]];
            }
            res += query(1, 1, n, 1, dfn[x]);
            cout << res << "\n";
        }
    }
    return 0;
}