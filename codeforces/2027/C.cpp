// Author: Zhangwuji
// Date: 2025-01-03
// Time: 23:27:34

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
    int n;
    cin>>n;
    vl a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    map<ll,set<int>>mp;
    for(int i=1;i<=n;i++){
        ll len=a[i]+i-1;
        mp[len].insert(i);
    }
    set<ll>st;
    st.insert(n);
    for(auto &[len,x]:mp){
        if(!st.count(len)) continue;
        for(auto &y:x){
            st.insert(len+y-1);
        }
    }
    cout<<*st.rbegin()<<'\n';
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