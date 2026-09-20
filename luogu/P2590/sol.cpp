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

constexpr int N = 30005;
int siz[N],fa[N],dep[N],son[N],top[N],dfn[N],seg[N];
#define ls p<<1
#define rs p<<1|1
#define mi ((l+r)>>1)
struct node{
    ll sum,max;
};
node tr[N<<2];

void push_up(int p)
{
    tr[p].sum = tr[ls].sum+tr[rs].sum;
    tr[p].max = max(tr[ls].max,tr[rs].max);
}
void upd(int p,int l,int r,int i,int val)
{
    if(l == r){
        tr[p] = {val,val};
        return;
    }
    if(i <= mi) upd(ls,l,mi,i,val);
    else upd(rs,mi+1,r,i,val);
    push_up(p);
}
int ask1(int p,int l,int r,int lx,int rx)
{
    if(l >= lx && r <= rx) return tr[p].max;
    int res=-INF;
    if(lx <= mi) cmax(res,ask1(ls,l,mi,lx,rx));
    if(rx > mi) cmax(res,ask1(rs,mi+1,r,lx,rx));
    return res;
}
int ask2(int p,int l,int r,int lx,int rx)
{
    if(l >= lx && r <= rx) return tr[p].sum;
    int res=0;
    if(lx <= mi) res += ask2(ls,l,mi,lx,rx);
    if(rx > mi) res += ask2(rs,mi+1,r,lx,rx);
    return res;
}
void ChatGptDeepSeek() // Date: 2025-04-22
{                      // Time: 16:39:15 
    int n;
    cin >> n;
    vector<vi>g(n+1,vi());
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs1 = [&](auto &&self,int u,int pre)->void{
        dep[u] = dep[pre] + 1,siz[u] = 1,fa[u] = pre;
        for(auto v:g[u]){
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
        seg[cntd] = u;
        if(son[pre] == u) top[u] = top[pre];
        else top[u] = u;
        if(son[u]) self(self,son[u],u);
        for(auto v:g[u]){
            if(v == pre || v == son[u]) continue;
            self(self,v,u);
        }
    };
    dfs2(dfs2,1,0);
    vi a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    auto build = [&](auto &&self,int p,int l,int r)->void{
        if(l==r){
            tr[p]={a[seg[l]],a[seg[l]]};
            return;
        }
        self(self,ls,l,mi);
        self(self,rs,mi+1,r);
        push_up(p);
    };
    build(build, 1, 1, n);
    int q;
    cin >> q;
    while(q--){
        string op;
        int x,y;
        cin >> op >> x >> y;
        if(op == "CHANGE") upd(1,1,n,dfn[x],y);
        else if(op == "QMAX"){
            int res = -INF;
            while(top[x] != top[y]){
                if(dep[top[x]] < dep[top[y]]) swap(x,y);
                cmax(res,ask1(1,1,n,dfn[top[x]],dfn[x]));
                x = fa[top[x]];
            }
            if(dep[x] > dep[y]) swap(x,y);
            cmax(res,ask1(1,1,n,dfn[x],dfn[y]));
            cout << res << '\n';
        }else{
            int res = 0;
            while(top[x] != top[y]){
                if(dep[top[x]] < dep[top[y]]) swap(x,y);
                res += ask2(1,1,n,dfn[top[x]],dfn[x]);
                x = fa[top[x]];
            }
            if(dep[x] > dep[y]) swap(x,y);
            res += ask2(1,1,n,dfn[x],dfn[y]);
            cout << res << '\n';
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