// Author: Zhangwuji
// Date: 2025-01-05
// Time: 20:36:51

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

void solve()
{
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vi val(n+1);
    for(int i=0;i<n;i++)
        val[i+1]=(s[i]=='R'?1:0);
    vector<vi>adj(n+1,vi());
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int x,y;
    cin>>x>>y;
    vi p(n+1);
    auto dfs1=[&](auto self,int u,int pre)->void{
        if(u==y)
            return;
        for(auto v:adj[u]){
            if(v==pre) continue;
            p[v]=u;
            self(self,v,u);
        }
    };
    dfs1(dfs1,x,0);
    dbg(val);
    while(y){
        val[y]=1;
        y=p[y];
    }
    dbg(val);
    vector<vi>dp(n+1,vi(4,n+1));
    //不对不对 还需要一种状态
    //这个子树没有满足条件 加上父节点才满足
    //dp[u][0] 表示 子结点有红色
    //dp[u][1] 表示 子结点有蓝色
    //dp[u][2] 表示 子结点没有红色
    //dp[u][3] 表示 子结点没有蓝色
    auto dfs=[&](auto &&self,int u,int pre)->void{
        // dbg(u);
        if(u!=1&&sz(adj[u])==1){
            dp[u][2]=val[u]^1;
            dp[u][3]=val[u];
            return;
        }
        // dbg(dp[u]);
        vl sum(4);
        for(auto v:adj[u]){
            dbg(v);
            if(v==pre)  continue;
            self(self,v,u);
            //如果这个点为0 他的其他儿子 如果为1 必须有为1的孩子
            //
            for(int i=0;i<4;i++)
                sum[i]+=dp[v][i];
        }
        //dp[u][1] 需要 一个dp[v][1] 
        //dp[u][0] 
        for(auto v:adj[u]){
            if(v==pre) continue;
            cmin(dp[u][0],dp[v][2]+sum[1]-dp[v][1]+(val[u]^1));
            cmin(dp[u][1],dp[v][3]+sum[0]-dp[v][0]+val[u]);
        }
        cmin(dp[u][2],sum[1]+(val[u]^1));
        cmin(dp[u][3],sum[0]+val[u]);
        dbg(u,dp[u]);
    };
    dfs(dfs,1,0);
    int ans=min(dp[1][0],dp[1][1]);
    // cout<<"-1\n";
    // return;
    if(ans>n+1){
        cout<<"-1\n";
    }else {
        cout<<ans<<'\n';
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
        solve();
    return 0;
}