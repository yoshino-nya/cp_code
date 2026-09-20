#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100005;
int w[N];
vector<vector<int>> g;
int siz[N], dep[N], fa[N], son[N], dfn[N], top[N], cntd, rnk[N];
void dfs1(int u, int p){
    siz[u] = 1, dep[u] = dep[p] + 1, fa[u] = p;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if(siz[v] > siz[son[u]]) son[u] = v;
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
    int pre, suf, len, lazy;
    node(){pre = suf = len = lazy = 0;}
};
node seg[N << 2];
node merge(const node &x, const node &y){
    if(!x.len) return y;
    if(!y.len) return x;
    node res;
    res.pre = x.pre, res.suf = y.suf, res.len = x.len + y.len;
    if(x.suf == y.pre) res.len--;
    return res;
}
void build(int p, int l, int r){
    if(l == r){
        seg[p].pre = seg[p].suf = w[rnk[l]];
        seg[p].len = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
    seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
}
void push_down(int p){
    if(seg[p].lazy){
        seg[p << 1].pre = seg[p << 1].suf = seg[p].lazy;
        seg[p << 1 | 1].pre = seg[p << 1 | 1].suf = seg[p].lazy;
        seg[p << 1].len = seg[p << 1 | 1].len = 1;
        seg[p << 1].lazy = seg[p << 1 | 1].lazy = seg[p].lazy;
        seg[p].lazy = 0;
    }
}
void update(int p, int l, int r, int lx, int rx, int c){
    if(l >= lx && r <= rx){
        seg[p].pre = seg[p].suf = c;
        seg[p].len = 1;
        seg[p].lazy = c;
        return;
    }
    push_down(p);
    int mid = (l + r) >> 1;
    if(lx <= mid) update(p << 1, l, mid, lx, rx, c);
    if(rx > mid) update(p << 1 | 1, mid + 1, r, lx, rx, c);
    seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
}
node query(int p, int l, int r, int lx, int rx){
    if(l >= lx && r <= rx) return seg[p];
    push_down(p);
    int mid = (l + r) >> 1;
    node res;
    if(lx <= mid) res = merge(res, query(p << 1, l, mid, lx, rx));
    if(rx > mid) res = merge(res, query(p << 1 | 1, mid + 1, r, lx, rx));
    return res;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    g.assign(n + 1, {});
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0), dfs2(1);
    build(1, 1, n);
    char op;
    int a, b, c;
    while(m--){
        cin >> op;
        if(op == 'C'){
            cin >> a >> b >> c;
            while(top[a] != top[b]){
                if(dep[top[a]] < dep[top[b]]) swap(a, b);
                update(1, 1, n, dfn[top[a]], dfn[a], c);
                a = fa[top[a]];
            }
            if(dep[a] > dep[b]) swap(a, b);
            update(1, 1, n, dfn[a], dfn[b], c);
        }else{
            cin >> a >> b;
            node rx, ry;
            while(top[a] != top[b]){
                if(dep[top[a]] >= dep[top[b]]){
                    rx = merge(query(1, 1, n, dfn[top[a]], dfn[a]), rx);
                    a = fa[top[a]];
                }else{
                    ry = merge(query(1, 1, n, dfn[top[b]], dfn[b]), ry);
                    b = fa[top[b]];
                }
            }
            // cerr << a << " " << b << '\n';
            if(dep[a] <= dep[b])
                ry = merge(query(1, 1, n, dfn[a], dfn[b]), ry);
            else
                rx = merge(query(1, 1, n, dfn[b], dfn[a]), rx);
            // cerr << format("rx : {} {} {}, ry : {} {} {}\n", rx.pre, rx.suf, rx.len, ry.pre, ry.suf, ry.len);
            swap(rx.pre, rx.suf);
            cout << merge(rx, ry).len << "\n";
        }
    }
    return 0;
}