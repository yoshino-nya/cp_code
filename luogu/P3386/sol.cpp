// Author: Zhangwuji
// Date: 2025-02-19
// Time: 23:45:00

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

void solve()
{
    int n,m,e;
    cin>>n>>m>>e;
    vector<vi>adj(n+1,vi());
    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>match(m+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        vector<bool>sel(m+1);//记有没有被选过
        auto dfs=[&](auto &&self,int u)->bool{
            for(auto v:adj[u]){
                if(!sel[v]){
                    sel[v]=true;
                    if(!match[v]||self(self,match[v])){
                        match[v]=u;
                        return true;
                    }
                }
            }
            return false;
        };
        if(dfs(dfs,i))
            ans++;
    }
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