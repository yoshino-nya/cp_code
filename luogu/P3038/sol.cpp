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

constexpr int N = 1e5+5;
int siz[N],fa[N],dep[N],top[N],son[N],dfn[N];
ll tr[N<<2],tag[N<<2];

#define ls p<<1
#define rs p<<1|1
#define mi ((l+r)>>1)

void push_down(int p,int l,int r)
{
    if(tag[p]){
        tr[ls]+=(mi-l+1)*tag[p];
        tr[rs]+=(r-mi)*tag[p];
        tag[ls]+=tag[p],tag[rs]+=tag[p];
        tag[p]=0;
    }
}
void upd(int p,int l,int r,int lx,int rx)
{
    if(lx>rx) return;
    if(l>=lx&&r<=rx){
        tr[p]+=(r-l+1);
        tag[p]+=1;
        return;
    }
    push_down(p,l,r);
    if(lx<=mi) upd(ls,l,mi,lx,rx);
    if(rx>mi) upd(rs,mi+1,r,lx,rx);
    tr[p]=tr[ls]+tr[rs];
}
int query(int p,int l,int r,int i)
{
    if(l==r) return tr[p];
    push_down(p,l,r);
    if(i<=mi) return query(ls,l,mi,i);
    return query(rs,mi+1,r,i);
}

void ChatGptDeepSeek() // Date: 2025-04-19
{                      // Time: 18:06:21 
    int n,m;
    cin>>n>>m;
    vector<vi>g(n+1,vi());
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs1=[&](auto &&self,int u,int pre)->void{
        siz[u]=1;
        dep[u]=dep[pre]+1;
        fa[u]=pre;
        for(auto v:g[u]){
            if(v==pre) continue;
            self(self,v,u);
            if(son[u]==0||siz[v]>siz[son[u]])
                son[u]=v;
            siz[u]+=siz[pre];
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
    while(m--){
        char ch;
        int u,v;
        cin>>ch>>u>>v;
        if(ch=='P'){
            while(top[u]!=top[v]){
                if(dep[top[u]]<dep[top[v]]) swap(u,v);
                // cerr<<dfn[top[u]]+1<<" "<<dfn[u]<<"\n";
                upd(1,1,n,dfn[top[u]],dfn[u]);
                u=fa[top[u]];
            }
            if(dep[u]>dep[v]) swap(u,v);
            // cerr<<dfn[u]+1<<" "<<dfn[v]<<" \n";
            upd(1,1,n,dfn[u]+1,dfn[v]);
        }else{
            if(dep[u]<dep[v]) swap(u,v);
            // cerr<<"u: "<<u<<" "<<dfn[u]<<'\n';
            cout<<query(1,1,n,dfn[u])<<'\n';
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