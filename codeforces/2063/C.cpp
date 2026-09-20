// Author: Zhangwuji
// Date: 2025-01-23
// Time: 03:03:03

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
    int n;
    cin>>n;
    vi deg(n+1);
    vector<vi>adj(n+1,vi());
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    multiset<int>st;
    for(int i=1;i<=n;i++){
        st.insert(deg[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        st.erase(st.find(deg[i]));
        for(auto v:adj[i]){
            st.erase(st.find(deg[v]));
            st.insert(deg[v]-1);
        }
        cmax(ans,deg[i]+*st.rbegin()-1);
        for(auto v:adj[i]){
            st.erase(st.find(deg[v]-1));
            st.insert(deg[v]);
        }
        st.insert(deg[i]);
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}