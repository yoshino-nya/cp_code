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

constexpr int N = int(3e5)+5;
int siz[N],fa[N],top[N],dfn[N],son[N],dep[N];

struct Fenwick{
    vector<int>b;
    Fenwick(int n){
        b=vector<int>(n+1);
    };
    int lowbit(int x){return (x)&(-x);}
    void add(int i,int x){
        while(i&&i<b.size()){
            b[i]+=x;
            i+=lowbit(i);
        }
    }
    int query(int i){
        int res=0;
        while(i){
            res+=b[i];
            i-=lowbit(i);
        }
        return res;
    }
};
void ChatGptDeepSeek() // Date: 2025-04-18
{                      // Time: 15:07:04 
    int n;
    cin>>n;
    vi a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vi>g(n+1,vi());
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v),g[v].push_back(u);
    }
    auto dfs1=[&](auto&& self,int u,int pre)->void{
        siz[u]=1;
        fa[u]=pre;
        dep[u]=dep[pre]+1;
        for(auto v:g[u]){
            if(v==pre) continue;
            self(self,v,u);
            if(son[u]==0||siz[v]>siz[son[u]])
                son[u]=v;
            siz[u]+=siz[v];
        }
    };
    dfs1(dfs1,a[1],0);
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
    dfs2(dfs2,a[1],0);
    Fenwick Tr(n);
    for(int i=2;i<=n;i++){
        int x=a[i-1],y=a[i];
        while(top[x]!=top[y]){
            // cerr<<x<<" "<<y<<'\n';
            if(dep[top[x]]<dep[top[y]]) swap(x,y);
            //[dfn[top[x]],x] 区间加
            Tr.add(dfn[top[x]],1);
            Tr.add(dfn[x]+1,-1);
            x=fa[top[x]];
        }
        // cerr<<'\n';
        if(dep[x]>dep[y]) swap(x,y);
        // cerr<<x<<" "<<y<<'\n';
        Tr.add(dfn[x],1);
        Tr.add(dfn[y]+1,-1);
        Tr.add(dfn[a[i]],-1);
        Tr.add(dfn[a[i]]+1,1);
    }
    vi ans(n+1);
    for(int i=1;i<=n;i++){
        ans[a[i]]=Tr.query(dfn[a[i]]);
        // cout<<ans[a[i]]<<"\n";
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<"\n";
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