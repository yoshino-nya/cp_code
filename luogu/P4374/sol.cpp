// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/codes/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif

#define rep(N) for(int i = 1; i <= N; i++)

template <typename T1, typename T2>
void cmin(T1& x, const T2& y)
{
    x = x < y ? x : y;
}
template <typename T1, typename T2>
void cmax(T1& x, const T2& y)
{
    x = x > y ? x : y;
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using vc = vector<T>;

#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000 + 10;
constexpr ll LNF = 1000000000000000000LL;

// Date: 2025-05-18
// Time: 01:11:52
constexpr int N = int(5e4) + 5;
int siz[N], fa[N], dep[N], son[N], top[N], dfn[N];

#define ls p << 1
#define rs p << 1 | 1
#define mi ((l + r) >> 1)
struct node{
    int min, tag;
    node(int val = INF){min = tag = val;}
};
node tr[N << 2];
void push_down(int p, int l, int r)
{
    cmin(tr[ls].min, tr[p].tag);
    cmin(tr[rs].min, tr[p].tag);
    cmin(tr[ls].tag, tr[p].tag);
    cmin(tr[rs].tag, tr[p].tag);
    tr[p].tag = INF;
}
void upd(int p, int l, int r, int lx, int rx, int val)
{
    if(l >= lx && r <= rx){
        cmin(tr[p].min, val);
        cmin(tr[p].tag, val);
        return;
    }
    if(tr[p].tag != INF)
        push_down(p, l, r);
    if(lx <= mi) upd(ls, l, mi, lx, rx, val);
    if(rx > mi) upd(rs, mi + 1, r, lx, rx, val);
    tr[p].min = min(tr[ls].min, tr[rs].min);
}
int query(int p, int l, int r, int i)
{
    if(l == r) return tr[p].min;
    if(tr[p].tag != INF)
        push_down(p, l, r);
    if(i <= mi) return query(ls, l, mi, i);
    return query(rs, mi + 1, r, i);
}
void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    vc<vi> g(n + 1, vi());
    vc<pii> e(n);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        e[i] = {u, v};
    }
    auto dfs1 = [&](auto &&self, int u, int pre) -> void{
        dep[u] = dep[pre] + 1, fa[u] = pre, siz[u] = 1;
        for(auto v : g[u]){
            if(v == pre) continue;
            self(self, v, u);
            siz[u] += siz[v];
            if(son[u] == 0 || siz[v] > siz[son[u]])
                son[u] = v;
        }
    };
    dfs1(dfs1, 1, 0);
    int tot = 0;
    auto dfs2 = [&](auto &&self, int u, int pre) -> void{
        dfn[u] = ++tot;
        if(u == son[pre]) top[u] = top[pre];
        else top[u] = u;
        if(son[u]) self(self, son[u], u);
        for(auto v : g[u]){
            if(v == pre || v == son[u]) continue;
            self(self, v, u);
        }
    };
    dfs2(dfs2, 1, 0);
    
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        while(top[u] != top[v]){
            if(dep[top[u]] < dep[top[v]])
                swap(u, v);
            upd(1, 1, n, dfn[top[u]], dfn[u], w);
            u = fa[top[u]];
        }
        if(dep[u] > dep[v]) swap(u, v);
        if(u != v) upd(1, 1, n, dfn[u] + 1, dfn[v], w);
    }
    for(int i = 1; i < n; i++){
        auto [u, v] = e[i];
        if(dep[u] < dep[v]) swap(u, v);
        int res = query(1, 1, n, dfn[u]);
        cout << (res == INF ? -1 : res) << '\n';
    }   
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    // freopen("1.in", "r", stdin);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}