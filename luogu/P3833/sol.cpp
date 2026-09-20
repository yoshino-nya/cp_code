// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
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
#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

constexpr int N = 100005;
int fa[N],siz[N],dep[N],son[N],top[N],dfn[N];
#define ls p<<1
#define rs p<<1|1
#define mi ((l+r)>>1)
ll sum[N<<2], lazy[N<<2];
void push_down(int p, int l, int r)
{
    if(lazy[p]){
        sum[ls] += ll(mi - l + 1) * lazy[p];
        sum[rs] += ll(r - mi) * lazy[p];
        lazy[ls] += lazy[p], lazy[rs] += lazy[p];
        lazy[p] = 0;
    }
}
void add(int p, int l, int r, int lx, int rx, int val)
{
    if(l >= lx && r <= rx){
        sum[p] += ll(r - l + 1) * val;
        lazy[p] += val;
        return;
    }
    push_down(p,l,r);
    if(lx <= mi) add(ls, l, mi, lx, rx, val);
    if(rx > mi) add(rs, mi+1, r, lx, rx, val);
    sum[p] = sum[ls] + sum[rs];
}
ll query(int p, int l, int r, int lx, int rx)
{
    if(l >= lx && r <= rx) return sum[p];
    push_down(p, l, r);
    ll res = 0;
    if(lx <= mi) res += query(ls, l, mi, lx, rx);
    if(rx > mi) res += query(rs, mi+1, r, lx, rx);
    return res;
}
void ChatGptDeepSeek() // Date: 2025-04-22
{                      // Time: 17:34:59 
    int n;
    cin >> n;
    vector<vi>g(n+1,vi());
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        ++u, ++v;
        g[u].push_back(v),g[v].push_back(u);
    }
    auto dfs1 = [&](auto &&self,int u,int pre)->void{
        siz[u] = 1, fa[u] = pre, dep[u] = dep[pre] + 1;
        for(auto v : g[u]){
            if(v == pre) continue;
            self(self,v,u);
            siz[u] += siz[v];
            if(son[u] == 0 || siz[v] > siz[son[u]])
                son[u] = v;
        }
    };
    dfs1(dfs1,1,0);
    int cntd = 0;
    auto dfs2 = [&](auto &&self,int u,int pre)->void{
        dfn[u] = ++cntd;
        if(son[pre] == u) top[u] = top[pre];
        else top[u] = u;
        if(son[u]) self(self,son[u],u);
        for(auto v : g[u]){
            if(v == pre || v == son[u]) continue;
            self(self,v,u);
        }
    };
    dfs2(dfs2,1,0);
    int Q;
    cin >> Q;
    while(Q--){
        char op;
        cin >> op;
        if(op == 'A'){
            int u, v, d;
            cin >> u >> v >> d;
            ++u, ++v;
            while(top[u] != top[v]){
                if(dep[top[u]] < dep[top[v]]) swap(u, v);
                add(1, 1, n, dfn[top[u]], dfn[u], d);
                u = fa[top[u]];
            }
            if(dep[u] > dep[v]) swap(u,v);
            add(1, 1, n, dfn[u], dfn[v], d);
        }else{
            int u;
            cin >> u;
            ++u;
            cout << query(1, 1, n, dfn[u], dfn[u] + siz[u] -1) << '\n';
        }
    }
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}