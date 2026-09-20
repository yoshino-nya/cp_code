// Author: Zhangwuji
// Date: 2025-02-18
// Time: 00:18:46

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
    int n,m,s;
    cin>>n>>m>>s;
    vector<vector<pii>>adj(n+1,vector<pii>());
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<int>dis(n+1,(1LL<<31)-1);
    dis[s]=0;
    auto dij=[&](){
        priority_queue<pii>pq;
        pq.push({0,s});
        while(!pq.empty()){
            auto [dist,u]=pq.top();
            // cerr<<dist<<" "<<u<<'\n';
            dist=-dist;
            pq.pop();
            if(dist>dis[u]) continue;
            for(auto [v,w]:adj[u]){
                if(dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                    pq.push({-dis[v],v});
                }
            }
        }
    };
    dij();
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" \n"[i==n];
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