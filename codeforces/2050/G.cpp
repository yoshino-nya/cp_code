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

void ChatGptDeepSeek() // Date: 2025-04-15
{                      // Time: 20:02:56 
    int n;
    cin>>n;
    vector<vi>adj(n+1,vi());
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[v].push_back(u); adj[u].push_back(v);
    }
    vector<vi>dp(n+1,vi(2));
    auto dfs=[&](auto&& self,int u,int pre)->void{
        dp[u][0]=sz(adj[u]);
        int s1=-1,s2=-1;
        for(auto v:adj[u]){
            if(v==pre) continue;
            self(self,v,u);
            //s-2k
            cmax(dp[u][0],dp[v][0]+sz(adj[u])-2);
            cmax(s2,dp[v][0]);
            if(s1<s2) swap(s1,s2);
        }
        if(s2!=-1) cmax(dp[u][1],s1+s2+sz(adj[u])-4);
    };
    dfs(dfs,1,0);
    int ans=0;
    for(int i=1;i<=n;i++)
        cmax(ans,max(dp[i][0],dp[i][1]));
    cout<<ans<<'\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}