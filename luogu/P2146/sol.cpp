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

constexpr int N = (int)1e5+5;
int siz[N],top[N],son[N],fa[N],dep[N],dfn[N],tr[N<<2],tag[N<<2];

#define ls p<<1
#define rs p<<1|1
#define mi ((l+r)>>1)

void push_down(int p,int l,int r)
{
    if(tag[p]){
        tag[ls]=tag[rs]=tag[p];
        if(tag[p]==-1) tag[p]=0;
        tr[ls]=(mi-l+1)*tag[p];
        tr[rs]=(r-mi)*tag[p];
        tag[p]=0;
    }
}
void upd1(int p,int l,int r,int lx,int rx)
{
    assert(lx<=rx&&l<=r);
    if(l>=lx&&r<=rx){
        tag[p]=1;
        tr[p]=r-l+1;
        return;
    }
    push_down(p,l,r);
    if(lx<=mi) upd1(ls,l,mi,lx,rx);
    if(rx>mi) upd1(rs,mi+1,r,lx,rx);
    tr[p]=tr[ls]+tr[rs];
}
void upd2(int p,int l,int r,int lx,int rx)
{
    assert(lx<=rx&&l<=r);
    if(l>=lx&&r<=rx){
        tag[p]=-1;
        tr[p]=0;
        return;
    }
    push_down(p,l,r);
    if(lx<=mi) upd2(ls,l,mi,lx,rx);
    if(rx>mi) upd2(rs,mi+1,r,lx,rx);
    tr[p]=tr[ls]+tr[rs];
}
int query(int p,int l,int r,int lx,int rx)
{
    assert(lx<=rx&&l<=r);
    if(l>=lx&&r<=rx) return tr[p];
    push_down(p,l,r);
    int res=0;
    if(lx<=mi) res+=query(ls,l,mi,lx,rx);
    if(rx>mi) res+=query(rs,mi+1,r,lx,rx);
    return res;
}
void ChatGptDeepSeek() // Date: 2025-04-17
{                      // Time: 15:10:38 
    int n;
    cin>>n;
    vector<vi>g(n,vi());
    for(int i=1;i<n;i++){
        int x; cin >> x;
        g[x].push_back(i);
    }
    auto dfs1=[&](auto &&self,int u,int pre)->void{
        assert(u<n&&pre<n);
        siz[u]=1;
        dep[u]=dep[pre]+1;
        fa[u]=pre;
        for(auto v:g[u]){
            if(v==pre) continue;
            self(self,v,u);
            if(son[u]==0||siz[son[u]]<siz[v])
                son[u]=v;
            // fa[v]=u;
            siz[u]+=siz[v];
        }
    };
    dfs1(dfs1,0,0);
    int cntd=0,q;
    auto dfs2=[&](auto &&self,int u,int pre)->void{
        // cerr<<u<<'\n';
        assert(u<n&&pre<n);
        dfn[u]=++cntd;
        if(son[pre]==u) top[u]=top[pre];
        else top[u]=u;
        if(son[u]) self(self,son[u],u);
        for(auto v:g[u]){
            if(v==pre||v==son[u]) continue;
            self(self,v,u);
        }
    };
    dfs2(dfs2,0,0);
    cin>>q;
    // for(int i=0;i<n;i++){
    //     cerr<<fa[i]<<" \n"[i+1==n];
    // }
    // for(int i=0;i<n;i++){
    //     cerr<<top[i]<<" \n"[i+1==n];
    // }
    /* 
    安装的话 需要把 1-> x 都变成1 还需要统计 1 的数量 区间和 然后把区间变成1
    卸载的话 统计子树的1的数量 然后把区间变成全0
    */
    while(q--){
        string s;
        int x;
        cin>>s>>x;
        // cerr<<s<<" "<<x<<'\n';
        assert(s!="\n");
        assert(s.size());
        if(s[0]=='i'){
            int res=0;
            while(top[x]!=0&&x){
                // assert(x<n&&dfn[top[x]]<n&&dfn[x]<n);
                // cerr<<x<<'\n';
                res+=dfn[x]-dfn[top[x]]+1-query(1,1,n,dfn[top[x]],dfn[x]);
                upd1(1,1,n,dfn[top[x]],dfn[x]);
                x=fa[top[x]];
            }
            res+=dfn[x]-query(1,1,n,1,dfn[x]);
            upd1(1,1,n,1,dfn[x]);
            // cerr<<x<<'\n';
            cout<<res<<'\n';
        }
        else{
            cout<<query(1,1,n,dfn[x],dfn[x]+siz[x]-1)<<'\n';
            upd2(1,1,n,dfn[x],dfn[x]+siz[x]-1);
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