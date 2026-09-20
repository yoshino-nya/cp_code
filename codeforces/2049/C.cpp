// Author: Zhangwuji
// Date: 2024-12-20
// Time: 23:16:51

// #define YUANSHEN
#if defined(YUANSHEN)
#include "D:/cp/template/debug.hpp"
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
    int n,x,y;
    cin>>n>>x>>y;
    vector<vi>adj(n+1,vi());
    for(int i=1;i<n;i++){
        adj[i].push_back(i+1);
    }
    adj[n].push_back(1);
    for(int i=n;i>1;i--){
        adj[i].push_back(i-1);
    }
    adj[1].push_back(n);
    if(find(all(adj[x]),y)==adj[x].end()){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vi a(n+1,-1);
    for(int i=1;i<=n;i++){
        int mex=0;
        set<int>st;
        for(auto v:adj[i]){
            st.insert(a[v]);
        }
        for(auto x:st)
            if(x==mex) mex++;
        a[i]=mex;
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}