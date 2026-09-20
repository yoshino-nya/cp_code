// Author: Zhangwuji
// Date: 2025-02-17
// Time: 20:19:41

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
    //每个连通块进行排序 输出
    int n,m;
    cin>>n>>m;
    vi a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    vector<vi>adj(n+1,vi());
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>vis(n+1);
    set<int>st;
    auto dfs=[&](auto &&self,int u)->void{
        st.insert(u);
        vis[u]=true;
        for(auto v:adj[u]){
            if(!vis[v]){
                self(self,v);
            }
        }
    };
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(dfs,i);
        vi stk;
        for(auto x:st)
            stk.push_back(a[x]);
        sort(all(stk));
        for(auto x:st){
            a[x]=stk.back();
            stk.pop_back();
        }
        st.clear();
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" \n"[i==n];
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