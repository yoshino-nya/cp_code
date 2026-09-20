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

constexpr int N = 100000+5;
int siz[N],fa[N],dep[N],son[N],dfn[N],top[N],seg[N];

#define ls p<<1
#define rs p<<1|1
#define mi ((l+r)>>1)
pii tr[N<<2];

pii merge(pii x,pii y)
{
    pii z;
    z.fi=min(x.fi,y.fi),z.se=min(x.se,y.se);
    return z;
}
void build(int p,int l,int r)
{
    if(l==r){
        tr[p]={l,INF};
        return;
    }
    build(ls,l,mi),build(rs,mi+1,r);
    tr[p]=merge(tr[ls],tr[rs]);
}
void change(int p,int l,int r,int i)
{
    if(l==r){
        swap(tr[p].fi,tr[p].se);
        return;
    }
    if(i<=mi) change(ls,l,mi,i);
    else change(rs,mi+1,r,i);
    tr[p]=merge(tr[ls],tr[rs]);
}
int query(int p,int l,int r,int lx,int rx)
{
    if(lx>rx) return INF;
    if(l>=lx&&r<=rx) return tr[p].se;
    int res=INF;
    if(lx<=mi) cmin(res,query(ls,l,mi,lx,rx));
    if(rx>mi) cmin(res,query(rs,mi+1,r,lx,rx));
    return res;
}
void ChatGptDeepSeek() // Date: 2025-04-20
{                      // Time: 11:07:35 
    int n,q;
    cin>>n>>q;
    vector<vi>g(n+1,vi());
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs1=[&](auto &&self,int u,int pre)->void{
        siz[u]=1,dep[u]=dep[pre]+1,fa[u]=pre;
        for(auto v:g[u]){
            if(v==pre) continue;
            self(self,v,u);
            siz[u]+=siz[v];
            if(son[u]==0||siz[v]>siz[son[u]])
                son[u]=v;
        }
    };
    dfs1(dfs1,1,0);
    int cntd=0;
    auto dfs2=[&](auto &&self,int u,int pre)->void{
        dfn[u]=++cntd;
        seg[cntd]=u;
        if(son[pre]==u) top[u]=top[pre];
        else top[u]=u;
        if(son[u]) self(self,son[u],u);
        for(auto v:g[u]){
            if(v==pre||v==son[u]) continue;
            self(self,v,u);
        }
    };
    dfs2(dfs2,1,0);
    build(1,1,n);
    while(q--){
        int op,x;
        cin>>op>>x;
        if(op==0) change(1,1,n,dfn[x]);
        else{
            int res=INF;
            while(top[x]!=1){
                cmin(res,query(1,1,n,dfn[top[x]],dfn[x]));
                x=fa[top[x]];
            }
            cmin(res,query(1,1,n,1,dfn[x]));
            cout<<(res==INF?-1:seg[res])<<'\n';
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