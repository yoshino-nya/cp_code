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

constexpr int N = int(3e5)+5;
int siz[N],fa[N],dep[N],son[N],top[N],dfn[N];

#define ls p<<1
#define rs p<<1|1
#define mi ((l+r)>>1)

int tr[N<<2];

void add(int p,int l,int r,int i,int x)
{
    if(l==r){
        tr[p]+=x;
        return;
    }
    if(i<=mi) add(ls,l,mi,i,x);
    else add(rs,mi+1,r,i,x);
    tr[p]=tr[ls]+tr[rs];
}
int query(int p,int l,int r,int lx,int rx)
{
    if(lx>rx) return 0;
    if(l>=lx&&r<=rx) return tr[p];
    ll res=0;
    if(lx<=mi) res+=query(ls,l,mi,lx,rx);
    if(rx>mi) res+=query(rs,mi+1,r,lx,rx);
    return res;
}

void ChatGptDeepSeek() // Date: 2025-04-20
{                      // Time: 10:18:40 
    int n,m; cin>>n>>m;
    vector<pii>edge(n);
    vector<vi>g(n+1,vi());
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        edge[i]={u,v};
        g[v].push_back(u),g[u].push_back(v);
    }
    auto dfs1=[&](auto &&self,int u,int pre)->void{
        siz[u]=1,fa[u]=pre,dep[u]=dep[pre]+1;
        for(auto v:g[u]){
            if(v==pre) continue;
            self(self,v,u);
            if(son[u]==0||siz[son[u]]<siz[v])
                son[u]=v;
        }
    };
    dfs1(dfs1,1,0);
    int cntd=0;
    auto dfs2=[&](auto &&self,int u,int pre)->void{
        dfn[u]=++cntd;
        if(son[pre]==u) top[u]=top[pre];
        else top[u]=u;
        if(son[u]) self(self,son[u],u);
        for(auto v:g[u]){
            if(v==pre||v==son[u]) continue;
            self(self,v,u);
        }
    };
    dfs2(dfs2,1,0);
    vector<pii>war;
    for(int i=1;i<=m;i++){
        char op;
        cin>>op;
        if(op=='Q'){
            int x,y;
            cin>>x>>y;
            bool ok=false;
            while(top[x]!=top[y]){
                if(dep[top[x]]<dep[top[y]]) swap(x,y);
                if(query(1,1,n,dfn[top[x]],dfn[x])) ok=true;
                x=fa[top[x]];
            }
            if(dep[x]>dep[y]) swap(x,y);
            if(query(1,1,n,dfn[x]+1,dfn[y])) ok=true;
            cout<<(ok?"No":"Yes")<<'\n';
        }else if(op=='C'){
            int p,q;
            cin>>p>>q;
            war.push_back({p,q});
            if(dep[p]>dep[q]) swap(p,q);
            add(1,1,n,dfn[q],1);
        }else{
            int k; cin>>k;
            auto [p,q]=war[k-1];
            if(dep[p]>dep[q]) swap(p,q);
            add(1,1,n,dfn[q],-1);
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