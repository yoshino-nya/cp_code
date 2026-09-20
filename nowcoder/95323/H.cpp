// Author: Zhangwuji
// Date: 2025-01-21
// Time: 14:21:05

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
    int n;
    cin >> n;
    vi l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    vector<vector<pii>>v(n+1,vector<pii>());
    for(int i=1;i<=n;i++){
        v[l[i]].push_back({r[i],i});
    }
    set<pii>st;
    vector<int>ans(n+1);
    for(int i=1;i<=n;i++){
        for(auto [x,y]:v[i])
            st.insert({x,y});
        if(st.empty()||st.begin()->first<i){
            cout<<"-1\n";
            return;
        }
        ans[st.begin()->second]=i;
        st.erase(st.begin());
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
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