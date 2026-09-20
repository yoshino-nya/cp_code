#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 6010;
int n, r[N], ans;
vector<vector<int>> g;

struct node{
    int lds, lis, l, r;
};
node tr[N * 50];
#define lson tr[p].l
#define rson tr[p].r
#define mi ((l + r) >> 1)
int ttot, rt[N];
void push_up(int p)
{
    tr[p].lds = max(tr[lson].lds, tr[rson].lds);
    tr[p].lis = max(tr[lson].lis, tr[rson].lis);
}
void update(int &p, int l, int r, int pos, int lds, int lis)
{
    if(!p) p = ++ttot;
    if(l == r){
        tr[p].lds = max(tr[p].lds, lds);
        tr[p].lis = max(tr[p].lis, lis);
        return;
    }
    if(pos <= mi) update(lson, l, mi, pos, lds, lis);
    else update(rson, mi + 1, r, pos, lds, lis);
    push_up(p);
}
int merge(int a, int b, int l, int r)
{
    if(!a || !b) return a + b;
    if(l == r){
        tr[a].lis = max(tr[a].lis, tr[b].lis);
        tr[a].lds = max(tr[a].lds, tr[b].lds);
        return a;
    }
    ans = max({ans, tr[tr[a].l].lis + tr[tr[b].r].lds, tr[tr[b].l].lis + tr[tr[a].r].lds});
    tr[a].l = merge(tr[a].l, tr[b].l, l, mi);
    tr[a].r = merge(tr[a].r, tr[b].r, mi + 1, r);
    push_up(a);
    return a;
}
node query(int &p, int l, int r, int lx, int rx)
{
    if(!p) return {};
    if(l >= lx && r <= rx)
        return tr[p];
    node res{0, 0, 0, 0};
    if(lx <= mi) res = query(lson, l, mi, lx, rx);
    if(rx > mi){
        node tmp = query(rson, mi + 1, r, lx, rx);
        res.lds = max(res.lds, tmp.lds);
        res.lis = max(res.lis, tmp.lis);
    }
    return res;
}
void dfs(int u, int p)
{
    int ulds = 0, ulis = 0;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
        int vlds = query(rt[v], 1, N, r[u] + 1, N).lds;
        int vlis = query(rt[v], 1, N, 1, r[u] - 1).lis;
        ans = max(ans, ulds + vlis + 1);
        ans = max(ans, ulis + vlds + 1);
        ulds = max(ulds, vlds), ulis = max(ulis, vlis);
        rt[u] = merge(rt[u], rt[v], 1, N);
    }
    update(rt[u], 1, N, r[u], ulds + 1, ulis + 1);
}
void solve()
{
    cin >> n;
    g = vector<vector<int>> (n + 1);
    {
        vector<int> tmp(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> tmp[i];
            r[i] = tmp[i];
        }
        sort(r + 1, r + n + 1);
        for(int i = 1; i <= n; i++)
            tmp[i] = lower_bound(r + 1, r + n + 1, tmp[i]) - r;
        for(int i = 1; i <= n; i++){
            r[i] = tmp[i];
            // cerr << r[i] << " \n"[i == n];
        }
    }
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << '\n';
}

int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}
/*

*/