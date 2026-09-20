/*
拿一段正数+一段负数
或全拿正数 全拿负数
*/
// Author: Zhangwuji
// Date: 2025-02-16
// Time: 23:14:01

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
    ll ans=0;
    vi a(n+1);
    vl p1(n+1),p2(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p1[i]=p1[i-1],p2[i]=p2[i-1];
        if(a[i]<0)
            p1[i]-=a[i];
        else
            p2[i]+=a[i];
    }
    ans=p1[n];
    for(int i=1;i<=n;i++){
        cmax(ans,p2[i]+p1[n]-p1[i]);
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