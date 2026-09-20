// Author: Zhangwuji
// Date: 2024-12-29
// Time: 20:04:37

// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/templates/debug.hpp"
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
    int n,a,b;
    cin>>n>>a>>b;
    vector<vi>g(n+1,vi());
    vi w(n+1);
    for(int i=1;i<=n;i++)
        cin>>w[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto calc=[&](int x){
        int res=0;
        if(x<=a) res|=1;
        if(x>=b) res|=2;
        return res;
    };
    vector<vl>dp(n+1,vl(4));
    ll ans=0;
    auto dfs=[&](auto &&self,int u,int pre)->void{
        dp[u][calc(w[u])]=1;
        // cerr<<u<<" "<<pre<<'\n';
        for(auto &v:g[u]){
            if(v==pre) continue;
            self(self,v,u);
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++){
                    if((i|j)==3){
                        ans+=dp[u][i]*dp[v][j];
                        // cerr<<ans<<'\n';
                    }
                }
            for(int i=0;i<4;i++)
                dp[u][calc(w[u])|i]+=dp[v][i];
        }
    };
    dfs(dfs,1,0);
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}