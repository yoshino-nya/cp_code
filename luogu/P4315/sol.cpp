// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/template/debug.hpp"
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

constexpr int N = int(1e5)+5;
int siz[N],fa[N],top[N],son[N],dep[N],dfn[N];

#define ls p<<1
#define rs p<<1|1
#define mi ((l+r)>>1)

ll tr[N<<2],t1[N<<2],t2[N<<2];

void pushdown(int p,int l,int r)
{
    if(t1[p]){
        assert(t2[p]==0);
        tr[ls]=tr[rs]=t1[p];
        t1[ls]=t1[rs]=t1[p];
        t2[ls]=t2[rs]=0;
        t1[p]=0;
    }else if(t2[p]){
        tr[ls]+=t2[p],tr[rs]+=t2[p];

        if(t1[ls]) t1[ls]+=t2[p];
        else t2[ls]+=t2[p];
        
        if(t1[rs]) t1[rs]+=t2[p];
        else t2[rs]+=t2[p];
        
        t2[p]=0;
    }
}
void change(int p,int l,int r,int i,int x)
{
    if(l==r){
        tr[p]=x;
        return;
    }
    pushdown(p,l,r);
    if(i<=mi) change(ls,l,mi,i,x);
    else change(rs,mi+1,r,i,x);
    tr[p]=max(tr[ls],tr[rs]);
}
void cover(int p,int l,int r,int lx,int rx,int w)
{
    if(lx>rx) return;
    if(l>=lx&&r<=rx){
        tr[p]=w;
        t1[p]=w,t2[p]=0;
        return;
    }
    pushdown(p,l,r);
    if(lx<=mi) cover(ls,l,mi,lx,rx,w);
    if(rx>mi) cover(rs,mi+1,r,lx,rx,w);
    tr[p]=max(tr[ls],tr[rs]);
}
void add(int p,int l,int r,int lx,int rx,int w)
{
    if(lx>rx) return;
    if(l>=lx&&r<=rx){
        tr[p]+=w;
        if(t1[p]) t1[p]+=w;
        else t2[p]+=w;
        return;
    }
    pushdown(p,l,r);
    if(lx<=mi) add(ls,l,mi,lx,rx,w);
    if(rx>mi) add(rs,mi+1,r,lx,rx,w);
    tr[p]=max(tr[ls],tr[rs]);
}
int query(int p,int l,int r,int lx,int rx)
{
    if(lx>rx) return 0;
    if(l>=lx&&r<=rx) return tr[p];
    pushdown(p,l,r);
    int res=0;
    if(lx<=mi) cmax(res,query(ls,l,mi,lx,rx));
    if(rx>mi) cmax(res,query(rs,mi+1,r,lx,rx));
    return res;
}


void ChatGptDeepSeek() // Date: 2025-04-19
{                      // Time: 18:36:52 
    int n;
    cin>>n;
    vector<vector<pii>>g(n+1,vector<pii>());
    vector<array<int,3>>edge(n);
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[i]={u,v,w};
        g[u].push_back({v,w}),g[v].push_back({u,w});
    }
    int cntd=0;
    vi a(n+1);
    auto dfs1=[&](auto&& self,int u,int pre)->void{
        siz[u]=1;
        dep[u]=dep[pre]+1;
        fa[u]=pre;
        for(auto [v,w]:g[u]){
            if(v==pre) continue;
            self(self,v,u);
            siz[u]+=siz[v];
            if(son[u]==0||siz[son[u]]<siz[v])
                son[u]=v;
        }
    };
    dfs1(dfs1,1,0);
    auto dfs2=[&](auto &&self,int u,int pre)->void{
        dfn[u]=++cntd;
        if(son[pre]==u) top[u]=top[pre];
        else top[u]=u;
        if(son[u]) self(self,son[u],u);
        for(auto [v,w]:g[u]){
            if(v==pre||v==son[u]) continue;
            self(self,v,u);
        }
    };
    dfs2(dfs2,1,0);
    for(int i=1;i<n;i++){
        auto [u,v,w]=edge[i];
        if(dep[u]>dep[v]) swap(u,v);
        change(1,1,n,dfn[v],w);
    }
    string op;
    while(cin>>op&&op!="Stop"){
        if(op=="Change"){
            int k,x;
            cin>>k>>x;
            auto [u,v,w]=edge[k];
            if(dep[u]>dep[v]) swap(u,v);
            change(1,1,n,dfn[v],x);
        }else if(op=="Cover"){
            int u,v,x;
            cin>>u>>v>>x;
            while(top[u]!=top[v]){
                if(dep[top[u]]<dep[top[v]]) swap(u,v);
                cover(1,1,n,dfn[top[u]],dfn[u],x);
                u=fa[top[u]];
            }
            if(dep[u]>dep[v]) swap(u,v);
            cover(1,1,n,dfn[u]+1,dfn[v],x);
        }else if(op=="Add"){
            int u,v,x;
            cin>>u>>v>>x;
            while(top[u]!=top[v]){
                if(dep[top[u]]<dep[top[v]]) swap(u,v);
                add(1,1,n,dfn[top[u]],dfn[u],x);
                u=fa[top[u]];
            }
            if(dep[u]>dep[v]) swap(u,v);
            add(1,1,n,dfn[u]+1,dfn[v],x);
        }else{
            int u,v;
            cin>>u>>v;
            int res=0;
            while(top[u]!=top[v]){
                if(dep[top[u]]<dep[top[v]]) swap(u,v);
                cmax(res,query(1,1,n,dfn[top[u]],dfn[u]));
                u=fa[top[u]];
            }
            if(dep[u]>dep[v]) swap(u,v);
            cmax(res,query(1,1,n,dfn[u]+1,dfn[v]));
            cout<<res<<'\n';
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